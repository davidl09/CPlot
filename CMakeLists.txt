cmake_minimum_required(VERSION 3.25)
project(imgui-test2)

set(CMAKE_CXX_STANDARD 20)
add_compile_options(-O3 -D_REENTRANT -march=native)

add_subdirectory(deps)

add_executable(CPlot 
    "main.cpp"
)


target_link_libraries(CPlot
        imgui
        libcplot
        SDL2
)

