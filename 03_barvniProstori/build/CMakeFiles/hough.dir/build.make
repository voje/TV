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
CMAKE_SOURCE_DIR = /home/kristjan/FRI/TV/03_barvniProstori

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/kristjan/FRI/TV/03_barvniProstori/build

# Include any dependencies generated for this target.
include CMakeFiles/hough.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/hough.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/hough.dir/flags.make

CMakeFiles/hough.dir/hough.cpp.o: CMakeFiles/hough.dir/flags.make
CMakeFiles/hough.dir/hough.cpp.o: ../hough.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/kristjan/FRI/TV/03_barvniProstori/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/hough.dir/hough.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/hough.dir/hough.cpp.o -c /home/kristjan/FRI/TV/03_barvniProstori/hough.cpp

CMakeFiles/hough.dir/hough.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/hough.dir/hough.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/kristjan/FRI/TV/03_barvniProstori/hough.cpp > CMakeFiles/hough.dir/hough.cpp.i

CMakeFiles/hough.dir/hough.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/hough.dir/hough.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/kristjan/FRI/TV/03_barvniProstori/hough.cpp -o CMakeFiles/hough.dir/hough.cpp.s

CMakeFiles/hough.dir/hough.cpp.o.requires:
.PHONY : CMakeFiles/hough.dir/hough.cpp.o.requires

CMakeFiles/hough.dir/hough.cpp.o.provides: CMakeFiles/hough.dir/hough.cpp.o.requires
	$(MAKE) -f CMakeFiles/hough.dir/build.make CMakeFiles/hough.dir/hough.cpp.o.provides.build
.PHONY : CMakeFiles/hough.dir/hough.cpp.o.provides

CMakeFiles/hough.dir/hough.cpp.o.provides.build: CMakeFiles/hough.dir/hough.cpp.o

# Object files for target hough
hough_OBJECTS = \
"CMakeFiles/hough.dir/hough.cpp.o"

# External object files for target hough
hough_EXTERNAL_OBJECTS =

hough: CMakeFiles/hough.dir/hough.cpp.o
hough: CMakeFiles/hough.dir/build.make
hough: /usr/local/lib/libopencv_viz.so.3.1.0
hough: /usr/local/lib/libopencv_videostab.so.3.1.0
hough: /usr/local/lib/libopencv_videoio.so.3.1.0
hough: /usr/local/lib/libopencv_video.so.3.1.0
hough: /usr/local/lib/libopencv_superres.so.3.1.0
hough: /usr/local/lib/libopencv_stitching.so.3.1.0
hough: /usr/local/lib/libopencv_shape.so.3.1.0
hough: /usr/local/lib/libopencv_photo.so.3.1.0
hough: /usr/local/lib/libopencv_objdetect.so.3.1.0
hough: /usr/local/lib/libopencv_ml.so.3.1.0
hough: /usr/local/lib/libopencv_imgproc.so.3.1.0
hough: /usr/local/lib/libopencv_imgcodecs.so.3.1.0
hough: /usr/local/lib/libopencv_highgui.so.3.1.0
hough: /usr/local/lib/libopencv_flann.so.3.1.0
hough: /usr/local/lib/libopencv_features2d.so.3.1.0
hough: /usr/local/lib/libopencv_core.so.3.1.0
hough: /usr/local/lib/libopencv_calib3d.so.3.1.0
hough: /usr/local/lib/libopencv_features2d.so.3.1.0
hough: /usr/local/lib/libopencv_ml.so.3.1.0
hough: /usr/local/lib/libopencv_highgui.so.3.1.0
hough: /usr/local/lib/libopencv_videoio.so.3.1.0
hough: /usr/local/lib/libopencv_imgcodecs.so.3.1.0
hough: /usr/local/lib/libopencv_flann.so.3.1.0
hough: /usr/local/lib/libopencv_video.so.3.1.0
hough: /usr/local/lib/libopencv_imgproc.so.3.1.0
hough: /usr/local/lib/libopencv_core.so.3.1.0
hough: CMakeFiles/hough.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable hough"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/hough.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/hough.dir/build: hough
.PHONY : CMakeFiles/hough.dir/build

CMakeFiles/hough.dir/requires: CMakeFiles/hough.dir/hough.cpp.o.requires
.PHONY : CMakeFiles/hough.dir/requires

CMakeFiles/hough.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/hough.dir/cmake_clean.cmake
.PHONY : CMakeFiles/hough.dir/clean

CMakeFiles/hough.dir/depend:
	cd /home/kristjan/FRI/TV/03_barvniProstori/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/kristjan/FRI/TV/03_barvniProstori /home/kristjan/FRI/TV/03_barvniProstori /home/kristjan/FRI/TV/03_barvniProstori/build /home/kristjan/FRI/TV/03_barvniProstori/build /home/kristjan/FRI/TV/03_barvniProstori/build/CMakeFiles/hough.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/hough.dir/depend

