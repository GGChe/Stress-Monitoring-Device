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
CMAKE_SOURCE_DIR = /home/pi/Desktop/VEML6030rpiV1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/pi/Desktop/VEML6030rpiV1

# Include any dependencies generated for this target.
include CMakeFiles/iir_static.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/iir_static.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/iir_static.dir/flags.make

CMakeFiles/iir_static.dir/iir/Biquad.cpp.o: CMakeFiles/iir_static.dir/flags.make
CMakeFiles/iir_static.dir/iir/Biquad.cpp.o: iir/Biquad.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pi/Desktop/VEML6030rpiV1/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/iir_static.dir/iir/Biquad.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/iir_static.dir/iir/Biquad.cpp.o -c /home/pi/Desktop/VEML6030rpiV1/iir/Biquad.cpp

CMakeFiles/iir_static.dir/iir/Biquad.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/iir_static.dir/iir/Biquad.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/pi/Desktop/VEML6030rpiV1/iir/Biquad.cpp > CMakeFiles/iir_static.dir/iir/Biquad.cpp.i

CMakeFiles/iir_static.dir/iir/Biquad.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/iir_static.dir/iir/Biquad.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/pi/Desktop/VEML6030rpiV1/iir/Biquad.cpp -o CMakeFiles/iir_static.dir/iir/Biquad.cpp.s

CMakeFiles/iir_static.dir/iir/Biquad.cpp.o.requires:

.PHONY : CMakeFiles/iir_static.dir/iir/Biquad.cpp.o.requires

CMakeFiles/iir_static.dir/iir/Biquad.cpp.o.provides: CMakeFiles/iir_static.dir/iir/Biquad.cpp.o.requires
	$(MAKE) -f CMakeFiles/iir_static.dir/build.make CMakeFiles/iir_static.dir/iir/Biquad.cpp.o.provides.build
.PHONY : CMakeFiles/iir_static.dir/iir/Biquad.cpp.o.provides

CMakeFiles/iir_static.dir/iir/Biquad.cpp.o.provides.build: CMakeFiles/iir_static.dir/iir/Biquad.cpp.o


CMakeFiles/iir_static.dir/iir/Butterworth.cpp.o: CMakeFiles/iir_static.dir/flags.make
CMakeFiles/iir_static.dir/iir/Butterworth.cpp.o: iir/Butterworth.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pi/Desktop/VEML6030rpiV1/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/iir_static.dir/iir/Butterworth.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/iir_static.dir/iir/Butterworth.cpp.o -c /home/pi/Desktop/VEML6030rpiV1/iir/Butterworth.cpp

CMakeFiles/iir_static.dir/iir/Butterworth.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/iir_static.dir/iir/Butterworth.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/pi/Desktop/VEML6030rpiV1/iir/Butterworth.cpp > CMakeFiles/iir_static.dir/iir/Butterworth.cpp.i

CMakeFiles/iir_static.dir/iir/Butterworth.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/iir_static.dir/iir/Butterworth.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/pi/Desktop/VEML6030rpiV1/iir/Butterworth.cpp -o CMakeFiles/iir_static.dir/iir/Butterworth.cpp.s

CMakeFiles/iir_static.dir/iir/Butterworth.cpp.o.requires:

.PHONY : CMakeFiles/iir_static.dir/iir/Butterworth.cpp.o.requires

CMakeFiles/iir_static.dir/iir/Butterworth.cpp.o.provides: CMakeFiles/iir_static.dir/iir/Butterworth.cpp.o.requires
	$(MAKE) -f CMakeFiles/iir_static.dir/build.make CMakeFiles/iir_static.dir/iir/Butterworth.cpp.o.provides.build
.PHONY : CMakeFiles/iir_static.dir/iir/Butterworth.cpp.o.provides

CMakeFiles/iir_static.dir/iir/Butterworth.cpp.o.provides.build: CMakeFiles/iir_static.dir/iir/Butterworth.cpp.o


