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
include CMakeFiles/libcommon.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/libcommon.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/libcommon.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/libcommon.dir/flags.make

CMakeFiles/libcommon.dir/common_libs/src/ParseMapFromFile.cpp.o: CMakeFiles/libcommon.dir/flags.make
CMakeFiles/libcommon.dir/common_libs/src/ParseMapFromFile.cpp.o: ../common_libs/src/ParseMapFromFile.cpp
CMakeFiles/libcommon.dir/common_libs/src/ParseMapFromFile.cpp.o: CMakeFiles/libcommon.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/vic/Escritorio/universidad/materias/taller_i/tps/worms/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/libcommon.dir/common_libs/src/ParseMapFromFile.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/libcommon.dir/common_libs/src/ParseMapFromFile.cpp.o -MF CMakeFiles/libcommon.dir/common_libs/src/ParseMapFromFile.cpp.o.d -o CMakeFiles/libcommon.dir/common_libs/src/ParseMapFromFile.cpp.o -c /home/vic/Escritorio/universidad/materias/taller_i/tps/worms/common_libs/src/ParseMapFromFile.cpp

CMakeFiles/libcommon.dir/common_libs/src/ParseMapFromFile.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/libcommon.dir/common_libs/src/ParseMapFromFile.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/vic/Escritorio/universidad/materias/taller_i/tps/worms/common_libs/src/ParseMapFromFile.cpp > CMakeFiles/libcommon.dir/common_libs/src/ParseMapFromFile.cpp.i

CMakeFiles/libcommon.dir/common_libs/src/ParseMapFromFile.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/libcommon.dir/common_libs/src/ParseMapFromFile.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/vic/Escritorio/universidad/materias/taller_i/tps/worms/common_libs/src/ParseMapFromFile.cpp -o CMakeFiles/libcommon.dir/common_libs/src/ParseMapFromFile.cpp.s

CMakeFiles/libcommon.dir/common_libs/src/Protocol.cpp.o: CMakeFiles/libcommon.dir/flags.make
CMakeFiles/libcommon.dir/common_libs/src/Protocol.cpp.o: ../common_libs/src/Protocol.cpp
CMakeFiles/libcommon.dir/common_libs/src/Protocol.cpp.o: CMakeFiles/libcommon.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/vic/Escritorio/universidad/materias/taller_i/tps/worms/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/libcommon.dir/common_libs/src/Protocol.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/libcommon.dir/common_libs/src/Protocol.cpp.o -MF CMakeFiles/libcommon.dir/common_libs/src/Protocol.cpp.o.d -o CMakeFiles/libcommon.dir/common_libs/src/Protocol.cpp.o -c /home/vic/Escritorio/universidad/materias/taller_i/tps/worms/common_libs/src/Protocol.cpp

CMakeFiles/libcommon.dir/common_libs/src/Protocol.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/libcommon.dir/common_libs/src/Protocol.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/vic/Escritorio/universidad/materias/taller_i/tps/worms/common_libs/src/Protocol.cpp > CMakeFiles/libcommon.dir/common_libs/src/Protocol.cpp.i

CMakeFiles/libcommon.dir/common_libs/src/Protocol.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/libcommon.dir/common_libs/src/Protocol.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/vic/Escritorio/universidad/materias/taller_i/tps/worms/common_libs/src/Protocol.cpp -o CMakeFiles/libcommon.dir/common_libs/src/Protocol.cpp.s

CMakeFiles/libcommon.dir/common_libs/src/liberror.cpp.o: CMakeFiles/libcommon.dir/flags.make
CMakeFiles/libcommon.dir/common_libs/src/liberror.cpp.o: ../common_libs/src/liberror.cpp
CMakeFiles/libcommon.dir/common_libs/src/liberror.cpp.o: CMakeFiles/libcommon.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/vic/Escritorio/universidad/materias/taller_i/tps/worms/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/libcommon.dir/common_libs/src/liberror.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/libcommon.dir/common_libs/src/liberror.cpp.o -MF CMakeFiles/libcommon.dir/common_libs/src/liberror.cpp.o.d -o CMakeFiles/libcommon.dir/common_libs/src/liberror.cpp.o -c /home/vic/Escritorio/universidad/materias/taller_i/tps/worms/common_libs/src/liberror.cpp

CMakeFiles/libcommon.dir/common_libs/src/liberror.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/libcommon.dir/common_libs/src/liberror.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/vic/Escritorio/universidad/materias/taller_i/tps/worms/common_libs/src/liberror.cpp > CMakeFiles/libcommon.dir/common_libs/src/liberror.cpp.i

