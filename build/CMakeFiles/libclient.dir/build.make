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
CMAKE_SOURCE_DIR = /home/fran/Escritorio/Taller_/Worms

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/fran/Escritorio/Taller_/Worms/build

# Include any dependencies generated for this target.
include CMakeFiles/libclient.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/libclient.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/libclient.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/libclient.dir/flags.make

CMakeFiles/libclient.dir/client/src/EventSender.cpp.o: CMakeFiles/libclient.dir/flags.make
CMakeFiles/libclient.dir/client/src/EventSender.cpp.o: ../client/src/EventSender.cpp
CMakeFiles/libclient.dir/client/src/EventSender.cpp.o: CMakeFiles/libclient.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/fran/Escritorio/Taller_/Worms/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/libclient.dir/client/src/EventSender.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/libclient.dir/client/src/EventSender.cpp.o -MF CMakeFiles/libclient.dir/client/src/EventSender.cpp.o.d -o CMakeFiles/libclient.dir/client/src/EventSender.cpp.o -c /home/fran/Escritorio/Taller_/Worms/client/src/EventSender.cpp

CMakeFiles/libclient.dir/client/src/EventSender.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/libclient.dir/client/src/EventSender.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/fran/Escritorio/Taller_/Worms/client/src/EventSender.cpp > CMakeFiles/libclient.dir/client/src/EventSender.cpp.i

CMakeFiles/libclient.dir/client/src/EventSender.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/libclient.dir/client/src/EventSender.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/fran/Escritorio/Taller_/Worms/client/src/EventSender.cpp -o CMakeFiles/libclient.dir/client/src/EventSender.cpp.s

CMakeFiles/libclient.dir/client/src/GameClient.cpp.o: CMakeFiles/libclient.dir/flags.make
CMakeFiles/libclient.dir/client/src/GameClient.cpp.o: ../client/src/GameClient.cpp
CMakeFiles/libclient.dir/client/src/GameClient.cpp.o: CMakeFiles/libclient.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/fran/Escritorio/Taller_/Worms/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/libclient.dir/client/src/GameClient.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/libclient.dir/client/src/GameClient.cpp.o -MF CMakeFiles/libclient.dir/client/src/GameClient.cpp.o.d -o CMakeFiles/libclient.dir/client/src/GameClient.cpp.o -c /home/fran/Escritorio/Taller_/Worms/client/src/GameClient.cpp

CMakeFiles/libclient.dir/client/src/GameClient.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/libclient.dir/client/src/GameClient.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/fran/Escritorio/Taller_/Worms/client/src/GameClient.cpp > CMakeFiles/libclient.dir/client/src/GameClient.cpp.i

CMakeFiles/libclient.dir/client/src/GameClient.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/libclient.dir/client/src/GameClient.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/fran/Escritorio/Taller_/Worms/client/src/GameClient.cpp -o CMakeFiles/libclient.dir/client/src/GameClient.cpp.s

CMakeFiles/libclient.dir/client/src/PruebaClient.cpp.o: CMakeFiles/libclient.dir/flags.make
CMakeFiles/libclient.dir/client/src/PruebaClient.cpp.o: ../client/src/PruebaClient.cpp
CMakeFiles/libclient.dir/client/src/PruebaClient.cpp.o: CMakeFiles/libclient.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/fran/Escritorio/Taller_/Worms/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/libclient.dir/client/src/PruebaClient.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/libclient.dir/client/src/PruebaClient.cpp.o -MF CMakeFiles/libclient.dir/client/src/PruebaClient.cpp.o.d -o CMakeFiles/libclient.dir/client/src/PruebaClient.cpp.o -c /home/fran/Escritorio/Taller_/Worms/client/src/PruebaClient.cpp

CMakeFiles/libclient.dir/client/src/PruebaClient.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/libclient.dir/client/src/PruebaClient.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/fran/Escritorio/Taller_/Worms/client/src/PruebaClient.cpp > CMakeFiles/libclient.dir/client/src/PruebaClient.cpp.i

