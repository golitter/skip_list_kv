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
CMAKE_SOURCE_DIR = /home/golitter/learn_cpp_dir/skip_list_kv

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/golitter/learn_cpp_dir/skip_list_kv/build

# Include any dependencies generated for this target.
include CMakeFiles/skip_list_kv.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/skip_list_kv.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/skip_list_kv.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/skip_list_kv.dir/flags.make

CMakeFiles/skip_list_kv.dir/main.cpp.o: CMakeFiles/skip_list_kv.dir/flags.make
CMakeFiles/skip_list_kv.dir/main.cpp.o: ../main.cpp
CMakeFiles/skip_list_kv.dir/main.cpp.o: CMakeFiles/skip_list_kv.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/golitter/learn_cpp_dir/skip_list_kv/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/skip_list_kv.dir/main.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/skip_list_kv.dir/main.cpp.o -MF CMakeFiles/skip_list_kv.dir/main.cpp.o.d -o CMakeFiles/skip_list_kv.dir/main.cpp.o -c /home/golitter/learn_cpp_dir/skip_list_kv/main.cpp

CMakeFiles/skip_list_kv.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/skip_list_kv.dir/main.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/golitter/learn_cpp_dir/skip_list_kv/main.cpp > CMakeFiles/skip_list_kv.dir/main.cpp.i

CMakeFiles/skip_list_kv.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/skip_list_kv.dir/main.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/golitter/learn_cpp_dir/skip_list_kv/main.cpp -o CMakeFiles/skip_list_kv.dir/main.cpp.s

# Object files for target skip_list_kv
skip_list_kv_OBJECTS = \
"CMakeFiles/skip_list_kv.dir/main.cpp.o"

# External object files for target skip_list_kv
skip_list_kv_EXTERNAL_OBJECTS =

skip_list_kv: CMakeFiles/skip_list_kv.dir/main.cpp.o
skip_list_kv: CMakeFiles/skip_list_kv.dir/build.make
skip_list_kv: CMakeFiles/skip_list_kv.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/golitter/learn_cpp_dir/skip_list_kv/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable skip_list_kv"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/skip_list_kv.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/skip_list_kv.dir/build: skip_list_kv
.PHONY : CMakeFiles/skip_list_kv.dir/build

CMakeFiles/skip_list_kv.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/skip_list_kv.dir/cmake_clean.cmake
.PHONY : CMakeFiles/skip_list_kv.dir/clean

CMakeFiles/skip_list_kv.dir/depend:
	cd /home/golitter/learn_cpp_dir/skip_list_kv/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/golitter/learn_cpp_dir/skip_list_kv /home/golitter/learn_cpp_dir/skip_list_kv /home/golitter/learn_cpp_dir/skip_list_kv/build /home/golitter/learn_cpp_dir/skip_list_kv/build /home/golitter/learn_cpp_dir/skip_list_kv/build/CMakeFiles/skip_list_kv.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/skip_list_kv.dir/depend

