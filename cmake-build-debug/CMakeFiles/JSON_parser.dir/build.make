# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.14

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
CMAKE_SOURCE_DIR = /Users/miroslavparapanov/workspace/JSON-parser

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/miroslavparapanov/workspace/JSON-parser/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/JSON_parser.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/JSON_parser.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/JSON_parser.dir/flags.make

CMakeFiles/JSON_parser.dir/main.cpp.o: CMakeFiles/JSON_parser.dir/flags.make
CMakeFiles/JSON_parser.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/miroslavparapanov/workspace/JSON-parser/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/JSON_parser.dir/main.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/JSON_parser.dir/main.cpp.o -c /Users/miroslavparapanov/workspace/JSON-parser/main.cpp

CMakeFiles/JSON_parser.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/JSON_parser.dir/main.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/miroslavparapanov/workspace/JSON-parser/main.cpp > CMakeFiles/JSON_parser.dir/main.cpp.i

CMakeFiles/JSON_parser.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/JSON_parser.dir/main.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/miroslavparapanov/workspace/JSON-parser/main.cpp -o CMakeFiles/JSON_parser.dir/main.cpp.s

CMakeFiles/JSON_parser.dir/dbmanager/JsonManager.cpp.o: CMakeFiles/JSON_parser.dir/flags.make
CMakeFiles/JSON_parser.dir/dbmanager/JsonManager.cpp.o: ../dbmanager/JsonManager.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/miroslavparapanov/workspace/JSON-parser/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/JSON_parser.dir/dbmanager/JsonManager.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/JSON_parser.dir/dbmanager/JsonManager.cpp.o -c /Users/miroslavparapanov/workspace/JSON-parser/dbmanager/JsonManager.cpp

CMakeFiles/JSON_parser.dir/dbmanager/JsonManager.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/JSON_parser.dir/dbmanager/JsonManager.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/miroslavparapanov/workspace/JSON-parser/dbmanager/JsonManager.cpp > CMakeFiles/JSON_parser.dir/dbmanager/JsonManager.cpp.i

CMakeFiles/JSON_parser.dir/dbmanager/JsonManager.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/JSON_parser.dir/dbmanager/JsonManager.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/miroslavparapanov/workspace/JSON-parser/dbmanager/JsonManager.cpp -o CMakeFiles/JSON_parser.dir/dbmanager/JsonManager.cpp.s

# Object files for target JSON_parser
JSON_parser_OBJECTS = \
"CMakeFiles/JSON_parser.dir/main.cpp.o" \
"CMakeFiles/JSON_parser.dir/dbmanager/JsonManager.cpp.o"

# External object files for target JSON_parser
JSON_parser_EXTERNAL_OBJECTS =

JSON_parser: CMakeFiles/JSON_parser.dir/main.cpp.o
JSON_parser: CMakeFiles/JSON_parser.dir/dbmanager/JsonManager.cpp.o
JSON_parser: CMakeFiles/JSON_parser.dir/build.make
JSON_parser: CMakeFiles/JSON_parser.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/miroslavparapanov/workspace/JSON-parser/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable JSON_parser"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/JSON_parser.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/JSON_parser.dir/build: JSON_parser

.PHONY : CMakeFiles/JSON_parser.dir/build

CMakeFiles/JSON_parser.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/JSON_parser.dir/cmake_clean.cmake
.PHONY : CMakeFiles/JSON_parser.dir/clean

CMakeFiles/JSON_parser.dir/depend:
	cd /Users/miroslavparapanov/workspace/JSON-parser/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/miroslavparapanov/workspace/JSON-parser /Users/miroslavparapanov/workspace/JSON-parser /Users/miroslavparapanov/workspace/JSON-parser/cmake-build-debug /Users/miroslavparapanov/workspace/JSON-parser/cmake-build-debug /Users/miroslavparapanov/workspace/JSON-parser/cmake-build-debug/CMakeFiles/JSON_parser.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/JSON_parser.dir/depend
