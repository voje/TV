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
CMAKE_SOURCE_DIR = /home/kristjan/FRI/TV/Project

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/kristjan/FRI/TV/Project/build

# Include any dependencies generated for this target.
include CMakeFiles/head_bob.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/head_bob.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/head_bob.dir/flags.make

CMakeFiles/head_bob.dir/head_bob.cpp.o: CMakeFiles/head_bob.dir/flags.make
CMakeFiles/head_bob.dir/head_bob.cpp.o: ../head_bob.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/kristjan/FRI/TV/Project/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/head_bob.dir/head_bob.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/head_bob.dir/head_bob.cpp.o -c /home/kristjan/FRI/TV/Project/head_bob.cpp

CMakeFiles/head_bob.dir/head_bob.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/head_bob.dir/head_bob.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/kristjan/FRI/TV/Project/head_bob.cpp > CMakeFiles/head_bob.dir/head_bob.cpp.i

CMakeFiles/head_bob.dir/head_bob.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/head_bob.dir/head_bob.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/kristjan/FRI/TV/Project/head_bob.cpp -o CMakeFiles/head_bob.dir/head_bob.cpp.s

CMakeFiles/head_bob.dir/head_bob.cpp.o.requires:
.PHONY : CMakeFiles/head_bob.dir/head_bob.cpp.o.requires

CMakeFiles/head_bob.dir/head_bob.cpp.o.provides: CMakeFiles/head_bob.dir/head_bob.cpp.o.requires
	$(MAKE) -f CMakeFiles/head_bob.dir/build.make CMakeFiles/head_bob.dir/head_bob.cpp.o.provides.build
.PHONY : CMakeFiles/head_bob.dir/head_bob.cpp.o.provides

CMakeFiles/head_bob.dir/head_bob.cpp.o.provides.build: CMakeFiles/head_bob.dir/head_bob.cpp.o

# Object files for target head_bob
head_bob_OBJECTS = \
"CMakeFiles/head_bob.dir/head_bob.cpp.o"

# External object files for target head_bob
head_bob_EXTERNAL_OBJECTS =

head_bob: CMakeFiles/head_bob.dir/head_bob.cpp.o
head_bob: CMakeFiles/head_bob.dir/build.make
head_bob: /usr/local/lib/libopencv_xphoto.so.3.1.0
head_bob: /usr/local/lib/libopencv_xobjdetect.so.3.1.0
head_bob: /usr/local/lib/libopencv_ximgproc.so.3.1.0
head_bob: /usr/local/lib/libopencv_xfeatures2d.so.3.1.0
head_bob: /usr/local/lib/libopencv_tracking.so.3.1.0
head_bob: /usr/local/lib/libopencv_text.so.3.1.0
head_bob: /usr/local/lib/libopencv_surface_matching.so.3.1.0
head_bob: /usr/local/lib/libopencv_structured_light.so.3.1.0
head_bob: /usr/local/lib/libopencv_stereo.so.3.1.0
head_bob: /usr/local/lib/libopencv_saliency.so.3.1.0
head_bob: /usr/local/lib/libopencv_rgbd.so.3.1.0
head_bob: /usr/local/lib/libopencv_reg.so.3.1.0
head_bob: /usr/local/lib/libopencv_plot.so.3.1.0
head_bob: /usr/local/lib/libopencv_optflow.so.3.1.0
head_bob: /usr/local/lib/libopencv_line_descriptor.so.3.1.0
head_bob: /usr/local/lib/libopencv_fuzzy.so.3.1.0
head_bob: /usr/local/lib/libopencv_face.so.3.1.0
head_bob: /usr/local/lib/libopencv_dpm.so.3.1.0
head_bob: /usr/local/lib/libopencv_dnn.so.3.1.0
head_bob: /usr/local/lib/libopencv_datasets.so.3.1.0
head_bob: /usr/local/lib/libopencv_ccalib.so.3.1.0
head_bob: /usr/local/lib/libopencv_bioinspired.so.3.1.0
head_bob: /usr/local/lib/libopencv_bgsegm.so.3.1.0
head_bob: /usr/local/lib/libopencv_aruco.so.3.1.0
head_bob: /usr/local/lib/libopencv_videostab.so.3.1.0
head_bob: /usr/local/lib/libopencv_videoio.so.3.1.0
head_bob: /usr/local/lib/libopencv_video.so.3.1.0
head_bob: /usr/local/lib/libopencv_superres.so.3.1.0
head_bob: /usr/local/lib/libopencv_stitching.so.3.1.0
head_bob: /usr/local/lib/libopencv_shape.so.3.1.0
head_bob: /usr/local/lib/libopencv_photo.so.3.1.0
head_bob: /usr/local/lib/libopencv_objdetect.so.3.1.0
head_bob: /usr/local/lib/libopencv_ml.so.3.1.0
head_bob: /usr/local/lib/libopencv_imgproc.so.3.1.0
head_bob: /usr/local/lib/libopencv_imgcodecs.so.3.1.0
head_bob: /usr/local/lib/libopencv_highgui.so.3.1.0
head_bob: /usr/local/lib/libopencv_flann.so.3.1.0
head_bob: /usr/local/lib/libopencv_features2d.so.3.1.0
head_bob: /usr/local/lib/libopencv_core.so.3.1.0
head_bob: /usr/local/lib/libopencv_calib3d.so.3.1.0
head_bob: /usr/local/lib/libopencv_text.so.3.1.0
head_bob: /usr/local/lib/libopencv_face.so.3.1.0
head_bob: /usr/local/lib/libopencv_ximgproc.so.3.1.0
head_bob: /usr/local/lib/libopencv_xfeatures2d.so.3.1.0
head_bob: /usr/local/lib/libopencv_shape.so.3.1.0
head_bob: /usr/local/lib/libopencv_video.so.3.1.0
head_bob: /usr/local/lib/libopencv_objdetect.so.3.1.0
head_bob: /usr/local/lib/libopencv_calib3d.so.3.1.0
head_bob: /usr/local/lib/libopencv_features2d.so.3.1.0
head_bob: /usr/local/lib/libopencv_ml.so.3.1.0
head_bob: /usr/local/lib/libopencv_highgui.so.3.1.0
head_bob: /usr/local/lib/libopencv_videoio.so.3.1.0
head_bob: /usr/local/lib/libopencv_imgcodecs.so.3.1.0
head_bob: /usr/local/lib/libopencv_imgproc.so.3.1.0
head_bob: /usr/local/lib/libopencv_flann.so.3.1.0
head_bob: /usr/local/lib/libopencv_core.so.3.1.0
head_bob: CMakeFiles/head_bob.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable head_bob"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/head_bob.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/head_bob.dir/build: head_bob
.PHONY : CMakeFiles/head_bob.dir/build

CMakeFiles/head_bob.dir/requires: CMakeFiles/head_bob.dir/head_bob.cpp.o.requires
.PHONY : CMakeFiles/head_bob.dir/requires

CMakeFiles/head_bob.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/head_bob.dir/cmake_clean.cmake
.PHONY : CMakeFiles/head_bob.dir/clean

CMakeFiles/head_bob.dir/depend:
	cd /home/kristjan/FRI/TV/Project/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/kristjan/FRI/TV/Project /home/kristjan/FRI/TV/Project /home/kristjan/FRI/TV/Project/build /home/kristjan/FRI/TV/Project/build /home/kristjan/FRI/TV/Project/build/CMakeFiles/head_bob.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/head_bob.dir/depend

