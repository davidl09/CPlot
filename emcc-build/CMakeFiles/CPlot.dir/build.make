# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.25

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/davidl09/C++/imgui-cplx-plot

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/davidl09/C++/imgui-cplx-plot/emcc-build

# Include any dependencies generated for this target.
include CMakeFiles/CPlot.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/CPlot.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/CPlot.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/CPlot.dir/flags.make

CMakeFiles/CPlot.dir/main.cpp.o: CMakeFiles/CPlot.dir/flags.make
CMakeFiles/CPlot.dir/main.cpp.o: CMakeFiles/CPlot.dir/includes_CXX.rsp
CMakeFiles/CPlot.dir/main.cpp.o: /home/davidl09/C++/imgui-cplx-plot/main.cpp
CMakeFiles/CPlot.dir/main.cpp.o: CMakeFiles/CPlot.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/davidl09/C++/imgui-cplx-plot/emcc-build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/CPlot.dir/main.cpp.o"
	/home/davidl09/emsdk/upstream/emscripten/em++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/CPlot.dir/main.cpp.o -MF CMakeFiles/CPlot.dir/main.cpp.o.d -o CMakeFiles/CPlot.dir/main.cpp.o -c /home/davidl09/C++/imgui-cplx-plot/main.cpp

CMakeFiles/CPlot.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CPlot.dir/main.cpp.i"
	/home/davidl09/emsdk/upstream/emscripten/em++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/davidl09/C++/imgui-cplx-plot/main.cpp > CMakeFiles/CPlot.dir/main.cpp.i

CMakeFiles/CPlot.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CPlot.dir/main.cpp.s"
	/home/davidl09/emsdk/upstream/emscripten/em++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/davidl09/C++/imgui-cplx-plot/main.cpp -o CMakeFiles/CPlot.dir/main.cpp.s

CMakeFiles/CPlot.dir/imgui/imgui.cpp.o: CMakeFiles/CPlot.dir/flags.make
CMakeFiles/CPlot.dir/imgui/imgui.cpp.o: CMakeFiles/CPlot.dir/includes_CXX.rsp
CMakeFiles/CPlot.dir/imgui/imgui.cpp.o: /home/davidl09/C++/imgui-cplx-plot/imgui/imgui.cpp
CMakeFiles/CPlot.dir/imgui/imgui.cpp.o: CMakeFiles/CPlot.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/davidl09/C++/imgui-cplx-plot/emcc-build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/CPlot.dir/imgui/imgui.cpp.o"
	/home/davidl09/emsdk/upstream/emscripten/em++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/CPlot.dir/imgui/imgui.cpp.o -MF CMakeFiles/CPlot.dir/imgui/imgui.cpp.o.d -o CMakeFiles/CPlot.dir/imgui/imgui.cpp.o -c /home/davidl09/C++/imgui-cplx-plot/imgui/imgui.cpp

CMakeFiles/CPlot.dir/imgui/imgui.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CPlot.dir/imgui/imgui.cpp.i"
	/home/davidl09/emsdk/upstream/emscripten/em++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/davidl09/C++/imgui-cplx-plot/imgui/imgui.cpp > CMakeFiles/CPlot.dir/imgui/imgui.cpp.i

CMakeFiles/CPlot.dir/imgui/imgui.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CPlot.dir/imgui/imgui.cpp.s"
	/home/davidl09/emsdk/upstream/emscripten/em++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/davidl09/C++/imgui-cplx-plot/imgui/imgui.cpp -o CMakeFiles/CPlot.dir/imgui/imgui.cpp.s

CMakeFiles/CPlot.dir/imgui/imgui_draw.cpp.o: CMakeFiles/CPlot.dir/flags.make
CMakeFiles/CPlot.dir/imgui/imgui_draw.cpp.o: CMakeFiles/CPlot.dir/includes_CXX.rsp
CMakeFiles/CPlot.dir/imgui/imgui_draw.cpp.o: /home/davidl09/C++/imgui-cplx-plot/imgui/imgui_draw.cpp
CMakeFiles/CPlot.dir/imgui/imgui_draw.cpp.o: CMakeFiles/CPlot.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/davidl09/C++/imgui-cplx-plot/emcc-build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/CPlot.dir/imgui/imgui_draw.cpp.o"
	/home/davidl09/emsdk/upstream/emscripten/em++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/CPlot.dir/imgui/imgui_draw.cpp.o -MF CMakeFiles/CPlot.dir/imgui/imgui_draw.cpp.o.d -o CMakeFiles/CPlot.dir/imgui/imgui_draw.cpp.o -c /home/davidl09/C++/imgui-cplx-plot/imgui/imgui_draw.cpp