CMakeFiles/libclient.dir/client/src/PruebaClient.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/libclient.dir/client/src/PruebaClient.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/fran/Escritorio/Taller_/Worms/client/src/PruebaClient.cpp -o CMakeFiles/libclient.dir/client/src/PruebaClient.cpp.s

CMakeFiles/libclient.dir/client/src/client_juego.cpp.o: CMakeFiles/libclient.dir/flags.make
CMakeFiles/libclient.dir/client/src/client_juego.cpp.o: ../client/src/client_juego.cpp
CMakeFiles/libclient.dir/client/src/client_juego.cpp.o: CMakeFiles/libclient.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/fran/Escritorio/Taller_/Worms/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/libclient.dir/client/src/client_juego.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/libclient.dir/client/src/client_juego.cpp.o -MF CMakeFiles/libclient.dir/client/src/client_juego.cpp.o.d -o CMakeFiles/libclient.dir/client/src/client_juego.cpp.o -c /home/fran/Escritorio/Taller_/Worms/client/src/client_juego.cpp

CMakeFiles/libclient.dir/client/src/client_juego.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/libclient.dir/client/src/client_juego.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/fran/Escritorio/Taller_/Worms/client/src/client_juego.cpp > CMakeFiles/libclient.dir/client/src/client_juego.cpp.i

CMakeFiles/libclient.dir/client/src/client_juego.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/libclient.dir/client/src/client_juego.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/fran/Escritorio/Taller_/Worms/client/src/client_juego.cpp -o CMakeFiles/libclient.dir/client/src/client_juego.cpp.s

CMakeFiles/libclient.dir/client/src/client_receiver.cpp.o: CMakeFiles/libclient.dir/flags.make
CMakeFiles/libclient.dir/client/src/client_receiver.cpp.o: ../client/src/client_receiver.cpp
CMakeFiles/libclient.dir/client/src/client_receiver.cpp.o: CMakeFiles/libclient.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/fran/Escritorio/Taller_/Worms/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/libclient.dir/client/src/client_receiver.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/libclient.dir/client/src/client_receiver.cpp.o -MF CMakeFiles/libclient.dir/client/src/client_receiver.cpp.o.d -o CMakeFiles/libclient.dir/client/src/client_receiver.cpp.o -c /home/fran/Escritorio/Taller_/Worms/client/src/client_receiver.cpp

CMakeFiles/libclient.dir/client/src/client_receiver.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/libclient.dir/client/src/client_receiver.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/fran/Escritorio/Taller_/Worms/client/src/client_receiver.cpp > CMakeFiles/libclient.dir/client/src/client_receiver.cpp.i

CMakeFiles/libclient.dir/client/src/client_receiver.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/libclient.dir/client/src/client_receiver.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/fran/Escritorio/Taller_/Worms/client/src/client_receiver.cpp -o CMakeFiles/libclient.dir/client/src/client_receiver.cpp.s

CMakeFiles/libclient.dir/client/src/createGameWindow.cpp.o: CMakeFiles/libclient.dir/flags.make
CMakeFiles/libclient.dir/client/src/createGameWindow.cpp.o: ../client/src/createGameWindow.cpp
CMakeFiles/libclient.dir/client/src/createGameWindow.cpp.o: CMakeFiles/libclient.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/fran/Escritorio/Taller_/Worms/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/libclient.dir/client/src/createGameWindow.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/libclient.dir/client/src/createGameWindow.cpp.o -MF CMakeFiles/libclient.dir/client/src/createGameWindow.cpp.o.d -o CMakeFiles/libclient.dir/client/src/createGameWindow.cpp.o -c /home/fran/Escritorio/Taller_/Worms/client/src/createGameWindow.cpp

CMakeFiles/libclient.dir/client/src/createGameWindow.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/libclient.dir/client/src/createGameWindow.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/fran/Escritorio/Taller_/Worms/client/src/createGameWindow.cpp > CMakeFiles/libclient.dir/client/src/createGameWindow.cpp.i

CMakeFiles/libclient.dir/client/src/createGameWindow.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/libclient.dir/client/src/createGameWindow.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/fran/Escritorio/Taller_/Worms/client/src/createGameWindow.cpp -o CMakeFiles/libclient.dir/client/src/createGameWindow.cpp.s