CMakeFiles/iir_static.dir/iir/Cascade.cpp.o: CMakeFiles/iir_static.dir/flags.make
CMakeFiles/iir_static.dir/iir/Cascade.cpp.o: iir/Cascade.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pi/Desktop/VEML6030rpiV1/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/iir_static.dir/iir/Cascade.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/iir_static.dir/iir/Cascade.cpp.o -c /home/pi/Desktop/VEML6030rpiV1/iir/Cascade.cpp

CMakeFiles/iir_static.dir/iir/Cascade.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/iir_static.dir/iir/Cascade.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/pi/Desktop/VEML6030rpiV1/iir/Cascade.cpp > CMakeFiles/iir_static.dir/iir/Cascade.cpp.i

CMakeFiles/iir_static.dir/iir/Cascade.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/iir_static.dir/iir/Cascade.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/pi/Desktop/VEML6030rpiV1/iir/Cascade.cpp -o CMakeFiles/iir_static.dir/iir/Cascade.cpp.s

CMakeFiles/iir_static.dir/iir/Cascade.cpp.o.requires:

.PHONY : CMakeFiles/iir_static.dir/iir/Cascade.cpp.o.requires

CMakeFiles/iir_static.dir/iir/Cascade.cpp.o.provides: CMakeFiles/iir_static.dir/iir/Cascade.cpp.o.requires
	$(MAKE) -f CMakeFiles/iir_static.dir/build.make CMakeFiles/iir_static.dir/iir/Cascade.cpp.o.provides.build
.PHONY : CMakeFiles/iir_static.dir/iir/Cascade.cpp.o.provides

CMakeFiles/iir_static.dir/iir/Cascade.cpp.o.provides.build: CMakeFiles/iir_static.dir/iir/Cascade.cpp.o


CMakeFiles/iir_static.dir/iir/ChebyshevI.cpp.o: CMakeFiles/iir_static.dir/flags.make
CMakeFiles/iir_static.dir/iir/ChebyshevI.cpp.o: iir/ChebyshevI.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pi/Desktop/VEML6030rpiV1/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/iir_static.dir/iir/ChebyshevI.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/iir_static.dir/iir/ChebyshevI.cpp.o -c /home/pi/Desktop/VEML6030rpiV1/iir/ChebyshevI.cpp

CMakeFiles/iir_static.dir/iir/ChebyshevI.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/iir_static.dir/iir/ChebyshevI.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/pi/Desktop/VEML6030rpiV1/iir/ChebyshevI.cpp > CMakeFiles/iir_static.dir/iir/ChebyshevI.cpp.i

CMakeFiles/iir_static.dir/iir/ChebyshevI.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/iir_static.dir/iir/ChebyshevI.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/pi/Desktop/VEML6030rpiV1/iir/ChebyshevI.cpp -o CMakeFiles/iir_static.dir/iir/ChebyshevI.cpp.s

CMakeFiles/iir_static.dir/iir/ChebyshevI.cpp.o.requires:

.PHONY : CMakeFiles/iir_static.dir/iir/ChebyshevI.cpp.o.requires

CMakeFiles/iir_static.dir/iir/ChebyshevI.cpp.o.provides: CMakeFiles/iir_static.dir/iir/ChebyshevI.cpp.o.requires
	$(MAKE) -f CMakeFiles/iir_static.dir/build.make CMakeFiles/iir_static.dir/iir/ChebyshevI.cpp.o.provides.build
.PHONY : CMakeFiles/iir_static.dir/iir/ChebyshevI.cpp.o.provides

CMakeFiles/iir_static.dir/iir/ChebyshevI.cpp.o.provides.build: CMakeFiles/iir_static.dir/iir/ChebyshevI.cpp.o


CMakeFiles/iir_static.dir/iir/ChebyshevII.cpp.o: CMakeFiles/iir_static.dir/flags.make
CMakeFiles/iir_static.dir/iir/ChebyshevII.cpp.o: iir/ChebyshevII.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pi/Desktop/VEML6030rpiV1/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/iir_static.dir/iir/ChebyshevII.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/iir_static.dir/iir/ChebyshevII.cpp.o -c /home/pi/Desktop/VEML6030rpiV1/iir/ChebyshevII.cpp

