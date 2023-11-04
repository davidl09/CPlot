cmake_minimum_required(VERSION 3.25)
project(CPlot-Plotter)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

add_subdirectory(deps)

add_executable(CPlot
    "main.cpp"
)

target_include_directories(
        CPlot PUBLIC
        SDL2::SDL2_INCLUDE_DIR
)

target_link_libraries(
        CPlot PUBLIC
        imgui
        libcplot
        SDL2::SDL2-static
)

if (NOT WIN32) 
        target_link_libraries(
                CPlot PUBLIC 
                pthread
        )
endif()

