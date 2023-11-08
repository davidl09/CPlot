cmake_minimum_required(VERSION 3.25)
project(CPlot-Plotter)

set(CMAKE_CXX_STANDARD 20)

if (WIN32)
        set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR})
else()
        set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)
endif()

set(PROJECT_VER_PATCH 0)
set(PROJECT_VER_MINOR 2)
set(PROJECT_VER_MAJOR 0)

set(PROJECT_VER "${PROJECT_VER_MAJOR}.${PROJECT_VER_MINOR}.${PROJECT_VER_PATCH}")

add_subdirectory(submodules)


add_subdirectory(src)

if(WIN32)
        add_executable(CPlot WIN32
        "main.cpp"
        "assets/icon.rc"
        )
else()
        add_executable(CPlot 
        "main.cpp"
        )
endif()

target_include_directories(
        CPlotSrc PUBLIC
        SDL2::SDL2_INCLUDE_DIR
        "${IMGUI_INCLUDE_DIR}"
)

target_include_directories(
        CPlot PUBLIC
        SDL2::SDL2_INCLUDE_DIR
        "${IMGUI_INCLUDE_DIR}"
        "${PORTABLE_FILE_LIB_INCLUDE}"
        "${CPLOT_INCLUDE_DIR}"
)

target_link_libraries(
        CPlot PUBLIC
        imgui
        CPlotSrc
        libcplot
)