CMakeFiles/iir_static.dir/iir/ChebyshevII.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/iir_static.dir/iir/ChebyshevII.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/pi/Desktop/VEML6030rpiV1/iir/ChebyshevII.cpp > CMakeFiles/iir_static.dir/iir/ChebyshevII.cpp.i

CMakeFiles/iir_static.dir/iir/ChebyshevII.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/iir_static.dir/iir/ChebyshevII.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/pi/Desktop/VEML6030rpiV1/iir/ChebyshevII.cpp -o CMakeFiles/iir_static.dir/iir/ChebyshevII.cpp.s

CMakeFiles/iir_static.dir/iir/ChebyshevII.cpp.o.requires:

.PHONY : CMakeFiles/iir_static.dir/iir/ChebyshevII.cpp.o.requires

CMakeFiles/iir_static.dir/iir/ChebyshevII.cpp.o.provides: CMakeFiles/iir_static.dir/iir/ChebyshevII.cpp.o.requires
	$(MAKE) -f CMakeFiles/iir_static.dir/build.make CMakeFiles/iir_static.dir/iir/ChebyshevII.cpp.o.provides.build
.PHONY : CMakeFiles/iir_static.dir/iir/ChebyshevII.cpp.o.provides

CMakeFiles/iir_static.dir/iir/ChebyshevII.cpp.o.provides.build: CMakeFiles/iir_static.dir/iir/ChebyshevII.cpp.o


CMakeFiles/iir_static.dir/iir/Custom.cpp.o: CMakeFiles/iir_static.dir/flags.make
CMakeFiles/iir_static.dir/iir/Custom.cpp.o: iir/Custom.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pi/Desktop/VEML6030rpiV1/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/iir_static.dir/iir/Custom.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/iir_static.dir/iir/Custom.cpp.o -c /home/pi/Desktop/VEML6030rpiV1/iir/Custom.cpp

CMakeFiles/iir_static.dir/iir/Custom.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/iir_static.dir/iir/Custom.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/pi/Desktop/VEML6030rpiV1/iir/Custom.cpp > CMakeFiles/iir_static.dir/iir/Custom.cpp.i

CMakeFiles/iir_static.dir/iir/Custom.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/iir_static.dir/iir/Custom.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/pi/Desktop/VEML6030rpiV1/iir/Custom.cpp -o CMakeFiles/iir_static.dir/iir/Custom.cpp.s

CMakeFiles/iir_static.dir/iir/Custom.cpp.o.requires:

.PHONY : CMakeFiles/iir_static.dir/iir/Custom.cpp.o.requires

CMakeFiles/iir_static.dir/iir/Custom.cpp.o.provides: CMakeFiles/iir_static.dir/iir/Custom.cpp.o.requires
	$(MAKE) -f CMakeFiles/iir_static.dir/build.make CMakeFiles/iir_static.dir/iir/Custom.cpp.o.provides.build
.PHONY : CMakeFiles/iir_static.dir/iir/Custom.cpp.o.provides

CMakeFiles/iir_static.dir/iir/Custom.cpp.o.provides.build: CMakeFiles/iir_static.dir/iir/Custom.cpp.o


CMakeFiles/iir_static.dir/iir/PoleFilter.cpp.o: CMakeFiles/iir_static.dir/flags.make
CMakeFiles/iir_static.dir/iir/PoleFilter.cpp.o: iir/PoleFilter.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pi/Desktop/VEML6030rpiV1/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/iir_static.dir/iir/PoleFilter.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/iir_static.dir/iir/PoleFilter.cpp.o -c /home/pi/Desktop/VEML6030rpiV1/iir/PoleFilter.cpp

CMakeFiles/iir_static.dir/iir/PoleFilter.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/iir_static.dir/iir/PoleFilter.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/pi/Desktop/VEML6030rpiV1/iir/PoleFilter.cpp > CMakeFiles/iir_static.dir/iir/PoleFilter.cpp.i

CMakeFiles/iir_static.dir/iir/PoleFilter.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/iir_static.dir/iir/PoleFilter.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/pi/Desktop/VEML6030rpiV1/iir/PoleFilter.cpp -o CMakeFiles/iir_static.dir/iir/PoleFilter.cpp.s

