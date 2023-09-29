cmake_minimum_required(VERSION 3.25)
project(imgui-test2)

set(CMAKE_CXX_STANDARD 20)


add_executable(CPlot 
    "main.cpp" 
    "imgui/imgui.cpp" 
    "imgui/imgui_draw.cpp" 
    "imgui/imgui_tables.cpp" 
    "imgui/imgui_widgets.cpp" 
    "imgui/backends/imgui_impl_sdl2.cpp" 
    "imgui/backends/imgui_impl_sdlrenderer2.cpp" 
    "libcplot/src/libcplot.cpp"
    "libcplot/src/toojpeg.cpp"
)

include_directories(imgui imgui/backends libcplot/include libcplot/include/expr_parsing_cpp/src /usr/include/SDL2)

add_compile_options(-O3 -D_REENTRANT)
target_link_libraries(CPlot SDL2)

