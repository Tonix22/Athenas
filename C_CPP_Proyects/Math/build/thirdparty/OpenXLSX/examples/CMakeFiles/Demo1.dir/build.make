# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.18

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
CMAKE_COMMAND = /usr/local/bin/cmake

# The command to remove a file.
RM = /usr/local/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/tonix/Documents/ATHENAS/C_CPP_Proyects/Math

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/tonix/Documents/ATHENAS/C_CPP_Proyects/Math/build

# Include any dependencies generated for this target.
include thirdparty/OpenXLSX/examples/CMakeFiles/Demo1.dir/depend.make

# Include the progress variables for this target.
include thirdparty/OpenXLSX/examples/CMakeFiles/Demo1.dir/progress.make

# Include the compile flags for this target's objects.
include thirdparty/OpenXLSX/examples/CMakeFiles/Demo1.dir/flags.make

thirdparty/OpenXLSX/examples/CMakeFiles/Demo1.dir/Demo1.cpp.o: thirdparty/OpenXLSX/examples/CMakeFiles/Demo1.dir/flags.make
thirdparty/OpenXLSX/examples/CMakeFiles/Demo1.dir/Demo1.cpp.o: ../thirdparty/OpenXLSX/examples/Demo1.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/tonix/Documents/ATHENAS/C_CPP_Proyects/Math/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object thirdparty/OpenXLSX/examples/CMakeFiles/Demo1.dir/Demo1.cpp.o"
	cd /home/tonix/Documents/ATHENAS/C_CPP_Proyects/Math/build/thirdparty/OpenXLSX/examples && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Demo1.dir/Demo1.cpp.o -c /home/tonix/Documents/ATHENAS/C_CPP_Proyects/Math/thirdparty/OpenXLSX/examples/Demo1.cpp

thirdparty/OpenXLSX/examples/CMakeFiles/Demo1.dir/Demo1.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Demo1.dir/Demo1.cpp.i"
	cd /home/tonix/Documents/ATHENAS/C_CPP_Proyects/Math/build/thirdparty/OpenXLSX/examples && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/tonix/Documents/ATHENAS/C_CPP_Proyects/Math/thirdparty/OpenXLSX/examples/Demo1.cpp > CMakeFiles/Demo1.dir/Demo1.cpp.i

thirdparty/OpenXLSX/examples/CMakeFiles/Demo1.dir/Demo1.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Demo1.dir/Demo1.cpp.s"
	cd /home/tonix/Documents/ATHENAS/C_CPP_Proyects/Math/build/thirdparty/OpenXLSX/examples && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/tonix/Documents/ATHENAS/C_CPP_Proyects/Math/thirdparty/OpenXLSX/examples/Demo1.cpp -o CMakeFiles/Demo1.dir/Demo1.cpp.s

# Object files for target Demo1
Demo1_OBJECTS = \
"CMakeFiles/Demo1.dir/Demo1.cpp.o"

# External object files for target Demo1
Demo1_EXTERNAL_OBJECTS =

output/Demo1: thirdparty/OpenXLSX/examples/CMakeFiles/Demo1.dir/Demo1.cpp.o
output/Demo1: thirdparty/OpenXLSX/examples/CMakeFiles/Demo1.dir/build.make
output/Demo1: output/libOpenXLSX-static.a
output/Demo1: thirdparty/OpenXLSX/examples/CMakeFiles/Demo1.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/tonix/Documents/ATHENAS/C_CPP_Proyects/Math/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ../../../output/Demo1"
	cd /home/tonix/Documents/ATHENAS/C_CPP_Proyects/Math/build/thirdparty/OpenXLSX/examples && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Demo1.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
thirdparty/OpenXLSX/examples/CMakeFiles/Demo1.dir/build: output/Demo1

.PHONY : thirdparty/OpenXLSX/examples/CMakeFiles/Demo1.dir/build

thirdparty/OpenXLSX/examples/CMakeFiles/Demo1.dir/clean:
	cd /home/tonix/Documents/ATHENAS/C_CPP_Proyects/Math/build/thirdparty/OpenXLSX/examples && $(CMAKE_COMMAND) -P CMakeFiles/Demo1.dir/cmake_clean.cmake
.PHONY : thirdparty/OpenXLSX/examples/CMakeFiles/Demo1.dir/clean

thirdparty/OpenXLSX/examples/CMakeFiles/Demo1.dir/depend:
	cd /home/tonix/Documents/ATHENAS/C_CPP_Proyects/Math/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/tonix/Documents/ATHENAS/C_CPP_Proyects/Math /home/tonix/Documents/ATHENAS/C_CPP_Proyects/Math/thirdparty/OpenXLSX/examples /home/tonix/Documents/ATHENAS/C_CPP_Proyects/Math/build /home/tonix/Documents/ATHENAS/C_CPP_Proyects/Math/build/thirdparty/OpenXLSX/examples /home/tonix/Documents/ATHENAS/C_CPP_Proyects/Math/build/thirdparty/OpenXLSX/examples/CMakeFiles/Demo1.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : thirdparty/OpenXLSX/examples/CMakeFiles/Demo1.dir/depend