CMakeFiles/iir_static.dir/iir/PoleFilter.cpp.o.requires:

.PHONY : CMakeFiles/iir_static.dir/iir/PoleFilter.cpp.o.requires

CMakeFiles/iir_static.dir/iir/PoleFilter.cpp.o.provides: CMakeFiles/iir_static.dir/iir/PoleFilter.cpp.o.requires
	$(MAKE) -f CMakeFiles/iir_static.dir/build.make CMakeFiles/iir_static.dir/iir/PoleFilter.cpp.o.provides.build
.PHONY : CMakeFiles/iir_static.dir/iir/PoleFilter.cpp.o.provides

CMakeFiles/iir_static.dir/iir/PoleFilter.cpp.o.provides.build: CMakeFiles/iir_static.dir/iir/PoleFilter.cpp.o


CMakeFiles/iir_static.dir/iir/RBJ.cpp.o: CMakeFiles/iir_static.dir/flags.make
CMakeFiles/iir_static.dir/iir/RBJ.cpp.o: iir/RBJ.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pi/Desktop/VEML6030rpiV1/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/iir_static.dir/iir/RBJ.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/iir_static.dir/iir/RBJ.cpp.o -c /home/pi/Desktop/VEML6030rpiV1/iir/RBJ.cpp

CMakeFiles/iir_static.dir/iir/RBJ.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/iir_static.dir/iir/RBJ.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/pi/Desktop/VEML6030rpiV1/iir/RBJ.cpp > CMakeFiles/iir_static.dir/iir/RBJ.cpp.i

CMakeFiles/iir_static.dir/iir/RBJ.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/iir_static.dir/iir/RBJ.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/pi/Desktop/VEML6030rpiV1/iir/RBJ.cpp -o CMakeFiles/iir_static.dir/iir/RBJ.cpp.s

CMakeFiles/iir_static.dir/iir/RBJ.cpp.o.requires:

.PHONY : CMakeFiles/iir_static.dir/iir/RBJ.cpp.o.requires

CMakeFiles/iir_static.dir/iir/RBJ.cpp.o.provides: CMakeFiles/iir_static.dir/iir/RBJ.cpp.o.requires
	$(MAKE) -f CMakeFiles/iir_static.dir/build.make CMakeFiles/iir_static.dir/iir/RBJ.cpp.o.provides.build
.PHONY : CMakeFiles/iir_static.dir/iir/RBJ.cpp.o.provides

CMakeFiles/iir_static.dir/iir/RBJ.cpp.o.provides.build: CMakeFiles/iir_static.dir/iir/RBJ.cpp.o


CMakeFiles/iir_static.dir/iir/State.cpp.o: CMakeFiles/iir_static.dir/flags.make
CMakeFiles/iir_static.dir/iir/State.cpp.o: iir/State.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pi/Desktop/VEML6030rpiV1/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/iir_static.dir/iir/State.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/iir_static.dir/iir/State.cpp.o -c /home/pi/Desktop/VEML6030rpiV1/iir/State.cpp

CMakeFiles/iir_static.dir/iir/State.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/iir_static.dir/iir/State.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/pi/Desktop/VEML6030rpiV1/iir/State.cpp > CMakeFiles/iir_static.dir/iir/State.cpp.i

CMakeFiles/iir_static.dir/iir/State.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/iir_static.dir/iir/State.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/pi/Desktop/VEML6030rpiV1/iir/State.cpp -o CMakeFiles/iir_static.dir/iir/State.cpp.s

CMakeFiles/iir_static.dir/iir/State.cpp.o.requires:

.PHONY : CMakeFiles/iir_static.dir/iir/State.cpp.o.requires

CMakeFiles/iir_static.dir/iir/State.cpp.o.provides: CMakeFiles/iir_static.dir/iir/State.cpp.o.requires
	$(MAKE) -f CMakeFiles/iir_static.dir/build.make CMakeFiles/iir_static.dir/iir/State.cpp.o.provides.build
.PHONY : CMakeFiles/iir_static.dir/iir/State.cpp.o.provides

CMakeFiles/iir_static.dir/iir/State.cpp.o.provides.build: CMakeFiles/iir_static.dir/iir/State.cpp.o