CMakeFiles/libclient.dir/client/src/engine/entities/grd/GrdLarge.cpp.o: CMakeFiles/libclient.dir/flags.make
CMakeFiles/libclient.dir/client/src/engine/entities/grd/GrdLarge.cpp.o: ../client/src/engine/entities/grd/GrdLarge.cpp
CMakeFiles/libclient.dir/client/src/engine/entities/grd/GrdLarge.cpp.o: CMakeFiles/libclient.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/fran/Escritorio/Taller_/Worms/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/libclient.dir/client/src/engine/entities/grd/GrdLarge.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/libclient.dir/client/src/engine/entities/grd/GrdLarge.cpp.o -MF CMakeFiles/libclient.dir/client/src/engine/entities/grd/GrdLarge.cpp.o.d -o CMakeFiles/libclient.dir/client/src/engine/entities/grd/GrdLarge.cpp.o -c /home/fran/Escritorio/Taller_/Worms/client/src/engine/entities/grd/GrdLarge.cpp

CMakeFiles/libclient.dir/client/src/engine/entities/grd/GrdLarge.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/libclient.dir/client/src/engine/entities/grd/GrdLarge.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/fran/Escritorio/Taller_/Worms/client/src/engine/entities/grd/GrdLarge.cpp > CMakeFiles/libclient.dir/client/src/engine/entities/grd/GrdLarge.cpp.i

CMakeFiles/libclient.dir/client/src/engine/entities/grd/GrdLarge.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/libclient.dir/client/src/engine/entities/grd/GrdLarge.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/fran/Escritorio/Taller_/Worms/client/src/engine/entities/grd/GrdLarge.cpp -o CMakeFiles/libclient.dir/client/src/engine/entities/grd/GrdLarge.cpp.s

CMakeFiles/libclient.dir/client/src/engine/entities/worms/Worm.cpp.o: CMakeFiles/libclient.dir/flags.make
CMakeFiles/libclient.dir/client/src/engine/entities/worms/Worm.cpp.o: ../client/src/engine/entities/worms/Worm.cpp
CMakeFiles/libclient.dir/client/src/engine/entities/worms/Worm.cpp.o: CMakeFiles/libclient.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/fran/Escritorio/Taller_/Worms/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/libclient.dir/client/src/engine/entities/worms/Worm.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/libclient.dir/client/src/engine/entities/worms/Worm.cpp.o -MF CMakeFiles/libclient.dir/client/src/engine/entities/worms/Worm.cpp.o.d -o CMakeFiles/libclient.dir/client/src/engine/entities/worms/Worm.cpp.o -c /home/fran/Escritorio/Taller_/Worms/client/src/engine/entities/worms/Worm.cpp

CMakeFiles/libclient.dir/client/src/engine/entities/worms/Worm.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/libclient.dir/client/src/engine/entities/worms/Worm.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/fran/Escritorio/Taller_/Worms/client/src/engine/entities/worms/Worm.cpp > CMakeFiles/libclient.dir/client/src/engine/entities/worms/Worm.cpp.i

CMakeFiles/libclient.dir/client/src/engine/entities/worms/Worm.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/libclient.dir/client/src/engine/entities/worms/Worm.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/fran/Escritorio/Taller_/Worms/client/src/engine/entities/worms/Worm.cpp -o CMakeFiles/libclient.dir/client/src/engine/entities/worms/Worm.cpp.s

CMakeFiles/libclient.dir/client/src/engine/graphics/Animation.cpp.o: CMakeFiles/libclient.dir/flags.make
CMakeFiles/libclient.dir/client/src/engine/graphics/Animation.cpp.o: ../client/src/engine/graphics/Animation.cpp
CMakeFiles/libclient.dir/client/src/engine/graphics/Animation.cpp.o: CMakeFiles/libclient.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/fran/Escritorio/Taller_/Worms/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/libclient.dir/client/src/engine/graphics/Animation.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/libclient.dir/client/src/engine/graphics/Animation.cpp.o -MF CMakeFiles/libclient.dir/client/src/engine/graphics/Animation.cpp.o.d -o CMakeFiles/libclient.dir/client/src/engine/graphics/Animation.cpp.o -c /home/fran/Escritorio/Taller_/Worms/client/src/engine/graphics/Animation.cpp

