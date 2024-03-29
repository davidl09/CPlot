#include "imgui.h"
#include "imgui_impl_sdl2.h"
#include "imgui_impl_sdlrenderer2.h"

#include "libcplot.hpp"

#include <SDL.h>

#include <string>
#include <cstring>

#include "portable-file-dialogs.h"

#if !SDL_VERSION_ATLEAST(2,0,17)
#error This backend requires SDL 2.0.17+ because of SDL_RenderGeometry() function
#endif

#ifdef _WIN32
#include <Windows.h>
#include <SDL2/SDL_syswm.h>
#endif

const static std::vector<std::pair<const char *, const char *>> examples({
    {"5th degree polynomial", "0.4z^5+3z^3-z^2+5z"},
    {"6th degree polynomial", "3*z^4-7*z^3+(2/9)+z^2-z+10-34*i*z^6"}, 
    {"Grid", "cos(imag(z)) + i * sin(real(z))"},
    {"Zoom-independent function", "10*exp(i*arg(z))"},
    {"Radial Symmetry", "10*exp(i*abs(z))"},
    {"Imaginary roots at +-i", "z^2 + 1"},
    {"Spiral", "100*(sin(3*arg(exp(i*(abs(z)-arg(z)))))*exp(i*(abs(z)-arg(z))))"},
    {"Exponential with cubic argument", "exp(z^3 + z^z)"},
    {"Cool pattern", "z^z^sin(exp(cos(z)))"}

});

// Main code
#ifdef _WIN32
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) 
#else
int main(int, char**)
#endif
{
    // Setup SDL
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER) != 0)
    {
        printf("Error: %s\n", SDL_GetError());
        return -1;
    }

    // From 2.0.18: Enable native IME.
#ifdef SDL_HINT_IME_SHOW_UI
    SDL_SetHint(SDL_HINT_IME_SHOW_UI, "1");
