# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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
CMAKE_SOURCE_DIR = /home/vic/Escritorio/universidad/materias/taller_i/tps/worms

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/vic/Escritorio/universidad/materias/taller_i/tps/worms/build

# Include any dependencies generated for this target.
include CMakeFiles/worms-editor.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/worms-editor.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/worms-editor.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/worms-editor.dir/flags.make

CMakeFiles/worms-editor.dir/editor/src/main.cpp.o: CMakeFiles/worms-editor.dir/flags.make
CMakeFiles/worms-editor.dir/editor/src/main.cpp.o: ../editor/src/main.cpp
CMakeFiles/worms-editor.dir/editor/src/main.cpp.o: CMakeFiles/worms-editor.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/vic/Escritorio/universidad/materias/taller_i/tps/worms/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/worms-editor.dir/editor/src/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/worms-editor.dir/editor/src/main.cpp.o -MF CMakeFiles/worms-editor.dir/editor/src/main.cpp.o.d -o CMakeFiles/worms-editor.dir/editor/src/main.cpp.o -c /home/vic/Escritorio/universidad/materias/taller_i/tps/worms/editor/src/main.cpp

CMakeFiles/worms-editor.dir/editor/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/worms-editor.dir/editor/src/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/vic/Escritorio/universidad/materias/taller_i/tps/worms/editor/src/main.cpp > CMakeFiles/worms-editor.dir/editor/src/main.cpp.i

CMakeFiles/worms-editor.dir/editor/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/worms-editor.dir/editor/src/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/vic/Escritorio/universidad/materias/taller_i/tps/worms/editor/src/main.cpp -o CMakeFiles/worms-editor.dir/editor/src/main.cpp.s

# Object files for target worms-editor
worms__editor_OBJECTS = \
"CMakeFiles/worms-editor.dir/editor/src/main.cpp.o"

# External object files for target worms-editor
worms__editor_EXTERNAL_OBJECTS =

worms-editor: CMakeFiles/worms-editor.dir/editor/src/main.cpp.o
worms-editor: CMakeFiles/worms-editor.dir/build.make
worms-editor: liblibeditor.a
worms-editor: liblibcommon.a
worms-editor: SDL2pp/libSDL2pp.so.8.3.0
worms-editor: /usr/lib/x86_64-linux-gnu/libSDL2.so
worms-editor: /usr/lib/x86_64-linux-gnu/libSDL2main.a
worms-editor: /usr/local/lib/libSDL2_image.so
worms-editor: /usr/local/lib/libSDL2_ttf.so
worms-editor: /usr/local/lib/libSDL2_mixer.so
worms-editor: /usr/lib/x86_64-linux-gnu/libQt5Widgets.so.5.15.3
worms-editor: /usr/lib/x86_64-linux-gnu/libQt5Gui.so.5.15.3
worms-editor: /usr/lib/x86_64-linux-gnu/libQt5Core.so.5.15.3
worms-editor: ../Box2D/build/bin/libbox2d.a
worms-editor: CMakeFiles/worms-editor.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/vic/Escritorio/universidad/materias/taller_i/tps/worms/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable worms-editor"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/worms-editor.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/worms-editor.dir/build: worms-editor
.PHONY : CMakeFiles/worms-editor.dir/build

CMakeFiles/worms-editor.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/worms-editor.dir/cmake_clean.cmake
.PHONY : CMakeFiles/worms-editor.dir/clean

CMakeFiles/worms-editor.dir/depend:
	cd /home/vic/Escritorio/universidad/materias/taller_i/tps/worms/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/vic/Escritorio/universidad/materias/taller_i/tps/worms /home/vic/Escritorio/universidad/materias/taller_i/tps/worms /home/vic/Escritorio/universidad/materias/taller_i/tps/worms/build /home/vic/Escritorio/universidad/materias/taller_i/tps/worms/build /home/vic/Escritorio/universidad/materias/taller_i/tps/worms/build/CMakeFiles/worms-editor.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/worms-editor.dir/depend

