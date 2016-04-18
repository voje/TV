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
CMAKE_SOURCE_DIR = /home/kristjan/FRI/TV/04_geometry

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/kristjan/FRI/TV/04_geometry/build

# Include any dependencies generated for this target.
include CMakeFiles/pose.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/pose.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/pose.dir/flags.make

CMakeFiles/pose.dir/pose.cpp.o: CMakeFiles/pose.dir/flags.make
CMakeFiles/pose.dir/pose.cpp.o: ../pose.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/kristjan/FRI/TV/04_geometry/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/pose.dir/pose.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/pose.dir/pose.cpp.o -c /home/kristjan/FRI/TV/04_geometry/pose.cpp

CMakeFiles/pose.dir/pose.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/pose.dir/pose.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/kristjan/FRI/TV/04_geometry/pose.cpp > CMakeFiles/pose.dir/pose.cpp.i

CMakeFiles/pose.dir/pose.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/pose.dir/pose.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/kristjan/FRI/TV/04_geometry/pose.cpp -o CMakeFiles/pose.dir/pose.cpp.s

CMakeFiles/pose.dir/pose.cpp.o.requires:
.PHONY : CMakeFiles/pose.dir/pose.cpp.o.requires

CMakeFiles/pose.dir/pose.cpp.o.provides: CMakeFiles/pose.dir/pose.cpp.o.requires
	$(MAKE) -f CMakeFiles/pose.dir/build.make CMakeFiles/pose.dir/pose.cpp.o.provides.build
.PHONY : CMakeFiles/pose.dir/pose.cpp.o.provides

CMakeFiles/pose.dir/pose.cpp.o.provides.build: CMakeFiles/pose.dir/pose.cpp.o

CMakeFiles/pose.dir/features.cpp.o: CMakeFiles/pose.dir/flags.make
CMakeFiles/pose.dir/features.cpp.o: ../features.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/kristjan/FRI/TV/04_geometry/build/CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/pose.dir/features.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/pose.dir/features.cpp.o -c /home/kristjan/FRI/TV/04_geometry/features.cpp

CMakeFiles/pose.dir/features.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/pose.dir/features.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/kristjan/FRI/TV/04_geometry/features.cpp > CMakeFiles/pose.dir/features.cpp.i

CMakeFiles/pose.dir/features.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/pose.dir/features.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/kristjan/FRI/TV/04_geometry/features.cpp -o CMakeFiles/pose.dir/features.cpp.s

CMakeFiles/pose.dir/features.cpp.o.requires:
.PHONY : CMakeFiles/pose.dir/features.cpp.o.requires

CMakeFiles/pose.dir/features.cpp.o.provides: CMakeFiles/pose.dir/features.cpp.o.requires
	$(MAKE) -f CMakeFiles/pose.dir/build.make CMakeFiles/pose.dir/features.cpp.o.provides.build
.PHONY : CMakeFiles/pose.dir/features.cpp.o.provides

CMakeFiles/pose.dir/features.cpp.o.provides.build: CMakeFiles/pose.dir/features.cpp.o

# Object files for target pose
pose_OBJECTS = \
"CMakeFiles/pose.dir/pose.cpp.o" \
"CMakeFiles/pose.dir/features.cpp.o"

# External object files for target pose
pose_EXTERNAL_OBJECTS =

