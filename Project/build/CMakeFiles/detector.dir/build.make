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
include CMakeFiles/detector.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/detector.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/detector.dir/flags.make

CMakeFiles/detector.dir/detector.cpp.o: CMakeFiles/detector.dir/flags.make
CMakeFiles/detector.dir/detector.cpp.o: ../detector.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/kristjan/FRI/TV/Project/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/detector.dir/detector.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/detector.dir/detector.cpp.o -c /home/kristjan/FRI/TV/Project/detector.cpp

CMakeFiles/detector.dir/detector.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/detector.dir/detector.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/kristjan/FRI/TV/Project/detector.cpp > CMakeFiles/detector.dir/detector.cpp.i

CMakeFiles/detector.dir/detector.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/detector.dir/detector.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/kristjan/FRI/TV/Project/detector.cpp -o CMakeFiles/detector.dir/detector.cpp.s

CMakeFiles/detector.dir/detector.cpp.o.requires:
.PHONY : CMakeFiles/detector.dir/detector.cpp.o.requires

CMakeFiles/detector.dir/detector.cpp.o.provides: CMakeFiles/detector.dir/detector.cpp.o.requires
	$(MAKE) -f CMakeFiles/detector.dir/build.make CMakeFiles/detector.dir/detector.cpp.o.provides.build
.PHONY : CMakeFiles/detector.dir/detector.cpp.o.provides

CMakeFiles/detector.dir/detector.cpp.o.provides.build: CMakeFiles/detector.dir/detector.cpp.o

CMakeFiles/detector.dir/color_extractor.cpp.o: CMakeFiles/detector.dir/flags.make
CMakeFiles/detector.dir/color_extractor.cpp.o: ../color_extractor.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/kristjan/FRI/TV/Project/build/CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/detector.dir/color_extractor.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/detector.dir/color_extractor.cpp.o -c /home/kristjan/FRI/TV/Project/color_extractor.cpp

CMakeFiles/detector.dir/color_extractor.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/detector.dir/color_extractor.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/kristjan/FRI/TV/Project/color_extractor.cpp > CMakeFiles/detector.dir/color_extractor.cpp.i

CMakeFiles/detector.dir/color_extractor.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/detector.dir/color_extractor.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/kristjan/FRI/TV/Project/color_extractor.cpp -o CMakeFiles/detector.dir/color_extractor.cpp.s

CMakeFiles/detector.dir/color_extractor.cpp.o.requires:
.PHONY : CMakeFiles/detector.dir/color_extractor.cpp.o.requires

CMakeFiles/detector.dir/color_extractor.cpp.o.provides: CMakeFiles/detector.dir/color_extractor.cpp.o.requires
	$(MAKE) -f CMakeFiles/detector.dir/build.make CMakeFiles/detector.dir/color_extractor.cpp.o.provides.build
.PHONY : CMakeFiles/detector.dir/color_extractor.cpp.o.provides

CMakeFiles/detector.dir/color_extractor.cpp.o.provides.build: CMakeFiles/detector.dir/color_extractor.cpp.o

CMakeFiles/detector.dir/hand_tracker.cpp.o: CMakeFiles/detector.dir/flags.make
CMakeFiles/detector.dir/hand_tracker.cpp.o: ../hand_tracker.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/kristjan/FRI/TV/Project/build/CMakeFiles $(CMAKE_PROGRESS_3)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/detector.dir/hand_tracker.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/detector.dir/hand_tracker.cpp.o -c /home/kristjan/FRI/TV/Project/hand_tracker.cpp

CMakeFiles/detector.dir/hand_tracker.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/detector.dir/hand_tracker.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/kristjan/FRI/TV/Project/hand_tracker.cpp > CMakeFiles/detector.dir/hand_tracker.cpp.i

CMakeFiles/detector.dir/hand_tracker.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/detector.dir/hand_tracker.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/kristjan/FRI/TV/Project/hand_tracker.cpp -o CMakeFiles/detector.dir/hand_tracker.cpp.s

CMakeFiles/detector.dir/hand_tracker.cpp.o.requires:
.PHONY : CMakeFiles/detector.dir/hand_tracker.cpp.o.requires

CMakeFiles/detector.dir/hand_tracker.cpp.o.provides: CMakeFiles/detector.dir/hand_tracker.cpp.o.requires
	$(MAKE) -f CMakeFiles/detector.dir/build.make CMakeFiles/detector.dir/hand_tracker.cpp.o.provides.build
.PHONY : CMakeFiles/detector.dir/hand_tracker.cpp.o.provides

CMakeFiles/detector.dir/hand_tracker.cpp.o.provides.build: CMakeFiles/detector.dir/hand_tracker.cpp.o

# Object files for target detector
detector_OBJECTS = \
"CMakeFiles/detector.dir/detector.cpp.o" \
"CMakeFiles/detector.dir/color_extractor.cpp.o" \
"CMakeFiles/detector.dir/hand_tracker.cpp.o"

# External object files for target detector
detector_EXTERNAL_OBJECTS =

