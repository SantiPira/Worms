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
include CMakeFiles/libclient.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/libclient.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/libclient.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/libclient.dir/flags.make

CMakeFiles/libclient.dir/client/src/PruebaClient.cpp.o: CMakeFiles/libclient.dir/flags.make
CMakeFiles/libclient.dir/client/src/PruebaClient.cpp.o: ../client/src/PruebaClient.cpp
CMakeFiles/libclient.dir/client/src/PruebaClient.cpp.o: CMakeFiles/libclient.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/vic/Escritorio/universidad/materias/taller_i/tps/worms/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/libclient.dir/client/src/PruebaClient.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/libclient.dir/client/src/PruebaClient.cpp.o -MF CMakeFiles/libclient.dir/client/src/PruebaClient.cpp.o.d -o CMakeFiles/libclient.dir/client/src/PruebaClient.cpp.o -c /home/vic/Escritorio/universidad/materias/taller_i/tps/worms/client/src/PruebaClient.cpp

CMakeFiles/libclient.dir/client/src/PruebaClient.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/libclient.dir/client/src/PruebaClient.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/vic/Escritorio/universidad/materias/taller_i/tps/worms/client/src/PruebaClient.cpp > CMakeFiles/libclient.dir/client/src/PruebaClient.cpp.i

CMakeFiles/libclient.dir/client/src/PruebaClient.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/libclient.dir/client/src/PruebaClient.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/vic/Escritorio/universidad/materias/taller_i/tps/worms/client/src/PruebaClient.cpp -o CMakeFiles/libclient.dir/client/src/PruebaClient.cpp.s

CMakeFiles/libclient.dir/client/src/client_juego.cpp.o: CMakeFiles/libclient.dir/flags.make
CMakeFiles/libclient.dir/client/src/client_juego.cpp.o: ../client/src/client_juego.cpp
CMakeFiles/libclient.dir/client/src/client_juego.cpp.o: CMakeFiles/libclient.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/vic/Escritorio/universidad/materias/taller_i/tps/worms/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/libclient.dir/client/src/client_juego.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/libclient.dir/client/src/client_juego.cpp.o -MF CMakeFiles/libclient.dir/client/src/client_juego.cpp.o.d -o CMakeFiles/libclient.dir/client/src/client_juego.cpp.o -c /home/vic/Escritorio/universidad/materias/taller_i/tps/worms/client/src/client_juego.cpp

CMakeFiles/libclient.dir/client/src/client_juego.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/libclient.dir/client/src/client_juego.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/vic/Escritorio/universidad/materias/taller_i/tps/worms/client/src/client_juego.cpp > CMakeFiles/libclient.dir/client/src/client_juego.cpp.i

CMakeFiles/libclient.dir/client/src/client_juego.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/libclient.dir/client/src/client_juego.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/vic/Escritorio/universidad/materias/taller_i/tps/worms/client/src/client_juego.cpp -o CMakeFiles/libclient.dir/client/src/client_juego.cpp.s

CMakeFiles/libclient.dir/client/src/client_receiver.cpp.o: CMakeFiles/libclient.dir/flags.make
CMakeFiles/libclient.dir/client/src/client_receiver.cpp.o: ../client/src/client_receiver.cpp
CMakeFiles/libclient.dir/client/src/client_receiver.cpp.o: CMakeFiles/libclient.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/vic/Escritorio/universidad/materias/taller_i/tps/worms/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/libclient.dir/client/src/client_receiver.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/libclient.dir/client/src/client_receiver.cpp.o -MF CMakeFiles/libclient.dir/client/src/client_receiver.cpp.o.d -o CMakeFiles/libclient.dir/client/src/client_receiver.cpp.o -c /home/vic/Escritorio/universidad/materias/taller_i/tps/worms/client/src/client_receiver.cpp

CMakeFiles/libclient.dir/client/src/client_receiver.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/libclient.dir/client/src/client_receiver.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/vic/Escritorio/universidad/materias/taller_i/tps/worms/client/src/client_receiver.cpp > CMakeFiles/libclient.dir/client/src/client_receiver.cpp.i

CMakeFiles/libclient.dir/client/src/client_receiver.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/libclient.dir/client/src/client_receiver.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/vic/Escritorio/universidad/materias/taller_i/tps/worms/client/src/client_receiver.cpp -o CMakeFiles/libclient.dir/client/src/client_receiver.cpp.s

