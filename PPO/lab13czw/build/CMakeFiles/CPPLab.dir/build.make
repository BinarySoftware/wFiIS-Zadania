# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.19

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
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.19.0_1/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.19.0_1/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/maciej/Downloads/lab13czw

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/maciej/Downloads/lab13czw/build

# Include any dependencies generated for this target.
include CMakeFiles/CPPLab.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/CPPLab.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/CPPLab.dir/flags.make

CMakeFiles/CPPLab.dir/main.cpp.o: CMakeFiles/CPPLab.dir/flags.make
CMakeFiles/CPPLab.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/maciej/Downloads/lab13czw/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/CPPLab.dir/main.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/CPPLab.dir/main.cpp.o -c /Users/maciej/Downloads/lab13czw/main.cpp

CMakeFiles/CPPLab.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CPPLab.dir/main.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/maciej/Downloads/lab13czw/main.cpp > CMakeFiles/CPPLab.dir/main.cpp.i

CMakeFiles/CPPLab.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CPPLab.dir/main.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/maciej/Downloads/lab13czw/main.cpp -o CMakeFiles/CPPLab.dir/main.cpp.s

# Object files for target CPPLab
CPPLab_OBJECTS = \
"CMakeFiles/CPPLab.dir/main.cpp.o"

# External object files for target CPPLab
CPPLab_EXTERNAL_OBJECTS =

CPPLab: CMakeFiles/CPPLab.dir/main.cpp.o
CPPLab: CMakeFiles/CPPLab.dir/build.make
CPPLab: libCPPLabSolution.dylib
CPPLab: CMakeFiles/CPPLab.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/maciej/Downloads/lab13czw/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable CPPLab"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/CPPLab.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/CPPLab.dir/build: CPPLab

.PHONY : CMakeFiles/CPPLab.dir/build

CMakeFiles/CPPLab.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/CPPLab.dir/cmake_clean.cmake
.PHONY : CMakeFiles/CPPLab.dir/clean

CMakeFiles/CPPLab.dir/depend:
	cd /Users/maciej/Downloads/lab13czw/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/maciej/Downloads/lab13czw /Users/maciej/Downloads/lab13czw /Users/maciej/Downloads/lab13czw/build /Users/maciej/Downloads/lab13czw/build /Users/maciej/Downloads/lab13czw/build/CMakeFiles/CPPLab.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/CPPLab.dir/depend
