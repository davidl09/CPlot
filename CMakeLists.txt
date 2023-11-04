cmake_minimum_required(VERSION 3.25)
project(imgui-test2)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(deps)

add_executable(CPlot WIN32
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

if (NOT MSVC) 
        target_link_libraries(
                CPlot PUBLIC 
                pthread
        )
endif()

install(
        TARGETS CPlot
        DESTINATION ${CMAKE_SOURCE_DIR}/package
)
install(
        DIRECTORY assets
        DESTINATION ${CMAKE_SOURCE_DIR}/package
)

include(CPackConfig.cmake)