CMakeFiles/libclient.dir/client/src/client_sender.cpp.o: CMakeFiles/libclient.dir/flags.make
CMakeFiles/libclient.dir/client/src/client_sender.cpp.o: ../client/src/client_sender.cpp
CMakeFiles/libclient.dir/client/src/client_sender.cpp.o: CMakeFiles/libclient.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/vic/Escritorio/universidad/materias/taller_i/tps/worms/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/libclient.dir/client/src/client_sender.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/libclient.dir/client/src/client_sender.cpp.o -MF CMakeFiles/libclient.dir/client/src/client_sender.cpp.o.d -o CMakeFiles/libclient.dir/client/src/client_sender.cpp.o -c /home/vic/Escritorio/universidad/materias/taller_i/tps/worms/client/src/client_sender.cpp

CMakeFiles/libclient.dir/client/src/client_sender.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/libclient.dir/client/src/client_sender.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/vic/Escritorio/universidad/materias/taller_i/tps/worms/client/src/client_sender.cpp > CMakeFiles/libclient.dir/client/src/client_sender.cpp.i

CMakeFiles/libclient.dir/client/src/client_sender.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/libclient.dir/client/src/client_sender.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/vic/Escritorio/universidad/materias/taller_i/tps/worms/client/src/client_sender.cpp -o CMakeFiles/libclient.dir/client/src/client_sender.cpp.s

CMakeFiles/libclient.dir/client/src/createGameWindow.cpp.o: CMakeFiles/libclient.dir/flags.make
CMakeFiles/libclient.dir/client/src/createGameWindow.cpp.o: ../client/src/createGameWindow.cpp
CMakeFiles/libclient.dir/client/src/createGameWindow.cpp.o: CMakeFiles/libclient.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/vic/Escritorio/universidad/materias/taller_i/tps/worms/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/libclient.dir/client/src/createGameWindow.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/libclient.dir/client/src/createGameWindow.cpp.o -MF CMakeFiles/libclient.dir/client/src/createGameWindow.cpp.o.d -o CMakeFiles/libclient.dir/client/src/createGameWindow.cpp.o -c /home/vic/Escritorio/universidad/materias/taller_i/tps/worms/client/src/createGameWindow.cpp

CMakeFiles/libclient.dir/client/src/createGameWindow.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/libclient.dir/client/src/createGameWindow.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/vic/Escritorio/universidad/materias/taller_i/tps/worms/client/src/createGameWindow.cpp > CMakeFiles/libclient.dir/client/src/createGameWindow.cpp.i

CMakeFiles/libclient.dir/client/src/createGameWindow.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/libclient.dir/client/src/createGameWindow.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/vic/Escritorio/universidad/materias/taller_i/tps/worms/client/src/createGameWindow.cpp -o CMakeFiles/libclient.dir/client/src/createGameWindow.cpp.s

CMakeFiles/libclient.dir/client/src/joinGameWindow.cpp.o: CMakeFiles/libclient.dir/flags.make
CMakeFiles/libclient.dir/client/src/joinGameWindow.cpp.o: ../client/src/joinGameWindow.cpp
CMakeFiles/libclient.dir/client/src/joinGameWindow.cpp.o: CMakeFiles/libclient.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/vic/Escritorio/universidad/materias/taller_i/tps/worms/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/libclient.dir/client/src/joinGameWindow.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/libclient.dir/client/src/joinGameWindow.cpp.o -MF CMakeFiles/libclient.dir/client/src/joinGameWindow.cpp.o.d -o CMakeFiles/libclient.dir/client/src/joinGameWindow.cpp.o -c /home/vic/Escritorio/universidad/materias/taller_i/tps/worms/client/src/joinGameWindow.cpp

CMakeFiles/libclient.dir/client/src/joinGameWindow.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/libclient.dir/client/src/joinGameWindow.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/vic/Escritorio/universidad/materias/taller_i/tps/worms/client/src/joinGameWindow.cpp > CMakeFiles/libclient.dir/client/src/joinGameWindow.cpp.i

CMakeFiles/libclient.dir/client/src/joinGameWindow.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/libclient.dir/client/src/joinGameWindow.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/vic/Escritorio/universidad/materias/taller_i/tps/worms/client/src/joinGameWindow.cpp -o CMakeFiles/libclient.dir/client/src/joinGameWindow.cpp.s

CMakeFiles/libclient.dir/client/src/mainWindow.cpp.o: CMakeFiles/libclient.dir/flags.make
CMakeFiles/libclient.dir/client/src/mainWindow.cpp.o: ../client/src/mainWindow.cpp
CMakeFiles/libclient.dir/client/src/mainWindow.cpp.o: CMakeFiles/libclient.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/vic/Escritorio/universidad/materias/taller_i/tps/worms/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/libclient.dir/client/src/mainWindow.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/libclient.dir/client/src/mainWindow.cpp.o -MF CMakeFiles/libclient.dir/client/src/mainWindow.cpp.o.d -o CMakeFiles/libclient.dir/client/src/mainWindow.cpp.o -c /home/vic/Escritorio/universidad/materias/taller_i/tps/worms/client/src/mainWindow.cpp

