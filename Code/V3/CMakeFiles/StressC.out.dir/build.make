# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.7

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/pi/Desktop/V3

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/pi/Desktop/V3

# Include any dependencies generated for this target.
include CMakeFiles/StressC.out.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/StressC.out.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/StressC.out.dir/flags.make

CMakeFiles/StressC.out.dir/StressController.cpp.o: CMakeFiles/StressC.out.dir/flags.make
CMakeFiles/StressC.out.dir/StressController.cpp.o: StressController.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pi/Desktop/V3/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/StressC.out.dir/StressController.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/StressC.out.dir/StressController.cpp.o -c /home/pi/Desktop/V3/StressController.cpp

CMakeFiles/StressC.out.dir/StressController.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/StressC.out.dir/StressController.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/pi/Desktop/V3/StressController.cpp > CMakeFiles/StressC.out.dir/StressController.cpp.i

CMakeFiles/StressC.out.dir/StressController.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/StressC.out.dir/StressController.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/pi/Desktop/V3/StressController.cpp -o CMakeFiles/StressC.out.dir/StressController.cpp.s

CMakeFiles/StressC.out.dir/StressController.cpp.o.requires:

.PHONY : CMakeFiles/StressC.out.dir/StressController.cpp.o.requires

CMakeFiles/StressC.out.dir/StressController.cpp.o.provides: CMakeFiles/StressC.out.dir/StressController.cpp.o.requires
	$(MAKE) -f CMakeFiles/StressC.out.dir/build.make CMakeFiles/StressC.out.dir/StressController.cpp.o.provides.build
.PHONY : CMakeFiles/StressC.out.dir/StressController.cpp.o.provides

CMakeFiles/StressC.out.dir/StressController.cpp.o.provides.build: CMakeFiles/StressC.out.dir/StressController.cpp.o


CMakeFiles/StressC.out.dir/VEML6030rpi.cpp.o: CMakeFiles/StressC.out.dir/flags.make
CMakeFiles/StressC.out.dir/VEML6030rpi.cpp.o: VEML6030rpi.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pi/Desktop/V3/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/StressC.out.dir/VEML6030rpi.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/StressC.out.dir/VEML6030rpi.cpp.o -c /home/pi/Desktop/V3/VEML6030rpi.cpp

CMakeFiles/StressC.out.dir/VEML6030rpi.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/StressC.out.dir/VEML6030rpi.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/pi/Desktop/V3/VEML6030rpi.cpp > CMakeFiles/StressC.out.dir/VEML6030rpi.cpp.i

CMakeFiles/StressC.out.dir/VEML6030rpi.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/StressC.out.dir/VEML6030rpi.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/pi/Desktop/V3/VEML6030rpi.cpp -o CMakeFiles/StressC.out.dir/VEML6030rpi.cpp.s

CMakeFiles/StressC.out.dir/VEML6030rpi.cpp.o.requires:

.PHONY : CMakeFiles/StressC.out.dir/VEML6030rpi.cpp.o.requires

CMakeFiles/StressC.out.dir/VEML6030rpi.cpp.o.provides: CMakeFiles/StressC.out.dir/VEML6030rpi.cpp.o.requires
	$(MAKE) -f CMakeFiles/StressC.out.dir/build.make CMakeFiles/StressC.out.dir/VEML6030rpi.cpp.o.provides.build
.PHONY : CMakeFiles/StressC.out.dir/VEML6030rpi.cpp.o.provides

CMakeFiles/StressC.out.dir/VEML6030rpi.cpp.o.provides.build: CMakeFiles/StressC.out.dir/VEML6030rpi.cpp.o


# Object files for target StressC.out
StressC_out_OBJECTS = \
"CMakeFiles/StressC.out.dir/StressController.cpp.o" \
"CMakeFiles/StressC.out.dir/VEML6030rpi.cpp.o"

# External object files for target StressC.out
StressC_out_EXTERNAL_OBJECTS =

StressC.out: CMakeFiles/StressC.out.dir/StressController.cpp.o
StressC.out: CMakeFiles/StressC.out.dir/VEML6030rpi.cpp.o
StressC.out: CMakeFiles/StressC.out.dir/build.make
StressC.out: /usr/lib/libwiringPi.so
StressC.out: /usr/lib/arm-linux-gnueabihf/librt.so
StressC.out: /usr/local/lib/libiir_static.a
StressC.out: CMakeFiles/StressC.out.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/pi/Desktop/V3/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable StressC.out"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/StressC.out.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/StressC.out.dir/build: StressC.out

.PHONY : CMakeFiles/StressC.out.dir/build

CMakeFiles/StressC.out.dir/requires: CMakeFiles/StressC.out.dir/StressController.cpp.o.requires
CMakeFiles/StressC.out.dir/requires: CMakeFiles/StressC.out.dir/VEML6030rpi.cpp.o.requires

.PHONY : CMakeFiles/StressC.out.dir/requires

CMakeFiles/StressC.out.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/StressC.out.dir/cmake_clean.cmake
.PHONY : CMakeFiles/StressC.out.dir/clean

CMakeFiles/StressC.out.dir/depend:
	cd /home/pi/Desktop/V3 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/pi/Desktop/V3 /home/pi/Desktop/V3 /home/pi/Desktop/V3 /home/pi/Desktop/V3 /home/pi/Desktop/V3/CMakeFiles/StressC.out.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/StressC.out.dir/depend
