cmake_minimum_required(VERSION 3.25)
project(imgui-test2)


add_executable(test 
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

include_directories(test imgui imgui/backends libcplot/include libcplot/include/expr_parsing_cpp)

add_compile_options(-Og -I/usr/include/SDL2 -D_REENTRANT)
target_link_libraries(test SDL2 GL dl)

