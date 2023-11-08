add_subdirectory(SDL)

set(
        SDL2_INCLUDE_DIR
        "${CMAKE_CURRENT_LIST_DIR}/SDL/include"
        CACHE INTERNAL "SDL2_INCLUDE_DIR"
)

set(
        PARSER_INCLUDE_DIR
        "${CMAKE_CURRENT_LIST_DIR}/astParser/include"
        CACHE INTERNAL "PARSER_INCLUDE_DIR"
)

set(
        IMGUI_INCLUDE_DIR
        "${CMAKE_CURRENT_LIST_DIR}/imgui"
        "${CMAKE_CURRENT_LIST_DIR}/imgui/backends"
        CACHE INTERNAL "IMGUI_INCLUDE_DIR"
)

set(IMGUI_SOURCES
        "imgui/imgui.cpp"
        "imgui/imgui_draw.cpp"
        "imgui/imgui_tables.cpp"
        "imgui/imgui_widgets.cpp"
        "imgui/backends/imgui_impl_sdl2.cpp"
        "imgui/backends/imgui_impl_sdlrenderer2.cpp"
)

add_library(imgui STATIC
        "${IMGUI_SOURCES}"
)

target_include_directories(
        imgui PUBLIC
        SDL2::SDL2_INCLUDE_DIR
        "${IMGUI_INCLUDE_DIR}"
)

target_link_libraries(
        imgui PUBLIC
        SDL2::SDL2-static
)