CMakeFiles/libclient.dir/client/src/mainWindow.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/libclient.dir/client/src/mainWindow.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/vic/Escritorio/universidad/materias/taller_i/tps/worms/client/src/mainWindow.cpp > CMakeFiles/libclient.dir/client/src/mainWindow.cpp.i

CMakeFiles/libclient.dir/client/src/mainWindow.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/libclient.dir/client/src/mainWindow.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/vic/Escritorio/universidad/materias/taller_i/tps/worms/client/src/mainWindow.cpp -o CMakeFiles/libclient.dir/client/src/mainWindow.cpp.s

CMakeFiles/libclient.dir/client/src/menuWindow.cpp.o: CMakeFiles/libclient.dir/flags.make
CMakeFiles/libclient.dir/client/src/menuWindow.cpp.o: ../client/src/menuWindow.cpp
CMakeFiles/libclient.dir/client/src/menuWindow.cpp.o: CMakeFiles/libclient.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/vic/Escritorio/universidad/materias/taller_i/tps/worms/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/libclient.dir/client/src/menuWindow.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/libclient.dir/client/src/menuWindow.cpp.o -MF CMakeFiles/libclient.dir/client/src/menuWindow.cpp.o.d -o CMakeFiles/libclient.dir/client/src/menuWindow.cpp.o -c /home/vic/Escritorio/universidad/materias/taller_i/tps/worms/client/src/menuWindow.cpp

CMakeFiles/libclient.dir/client/src/menuWindow.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/libclient.dir/client/src/menuWindow.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/vic/Escritorio/universidad/materias/taller_i/tps/worms/client/src/menuWindow.cpp > CMakeFiles/libclient.dir/client/src/menuWindow.cpp.i

CMakeFiles/libclient.dir/client/src/menuWindow.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/libclient.dir/client/src/menuWindow.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/vic/Escritorio/universidad/materias/taller_i/tps/worms/client/src/menuWindow.cpp -o CMakeFiles/libclient.dir/client/src/menuWindow.cpp.s

# Object files for target libclient
libclient_OBJECTS = \
"CMakeFiles/libclient.dir/client/src/PruebaClient.cpp.o" \
"CMakeFiles/libclient.dir/client/src/client_juego.cpp.o" \
"CMakeFiles/libclient.dir/client/src/client_receiver.cpp.o" \
"CMakeFiles/libclient.dir/client/src/client_sender.cpp.o" \
"CMakeFiles/libclient.dir/client/src/createGameWindow.cpp.o" \
"CMakeFiles/libclient.dir/client/src/joinGameWindow.cpp.o" \
"CMakeFiles/libclient.dir/client/src/mainWindow.cpp.o" \
"CMakeFiles/libclient.dir/client/src/menuWindow.cpp.o"

# External object files for target libclient
libclient_EXTERNAL_OBJECTS =

liblibclient.a: CMakeFiles/libclient.dir/client/src/PruebaClient.cpp.o
liblibclient.a: CMakeFiles/libclient.dir/client/src/client_juego.cpp.o
liblibclient.a: CMakeFiles/libclient.dir/client/src/client_receiver.cpp.o
liblibclient.a: CMakeFiles/libclient.dir/client/src/client_sender.cpp.o
liblibclient.a: CMakeFiles/libclient.dir/client/src/createGameWindow.cpp.o
liblibclient.a: CMakeFiles/libclient.dir/client/src/joinGameWindow.cpp.o
liblibclient.a: CMakeFiles/libclient.dir/client/src/mainWindow.cpp.o
liblibclient.a: CMakeFiles/libclient.dir/client/src/menuWindow.cpp.o
liblibclient.a: CMakeFiles/libclient.dir/build.make
liblibclient.a: CMakeFiles/libclient.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/vic/Escritorio/universidad/materias/taller_i/tps/worms/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Linking CXX static library liblibclient.a"
	$(CMAKE_COMMAND) -P CMakeFiles/libclient.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/libclient.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/libclient.dir/build: liblibclient.a
.PHONY : CMakeFiles/libclient.dir/build

CMakeFiles/libclient.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/libclient.dir/cmake_clean.cmake
.PHONY : CMakeFiles/libclient.dir/clean

CMakeFiles/libclient.dir/depend:
	cd /home/vic/Escritorio/universidad/materias/taller_i/tps/worms/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/vic/Escritorio/universidad/materias/taller_i/tps/worms /home/vic/Escritorio/universidad/materias/taller_i/tps/worms /home/vic/Escritorio/universidad/materias/taller_i/tps/worms/build /home/vic/Escritorio/universidad/materias/taller_i/tps/worms/build /home/vic/Escritorio/universidad/materias/taller_i/tps/worms/build/CMakeFiles/libclient.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/libclient.dir/depend