CMakeFiles/CPlot.dir/imgui/imgui_draw.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CPlot.dir/imgui/imgui_draw.cpp.i"
	/home/davidl09/emsdk/upstream/emscripten/em++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/davidl09/C++/imgui-cplx-plot/imgui/imgui_draw.cpp > CMakeFiles/CPlot.dir/imgui/imgui_draw.cpp.i

CMakeFiles/CPlot.dir/imgui/imgui_draw.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CPlot.dir/imgui/imgui_draw.cpp.s"
	/home/davidl09/emsdk/upstream/emscripten/em++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/davidl09/C++/imgui-cplx-plot/imgui/imgui_draw.cpp -o CMakeFiles/CPlot.dir/imgui/imgui_draw.cpp.s

CMakeFiles/CPlot.dir/imgui/imgui_tables.cpp.o: CMakeFiles/CPlot.dir/flags.make
CMakeFiles/CPlot.dir/imgui/imgui_tables.cpp.o: CMakeFiles/CPlot.dir/includes_CXX.rsp
CMakeFiles/CPlot.dir/imgui/imgui_tables.cpp.o: /home/davidl09/C++/imgui-cplx-plot/imgui/imgui_tables.cpp
CMakeFiles/CPlot.dir/imgui/imgui_tables.cpp.o: CMakeFiles/CPlot.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/davidl09/C++/imgui-cplx-plot/emcc-build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/CPlot.dir/imgui/imgui_tables.cpp.o"
	/home/davidl09/emsdk/upstream/emscripten/em++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/CPlot.dir/imgui/imgui_tables.cpp.o -MF CMakeFiles/CPlot.dir/imgui/imgui_tables.cpp.o.d -o CMakeFiles/CPlot.dir/imgui/imgui_tables.cpp.o -c /home/davidl09/C++/imgui-cplx-plot/imgui/imgui_tables.cpp

CMakeFiles/CPlot.dir/imgui/imgui_tables.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CPlot.dir/imgui/imgui_tables.cpp.i"
	/home/davidl09/emsdk/upstream/emscripten/em++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/davidl09/C++/imgui-cplx-plot/imgui/imgui_tables.cpp > CMakeFiles/CPlot.dir/imgui/imgui_tables.cpp.i

CMakeFiles/CPlot.dir/imgui/imgui_tables.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CPlot.dir/imgui/imgui_tables.cpp.s"
	/home/davidl09/emsdk/upstream/emscripten/em++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/davidl09/C++/imgui-cplx-plot/imgui/imgui_tables.cpp -o CMakeFiles/CPlot.dir/imgui/imgui_tables.cpp.s

CMakeFiles/CPlot.dir/imgui/imgui_widgets.cpp.o: CMakeFiles/CPlot.dir/flags.make
CMakeFiles/CPlot.dir/imgui/imgui_widgets.cpp.o: CMakeFiles/CPlot.dir/includes_CXX.rsp
CMakeFiles/CPlot.dir/imgui/imgui_widgets.cpp.o: /home/davidl09/C++/imgui-cplx-plot/imgui/imgui_widgets.cpp
CMakeFiles/CPlot.dir/imgui/imgui_widgets.cpp.o: CMakeFiles/CPlot.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/davidl09/C++/imgui-cplx-plot/emcc-build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/CPlot.dir/imgui/imgui_widgets.cpp.o"
	/home/davidl09/emsdk/upstream/emscripten/em++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/CPlot.dir/imgui/imgui_widgets.cpp.o -MF CMakeFiles/CPlot.dir/imgui/imgui_widgets.cpp.o.d -o CMakeFiles/CPlot.dir/imgui/imgui_widgets.cpp.o -c /home/davidl09/C++/imgui-cplx-plot/imgui/imgui_widgets.cpp

