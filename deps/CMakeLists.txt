add_subdirectory(SDL)

add_library(
        imgui STATIC
        "imgui/imgui.cpp"
        "imgui/imgui_draw.cpp"
        "imgui/imgui_tables.cpp"
        "imgui/imgui_widgets.cpp"
        "imgui/backends/imgui_impl_sdl2.cpp"
        "imgui/backends/imgui_impl_sdlrenderer2.cpp"
)

target_include_directories(
        imgui PUBLIC
        "imgui"
        "imgui/backends"
        SDL2::SDL2_INCLUDE_DIR
        
)

target_link_libraries(
        imgui PUBLIC
        SDL2::SDL2-static
)

add_library(
        libcplot STATIC
        "libcplot/src/libcplot.cpp"
        "libcplot/src/toojpeg.cpp"
)

target_include_directories(
        libcplot PUBLIC
        "libcplot/include"
        "libcplot/include/astParser/include"
)