CMakeFiles/libclient.dir/client/src/engine/graphics/Animation.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/libclient.dir/client/src/engine/graphics/Animation.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/fran/Escritorio/Taller_/Worms/client/src/engine/graphics/Animation.cpp > CMakeFiles/libclient.dir/client/src/engine/graphics/Animation.cpp.i

CMakeFiles/libclient.dir/client/src/engine/graphics/Animation.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/libclient.dir/client/src/engine/graphics/Animation.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/fran/Escritorio/Taller_/Worms/client/src/engine/graphics/Animation.cpp -o CMakeFiles/libclient.dir/client/src/engine/graphics/Animation.cpp.s

CMakeFiles/libclient.dir/client/src/engine/graphics/Texture.cpp.o: CMakeFiles/libclient.dir/flags.make
CMakeFiles/libclient.dir/client/src/engine/graphics/Texture.cpp.o: ../client/src/engine/graphics/Texture.cpp
CMakeFiles/libclient.dir/client/src/engine/graphics/Texture.cpp.o: CMakeFiles/libclient.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/fran/Escritorio/Taller_/Worms/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/libclient.dir/client/src/engine/graphics/Texture.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/libclient.dir/client/src/engine/graphics/Texture.cpp.o -MF CMakeFiles/libclient.dir/client/src/engine/graphics/Texture.cpp.o.d -o CMakeFiles/libclient.dir/client/src/engine/graphics/Texture.cpp.o -c /home/fran/Escritorio/Taller_/Worms/client/src/engine/graphics/Texture.cpp

CMakeFiles/libclient.dir/client/src/engine/graphics/Texture.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/libclient.dir/client/src/engine/graphics/Texture.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/fran/Escritorio/Taller_/Worms/client/src/engine/graphics/Texture.cpp > CMakeFiles/libclient.dir/client/src/engine/graphics/Texture.cpp.i

CMakeFiles/libclient.dir/client/src/engine/graphics/Texture.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/libclient.dir/client/src/engine/graphics/Texture.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/fran/Escritorio/Taller_/Worms/client/src/engine/graphics/Texture.cpp -o CMakeFiles/libclient.dir/client/src/engine/graphics/Texture.cpp.s

CMakeFiles/libclient.dir/client/src/engine/utils/WorldScale.cpp.o: CMakeFiles/libclient.dir/flags.make
CMakeFiles/libclient.dir/client/src/engine/utils/WorldScale.cpp.o: ../client/src/engine/utils/WorldScale.cpp
CMakeFiles/libclient.dir/client/src/engine/utils/WorldScale.cpp.o: CMakeFiles/libclient.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/fran/Escritorio/Taller_/Worms/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building CXX object CMakeFiles/libclient.dir/client/src/engine/utils/WorldScale.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/libclient.dir/client/src/engine/utils/WorldScale.cpp.o -MF CMakeFiles/libclient.dir/client/src/engine/utils/WorldScale.cpp.o.d -o CMakeFiles/libclient.dir/client/src/engine/utils/WorldScale.cpp.o -c /home/fran/Escritorio/Taller_/Worms/client/src/engine/utils/WorldScale.cpp

CMakeFiles/libclient.dir/client/src/engine/utils/WorldScale.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/libclient.dir/client/src/engine/utils/WorldScale.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/fran/Escritorio/Taller_/Worms/client/src/engine/utils/WorldScale.cpp > CMakeFiles/libclient.dir/client/src/engine/utils/WorldScale.cpp.i

CMakeFiles/libclient.dir/client/src/engine/utils/WorldScale.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/libclient.dir/client/src/engine/utils/WorldScale.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/fran/Escritorio/Taller_/Worms/client/src/engine/utils/WorldScale.cpp -o CMakeFiles/libclient.dir/client/src/engine/utils/WorldScale.cpp.s