pose: CMakeFiles/pose.dir/pose.cpp.o
pose: CMakeFiles/pose.dir/features.cpp.o
pose: CMakeFiles/pose.dir/build.make
pose: /usr/local/lib/libopencv_xphoto.so.3.1.0
pose: /usr/local/lib/libopencv_xobjdetect.so.3.1.0
pose: /usr/local/lib/libopencv_ximgproc.so.3.1.0
pose: /usr/local/lib/libopencv_xfeatures2d.so.3.1.0
pose: /usr/local/lib/libopencv_tracking.so.3.1.0
pose: /usr/local/lib/libopencv_text.so.3.1.0
pose: /usr/local/lib/libopencv_surface_matching.so.3.1.0
pose: /usr/local/lib/libopencv_structured_light.so.3.1.0
pose: /usr/local/lib/libopencv_stereo.so.3.1.0
pose: /usr/local/lib/libopencv_saliency.so.3.1.0
pose: /usr/local/lib/libopencv_rgbd.so.3.1.0
pose: /usr/local/lib/libopencv_reg.so.3.1.0
pose: /usr/local/lib/libopencv_plot.so.3.1.0
pose: /usr/local/lib/libopencv_optflow.so.3.1.0
pose: /usr/local/lib/libopencv_line_descriptor.so.3.1.0
pose: /usr/local/lib/libopencv_fuzzy.so.3.1.0
pose: /usr/local/lib/libopencv_face.so.3.1.0
pose: /usr/local/lib/libopencv_dpm.so.3.1.0
pose: /usr/local/lib/libopencv_dnn.so.3.1.0
pose: /usr/local/lib/libopencv_datasets.so.3.1.0
pose: /usr/local/lib/libopencv_ccalib.so.3.1.0
pose: /usr/local/lib/libopencv_bioinspired.so.3.1.0
pose: /usr/local/lib/libopencv_bgsegm.so.3.1.0
pose: /usr/local/lib/libopencv_aruco.so.3.1.0
pose: /usr/local/lib/libopencv_viz.so.3.1.0
pose: /usr/local/lib/libopencv_videostab.so.3.1.0
pose: /usr/local/lib/libopencv_videoio.so.3.1.0
pose: /usr/local/lib/libopencv_video.so.3.1.0
pose: /usr/local/lib/libopencv_superres.so.3.1.0
pose: /usr/local/lib/libopencv_stitching.so.3.1.0
pose: /usr/local/lib/libopencv_shape.so.3.1.0
pose: /usr/local/lib/libopencv_photo.so.3.1.0
pose: /usr/local/lib/libopencv_objdetect.so.3.1.0
pose: /usr/local/lib/libopencv_ml.so.3.1.0
pose: /usr/local/lib/libopencv_imgproc.so.3.1.0
pose: /usr/local/lib/libopencv_imgcodecs.so.3.1.0
pose: /usr/local/lib/libopencv_highgui.so.3.1.0
pose: /usr/local/lib/libopencv_flann.so.3.1.0
pose: /usr/local/lib/libopencv_features2d.so.3.1.0
pose: /usr/local/lib/libopencv_core.so.3.1.0
pose: /usr/local/lib/libopencv_calib3d.so.3.1.0
pose: /usr/local/lib/libopencv_text.so.3.1.0
pose: /usr/local/lib/libopencv_face.so.3.1.0
pose: /usr/local/lib/libopencv_ximgproc.so.3.1.0
pose: /usr/local/lib/libopencv_xfeatures2d.so.3.1.0
pose: /usr/local/lib/libopencv_shape.so.3.1.0
pose: /usr/local/lib/libopencv_video.so.3.1.0
pose: /usr/local/lib/libopencv_objdetect.so.3.1.0
pose: /usr/local/lib/libopencv_calib3d.so.3.1.0
pose: /usr/local/lib/libopencv_features2d.so.3.1.0
pose: /usr/local/lib/libopencv_ml.so.3.1.0
pose: /usr/local/lib/libopencv_highgui.so.3.1.0
pose: /usr/local/lib/libopencv_videoio.so.3.1.0
pose: /usr/local/lib/libopencv_imgcodecs.so.3.1.0
pose: /usr/local/lib/libopencv_imgproc.so.3.1.0
pose: /usr/local/lib/libopencv_flann.so.3.1.0
pose: /usr/local/lib/libopencv_core.so.3.1.0
pose: CMakeFiles/pose.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable pose"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/pose.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/pose.dir/build: pose
.PHONY : CMakeFiles/pose.dir/build

CMakeFiles/pose.dir/requires: CMakeFiles/pose.dir/pose.cpp.o.requires
CMakeFiles/pose.dir/requires: CMakeFiles/pose.dir/features.cpp.o.requires
.PHONY : CMakeFiles/pose.dir/requires

CMakeFiles/pose.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/pose.dir/cmake_clean.cmake
.PHONY : CMakeFiles/pose.dir/clean

CMakeFiles/pose.dir/depend:
	cd /home/kristjan/FRI/TV/04_geometry/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/kristjan/FRI/TV/04_geometry /home/kristjan/FRI/TV/04_geometry /home/kristjan/FRI/TV/04_geometry/build /home/kristjan/FRI/TV/04_geometry/build /home/kristjan/FRI/TV/04_geometry/build/CMakeFiles/pose.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/pose.dir/depend