CMakeFiles/CPlot.dir/imgui/imgui_widgets.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CPlot.dir/imgui/imgui_widgets.cpp.i"
	/home/davidl09/emsdk/upstream/emscripten/em++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/davidl09/C++/imgui-cplx-plot/imgui/imgui_widgets.cpp > CMakeFiles/CPlot.dir/imgui/imgui_widgets.cpp.i

CMakeFiles/CPlot.dir/imgui/imgui_widgets.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CPlot.dir/imgui/imgui_widgets.cpp.s"
	/home/davidl09/emsdk/upstream/emscripten/em++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/davidl09/C++/imgui-cplx-plot/imgui/imgui_widgets.cpp -o CMakeFiles/CPlot.dir/imgui/imgui_widgets.cpp.s

CMakeFiles/CPlot.dir/imgui/backends/imgui_impl_sdl2.cpp.o: CMakeFiles/CPlot.dir/flags.make
CMakeFiles/CPlot.dir/imgui/backends/imgui_impl_sdl2.cpp.o: CMakeFiles/CPlot.dir/includes_CXX.rsp
CMakeFiles/CPlot.dir/imgui/backends/imgui_impl_sdl2.cpp.o: /home/davidl09/C++/imgui-cplx-plot/imgui/backends/imgui_impl_sdl2.cpp
CMakeFiles/CPlot.dir/imgui/backends/imgui_impl_sdl2.cpp.o: CMakeFiles/CPlot.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/davidl09/C++/imgui-cplx-plot/emcc-build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/CPlot.dir/imgui/backends/imgui_impl_sdl2.cpp.o"
	/home/davidl09/emsdk/upstream/emscripten/em++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/CPlot.dir/imgui/backends/imgui_impl_sdl2.cpp.o -MF CMakeFiles/CPlot.dir/imgui/backends/imgui_impl_sdl2.cpp.o.d -o CMakeFiles/CPlot.dir/imgui/backends/imgui_impl_sdl2.cpp.o -c /home/davidl09/C++/imgui-cplx-plot/imgui/backends/imgui_impl_sdl2.cpp

CMakeFiles/CPlot.dir/imgui/backends/imgui_impl_sdl2.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CPlot.dir/imgui/backends/imgui_impl_sdl2.cpp.i"
	/home/davidl09/emsdk/upstream/emscripten/em++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/davidl09/C++/imgui-cplx-plot/imgui/backends/imgui_impl_sdl2.cpp > CMakeFiles/CPlot.dir/imgui/backends/imgui_impl_sdl2.cpp.i

CMakeFiles/CPlot.dir/imgui/backends/imgui_impl_sdl2.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CPlot.dir/imgui/backends/imgui_impl_sdl2.cpp.s"
	/home/davidl09/emsdk/upstream/emscripten/em++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/davidl09/C++/imgui-cplx-plot/imgui/backends/imgui_impl_sdl2.cpp -o CMakeFiles/CPlot.dir/imgui/backends/imgui_impl_sdl2.cpp.s

CMakeFiles/CPlot.dir/imgui/backends/imgui_impl_sdlrenderer2.cpp.o: CMakeFiles/CPlot.dir/flags.make
CMakeFiles/CPlot.dir/imgui/backends/imgui_impl_sdlrenderer2.cpp.o: CMakeFiles/CPlot.dir/includes_CXX.rsp
CMakeFiles/CPlot.dir/imgui/backends/imgui_impl_sdlrenderer2.cpp.o: /home/davidl09/C++/imgui-cplx-plot/imgui/backends/imgui_impl_sdlrenderer2.cpp
CMakeFiles/CPlot.dir/imgui/backends/imgui_impl_sdlrenderer2.cpp.o: CMakeFiles/CPlot.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/davidl09/C++/imgui-cplx-plot/emcc-build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/CPlot.dir/imgui/backends/imgui_impl_sdlrenderer2.cpp.o"
	/home/davidl09/emsdk/upstream/emscripten/em++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/CPlot.dir/imgui/backends/imgui_impl_sdlrenderer2.cpp.o -MF CMakeFiles/CPlot.dir/imgui/backends/imgui_impl_sdlrenderer2.cpp.o.d -o CMakeFiles/CPlot.dir/imgui/backends/imgui_impl_sdlrenderer2.cpp.o -c /home/davidl09/C++/imgui-cplx-plot/imgui/backends/imgui_impl_sdlrenderer2.cpp