CMakeFiles/libclient.dir/client/src/joinGameWindow.cpp.o: CMakeFiles/libclient.dir/flags.make
CMakeFiles/libclient.dir/client/src/joinGameWindow.cpp.o: ../client/src/joinGameWindow.cpp
CMakeFiles/libclient.dir/client/src/joinGameWindow.cpp.o: CMakeFiles/libclient.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/fran/Escritorio/Taller_/Worms/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Building CXX object CMakeFiles/libclient.dir/client/src/joinGameWindow.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/libclient.dir/client/src/joinGameWindow.cpp.o -MF CMakeFiles/libclient.dir/client/src/joinGameWindow.cpp.o.d -o CMakeFiles/libclient.dir/client/src/joinGameWindow.cpp.o -c /home/fran/Escritorio/Taller_/Worms/client/src/joinGameWindow.cpp

CMakeFiles/libclient.dir/client/src/joinGameWindow.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/libclient.dir/client/src/joinGameWindow.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/fran/Escritorio/Taller_/Worms/client/src/joinGameWindow.cpp > CMakeFiles/libclient.dir/client/src/joinGameWindow.cpp.i

CMakeFiles/libclient.dir/client/src/joinGameWindow.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/libclient.dir/client/src/joinGameWindow.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/fran/Escritorio/Taller_/Worms/client/src/joinGameWindow.cpp -o CMakeFiles/libclient.dir/client/src/joinGameWindow.cpp.s

CMakeFiles/libclient.dir/client/src/mainWindow.cpp.o: CMakeFiles/libclient.dir/flags.make
CMakeFiles/libclient.dir/client/src/mainWindow.cpp.o: ../client/src/mainWindow.cpp
CMakeFiles/libclient.dir/client/src/mainWindow.cpp.o: CMakeFiles/libclient.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/fran/Escritorio/Taller_/Worms/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_13) "Building CXX object CMakeFiles/libclient.dir/client/src/mainWindow.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/libclient.dir/client/src/mainWindow.cpp.o -MF CMakeFiles/libclient.dir/client/src/mainWindow.cpp.o.d -o CMakeFiles/libclient.dir/client/src/mainWindow.cpp.o -c /home/fran/Escritorio/Taller_/Worms/client/src/mainWindow.cpp

CMakeFiles/libclient.dir/client/src/mainWindow.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/libclient.dir/client/src/mainWindow.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/fran/Escritorio/Taller_/Worms/client/src/mainWindow.cpp > CMakeFiles/libclient.dir/client/src/mainWindow.cpp.i

CMakeFiles/libclient.dir/client/src/mainWindow.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/libclient.dir/client/src/mainWindow.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/fran/Escritorio/Taller_/Worms/client/src/mainWindow.cpp -o CMakeFiles/libclient.dir/client/src/mainWindow.cpp.s

CMakeFiles/libclient.dir/client/src/menuWindow.cpp.o: CMakeFiles/libclient.dir/flags.make
CMakeFiles/libclient.dir/client/src/menuWindow.cpp.o: ../client/src/menuWindow.cpp
CMakeFiles/libclient.dir/client/src/menuWindow.cpp.o: CMakeFiles/libclient.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/fran/Escritorio/Taller_/Worms/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_14) "Building CXX object CMakeFiles/libclient.dir/client/src/menuWindow.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/libclient.dir/client/src/menuWindow.cpp.o -MF CMakeFiles/libclient.dir/client/src/menuWindow.cpp.o.d -o CMakeFiles/libclient.dir/client/src/menuWindow.cpp.o -c /home/fran/Escritorio/Taller_/Worms/client/src/menuWindow.cpp

CMakeFiles/libclient.dir/client/src/menuWindow.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/libclient.dir/client/src/menuWindow.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/fran/Escritorio/Taller_/Worms/client/src/menuWindow.cpp > CMakeFiles/libclient.dir/client/src/menuWindow.cpp.i

