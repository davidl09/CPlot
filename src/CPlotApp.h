//
// Created by davidl09 on 11/6/23.
//

#ifndef IMGUI_TEST2_CPLOTAPP_H
#define IMGUI_TEST2_CPLOTAPP_H

#include <string>
#include <cstring>

#include "imgui.h"
#include "imgui_impl_sdl2.h"
#include "imgui_impl_sdlrenderer2.h"
#include "SDL.h"

enum AppState : int16_t {
    hasDarkMode = 0,
    isScrollingView = 1,

};

class CPlotApp {
public:
    CPlotApp();
    ~CPlotApp();
private:

    SDL_Renderer *renderer;
    SDL_Window *window;

    ImGuiIO *io;

    std::string errorMessage;
    std::string inputFunction;
    std::string about;
    std::string rendererInfo;

    int windowWidth, windowHeight;

    float scale;

};


#endif //IMGUI_TEST2_CPLOTAPP_H
