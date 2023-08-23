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

// Main code
int main(int, char**)
{
    // Setup SDL
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER | SDL_INIT_GAMECONTROLLER) != 0)
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
    
    int width = mode.w;
    int height = mode.h;
    BitMap image(width, height); //resolution set to max width
    image.plot_complex_func("z", 10, false, 16);
    SDL_Texture* imageTexture = nullptr;
    
    unsigned char* imageData = image.get_data(); // Initialize with initial data
    imageTexture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGB24, SDL_TEXTUREACCESS_STREAMING, width, height);
    SDL_UpdateTexture(imageTexture, nullptr, imageData, image.get_width() * 3);

    char text_input[100] = {0};
    /*
    SDL_RendererInfo info;
    SDL_GetRendererInfo(renderer, &info);
    SDL_Log("Current SDL_Renderer: %s", info.name);
    */

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
    auto ticks_at_last_render = SDL_GetTicks64();
    float maxval = 10.0;
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
                if (ImGui::MenuItem("Spiral")) {
                    text_input = 
                }
            }
            // Add more menus as needed
            ImGui::EndMainMenuBar();
        }

        if(show_save_popup)
        {
            //ImGui::BeginPopup("Save as");
            /*
            char filename[80] = {0};
            ImGui::OpenPopup("Save current view", ImGuiPopupFlags_AnyPopup);

            if (ImGui::BeginPopupModal("Save As Popup", &show_save_popup, ImGuiWindowFlags_AlwaysAutoResize)) {
                ImGui::Text("Filename to save current view");
                ImGui::InputText("Save", filename, IM_ARRAYSIZE(filename), ImGuiInputTextFlags_AutoSelectAll | ImGuiInputTextFlags_AlwaysOverwrite);

                if (ImGui::Button("Ok")) {
                    // Handle save logic here using 'filename'
                    // For example: image.save_jpeg(filename);
                    show_save_popup = false; // Close the popup
                    ImGui::CloseCurrentPopup(); // Close the modal after saving
                }

                ImGui::SameLine();

                if (ImGui::Button("Cancel")) {
                    show_save_popup = false; // Close the popup
                    ImGui::CloseCurrentPopup();
                }
                show_save_popup = false;
                ImGui::EndPopup();
            }
            */
        }

        float menuBarHeight = ImGui::GetFrameHeightWithSpacing(); // Height of the menu bar
        ImGui::SetNextWindowPos(ImVec2(0, menuBarHeight));
        auto img_size = ImVec2(io.DisplaySize.x, io.DisplaySize.y - menuBarHeight * 4);
        ImGui::SetNextWindowSize(img_size); // Exclude menu bar and text input heights
        //image.resize(img_size.x, img_size.y);
        ImGui::Begin("Image Display", nullptr, ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoScrollbar);
        ImGui::Image((void*)(intptr_t)imageTexture, img_size);
        ImGui::End();
        //ImGui::ShowMetricsWindow(); //debugging
        //ImGui::SetNextWindowPos(ImVec2(0, io.DisplaySize.y - menuBarHeight * 3)); // Docked at the bottom
        //ImGui::SetNextWindowSize(ImVec2(io.DisplaySize.x, menuBarHeight));

        ImGui::SetNextWindowPos(ImVec2(0, io.DisplaySize.y - menuBarHeight * 3));
        ImGui::SetNextWindowSize(ImVec2(io.DisplaySize.x, menuBarHeight * 3));
        ImGui::Begin("Text Input", nullptr, ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoScrollbar);

        if(ImGui::SliderFloat("Image plot range", &maxval, 0.5, 100))
        {
            render_due = true;
        }

        if(ImGui::InputText((error_text[0] ? error_text : "= f(z)"), text_input, 100, ImGuiInputTextFlags_None))
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
        //std::cout << ticks_at_last_render << "\n";
        if(render_due && (SDL_GetTicks64() - ticks_at_last_render) > 1000) //render events are at least 1 second apart
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