CMakeFiles/libcommon.dir/common_libs/src/liberror.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/libcommon.dir/common_libs/src/liberror.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/vic/Escritorio/universidad/materias/taller_i/tps/worms/common_libs/src/liberror.cpp -o CMakeFiles/libcommon.dir/common_libs/src/liberror.cpp.s

CMakeFiles/libcommon.dir/common_libs/src/messages/server/GameInfo.cpp.o: CMakeFiles/libcommon.dir/flags.make
CMakeFiles/libcommon.dir/common_libs/src/messages/server/GameInfo.cpp.o: ../common_libs/src/messages/server/GameInfo.cpp
CMakeFiles/libcommon.dir/common_libs/src/messages/server/GameInfo.cpp.o: CMakeFiles/libcommon.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/vic/Escritorio/universidad/materias/taller_i/tps/worms/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/libcommon.dir/common_libs/src/messages/server/GameInfo.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/libcommon.dir/common_libs/src/messages/server/GameInfo.cpp.o -MF CMakeFiles/libcommon.dir/common_libs/src/messages/server/GameInfo.cpp.o.d -o CMakeFiles/libcommon.dir/common_libs/src/messages/server/GameInfo.cpp.o -c /home/vic/Escritorio/universidad/materias/taller_i/tps/worms/common_libs/src/messages/server/GameInfo.cpp

CMakeFiles/libcommon.dir/common_libs/src/messages/server/GameInfo.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/libcommon.dir/common_libs/src/messages/server/GameInfo.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/vic/Escritorio/universidad/materias/taller_i/tps/worms/common_libs/src/messages/server/GameInfo.cpp > CMakeFiles/libcommon.dir/common_libs/src/messages/server/GameInfo.cpp.i

CMakeFiles/libcommon.dir/common_libs/src/messages/server/GameInfo.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/libcommon.dir/common_libs/src/messages/server/GameInfo.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/vic/Escritorio/universidad/materias/taller_i/tps/worms/common_libs/src/messages/server/GameInfo.cpp -o CMakeFiles/libcommon.dir/common_libs/src/messages/server/GameInfo.cpp.s

CMakeFiles/libcommon.dir/common_libs/src/resolver.cpp.o: CMakeFiles/libcommon.dir/flags.make
CMakeFiles/libcommon.dir/common_libs/src/resolver.cpp.o: ../common_libs/src/resolver.cpp
CMakeFiles/libcommon.dir/common_libs/src/resolver.cpp.o: CMakeFiles/libcommon.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/vic/Escritorio/universidad/materias/taller_i/tps/worms/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/libcommon.dir/common_libs/src/resolver.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/libcommon.dir/common_libs/src/resolver.cpp.o -MF CMakeFiles/libcommon.dir/common_libs/src/resolver.cpp.o.d -o CMakeFiles/libcommon.dir/common_libs/src/resolver.cpp.o -c /home/vic/Escritorio/universidad/materias/taller_i/tps/worms/common_libs/src/resolver.cpp

CMakeFiles/libcommon.dir/common_libs/src/resolver.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/libcommon.dir/common_libs/src/resolver.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/vic/Escritorio/universidad/materias/taller_i/tps/worms/common_libs/src/resolver.cpp > CMakeFiles/libcommon.dir/common_libs/src/resolver.cpp.i

CMakeFiles/libcommon.dir/common_libs/src/resolver.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/libcommon.dir/common_libs/src/resolver.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/vic/Escritorio/universidad/materias/taller_i/tps/worms/common_libs/src/resolver.cpp -o CMakeFiles/libcommon.dir/common_libs/src/resolver.cpp.s

CMakeFiles/libcommon.dir/common_libs/src/resolvererror.cpp.o: CMakeFiles/libcommon.dir/flags.make
CMakeFiles/libcommon.dir/common_libs/src/resolvererror.cpp.o: ../common_libs/src/resolvererror.cpp
CMakeFiles/libcommon.dir/common_libs/src/resolvererror.cpp.o: CMakeFiles/libcommon.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/vic/Escritorio/universidad/materias/taller_i/tps/worms/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/libcommon.dir/common_libs/src/resolvererror.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/libcommon.dir/common_libs/src/resolvererror.cpp.o -MF CMakeFiles/libcommon.dir/common_libs/src/resolvererror.cpp.o.d -o CMakeFiles/libcommon.dir/common_libs/src/resolvererror.cpp.o -c /home/vic/Escritorio/universidad/materias/taller_i/tps/worms/common_libs/src/resolvererror.cpp

CMakeFiles/libcommon.dir/common_libs/src/resolvererror.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/libcommon.dir/common_libs/src/resolvererror.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/vic/Escritorio/universidad/materias/taller_i/tps/worms/common_libs/src/resolvererror.cpp > CMakeFiles/libcommon.dir/common_libs/src/resolvererror.cpp.i

