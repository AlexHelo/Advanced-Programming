# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.20

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
CMAKE_COMMAND = "/Users/jc/Library/Application Support/JetBrains/Toolbox/apps/CLion/ch-0/212.5080.54/CLion.app/Contents/bin/cmake/mac/bin/cmake"

# The command to remove a file.
RM = "/Users/jc/Library/Application Support/JetBrains/Toolbox/apps/CLion/ch-0/212.5080.54/CLion.app/Contents/bin/cmake/mac/bin/cmake" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/jc/CLionProjects/programacionAvanzada

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/jc/CLionProjects/programacionAvanzada/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/programacionAvanzada.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/programacionAvanzada.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/programacionAvanzada.dir/flags.make

CMakeFiles/programacionAvanzada.dir/main.c.o: CMakeFiles/programacionAvanzada.dir/flags.make
CMakeFiles/programacionAvanzada.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/jc/CLionProjects/programacionAvanzada/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/programacionAvanzada.dir/main.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/programacionAvanzada.dir/main.c.o -c /Users/jc/CLionProjects/programacionAvanzada/main.c

CMakeFiles/programacionAvanzada.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/programacionAvanzada.dir/main.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/jc/CLionProjects/programacionAvanzada/main.c > CMakeFiles/programacionAvanzada.dir/main.c.i

CMakeFiles/programacionAvanzada.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/programacionAvanzada.dir/main.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/jc/CLionProjects/programacionAvanzada/main.c -o CMakeFiles/programacionAvanzada.dir/main.c.s

# Object files for target programacionAvanzada
programacionAvanzada_OBJECTS = \
"CMakeFiles/programacionAvanzada.dir/main.c.o"

# External object files for target programacionAvanzada
programacionAvanzada_EXTERNAL_OBJECTS =

programacionAvanzada: CMakeFiles/programacionAvanzada.dir/main.c.o
programacionAvanzada: CMakeFiles/programacionAvanzada.dir/build.make
programacionAvanzada: CMakeFiles/programacionAvanzada.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/jc/CLionProjects/programacionAvanzada/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable programacionAvanzada"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/programacionAvanzada.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/programacionAvanzada.dir/build: programacionAvanzada
.PHONY : CMakeFiles/programacionAvanzada.dir/build

CMakeFiles/programacionAvanzada.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/programacionAvanzada.dir/cmake_clean.cmake
.PHONY : CMakeFiles/programacionAvanzada.dir/clean

CMakeFiles/programacionAvanzada.dir/depend:
	cd /Users/jc/CLionProjects/programacionAvanzada/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/jc/CLionProjects/programacionAvanzada /Users/jc/CLionProjects/programacionAvanzada /Users/jc/CLionProjects/programacionAvanzada/cmake-build-debug /Users/jc/CLionProjects/programacionAvanzada/cmake-build-debug /Users/jc/CLionProjects/programacionAvanzada/cmake-build-debug/CMakeFiles/programacionAvanzada.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/programacionAvanzada.dir/depend

