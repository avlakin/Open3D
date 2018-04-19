cmake_minimum_required(VERSION 3.0.0)

if (NOT CMAKE_VERSION VERSION_LESS "3.0")
    cmake_policy(SET CMP0054 OLD)
endif()

project(open3d)

set(OPEN3D_VERSION_MAJOR "0")
set(OPEN3D_VERSION_MINOR "1")
set(OPEN3D_VERSION_PATCH "1")
set(OPEN3D_VERSION "${OPEN3D_VERSION_MAJOR}.${OPEN3D_VERSION_MINOR}.${OPEN3D_VERSION_PATCH}")

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_SOURCE_DIR}/cmake)
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

# config options
option(BUILD_SHARED_LIBS "Build shared libraries (.dll/.so) instead of static ones (.lib/.a)" OFF)
option(OPEN3D_BUILD_TESTS "Build the Open3D test programs" ON)
option(OPEN3D_BUILD_LIBREALSENSE "Build support for Intel RealSense camera" ON)
option(OPEN3D_USE_OPENMP "Use OpenMP multi-threading" ON)
option(OPEN3D_BUILD_PYTHON_BINDING "Build Python binding for Open3D" ON)
option(OPEN3D_BUILD_PYTHON_BINDING_TESTS "Copy test files for Open3D Python binding" ON)
option(OPEN3D_BUILD_PYTHON_BINDING_TUTORIALS "Copy tutorial files for Open3D Python binding" ON)
option(OPEN3D_HEADLESS_RENDERING "Use OSMesa for headless rendering" OFF)

# default built type
if(NOT CMAKE_BUILD_TYPE)
	set(CMAKE_BUILD_TYPE Release CACHE STRING
		"Choose the type of build, options are: None Debug Release RelWithDebInfo MinSizeRel."
		FORCE)
endif(NOT CMAKE_BUILD_TYPE)

# set include directories
include_directories(
	${CMAKE_SOURCE_DIR}/src
	${CMAKE_SOURCE_DIR}/3rdparty
	${CMAKE_SOURCE_DIR}/3rdparty/librealsense/include
	)

# if dynamic link is added, use if (WIN32) macro
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Set OS-specific things here
if(WIN32)
	message(STATUS "Compiling on Windows")
	add_definitions(-DWINDOWS)
	add_definitions(-D_CRT_SECURE_NO_DEPRECATE -D_CRT_NONSTDC_NO_DEPRECATE -D_SCL_SECURE_NO_WARNINGS)		# suppress C4996 warning
	add_definitions(-DGLEW_STATIC)		# enable GLEW for windows
	SET(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON) #Enable building DLLs
	if(MSVC)
		message(STATUS "Compiling with MSVC")
		add_definitions(-DNOMINMAX)
		add_definitions(-D_USE_MATH_DEFINES)
		SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /EHsc")
	endif(MSVC)
elseif(CYGWIN)
	message(STATUS "Compiling on Cygwin")
	# enable c++11
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
	add_definitions(-DCYGWIN)
	SET(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON) #Enable building DLLs
elseif(APPLE)
	add_definitions(-DUNIX)
	# enable c++11
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
	if (NOT ${BUILD_SHARED_LIBS})
		set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fvisibility=hidden")
	endif()
	# compile speed optimization for clang
	add_definitions(-O3)
elseif(UNIX)
	add_definitions(-DUNIX)
	# enable c++11
	set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fPIC")
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -fPIC")
	add_compile_options(-Wno-deprecated-declarations)
	add_compile_options(-Wno-unused-result)
	add_definitions(-O3)
	# disable BUILD_LIBREALSENSE since it is not fully supported on Linux
	message(STATUS "Compiling on Unix")
	message(STATUS "Disable BUILD_LIBREALSENSE since it is not fully supported on Linux.")
	set(OPEN3D_BUILD_LIBREALSENSE OFF)
endif(WIN32)

# Set OpenMP
message(STATUS "OPEN3D_USE_OPENMP=${OPEN3D_USE_OPENMP}")
if (OPEN3D_USE_OPENMP)
	find_package(OpenMP)
	if(OPENMP_FOUND)
		set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${OpenMP_C_FLAGS}")
		set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS}")
		set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} ${OpenMP_EXE_LINKER_FLAGS}")
	else()
		message(STATUS "OpenMP NOT found")
	endif()
endif()

message(STATUS "OPEN3D_BUILD_LIBREALSENSE=${OPEN3D_BUILD_LIBREALSENSE}")
message(STATUS "OPEN3D_BUILD_PYTHON_BINDING=${OPEN3D_BUILD_PYTHON_BINDING}")
message(STATUS "OPEN3D_BUILD_PYTHON_BINDING_TESTS=${OPEN3D_BUILD_PYTHON_BINDING_TESTS}")

# Handling dependencies
add_subdirectory(3rdparty)
include_directories(${EIGEN3_INCLUDE_DIRS})
include_directories(${GLEW_INCLUDE_DIRS})
include_directories(${GLFW_INCLUDE_DIRS})
include_directories(${JSONCPP_INCLUDE_DIRS})
link_directories(${GLFW_LIBRARY_DIRS})
link_directories(${JSONCPP_LIBRARY_DIRS})

# Open3D libraries
add_subdirectory("${CMAKE_SOURCE_DIR}/modules/Core")
add_subdirectory("${CMAKE_SOURCE_DIR}/modules/IO")
add_subdirectory("${CMAKE_SOURCE_DIR}/src/Visualization")
add_subdirectory("${CMAKE_SOURCE_DIR}/src/Tools")
if(OPEN3D_BUILD_TESTS)
	add_subdirectory("${CMAKE_SOURCE_DIR}/src/Test")
endif(OPEN3D_BUILD_TESTS)

if(EXISTS "${CMAKE_SOURCE_DIR}/src/Experimental/CMakeLists.txt")
	message(STATUS "Build experimental projects")
	add_subdirectory(src/Experimental)
endif(EXISTS "${CMAKE_SOURCE_DIR}/src/Experimental/CMakeLists.txt")

# Python binding
if (OPEN3D_BUILD_PYTHON_BINDING)
	add_subdirectory(src/Python)
endif(OPEN3D_BUILD_PYTHON_BINDING)
