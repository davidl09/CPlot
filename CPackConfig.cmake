set(CPACK_GENERATOR "ZIP")
set(CPACK_PACKAGE_DIRECTORY ${CMAKE_SOURCE_DIR}/share)
set(CPACK_PACKAGE_VERSION "1.0.0")
set(CPACK_PACKAGE_NAME "CPlot")
set(CPACK_INSTALL_CMAKE_PROJECTS "CPlot")
set(CPACK_INSTALLED_DIRECTORIES assets)
set(CPACK_PACKAGE_FILE_NAME "CPlot-1.0.0")
set(CPACK_PACKAGE_DESCRIPTION "A graphical tool that helps visualize features of complex valued functions using colour mapping and real-time rendering")

set(
        CPACK_SOURCE_IGNORE_FILES
        .git/
        .github/
        .vscode/
        cmake-build-debug/
        cmake-build-release/
        deps/
        .gitignore
        .gitmodules
        imgui.ini
        main.cpp
)