detector: CMakeFiles/detector.dir/detector.cpp.o
detector: CMakeFiles/detector.dir/color_extractor.cpp.o
detector: CMakeFiles/detector.dir/hand_tracker.cpp.o
detector: CMakeFiles/detector.dir/build.make
detector: /usr/local/lib/libopencv_xphoto.so.3.1.0
detector: /usr/local/lib/libopencv_xobjdetect.so.3.1.0
detector: /usr/local/lib/libopencv_ximgproc.so.3.1.0
detector: /usr/local/lib/libopencv_xfeatures2d.so.3.1.0
detector: /usr/local/lib/libopencv_tracking.so.3.1.0
detector: /usr/local/lib/libopencv_text.so.3.1.0
detector: /usr/local/lib/libopencv_surface_matching.so.3.1.0
detector: /usr/local/lib/libopencv_structured_light.so.3.1.0
detector: /usr/local/lib/libopencv_stereo.so.3.1.0
detector: /usr/local/lib/libopencv_saliency.so.3.1.0
detector: /usr/local/lib/libopencv_rgbd.so.3.1.0
detector: /usr/local/lib/libopencv_reg.so.3.1.0
detector: /usr/local/lib/libopencv_plot.so.3.1.0
detector: /usr/local/lib/libopencv_optflow.so.3.1.0
detector: /usr/local/lib/libopencv_line_descriptor.so.3.1.0
detector: /usr/local/lib/libopencv_fuzzy.so.3.1.0
detector: /usr/local/lib/libopencv_face.so.3.1.0
detector: /usr/local/lib/libopencv_dpm.so.3.1.0
detector: /usr/local/lib/libopencv_dnn.so.3.1.0
detector: /usr/local/lib/libopencv_datasets.so.3.1.0
detector: /usr/local/lib/libopencv_ccalib.so.3.1.0
detector: /usr/local/lib/libopencv_bioinspired.so.3.1.0
detector: /usr/local/lib/libopencv_bgsegm.so.3.1.0
detector: /usr/local/lib/libopencv_aruco.so.3.1.0
detector: /usr/local/lib/libopencv_videostab.so.3.1.0
detector: /usr/local/lib/libopencv_videoio.so.3.1.0
detector: /usr/local/lib/libopencv_video.so.3.1.0
detector: /usr/local/lib/libopencv_superres.so.3.1.0
detector: /usr/local/lib/libopencv_stitching.so.3.1.0
detector: /usr/local/lib/libopencv_shape.so.3.1.0
detector: /usr/local/lib/libopencv_photo.so.3.1.0
detector: /usr/local/lib/libopencv_objdetect.so.3.1.0
detector: /usr/local/lib/libopencv_ml.so.3.1.0
detector: /usr/local/lib/libopencv_imgproc.so.3.1.0
detector: /usr/local/lib/libopencv_imgcodecs.so.3.1.0
detector: /usr/local/lib/libopencv_highgui.so.3.1.0
detector: /usr/local/lib/libopencv_flann.so.3.1.0
detector: /usr/local/lib/libopencv_features2d.so.3.1.0
detector: /usr/local/lib/libopencv_core.so.3.1.0
detector: /usr/local/lib/libopencv_calib3d.so.3.1.0
detector: /usr/local/lib/libopencv_text.so.3.1.0
detector: /usr/local/lib/libopencv_face.so.3.1.0
detector: /usr/local/lib/libopencv_ximgproc.so.3.1.0
detector: /usr/local/lib/libopencv_xfeatures2d.so.3.1.0
detector: /usr/local/lib/libopencv_shape.so.3.1.0
detector: /usr/local/lib/libopencv_video.so.3.1.0
detector: /usr/local/lib/libopencv_objdetect.so.3.1.0
detector: /usr/local/lib/libopencv_calib3d.so.3.1.0
detector: /usr/local/lib/libopencv_features2d.so.3.1.0
detector: /usr/local/lib/libopencv_ml.so.3.1.0
detector: /usr/local/lib/libopencv_highgui.so.3.1.0
detector: /usr/local/lib/libopencv_videoio.so.3.1.0
detector: /usr/local/lib/libopencv_imgcodecs.so.3.1.0
detector: /usr/local/lib/libopencv_imgproc.so.3.1.0
detector: /usr/local/lib/libopencv_flann.so.3.1.0
detector: /usr/local/lib/libopencv_core.so.3.1.0
detector: CMakeFiles/detector.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable detector"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/detector.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/detector.dir/build: detector
.PHONY : CMakeFiles/detector.dir/build

CMakeFiles/detector.dir/requires: CMakeFiles/detector.dir/detector.cpp.o.requires
CMakeFiles/detector.dir/requires: CMakeFiles/detector.dir/color_extractor.cpp.o.requires
CMakeFiles/detector.dir/requires: CMakeFiles/detector.dir/hand_tracker.cpp.o.requires
.PHONY : CMakeFiles/detector.dir/requires

CMakeFiles/detector.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/detector.dir/cmake_clean.cmake
.PHONY : CMakeFiles/detector.dir/clean

CMakeFiles/detector.dir/depend:
	cd /home/kristjan/FRI/TV/Project/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/kristjan/FRI/TV/Project /home/kristjan/FRI/TV/Project /home/kristjan/FRI/TV/Project/build /home/kristjan/FRI/TV/Project/build /home/kristjan/FRI/TV/Project/build/CMakeFiles/detector.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/detector.dir/depend

