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
include CMakeFiles/my_threshold.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/my_threshold.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/my_threshold.dir/flags.make

CMakeFiles/my_threshold.dir/my_threshold.cpp.o: CMakeFiles/my_threshold.dir/flags.make
CMakeFiles/my_threshold.dir/my_threshold.cpp.o: ../my_threshold.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/kristjan/FRI/TV/03_barvniProstori/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/my_threshold.dir/my_threshold.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/my_threshold.dir/my_threshold.cpp.o -c /home/kristjan/FRI/TV/03_barvniProstori/my_threshold.cpp

CMakeFiles/my_threshold.dir/my_threshold.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/my_threshold.dir/my_threshold.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/kristjan/FRI/TV/03_barvniProstori/my_threshold.cpp > CMakeFiles/my_threshold.dir/my_threshold.cpp.i

CMakeFiles/my_threshold.dir/my_threshold.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/my_threshold.dir/my_threshold.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/kristjan/FRI/TV/03_barvniProstori/my_threshold.cpp -o CMakeFiles/my_threshold.dir/my_threshold.cpp.s

CMakeFiles/my_threshold.dir/my_threshold.cpp.o.requires:
.PHONY : CMakeFiles/my_threshold.dir/my_threshold.cpp.o.requires

CMakeFiles/my_threshold.dir/my_threshold.cpp.o.provides: CMakeFiles/my_threshold.dir/my_threshold.cpp.o.requires
	$(MAKE) -f CMakeFiles/my_threshold.dir/build.make CMakeFiles/my_threshold.dir/my_threshold.cpp.o.provides.build
.PHONY : CMakeFiles/my_threshold.dir/my_threshold.cpp.o.provides

CMakeFiles/my_threshold.dir/my_threshold.cpp.o.provides.build: CMakeFiles/my_threshold.dir/my_threshold.cpp.o

# Object files for target my_threshold
my_threshold_OBJECTS = \
"CMakeFiles/my_threshold.dir/my_threshold.cpp.o"

# External object files for target my_threshold
my_threshold_EXTERNAL_OBJECTS =

my_threshold: CMakeFiles/my_threshold.dir/my_threshold.cpp.o
my_threshold: CMakeFiles/my_threshold.dir/build.make
my_threshold: /usr/local/lib/libopencv_viz.so.3.1.0
my_threshold: /usr/local/lib/libopencv_videostab.so.3.1.0
my_threshold: /usr/local/lib/libopencv_videoio.so.3.1.0
my_threshold: /usr/local/lib/libopencv_video.so.3.1.0
my_threshold: /usr/local/lib/libopencv_superres.so.3.1.0
my_threshold: /usr/local/lib/libopencv_stitching.so.3.1.0
my_threshold: /usr/local/lib/libopencv_shape.so.3.1.0
my_threshold: /usr/local/lib/libopencv_photo.so.3.1.0
my_threshold: /usr/local/lib/libopencv_objdetect.so.3.1.0
my_threshold: /usr/local/lib/libopencv_ml.so.3.1.0
my_threshold: /usr/local/lib/libopencv_imgproc.so.3.1.0
my_threshold: /usr/local/lib/libopencv_imgcodecs.so.3.1.0
my_threshold: /usr/local/lib/libopencv_highgui.so.3.1.0
my_threshold: /usr/local/lib/libopencv_flann.so.3.1.0
my_threshold: /usr/local/lib/libopencv_features2d.so.3.1.0
my_threshold: /usr/local/lib/libopencv_core.so.3.1.0
my_threshold: /usr/local/lib/libopencv_calib3d.so.3.1.0
my_threshold: /usr/local/lib/libopencv_features2d.so.3.1.0
my_threshold: /usr/local/lib/libopencv_ml.so.3.1.0
my_threshold: /usr/local/lib/libopencv_highgui.so.3.1.0
my_threshold: /usr/local/lib/libopencv_videoio.so.3.1.0
my_threshold: /usr/local/lib/libopencv_imgcodecs.so.3.1.0
my_threshold: /usr/local/lib/libopencv_flann.so.3.1.0
my_threshold: /usr/local/lib/libopencv_video.so.3.1.0
my_threshold: /usr/local/lib/libopencv_imgproc.so.3.1.0
my_threshold: /usr/local/lib/libopencv_core.so.3.1.0
my_threshold: CMakeFiles/my_threshold.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable my_threshold"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/my_threshold.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/my_threshold.dir/build: my_threshold
.PHONY : CMakeFiles/my_threshold.dir/build

CMakeFiles/my_threshold.dir/requires: CMakeFiles/my_threshold.dir/my_threshold.cpp.o.requires
.PHONY : CMakeFiles/my_threshold.dir/requires

CMakeFiles/my_threshold.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/my_threshold.dir/cmake_clean.cmake
.PHONY : CMakeFiles/my_threshold.dir/clean

CMakeFiles/my_threshold.dir/depend:
	cd /home/kristjan/FRI/TV/03_barvniProstori/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/kristjan/FRI/TV/03_barvniProstori /home/kristjan/FRI/TV/03_barvniProstori /home/kristjan/FRI/TV/03_barvniProstori/build /home/kristjan/FRI/TV/03_barvniProstori/build /home/kristjan/FRI/TV/03_barvniProstori/build/CMakeFiles/my_threshold.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/my_threshold.dir/depend

