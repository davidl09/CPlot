cmake_minimum_required(VERSION 3.25)
project(imgui-test2)

set(CMAKE_CXX_STANDARD 20)
add_compile_options(-Ofast -DTHREAD_SAFE -Wno-writable-strings -Wno-write-strings)

find_package(SDL2 REQUIRED)

include_directories(
        ${SDL2_INCLUDE_DIR}
)

add_subdirectory(deps)

add_executable(CPlot 
    "main.cpp"
)

target_link_libraries(CPlot
        imgui
        libcplot
        ${SDL2_LIBRARIES}
        pthread
        tbb
)

