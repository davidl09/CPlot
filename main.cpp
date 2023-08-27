#include "imgui.h"
#include "imgui_impl_sdl2.h"
#include "imgui_impl_sdlrenderer2.h"

#include "libcplot.hpp"

#include <SDL2/SDL.h>

#include <string>
#include <cstring>

#if !SDL_VERSION_ATLEAST(2,0,17)
#error This backend requires SDL 2.0.17+ because of SDL_RenderGeometry() function
#endif

//(I * carg(z) * cabs(z) * exp((cpow(z, 3) + cpow(z, z))))
//(((cpow(z, 2) - 1)*cpow(z - 2 - I, 2))/(cpow(z, 2) + 2 + 2*I))
//(0.4*cpow((z), 5) + 3 * cpow(z, 3) - cpow(z, 2) + 5*z)/(cpow(I*z, 5))
//csin(3*carg(cexp(I *  (cabs(z) - carg(z))))) * cexp(I *  (cabs(z) - carg(z))) //spiral
//(0.4*cpow((z), 5) + 3 * cpow(z, 3) - cpow(z, 2) + 5*z)
//z*cexp(I * 2 * carg(z))
//cpow(z, 2) + 1
//cpow(M_E, ccos(z))
//(((cpow(z, 2) - 1)*cpow(z - 2 - I, 2))/(cpow(z, 2) + 2 + 2*I))

const static std::vector<std::pair<char *, char *>> examples({
    {"6th degree polynomial", "3*z^4-7*z^3+(2/9)+z^2-z+10-34*i*z^6"}, 
    {"Grid", "cos(imag(z)) + i * sin(real(z))"},
    {"Zoom-independent function", "10*exp(i*arg(z))"},
    {"Imaginary roots at +-i", "z^2 + 1"},
    {"Spiral", "100*(sin(3*arg(exp(i*(abs(z)-arg(z)))))*exp(i*(abs(z)-arg(z))))"},
    {"Cool pattern", "z^z^sin(exp(cos(z)))"}

});

// Main code
int main(int, char**)
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
    SDL_WindowFlags window_flags = (SDL_WindowFlags)(SDL_WINDOW_RESIZABLE | SDL_WINDOW_ALLOW_HIGHDPI);
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
/*
    // Load Fonts
    // - If no fonts are loaded, dear imgui will use the default font. You can also load multiple fonts and use ImGui::PushFont()/PopFont() to select them.
    // - AddFontFromFileTTF() will return the ImFont* so you can store it if you need to select the font among multiple.
    // - If the file cannot be loaded, the function will return a nullptr. Please handle those errors in your application (e.g. use an assertion, or display an error and quit).
    // - The fonts will be rasterized at a given size (w/ oversampling) and stored into a texture when calling ImFontAtlas::Build()/GetTexDataAsXXXX(), which ImGui_ImplXXXX_NewFrame below will call.
    // - Use '#define IMGUI_ENABLE_FREETYPE' in your imconfig file to use Freetype for higher quality font rendering.
    // - Read 'docs/FONTS.md' for more instructions and details.
    // - Remember that in C/C++ if you want to include a backslash \ in a string literal you need to write a double backslash \\ !
    io.Fonts->AddFontDefault();
    //io.Fonts->AddFontFromFileTTF("c:\\Windows\\Fonts\\segoeui.ttf", 18.0f);  //windows font :(
    io.Fonts->AddFontFromFileTTF("../../misc/fonts/DroidSans.ttf", 16.0f);
    io.Fonts->AddFontFromFileTTF("../../misc/fonts/Roboto-Medium.ttf", 16.0f);
    io.Fonts->AddFontFromFileTTF("../../misc/fonts/Cousine-Regular.ttf", 15.0f);
    //ImFont* font = io.Fonts->AddFontFromFileTTF("c:\\Windows\\Fonts\\ArialUni.ttf", 18.0f, nullptr, io.Fonts->GetGlyphRangesJapanese());
    //IM_ASSERT(font != nullptr);
*/
    

    bool done = false;
    bool flip_due = true;
    bool render_due = true;
    Uint64 ticks_at_last_render = 0;
    float maxval = 10.0;
    float menuBarHeight = 23; //default value
    char text_input[100] = {'z', '\0'};
    char error_text[100] = {0};
    ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);

    //rendering and image flip callbacks
    auto render = [&]()
    {
        try{
            image.plot_complex_func(std::string(text_input), static_cast<double>(maxval), false, std::thread::hardware_concurrency()); 
        }
        catch(std::invalid_argument& e)
        {
            std::strcpy(error_text, e.what());
            return;
        }

        error_text[0] = 0;
        ticks_at_last_render = SDL_GetTicks64();
        render_due = false; 
        
    };

    auto flip = [&]() {
        SDL_UpdateTexture(imageTexture, nullptr, image.get_data(), image.get_width() * 3);  
        flip_due = false;
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

            if (event.type == SDL_WINDOWEVENT_RESIZED) {
                image.resize(io.DisplaySize.x, io.DisplaySize.y - 4 * menuBarHeight);
                SDL_DestroyTexture(imageTexture);
                imageTexture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGB24, SDL_TEXTUREACCESS_STREAMING, io.DisplaySize.x, io.DisplaySize.y - 4 * menuBarHeight);
                render_due = true;
            }

        }
        ImGui_ImplSDLRenderer2_NewFrame();
        ImGui_ImplSDL2_NewFrame();
        ImGui::NewFrame();       
        
        // Main menu bar
        
        if (ImGui::BeginMainMenuBar()) {
            if (ImGui::BeginMenu("File")) {
                if (ImGui::MenuItem("Open")) {
                    // Handle open action
                }
                if (ImGui::MenuItem("Save As")) {
                    show_save_popup = true;
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
            if (ImGui::BeginMenu("Functions")) {
                for (auto& str : Parsing::operators) {
                    if(str.length() > 1) {
                        if (ImGui::MenuItem((str + "z)").c_str())) {
                            std::strcpy(text_input, (str + "z)").c_str());
                            render_due = true;
                        }
                    }
                }
                ImGui::EndMenu();
            }
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
        auto img_size = ImVec2(io.DisplaySize.x, io.DisplaySize.y - menuBarHeight * 4);
        ImGui::SetNextWindowSize(img_size); // Exclude menu bar and text input heights
        ImGui::Begin("Image Display", nullptr, ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoScrollbar);
        ImGui::Image((void*)(intptr_t)imageTexture, img_size);
        ImGui::End();
        //ImGui::ShowMetricsWindow(); //debugging

        ImGui::SetNextWindowPos(ImVec2(0, io.DisplaySize.y - menuBarHeight * 3));
        ImGui::SetNextWindowSize(ImVec2(io.DisplaySize.x, menuBarHeight * 3));
        ImGui::Begin("Text Input", nullptr, ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoScrollbar);

        if(ImGui::SliderFloat("Image plot range", &maxval, 0.5, 100))
        {
            render_due = true;
        }

        if(ImGui::InputText((error_text[0] ? error_text : "= f(z)"), text_input, 100, ImGuiInputTextFlags_EnterReturnsTrue))
        {
            render_due = true;
        }

        if(!(SDL_GetTicks64() % (1000 / 144))) //1000 ms per second divided by framerate is the time between refreshing ticks
        {
            flip_due = true;
        }
        ImGui::End();

        if(flip_due)
            flip();

        if(render_due && (SDL_GetTicks64() - ticks_at_last_render) > 1500) //render events are at least 1 second apart
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