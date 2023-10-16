add_subdirectory(tbb)
find_package(TBB REQUIRED tbb)
find_package(SDL2 REQUIRED)

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
        "/usr/include/SDL2"
)

add_library(
        libcplot STATIC
        "libcplot/src/libcplot.cpp"
        "libcplot/src/toojpeg.cpp"
)

target_include_directories(
        libcplot PUBLIC
        "libcplot/include"
        "libcplot/include/expr_parsing_cpp/src"
)

