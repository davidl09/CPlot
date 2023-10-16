cmake_minimum_required(VERSION 3.25)
project(imgui-test2)

set(CMAKE_CXX_STANDARD 20)
add_compile_options(-Ofast -DTHREAD_SAFE -Wno-writable-strings -Wno-write-strings -Wall -Wno-unused-variable)

find_package(SDL2 REQUIRED)

add_subdirectory(deps)

include_directories(
        ${SDL2_INCLUDE_DIR}
)

add_executable(CPlot 
    "main.cpp"
)

message("SDL2 Libs: ${SDL2_LIBRARIES}")

target_link_libraries(CPlot PUBLIC
        imgui
        libcplot
        ${SDL2_LIBRARIES}
        pthread
        tbb
)

