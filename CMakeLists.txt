cmake_minimum_required(VERSION 2.8)
project( RFS-VISUAL-SLAM )
SET (CMAKE_CXX_COMPILER             "/usr/bin/g++")
SET (CMAKE_CXX_FLAGS                "-Wall -std=c++11")
SET (CMAKE_CXX_FLAGS_DEBUG          "-g")
SET (CMAKE_CXX_FLAGS_MINSIZEREL     "-Os -DNDEBUG")
SET (CMAKE_CXX_FLAGS_RELEASE        "-O4 -DNDEBUG")
SET (CMAKE_CXX_FLAGS_RELWITHDEBINFO "-O2 -g")
set(Boost_USE_STATIC_LIBS OFF)
set(Boost_USE_MULTITHREADED ON)
set(Boost_USE_STATIC_RUNTIME ON)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)
include_directories(${Boost_INCLUDE_DIR})
link_directories(${CMAKE_CURRENT_SOURCE_DIR}/src)
find_package(
	OpenCV
	REQUIRED)
find_package(
	Boost 1.40
	COMPONENTS
		program_options
		filesystem
		system
	REQUIRED)
add_executable(
	rfs-visual-slam
	src/main.cpp
	src/pose.cpp
	src/trajectory.cpp
	src/utils.cpp)
target_link_libraries(
	rfs-visual-slam
	${OpenCV_LIBS}
	${Boost_LIBRARIES})