CMakeFiles/libclient.dir/client/src/menuWindow.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/libclient.dir/client/src/menuWindow.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/fran/Escritorio/Taller_/Worms/client/src/menuWindow.cpp -o CMakeFiles/libclient.dir/client/src/menuWindow.cpp.s

# Object files for target libclient
libclient_OBJECTS = \
"CMakeFiles/libclient.dir/client/src/EventSender.cpp.o" \
"CMakeFiles/libclient.dir/client/src/GameClient.cpp.o" \
"CMakeFiles/libclient.dir/client/src/PruebaClient.cpp.o" \
"CMakeFiles/libclient.dir/client/src/client_juego.cpp.o" \
"CMakeFiles/libclient.dir/client/src/client_receiver.cpp.o" \
"CMakeFiles/libclient.dir/client/src/createGameWindow.cpp.o" \
"CMakeFiles/libclient.dir/client/src/engine/entities/grd/GrdLarge.cpp.o" \
"CMakeFiles/libclient.dir/client/src/engine/entities/worms/Worm.cpp.o" \
"CMakeFiles/libclient.dir/client/src/engine/graphics/Animation.cpp.o" \
"CMakeFiles/libclient.dir/client/src/engine/graphics/Texture.cpp.o" \
"CMakeFiles/libclient.dir/client/src/engine/utils/WorldScale.cpp.o" \
"CMakeFiles/libclient.dir/client/src/joinGameWindow.cpp.o" \
"CMakeFiles/libclient.dir/client/src/mainWindow.cpp.o" \
"CMakeFiles/libclient.dir/client/src/menuWindow.cpp.o"

# External object files for target libclient
libclient_EXTERNAL_OBJECTS =

liblibclient.a: CMakeFiles/libclient.dir/client/src/EventSender.cpp.o
liblibclient.a: CMakeFiles/libclient.dir/client/src/GameClient.cpp.o
liblibclient.a: CMakeFiles/libclient.dir/client/src/PruebaClient.cpp.o
liblibclient.a: CMakeFiles/libclient.dir/client/src/client_juego.cpp.o
liblibclient.a: CMakeFiles/libclient.dir/client/src/client_receiver.cpp.o
liblibclient.a: CMakeFiles/libclient.dir/client/src/createGameWindow.cpp.o
liblibclient.a: CMakeFiles/libclient.dir/client/src/engine/entities/grd/GrdLarge.cpp.o
liblibclient.a: CMakeFiles/libclient.dir/client/src/engine/entities/worms/Worm.cpp.o
liblibclient.a: CMakeFiles/libclient.dir/client/src/engine/graphics/Animation.cpp.o
liblibclient.a: CMakeFiles/libclient.dir/client/src/engine/graphics/Texture.cpp.o
liblibclient.a: CMakeFiles/libclient.dir/client/src/engine/utils/WorldScale.cpp.o
liblibclient.a: CMakeFiles/libclient.dir/client/src/joinGameWindow.cpp.o
liblibclient.a: CMakeFiles/libclient.dir/client/src/mainWindow.cpp.o
liblibclient.a: CMakeFiles/libclient.dir/client/src/menuWindow.cpp.o
liblibclient.a: CMakeFiles/libclient.dir/build.make
liblibclient.a: CMakeFiles/libclient.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/fran/Escritorio/Taller_/Worms/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_15) "Linking CXX static library liblibclient.a"
	$(CMAKE_COMMAND) -P CMakeFiles/libclient.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/libclient.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/libclient.dir/build: liblibclient.a
.PHONY : CMakeFiles/libclient.dir/build

CMakeFiles/libclient.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/libclient.dir/cmake_clean.cmake
.PHONY : CMakeFiles/libclient.dir/clean

CMakeFiles/libclient.dir/depend:
	cd /home/fran/Escritorio/Taller_/Worms/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/fran/Escritorio/Taller_/Worms /home/fran/Escritorio/Taller_/Worms /home/fran/Escritorio/Taller_/Worms/build /home/fran/Escritorio/Taller_/Worms/build /home/fran/Escritorio/Taller_/Worms/build/CMakeFiles/libclient.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/libclient.dir/depend

