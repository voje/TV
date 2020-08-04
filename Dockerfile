FROM ubuntu:bionic
# Heavily inspired by: https://hub.docker.com/r/schickling/opencv/dockerfile

ENV OPENCV_VERSION=3.1.0
# Set number of threads for building opencv.
ENV NPROC=2

RUN apt-get update

# Install system utils.
RUN apt-get update && apt-get install -y \
    vim \
    git

# Install OpenCV dependencies.
# (https://docs.opencv.org/trunk/d7/d9f/tutorial_linux_install.html)
RUN apt-get install -y build-essential
RUN apt-get install -y cmake git libgtk2.0-dev pkg-config libavcodec-dev libavformat-dev libswscale-dev

# Get the right OpenCV version.
RUN mkdir -p /root/git/
WORKDIR /root/git
RUN git clone https://github.com/opencv/opencv.git
WORKDIR /root/git/opencv
RUN git checkout tags/${OPENCV_VERSION} -b v${OPENCV_VERSION}

# Bulid OpenCV. Increase NPROC for a faster build.
# Go grew a cup of coffee... this will take some time.
RUN mkdir build && \
    rm -rf ./build/* && \
    cd build && \
    cmake -D CMAKE_BUILD_TYPE=Release -D CMAKE_INSTALL_PREFIX=/usr/local -DENABLE_PRECOMPILED_HEADERS=OFF .. && \
    make -j`NPROC` && \
    make install
