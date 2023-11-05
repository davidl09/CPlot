cmake_minimum_required(VERSION 3.25)
project(CPlot-Plotter)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

set(PROJECT_VER_PATCH 0)
set(PROJECT_VER_MINOR 1)
set(PROJECT_VER_MAJOR 0)

set(PROJECT_VER "${PROJECT_VER_MAJOR}.${PROJECT_VER_MINOR}.${PROJECT_VER_PATCH}")

add_subdirectory(deps)

if(WIN32)
        add_executable(CPlot WIN32
        "main.cpp"
        )
else()
        add_executable(CPlot 
        "main.cpp"
        )
endif()


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

set(CPACK_GENERATOR "NSIS")
set(CPACK_PROJECT_CONFIG_FILE ${CMAKE_SOURCE_DIR}/cmake/CPackConfig.cmake)

if(WIN32)
    if(MSVC)
        install(TARGETS CPlot
            DESTINATION bin COMPONENT binaries)
        # install the target file since the foo target isn't built in this context.
        install(FILES ${CMAKE_SOURCE_DIR}/assets/*
            DESTINATION data COMPONENT data_files)
    endif(MSVC)
endif(WIN32)

include(${CPACK_PROJECT_CONFIG_FILE})