CMakeFiles/libcommon.dir/common_libs/src/resolvererror.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/libcommon.dir/common_libs/src/resolvererror.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/vic/Escritorio/universidad/materias/taller_i/tps/worms/common_libs/src/resolvererror.cpp -o CMakeFiles/libcommon.dir/common_libs/src/resolvererror.cpp.s

CMakeFiles/libcommon.dir/common_libs/src/socket.cpp.o: CMakeFiles/libcommon.dir/flags.make
CMakeFiles/libcommon.dir/common_libs/src/socket.cpp.o: ../common_libs/src/socket.cpp
CMakeFiles/libcommon.dir/common_libs/src/socket.cpp.o: CMakeFiles/libcommon.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/vic/Escritorio/universidad/materias/taller_i/tps/worms/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/libcommon.dir/common_libs/src/socket.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/libcommon.dir/common_libs/src/socket.cpp.o -MF CMakeFiles/libcommon.dir/common_libs/src/socket.cpp.o.d -o CMakeFiles/libcommon.dir/common_libs/src/socket.cpp.o -c /home/vic/Escritorio/universidad/materias/taller_i/tps/worms/common_libs/src/socket.cpp

CMakeFiles/libcommon.dir/common_libs/src/socket.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/libcommon.dir/common_libs/src/socket.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/vic/Escritorio/universidad/materias/taller_i/tps/worms/common_libs/src/socket.cpp > CMakeFiles/libcommon.dir/common_libs/src/socket.cpp.i

CMakeFiles/libcommon.dir/common_libs/src/socket.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/libcommon.dir/common_libs/src/socket.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/vic/Escritorio/universidad/materias/taller_i/tps/worms/common_libs/src/socket.cpp -o CMakeFiles/libcommon.dir/common_libs/src/socket.cpp.s

# Object files for target libcommon
libcommon_OBJECTS = \
"CMakeFiles/libcommon.dir/common_libs/src/ParseMapFromFile.cpp.o" \
"CMakeFiles/libcommon.dir/common_libs/src/Protocol.cpp.o" \
"CMakeFiles/libcommon.dir/common_libs/src/liberror.cpp.o" \
"CMakeFiles/libcommon.dir/common_libs/src/messages/server/GameInfo.cpp.o" \
"CMakeFiles/libcommon.dir/common_libs/src/resolver.cpp.o" \
"CMakeFiles/libcommon.dir/common_libs/src/resolvererror.cpp.o" \
"CMakeFiles/libcommon.dir/common_libs/src/socket.cpp.o"

# External object files for target libcommon
libcommon_EXTERNAL_OBJECTS =

liblibcommon.a: CMakeFiles/libcommon.dir/common_libs/src/ParseMapFromFile.cpp.o
liblibcommon.a: CMakeFiles/libcommon.dir/common_libs/src/Protocol.cpp.o
liblibcommon.a: CMakeFiles/libcommon.dir/common_libs/src/liberror.cpp.o
liblibcommon.a: CMakeFiles/libcommon.dir/common_libs/src/messages/server/GameInfo.cpp.o
liblibcommon.a: CMakeFiles/libcommon.dir/common_libs/src/resolver.cpp.o
liblibcommon.a: CMakeFiles/libcommon.dir/common_libs/src/resolvererror.cpp.o
liblibcommon.a: CMakeFiles/libcommon.dir/common_libs/src/socket.cpp.o
liblibcommon.a: CMakeFiles/libcommon.dir/build.make
liblibcommon.a: CMakeFiles/libcommon.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/vic/Escritorio/universidad/materias/taller_i/tps/worms/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Linking CXX static library liblibcommon.a"
	$(CMAKE_COMMAND) -P CMakeFiles/libcommon.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/libcommon.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/libcommon.dir/build: liblibcommon.a
.PHONY : CMakeFiles/libcommon.dir/build

CMakeFiles/libcommon.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/libcommon.dir/cmake_clean.cmake
.PHONY : CMakeFiles/libcommon.dir/clean

CMakeFiles/libcommon.dir/depend:
	cd /home/vic/Escritorio/universidad/materias/taller_i/tps/worms/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/vic/Escritorio/universidad/materias/taller_i/tps/worms /home/vic/Escritorio/universidad/materias/taller_i/tps/worms /home/vic/Escritorio/universidad/materias/taller_i/tps/worms/build /home/vic/Escritorio/universidad/materias/taller_i/tps/worms/build /home/vic/Escritorio/universidad/materias/taller_i/tps/worms/build/CMakeFiles/libcommon.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/libcommon.dir/depend

