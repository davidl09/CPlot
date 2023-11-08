add_library(
        CPlotSrc STATIC
        CPlotApp.cpp
        ComplexPlot.cpp
        Pixel.cpp
        Flags.cpp
)

set(
        CPLOT_INCLUDE_DIR ${CMAKE_CURRENT_LIST_DIR}
        PARENT_SCOPE
)

target_include_directories(
        CPlotSrc PUBLIC
        "${SDL2_INCLUDE_DIR}"
        "${IMGUI_INCLUDE_DIR}"
)