# Object files for target iir_static
iir_static_OBJECTS = \
"CMakeFiles/iir_static.dir/iir/Biquad.cpp.o" \
"CMakeFiles/iir_static.dir/iir/Butterworth.cpp.o" \
"CMakeFiles/iir_static.dir/iir/Cascade.cpp.o" \
"CMakeFiles/iir_static.dir/iir/ChebyshevI.cpp.o" \
"CMakeFiles/iir_static.dir/iir/ChebyshevII.cpp.o" \
"CMakeFiles/iir_static.dir/iir/Custom.cpp.o" \
"CMakeFiles/iir_static.dir/iir/PoleFilter.cpp.o" \
"CMakeFiles/iir_static.dir/iir/RBJ.cpp.o" \
"CMakeFiles/iir_static.dir/iir/State.cpp.o"

# External object files for target iir_static
iir_static_EXTERNAL_OBJECTS =

libiir_static.a: CMakeFiles/iir_static.dir/iir/Biquad.cpp.o
libiir_static.a: CMakeFiles/iir_static.dir/iir/Butterworth.cpp.o
libiir_static.a: CMakeFiles/iir_static.dir/iir/Cascade.cpp.o
libiir_static.a: CMakeFiles/iir_static.dir/iir/ChebyshevI.cpp.o
libiir_static.a: CMakeFiles/iir_static.dir/iir/ChebyshevII.cpp.o
libiir_static.a: CMakeFiles/iir_static.dir/iir/Custom.cpp.o
libiir_static.a: CMakeFiles/iir_static.dir/iir/PoleFilter.cpp.o
libiir_static.a: CMakeFiles/iir_static.dir/iir/RBJ.cpp.o
libiir_static.a: CMakeFiles/iir_static.dir/iir/State.cpp.o
libiir_static.a: CMakeFiles/iir_static.dir/build.make
libiir_static.a: CMakeFiles/iir_static.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/pi/Desktop/VEML6030rpiV1/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Linking CXX static library libiir_static.a"
	$(CMAKE_COMMAND) -P CMakeFiles/iir_static.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/iir_static.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/iir_static.dir/build: libiir_static.a

.PHONY : CMakeFiles/iir_static.dir/build

CMakeFiles/iir_static.dir/requires: CMakeFiles/iir_static.dir/iir/Biquad.cpp.o.requires
CMakeFiles/iir_static.dir/requires: CMakeFiles/iir_static.dir/iir/Butterworth.cpp.o.requires
CMakeFiles/iir_static.dir/requires: CMakeFiles/iir_static.dir/iir/Cascade.cpp.o.requires
CMakeFiles/iir_static.dir/requires: CMakeFiles/iir_static.dir/iir/ChebyshevI.cpp.o.requires
CMakeFiles/iir_static.dir/requires: CMakeFiles/iir_static.dir/iir/ChebyshevII.cpp.o.requires
CMakeFiles/iir_static.dir/requires: CMakeFiles/iir_static.dir/iir/Custom.cpp.o.requires
CMakeFiles/iir_static.dir/requires: CMakeFiles/iir_static.dir/iir/PoleFilter.cpp.o.requires
CMakeFiles/iir_static.dir/requires: CMakeFiles/iir_static.dir/iir/RBJ.cpp.o.requires
CMakeFiles/iir_static.dir/requires: CMakeFiles/iir_static.dir/iir/State.cpp.o.requires

.PHONY : CMakeFiles/iir_static.dir/requires

CMakeFiles/iir_static.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/iir_static.dir/cmake_clean.cmake
.PHONY : CMakeFiles/iir_static.dir/clean

CMakeFiles/iir_static.dir/depend:
	cd /home/pi/Desktop/VEML6030rpiV1 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/pi/Desktop/VEML6030rpiV1 /home/pi/Desktop/VEML6030rpiV1 /home/pi/Desktop/VEML6030rpiV1 /home/pi/Desktop/VEML6030rpiV1 /home/pi/Desktop/VEML6030rpiV1/CMakeFiles/iir_static.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/iir_static.dir/depend

