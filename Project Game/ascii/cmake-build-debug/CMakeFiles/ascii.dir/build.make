# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.12

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2018.2.4\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2018.2.4\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "C:\Users\Devon\Dropbox\2018 SCHOOL\CS\u18\Project Game\ascii"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\Devon\Dropbox\2018 SCHOOL\CS\u18\Project Game\ascii\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/ascii.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/ascii.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ascii.dir/flags.make

CMakeFiles/ascii.dir/src/main.cpp.obj: CMakeFiles/ascii.dir/flags.make
CMakeFiles/ascii.dir/src/main.cpp.obj: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\Devon\Dropbox\2018 SCHOOL\CS\u18\Project Game\ascii\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/ascii.dir/src/main.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\ascii.dir\src\main.cpp.obj -c "C:\Users\Devon\Dropbox\2018 SCHOOL\CS\u18\Project Game\ascii\src\main.cpp"

CMakeFiles/ascii.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ascii.dir/src/main.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\Devon\Dropbox\2018 SCHOOL\CS\u18\Project Game\ascii\src\main.cpp" > CMakeFiles\ascii.dir\src\main.cpp.i

CMakeFiles/ascii.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ascii.dir/src/main.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\Devon\Dropbox\2018 SCHOOL\CS\u18\Project Game\ascii\src\main.cpp" -o CMakeFiles\ascii.dir\src\main.cpp.s

CMakeFiles/ascii.dir/src/Items/Item.cpp.obj: CMakeFiles/ascii.dir/flags.make
CMakeFiles/ascii.dir/src/Items/Item.cpp.obj: ../src/Items/Item.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\Devon\Dropbox\2018 SCHOOL\CS\u18\Project Game\ascii\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/ascii.dir/src/Items/Item.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\ascii.dir\src\Items\Item.cpp.obj -c "C:\Users\Devon\Dropbox\2018 SCHOOL\CS\u18\Project Game\ascii\src\Items\Item.cpp"

CMakeFiles/ascii.dir/src/Items/Item.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ascii.dir/src/Items/Item.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\Devon\Dropbox\2018 SCHOOL\CS\u18\Project Game\ascii\src\Items\Item.cpp" > CMakeFiles\ascii.dir\src\Items\Item.cpp.i

CMakeFiles/ascii.dir/src/Items/Item.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ascii.dir/src/Items/Item.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\Devon\Dropbox\2018 SCHOOL\CS\u18\Project Game\ascii\src\Items\Item.cpp" -o CMakeFiles\ascii.dir\src\Items\Item.cpp.s

# Object files for target ascii
ascii_OBJECTS = \
"CMakeFiles/ascii.dir/src/main.cpp.obj" \
"CMakeFiles/ascii.dir/src/Items/Item.cpp.obj"

# External object files for target ascii
ascii_EXTERNAL_OBJECTS =

ascii.exe: CMakeFiles/ascii.dir/src/main.cpp.obj
ascii.exe: CMakeFiles/ascii.dir/src/Items/Item.cpp.obj
ascii.exe: CMakeFiles/ascii.dir/build.make
ascii.exe: CMakeFiles/ascii.dir/linklibs.rsp
ascii.exe: CMakeFiles/ascii.dir/objects1.rsp
ascii.exe: CMakeFiles/ascii.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\Devon\Dropbox\2018 SCHOOL\CS\u18\Project Game\ascii\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable ascii.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\ascii.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ascii.dir/build: ascii.exe

.PHONY : CMakeFiles/ascii.dir/build

CMakeFiles/ascii.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\ascii.dir\cmake_clean.cmake
.PHONY : CMakeFiles/ascii.dir/clean

CMakeFiles/ascii.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Users\Devon\Dropbox\2018 SCHOOL\CS\u18\Project Game\ascii" "C:\Users\Devon\Dropbox\2018 SCHOOL\CS\u18\Project Game\ascii" "C:\Users\Devon\Dropbox\2018 SCHOOL\CS\u18\Project Game\ascii\cmake-build-debug" "C:\Users\Devon\Dropbox\2018 SCHOOL\CS\u18\Project Game\ascii\cmake-build-debug" "C:\Users\Devon\Dropbox\2018 SCHOOL\CS\u18\Project Game\ascii\cmake-build-debug\CMakeFiles\ascii.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/ascii.dir/depend

