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
CMAKE_SOURCE_DIR = /home/kristjan/FRI/TV/02_opencv

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/kristjan/FRI/TV/02_opencv/build

# Include any dependencies generated for this target.
include CMakeFiles/datatypes.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/datatypes.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/datatypes.dir/flags.make

CMakeFiles/datatypes.dir/datatypes.cpp.o: CMakeFiles/datatypes.dir/flags.make
CMakeFiles/datatypes.dir/datatypes.cpp.o: ../datatypes.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/kristjan/FRI/TV/02_opencv/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/datatypes.dir/datatypes.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/datatypes.dir/datatypes.cpp.o -c /home/kristjan/FRI/TV/02_opencv/datatypes.cpp

CMakeFiles/datatypes.dir/datatypes.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/datatypes.dir/datatypes.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/kristjan/FRI/TV/02_opencv/datatypes.cpp > CMakeFiles/datatypes.dir/datatypes.cpp.i

CMakeFiles/datatypes.dir/datatypes.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/datatypes.dir/datatypes.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/kristjan/FRI/TV/02_opencv/datatypes.cpp -o CMakeFiles/datatypes.dir/datatypes.cpp.s

CMakeFiles/datatypes.dir/datatypes.cpp.o.requires:
.PHONY : CMakeFiles/datatypes.dir/datatypes.cpp.o.requires

CMakeFiles/datatypes.dir/datatypes.cpp.o.provides: CMakeFiles/datatypes.dir/datatypes.cpp.o.requires
	$(MAKE) -f CMakeFiles/datatypes.dir/build.make CMakeFiles/datatypes.dir/datatypes.cpp.o.provides.build
.PHONY : CMakeFiles/datatypes.dir/datatypes.cpp.o.provides

CMakeFiles/datatypes.dir/datatypes.cpp.o.provides.build: CMakeFiles/datatypes.dir/datatypes.cpp.o

# Object files for target datatypes
datatypes_OBJECTS = \
"CMakeFiles/datatypes.dir/datatypes.cpp.o"

# External object files for target datatypes
datatypes_EXTERNAL_OBJECTS =

datatypes: CMakeFiles/datatypes.dir/datatypes.cpp.o
datatypes: CMakeFiles/datatypes.dir/build.make
datatypes: /usr/local/lib/libopencv_viz.so.3.1.0
datatypes: /usr/local/lib/libopencv_videostab.so.3.1.0
datatypes: /usr/local/lib/libopencv_videoio.so.3.1.0
datatypes: /usr/local/lib/libopencv_video.so.3.1.0
datatypes: /usr/local/lib/libopencv_superres.so.3.1.0
datatypes: /usr/local/lib/libopencv_stitching.so.3.1.0
datatypes: /usr/local/lib/libopencv_shape.so.3.1.0
datatypes: /usr/local/lib/libopencv_photo.so.3.1.0
datatypes: /usr/local/lib/libopencv_objdetect.so.3.1.0
datatypes: /usr/local/lib/libopencv_ml.so.3.1.0
datatypes: /usr/local/lib/libopencv_imgproc.so.3.1.0
datatypes: /usr/local/lib/libopencv_imgcodecs.so.3.1.0
datatypes: /usr/local/lib/libopencv_highgui.so.3.1.0
datatypes: /usr/local/lib/libopencv_flann.so.3.1.0
datatypes: /usr/local/lib/libopencv_features2d.so.3.1.0
datatypes: /usr/local/lib/libopencv_core.so.3.1.0
datatypes: /usr/local/lib/libopencv_calib3d.so.3.1.0
datatypes: /usr/local/lib/libopencv_features2d.so.3.1.0
datatypes: /usr/local/lib/libopencv_ml.so.3.1.0
datatypes: /usr/local/lib/libopencv_highgui.so.3.1.0
datatypes: /usr/local/lib/libopencv_videoio.so.3.1.0
datatypes: /usr/local/lib/libopencv_imgcodecs.so.3.1.0
datatypes: /usr/local/lib/libopencv_flann.so.3.1.0
datatypes: /usr/local/lib/libopencv_video.so.3.1.0
datatypes: /usr/local/lib/libopencv_imgproc.so.3.1.0
datatypes: /usr/local/lib/libopencv_core.so.3.1.0
datatypes: CMakeFiles/datatypes.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable datatypes"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/datatypes.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/datatypes.dir/build: datatypes
.PHONY : CMakeFiles/datatypes.dir/build

CMakeFiles/datatypes.dir/requires: CMakeFiles/datatypes.dir/datatypes.cpp.o.requires
.PHONY : CMakeFiles/datatypes.dir/requires

CMakeFiles/datatypes.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/datatypes.dir/cmake_clean.cmake
.PHONY : CMakeFiles/datatypes.dir/clean

CMakeFiles/datatypes.dir/depend:
	cd /home/kristjan/FRI/TV/02_opencv/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/kristjan/FRI/TV/02_opencv /home/kristjan/FRI/TV/02_opencv /home/kristjan/FRI/TV/02_opencv/build /home/kristjan/FRI/TV/02_opencv/build /home/kristjan/FRI/TV/02_opencv/build/CMakeFiles/datatypes.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/datatypes.dir/depend

