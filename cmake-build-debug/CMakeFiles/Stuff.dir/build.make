# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.15

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Applications/GitHub/GitHub/Stuff

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Applications/GitHub/GitHub/Stuff/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Stuff.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Stuff.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Stuff.dir/flags.make

CMakeFiles/Stuff.dir/main.cpp.o: CMakeFiles/Stuff.dir/flags.make
CMakeFiles/Stuff.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Applications/GitHub/GitHub/Stuff/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Stuff.dir/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Stuff.dir/main.cpp.o -c /Applications/GitHub/GitHub/Stuff/main.cpp

CMakeFiles/Stuff.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Stuff.dir/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Applications/GitHub/GitHub/Stuff/main.cpp > CMakeFiles/Stuff.dir/main.cpp.i

CMakeFiles/Stuff.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Stuff.dir/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Applications/GitHub/GitHub/Stuff/main.cpp -o CMakeFiles/Stuff.dir/main.cpp.s

# Object files for target Stuff
Stuff_OBJECTS = \
"CMakeFiles/Stuff.dir/main.cpp.o"

# External object files for target Stuff
Stuff_EXTERNAL_OBJECTS =

Stuff: CMakeFiles/Stuff.dir/main.cpp.o
Stuff: CMakeFiles/Stuff.dir/build.make
Stuff: CMakeFiles/Stuff.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Applications/GitHub/GitHub/Stuff/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Stuff"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Stuff.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Stuff.dir/build: Stuff

.PHONY : CMakeFiles/Stuff.dir/build

CMakeFiles/Stuff.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Stuff.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Stuff.dir/clean

CMakeFiles/Stuff.dir/depend:
	cd /Applications/GitHub/GitHub/Stuff/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Applications/GitHub/GitHub/Stuff /Applications/GitHub/GitHub/Stuff /Applications/GitHub/GitHub/Stuff/cmake-build-debug /Applications/GitHub/GitHub/Stuff/cmake-build-debug /Applications/GitHub/GitHub/Stuff/cmake-build-debug/CMakeFiles/Stuff.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Stuff.dir/depend