CMakeFiles/CPlot.dir/imgui/backends/imgui_impl_sdlrenderer2.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CPlot.dir/imgui/backends/imgui_impl_sdlrenderer2.cpp.i"
	/home/davidl09/emsdk/upstream/emscripten/em++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/davidl09/C++/imgui-cplx-plot/imgui/backends/imgui_impl_sdlrenderer2.cpp > CMakeFiles/CPlot.dir/imgui/backends/imgui_impl_sdlrenderer2.cpp.i

CMakeFiles/CPlot.dir/imgui/backends/imgui_impl_sdlrenderer2.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CPlot.dir/imgui/backends/imgui_impl_sdlrenderer2.cpp.s"
	/home/davidl09/emsdk/upstream/emscripten/em++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/davidl09/C++/imgui-cplx-plot/imgui/backends/imgui_impl_sdlrenderer2.cpp -o CMakeFiles/CPlot.dir/imgui/backends/imgui_impl_sdlrenderer2.cpp.s

CMakeFiles/CPlot.dir/libcplot/src/libcplot.cpp.o: CMakeFiles/CPlot.dir/flags.make
CMakeFiles/CPlot.dir/libcplot/src/libcplot.cpp.o: CMakeFiles/CPlot.dir/includes_CXX.rsp
CMakeFiles/CPlot.dir/libcplot/src/libcplot.cpp.o: /home/davidl09/C++/imgui-cplx-plot/libcplot/src/libcplot.cpp
CMakeFiles/CPlot.dir/libcplot/src/libcplot.cpp.o: CMakeFiles/CPlot.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/davidl09/C++/imgui-cplx-plot/emcc-build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/CPlot.dir/libcplot/src/libcplot.cpp.o"
	/home/davidl09/emsdk/upstream/emscripten/em++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/CPlot.dir/libcplot/src/libcplot.cpp.o -MF CMakeFiles/CPlot.dir/libcplot/src/libcplot.cpp.o.d -o CMakeFiles/CPlot.dir/libcplot/src/libcplot.cpp.o -c /home/davidl09/C++/imgui-cplx-plot/libcplot/src/libcplot.cpp

CMakeFiles/CPlot.dir/libcplot/src/libcplot.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CPlot.dir/libcplot/src/libcplot.cpp.i"
	/home/davidl09/emsdk/upstream/emscripten/em++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/davidl09/C++/imgui-cplx-plot/libcplot/src/libcplot.cpp > CMakeFiles/CPlot.dir/libcplot/src/libcplot.cpp.i

CMakeFiles/CPlot.dir/libcplot/src/libcplot.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CPlot.dir/libcplot/src/libcplot.cpp.s"
	/home/davidl09/emsdk/upstream/emscripten/em++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/davidl09/C++/imgui-cplx-plot/libcplot/src/libcplot.cpp -o CMakeFiles/CPlot.dir/libcplot/src/libcplot.cpp.s

CMakeFiles/CPlot.dir/libcplot/src/toojpeg.cpp.o: CMakeFiles/CPlot.dir/flags.make
CMakeFiles/CPlot.dir/libcplot/src/toojpeg.cpp.o: CMakeFiles/CPlot.dir/includes_CXX.rsp
CMakeFiles/CPlot.dir/libcplot/src/toojpeg.cpp.o: /home/davidl09/C++/imgui-cplx-plot/libcplot/src/toojpeg.cpp
CMakeFiles/CPlot.dir/libcplot/src/toojpeg.cpp.o: CMakeFiles/CPlot.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/davidl09/C++/imgui-cplx-plot/emcc-build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/CPlot.dir/libcplot/src/toojpeg.cpp.o"
	/home/davidl09/emsdk/upstream/emscripten/em++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/CPlot.dir/libcplot/src/toojpeg.cpp.o -MF CMakeFiles/CPlot.dir/libcplot/src/toojpeg.cpp.o.d -o CMakeFiles/CPlot.dir/libcplot/src/toojpeg.cpp.o -c /home/davidl09/C++/imgui-cplx-plot/libcplot/src/toojpeg.cpp

