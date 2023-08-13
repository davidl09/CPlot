cmake_minimum_required(VERSION 3.25)
project(imgui-test)

set(CMAKE_CXX_STANDARD 17)

set(${IMGUI_BACKEND}
    imgui/backends/imgui_impl_opengl3.cpp 
    imgui/backends/imgui_impl_sdl2.cpp 
)

set(${SDL_FLAGS} `sdl2-config --cflags`)
set(${SDL_INCLUDES} `sdl2-config --libs)

include_directories(imgui)
include_directories(imgui/backends)
# Add your source files
add_executable(test 
    main.cpp 
    imgui/imgui.cpp 
    #imgui/imgui_demo.cpp
    imgui/imgui_draw.cpp 
    imgui/imgui_tables.cpp 
    imgui/imgui_widgets.cpp 
    imgui/backends/imgui_impl_opengl3.cpp 
    imgui/backends/imgui_impl_sdl2.cpp 
)

add_compile_options(-I/usr/include/SDL2 -D_REENTRANT)
target_link_libraries(test SDL2 GL dl)
