# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.28

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
CMAKE_COMMAND = /opt/homebrew/Cellar/cmake/3.28.1/bin/cmake

# The command to remove a file.
RM = /opt/homebrew/Cellar/cmake/3.28.1/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Applications/Workspace/Projects/Github/C++/TermGameLoader

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Applications/Workspace/Projects/Github/C++/TermGameLoader/build

# Include any dependencies generated for this target.
include CMakeFiles/run_test.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/run_test.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/run_test.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/run_test.dir/flags.make

CMakeFiles/run_test.dir/tests/test.cpp.o: CMakeFiles/run_test.dir/flags.make
CMakeFiles/run_test.dir/tests/test.cpp.o: /Applications/Workspace/Projects/Github/C++/TermGameLoader/tests/test.cpp
CMakeFiles/run_test.dir/tests/test.cpp.o: CMakeFiles/run_test.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Applications/Workspace/Projects/Github/C++/TermGameLoader/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/run_test.dir/tests/test.cpp.o"
	/Applications/Workspace/Coding/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/run_test.dir/tests/test.cpp.o -MF CMakeFiles/run_test.dir/tests/test.cpp.o.d -o CMakeFiles/run_test.dir/tests/test.cpp.o -c /Applications/Workspace/Projects/Github/C++/TermGameLoader/tests/test.cpp

CMakeFiles/run_test.dir/tests/test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/run_test.dir/tests/test.cpp.i"
	/Applications/Workspace/Coding/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Applications/Workspace/Projects/Github/C++/TermGameLoader/tests/test.cpp > CMakeFiles/run_test.dir/tests/test.cpp.i

CMakeFiles/run_test.dir/tests/test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/run_test.dir/tests/test.cpp.s"
	/Applications/Workspace/Coding/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Applications/Workspace/Projects/Github/C++/TermGameLoader/tests/test.cpp -o CMakeFiles/run_test.dir/tests/test.cpp.s

# Object files for target run_test
run_test_OBJECTS = \
"CMakeFiles/run_test.dir/tests/test.cpp.o"

# External object files for target run_test
run_test_EXTERNAL_OBJECTS =

run_test: CMakeFiles/run_test.dir/tests/test.cpp.o
run_test: CMakeFiles/run_test.dir/build.make
run_test: libProjectLib.a
run_test: /usr/local/lib/libgtest_main.a
run_test: /Applications/Workspace/Coding/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX14.2.sdk/usr/lib/libcurses.tbd
run_test: /Applications/Workspace/Coding/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX14.2.sdk/usr/lib/libform.tbd
run_test: /usr/local/lib/libgtest.a
run_test: CMakeFiles/run_test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Applications/Workspace/Projects/Github/C++/TermGameLoader/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable run_test"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/run_test.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/run_test.dir/build: run_test
.PHONY : CMakeFiles/run_test.dir/build

CMakeFiles/run_test.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/run_test.dir/cmake_clean.cmake
.PHONY : CMakeFiles/run_test.dir/clean

CMakeFiles/run_test.dir/depend:
	cd /Applications/Workspace/Projects/Github/C++/TermGameLoader/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Applications/Workspace/Projects/Github/C++/TermGameLoader /Applications/Workspace/Projects/Github/C++/TermGameLoader /Applications/Workspace/Projects/Github/C++/TermGameLoader/build /Applications/Workspace/Projects/Github/C++/TermGameLoader/build /Applications/Workspace/Projects/Github/C++/TermGameLoader/build/CMakeFiles/run_test.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/run_test.dir/depend