CMakeFiles/CPlot.dir/libcplot/src/toojpeg.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CPlot.dir/libcplot/src/toojpeg.cpp.i"
	/home/davidl09/emsdk/upstream/emscripten/em++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/davidl09/C++/imgui-cplx-plot/libcplot/src/toojpeg.cpp > CMakeFiles/CPlot.dir/libcplot/src/toojpeg.cpp.i

CMakeFiles/CPlot.dir/libcplot/src/toojpeg.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CPlot.dir/libcplot/src/toojpeg.cpp.s"
	/home/davidl09/emsdk/upstream/emscripten/em++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/davidl09/C++/imgui-cplx-plot/libcplot/src/toojpeg.cpp -o CMakeFiles/CPlot.dir/libcplot/src/toojpeg.cpp.s

# Object files for target CPlot
CPlot_OBJECTS = \
"CMakeFiles/CPlot.dir/main.cpp.o" \
"CMakeFiles/CPlot.dir/imgui/imgui.cpp.o" \
"CMakeFiles/CPlot.dir/imgui/imgui_draw.cpp.o" \
"CMakeFiles/CPlot.dir/imgui/imgui_tables.cpp.o" \
"CMakeFiles/CPlot.dir/imgui/imgui_widgets.cpp.o" \
"CMakeFiles/CPlot.dir/imgui/backends/imgui_impl_sdl2.cpp.o" \
"CMakeFiles/CPlot.dir/imgui/backends/imgui_impl_sdlrenderer2.cpp.o" \
"CMakeFiles/CPlot.dir/libcplot/src/libcplot.cpp.o" \
"CMakeFiles/CPlot.dir/libcplot/src/toojpeg.cpp.o"

# External object files for target CPlot
CPlot_EXTERNAL_OBJECTS =

CPlot.js: CMakeFiles/CPlot.dir/main.cpp.o
CPlot.js: CMakeFiles/CPlot.dir/imgui/imgui.cpp.o
CPlot.js: CMakeFiles/CPlot.dir/imgui/imgui_draw.cpp.o
CPlot.js: CMakeFiles/CPlot.dir/imgui/imgui_tables.cpp.o
CPlot.js: CMakeFiles/CPlot.dir/imgui/imgui_widgets.cpp.o
CPlot.js: CMakeFiles/CPlot.dir/imgui/backends/imgui_impl_sdl2.cpp.o
CPlot.js: CMakeFiles/CPlot.dir/imgui/backends/imgui_impl_sdlrenderer2.cpp.o
CPlot.js: CMakeFiles/CPlot.dir/libcplot/src/libcplot.cpp.o
CPlot.js: CMakeFiles/CPlot.dir/libcplot/src/toojpeg.cpp.o
CPlot.js: CMakeFiles/CPlot.dir/build.make
CPlot.js: CMakeFiles/CPlot.dir/linkLibs.rsp
CPlot.js: CMakeFiles/CPlot.dir/objects1
CPlot.js: CMakeFiles/CPlot.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/davidl09/C++/imgui-cplx-plot/emcc-build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Linking CXX executable CPlot.js"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/CPlot.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/CPlot.dir/build: CPlot.js
.PHONY : CMakeFiles/CPlot.dir/build

CMakeFiles/CPlot.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/CPlot.dir/cmake_clean.cmake
.PHONY : CMakeFiles/CPlot.dir/clean

CMakeFiles/CPlot.dir/depend:
	cd /home/davidl09/C++/imgui-cplx-plot/emcc-build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/davidl09/C++/imgui-cplx-plot /home/davidl09/C++/imgui-cplx-plot /home/davidl09/C++/imgui-cplx-plot/emcc-build /home/davidl09/C++/imgui-cplx-plot/emcc-build /home/davidl09/C++/imgui-cplx-plot/emcc-build/CMakeFiles/CPlot.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/CPlot.dir/depend