#endif


    // Create window with SDL_Renderer graphics context
    auto window_flags = (SDL_WindowFlags)(SDL_WINDOW_RESIZABLE | SDL_WINDOW_ALLOW_HIGHDPI);
    SDL_Window* window = SDL_CreateWindow("CPlot", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1280, 720, window_flags);
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC | SDL_RENDERER_ACCELERATED);
    if (renderer == nullptr)
    {
        SDL_Log("Error creating SDL_Renderer!");
        return 0;
    }
    
    SDL_DisplayMode mode;
    SDL_GetCurrentDisplayMode(0, &mode);
    

    BitMap image(mode.w, mode.h); //resolution set to max width
    SDL_Texture* imageTexture = nullptr;
    
    imageTexture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGB24, SDL_TEXTUREACCESS_STREAMING, mode.w, mode.h);
    SDL_UpdateTexture(imageTexture, nullptr, image.get_data(), image.get_width() * 3);

    // Setup Dear ImGui context
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO();
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;     // Enable Keyboard Controls
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;      // Enable Gamepad Controls

    // Setup Dear ImGui style
    ImGui::StyleColorsDark();
    //ImGui::StyleColorsLight();
    // Setup Platform/Renderer backends
    ImGui_ImplSDL2_InitForSDLRenderer(window, renderer);
    ImGui_ImplSDLRenderer2_Init(renderer);


    auto font_calibri = io.Fonts->AddFontFromFileTTF("../assets/fonts/calibri.ttf", 16.0f);
    if (font_calibri == nullptr) {
        font_calibri = io.Fonts->AddFontFromFileTTF("../../assets/fonts/calibri.ttf", 16.0f);
        if (font_calibri == nullptr) {
            io.Fonts->AddFontDefault();
        }
    }
    

    bool done = false;
    bool flip_due = true;
    bool render_due = true;
    bool dark_mode = true;
    bool multithreading = true;
    bool resizeDue = true;
    std::string saveAsFile;
    Uint64 ticks_at_last_render = 0;
    float maxval = 10.0;
    float menuBarHeight = 23; //default value
    char text_input[100] = {'z', '\0'};
    char error_text[100] = {0};
    int framerate = 144;
    Expression<std::complex<double>> expr;
    //auto ticks_per_frame = 1000 / 144;
    ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);
    ImVec2 imageDisplaySize{io.DisplaySize.x, io.DisplaySize.y};

    //rendering and image flip callbacks
    auto render = [&]()
    {
        try {
            expr.checkInitWithExcept(text_input);
            expr.evaluate({
                        {"z", {0, 0}}, 
                        {"i", {0, 1}},
                        {"e", {std::numbers::e, 0}},
                        {"pi", {std::numbers::pi}}
                                                                                                    
                    });

        }
        catch(std::exception& e) {
            std::strcpy(error_text, e.what());
            render_due = false;
            return;
        }

        image.plot_complex(expr, static_cast<double>(maxval), false, multithreading ? static_cast<int>(std::thread::hardware_concurrency()) : 1);

        error_text[0] = 0;
        ticks_at_last_render = SDL_GetTicks64();
        render_due = false; 
        
    };

    auto adjustSize = [&]() {
        image.resize(static_cast<int>(imageDisplaySize.x), static_cast<int>(imageDisplaySize.y));
        SDL_DestroyTexture(imageTexture);
        imageTexture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGB24, SDL_TEXTUREACCESS_STREAMING, static_cast<int>(imageDisplaySize.x), static_cast<int>(imageDisplaySize.y));
        resizeDue = false;
    };

    auto flip = [&]() {
        SDL_UpdateTexture(imageTexture, nullptr, image.get_data(), image.get_width() * 3);  
        flip_due = false;
    };

    auto saveOutput = [&]() {
        image.save_jpeg(saveAsFile);
        saveAsFile.erase();
    };

    bool show_save_popup = false;
    while (!done) //main loop
    {
        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            ImGui_ImplSDL2_ProcessEvent(&event);
            if (event.type == SDL_QUIT)
                done = true;

            if (event.type == SDL_WINDOWEVENT && event.window.event == SDL_WINDOWEVENT_CLOSE && event.window.windowID == SDL_GetWindowID(window))
                done = true;

            if (event.type == SDL_WINDOWEVENT && event.window.event == SDL_WINDOWEVENT_SIZE_CHANGED) {
                render_due = true;
                resizeDue = true;
            }

        }
        ImGui_ImplSDLRenderer2_NewFrame();
        ImGui_ImplSDL2_NewFrame();
        if(dark_mode) {
            ImGui::StyleColorsDark();
        } else ImGui::StyleColorsLight();
        ImGui::NewFrame();

        if (!saveAsFile.empty()) {
            saveOutput();
        }
        
        if (ImGui::BeginMainMenuBar()) {
            if (ImGui::BeginMenu("File")) {
                if (ImGui::MenuItem("Open")) {
                    // Handle open action
                }
                if (ImGui::MenuItem("Save as...")) {
                    saveAsFile = pfd::save_file(
                        "Save CPlot Output",
                        pfd::path::home(),
                        {"Jpeg Images (*.jpg, *.jpg)", "*.jpg"},
                        pfd::opt::force_overwrite
                    ).result();
                    
                }
                if (ImGui::MenuItem("Quit")) {
                    break;
                }
                ImGui::EndMenu();
            }

            if (ImGui::BeginMenu("Functions")) {
                for (auto& func : expr.getUnaryFuncs()) {
                    if(func.first.length() > 1) {
                        if (ImGui::MenuItem(&func.first[0])) {
                            std::strcpy(text_input, &func.first[0]);
                            std::strcat(text_input, "(z)");
                            render_due = true;
                        }
                    }
                }
                ImGui::EndMenu();
            }

            if (ImGui::BeginMenu("Examples")) {

                for(auto& example : examples)
                {
                    if(ImGui::MenuItem(example.first)) {
                        std::strcpy(text_input, example.second);
                        render_due = true;
                    }
                }
                ImGui::EndMenu();
            }
            /*
            if(ImGui::BeginMenu("Framerate")) {
                std::vector<int> options = {24, 30, 60, 144};
                for(auto& o : options) {
                    if(ImGui::MenuItem(std::to_string(o).c_str())) {
                        framerate = o;
                    }
                }
                ImGui::EndMenu();
            }
             */
            // Add more menus as needed
            ImGui::EndMainMenuBar();
        }

        if(show_save_popup) {
            ImGui::OpenPopup("Save current view as JPEG");
        }

        if(ImGui::BeginPopupModal("Save current view as JPEG", nullptr, ImGuiWindowFlags_AlwaysAutoResize)) {
            

            char filename[80] = {0};
            ImGui::Text("Save as...");
            ImGui::SameLine();
            if (ImGui::InputText("##", filename, IM_ARRAYSIZE(filename), ImGuiInputTextFlags_EnterReturnsTrue)) {
                image.save_jpeg(filename);
                ImGui::CloseCurrentPopup();
                show_save_popup = false;
            }
            ImGui::SameLine();
            if (ImGui::Button("Cancel")) {
                ImGui::CloseCurrentPopup();
                show_save_popup = false; // Close the popup
            }
            // End the popup modal
            ImGui::EndPopup();
        }


        menuBarHeight = ImGui::GetFrameHeightWithSpacing(); // Height of the menu bar
        ImGui::SetNextWindowPos(ImVec2(0, menuBarHeight));
        imageDisplaySize = {io.DisplaySize.x, io.DisplaySize.y - menuBarHeight * 4};
        if (resizeDue) {
            adjustSize();
        }
        ImGui::SetNextWindowSize(imageDisplaySize); // Exclude menu bar and text input heights
        ImGui::Begin("Image Display", nullptr, ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoScrollbar);
        ImGui::Image((void*)(intptr_t)imageTexture, imageDisplaySize);
        ImGui::End();

        ImGui::SetNextWindowPos(ImVec2(0, io.DisplaySize.y - menuBarHeight * 3));
        ImGui::SetNextWindowSize(ImVec2(io.DisplaySize.x, menuBarHeight * 3));
        ImGui::Begin("Text Input", nullptr, ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoScrollbar);

        if(ImGui::SliderFloat("Image plot range", &maxval, 0.0001, 10000, "%.4f", ImGuiSliderFlags_Logarithmic | ImGuiSliderFlags_NoRoundToFormat))
        {
            render_due = true;
        }

        ImGui::SameLine(ImGui::GetWindowContentRegionMax().x - 250);
        ImGui::Checkbox("Dark Mode", &dark_mode);
        ImGui::SameLine(ImGui::GetWindowContentRegionMax().x - 125);
        ImGui::Checkbox("Multithreading", &multithreading);

        if(ImGui::InputText((error_text[0] ? error_text : "= f(z)"), text_input, 100, ImGuiInputTextFlags_EnterReturnsTrue))
        {
            render_due = true;
        }

        if(!(SDL_GetTicks64() % (1000 / framerate))) //1000 ms per second divided by framerate is the time between refreshing ticks
        {                                            // Is broken but works for now
            flip_due = true;
        }
        ImGui::End();

        if(flip_due)
            flip();

        if(render_due && (SDL_GetTicks64() - ticks_at_last_render) > 250) //render events are at least 1 second apart
            render();

        // Rendering
        ImGui::Render();
        SDL_RenderSetScale(renderer, io.DisplayFramebufferScale.x, io.DisplayFramebufferScale.y);
        SDL_SetRenderDrawColor(renderer, (Uint8)(clear_color.x * 255), (Uint8)(clear_color.y * 255), (Uint8)(clear_color.z * 255), (Uint8)(clear_color.w * 255));
        SDL_RenderClear(renderer);
        ImGui_ImplSDLRenderer2_RenderDrawData(ImGui::GetDrawData());
        SDL_RenderPresent(renderer);
    }

    // Cleanup
    ImGui_ImplSDLRenderer2_Shutdown();
    ImGui_ImplSDL2_Shutdown();
    ImGui::DestroyContext();

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
    
}
