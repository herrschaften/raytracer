# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/phil/Desktop/Dropbox/Pro/programmiersprachen-raytracer

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/phil/Desktop/Dropbox/Pro/programmiersprachen-raytracer

# Include any dependencies generated for this target.
include source/CMakeFiles/auf65.dir/depend.make

# Include the progress variables for this target.
include source/CMakeFiles/auf65.dir/progress.make

# Include the compile flags for this target's objects.
include source/CMakeFiles/auf65.dir/flags.make

source/CMakeFiles/auf65.dir/auf65.cpp.o: source/CMakeFiles/auf65.dir/flags.make
source/CMakeFiles/auf65.dir/auf65.cpp.o: source/auf65.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/phil/Desktop/Dropbox/Pro/programmiersprachen-raytracer/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object source/CMakeFiles/auf65.dir/auf65.cpp.o"
	cd /home/phil/Desktop/Dropbox/Pro/programmiersprachen-raytracer/source && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/auf65.dir/auf65.cpp.o -c /home/phil/Desktop/Dropbox/Pro/programmiersprachen-raytracer/source/auf65.cpp

source/CMakeFiles/auf65.dir/auf65.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/auf65.dir/auf65.cpp.i"
	cd /home/phil/Desktop/Dropbox/Pro/programmiersprachen-raytracer/source && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/phil/Desktop/Dropbox/Pro/programmiersprachen-raytracer/source/auf65.cpp > CMakeFiles/auf65.dir/auf65.cpp.i

source/CMakeFiles/auf65.dir/auf65.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/auf65.dir/auf65.cpp.s"
	cd /home/phil/Desktop/Dropbox/Pro/programmiersprachen-raytracer/source && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/phil/Desktop/Dropbox/Pro/programmiersprachen-raytracer/source/auf65.cpp -o CMakeFiles/auf65.dir/auf65.cpp.s

source/CMakeFiles/auf65.dir/auf65.cpp.o.requires:
.PHONY : source/CMakeFiles/auf65.dir/auf65.cpp.o.requires

source/CMakeFiles/auf65.dir/auf65.cpp.o.provides: source/CMakeFiles/auf65.dir/auf65.cpp.o.requires
	$(MAKE) -f source/CMakeFiles/auf65.dir/build.make source/CMakeFiles/auf65.dir/auf65.cpp.o.provides.build
.PHONY : source/CMakeFiles/auf65.dir/auf65.cpp.o.provides

source/CMakeFiles/auf65.dir/auf65.cpp.o.provides.build: source/CMakeFiles/auf65.dir/auf65.cpp.o

# Object files for target auf65
auf65_OBJECTS = \
"CMakeFiles/auf65.dir/auf65.cpp.o"

# External object files for target auf65
auf65_EXTERNAL_OBJECTS =

build/Release/auf65: source/CMakeFiles/auf65.dir/auf65.cpp.o
build/Release/auf65: source/CMakeFiles/auf65.dir/build.make
build/Release/auf65: source/CMakeFiles/auf65.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable ../build/Release/auf65"
	cd /home/phil/Desktop/Dropbox/Pro/programmiersprachen-raytracer/source && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/auf65.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
source/CMakeFiles/auf65.dir/build: build/Release/auf65
.PHONY : source/CMakeFiles/auf65.dir/build

source/CMakeFiles/auf65.dir/requires: source/CMakeFiles/auf65.dir/auf65.cpp.o.requires
.PHONY : source/CMakeFiles/auf65.dir/requires

source/CMakeFiles/auf65.dir/clean:
	cd /home/phil/Desktop/Dropbox/Pro/programmiersprachen-raytracer/source && $(CMAKE_COMMAND) -P CMakeFiles/auf65.dir/cmake_clean.cmake
.PHONY : source/CMakeFiles/auf65.dir/clean

source/CMakeFiles/auf65.dir/depend:
	cd /home/phil/Desktop/Dropbox/Pro/programmiersprachen-raytracer && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/phil/Desktop/Dropbox/Pro/programmiersprachen-raytracer /home/phil/Desktop/Dropbox/Pro/programmiersprachen-raytracer/source /home/phil/Desktop/Dropbox/Pro/programmiersprachen-raytracer /home/phil/Desktop/Dropbox/Pro/programmiersprachen-raytracer/source /home/phil/Desktop/Dropbox/Pro/programmiersprachen-raytracer/source/CMakeFiles/auf65.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : source/CMakeFiles/auf65.dir/depend
