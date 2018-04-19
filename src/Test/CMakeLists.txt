project(TestPointCloud)
add_executable(${PROJECT_NAME} TestPointCloud.cpp)
target_include_directories(${PROJECT_NAME} PRIVATE "${CMAKE_SOURCE_DIR}/modules/Core/include")
target_include_directories(${PROJECT_NAME} PRIVATE "${CMAKE_SOURCE_DIR}/modules/IO/include")
target_link_libraries(${PROJECT_NAME} Core IO Visualization)
set_target_properties(${PROJECT_NAME} PROPERTIES
		FOLDER "apps/test"
		RUNTIME_OUTPUT_DIRECTORY "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/Test")

project(TestCameraPoseTrajectory)
add_executable(${PROJECT_NAME} TestCameraPoseTrajectory)
target_include_directories(${PROJECT_NAME} PRIVATE "${CMAKE_SOURCE_DIR}/modules/Core/include")
target_include_directories(${PROJECT_NAME} PRIVATE "${CMAKE_SOURCE_DIR}/modules/IO/include")
target_link_libraries(${PROJECT_NAME} Core IO Visualization)
set_target_properties(${PROJECT_NAME} PROPERTIES
		FOLDER "apps/test"
		RUNTIME_OUTPUT_DIRECTORY "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/Test")

project(TestLineSet)
add_executable(${PROJECT_NAME} TestLineSet.cpp)
target_include_directories(${PROJECT_NAME} PRIVATE "${CMAKE_SOURCE_DIR}/modules/Core/include")
target_include_directories(${PROJECT_NAME} PRIVATE "${CMAKE_SOURCE_DIR}/modules/IO/include")
target_link_libraries(${PROJECT_NAME} Core IO Visualization)
set_target_properties(${PROJECT_NAME} PROPERTIES
		FOLDER "apps/test"
		RUNTIME_OUTPUT_DIRECTORY "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/Test")

project(TestTriangleMesh)
add_executable(${PROJECT_NAME} TestTriangleMesh.cpp)
target_include_directories(${PROJECT_NAME} PRIVATE "${CMAKE_SOURCE_DIR}/modules/Core/include")
target_include_directories(${PROJECT_NAME} PRIVATE "${CMAKE_SOURCE_DIR}/modules/IO/include")
target_link_libraries(${PROJECT_NAME} Core IO Visualization)
set_target_properties(${PROJECT_NAME} PROPERTIES
		FOLDER "apps/test"
		RUNTIME_OUTPUT_DIRECTORY "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/Test")

project(TestVisualizer)
add_executable(${PROJECT_NAME} TestVisualizer.cpp)
target_include_directories(${PROJECT_NAME} PRIVATE "${CMAKE_SOURCE_DIR}/modules/Core/include")
target_include_directories(${PROJECT_NAME} PRIVATE "${CMAKE_SOURCE_DIR}/modules/IO/include")
target_link_libraries(${PROJECT_NAME} Core IO Visualization)
set_target_properties(${PROJECT_NAME} PROPERTIES
		FOLDER "apps/test"
		RUNTIME_OUTPUT_DIRECTORY "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/Test")

project(TestOpenMP)
add_executable(${PROJECT_NAME} TestOpenMP.cpp)
target_include_directories(${PROJECT_NAME} PRIVATE "${CMAKE_SOURCE_DIR}/modules/Core/include")
target_link_libraries(${PROJECT_NAME} Core)
set_target_properties(${PROJECT_NAME} PROPERTIES
		FOLDER "apps/test"
		RUNTIME_OUTPUT_DIRECTORY "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/Test")

project(TestFlann)
add_executable(${PROJECT_NAME} TestFlann.cpp)
target_include_directories(${PROJECT_NAME} PRIVATE "${CMAKE_SOURCE_DIR}/modules/Core/include")
target_include_directories(${PROJECT_NAME} PRIVATE "${CMAKE_SOURCE_DIR}/modules/IO/include")
target_link_libraries(${PROJECT_NAME} Core IO Visualization)
set_target_properties(${PROJECT_NAME} PROPERTIES
		FOLDER "apps/test"
		RUNTIME_OUTPUT_DIRECTORY "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/Test")

project(TestFileSystem)
add_executable(${PROJECT_NAME} TestFileSystem.cpp)
target_include_directories(${PROJECT_NAME} PRIVATE "${CMAKE_SOURCE_DIR}/modules/Core/include")
target_include_directories(${PROJECT_NAME} PRIVATE "${CMAKE_SOURCE_DIR}/modules/IO/include")
target_link_libraries(${PROJECT_NAME} Core IO)
set_target_properties(${PROJECT_NAME} PROPERTIES
		FOLDER "apps/test"
		RUNTIME_OUTPUT_DIRECTORY "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/Test")

project(TestProgramOptions)
add_executable(${PROJECT_NAME} TestProgramOptions.cpp)
target_include_directories(${PROJECT_NAME} PRIVATE "${CMAKE_SOURCE_DIR}/modules/Core/include")
target_link_libraries(${PROJECT_NAME} Core)
set_target_properties(${PROJECT_NAME} PROPERTIES
		FOLDER "apps/test"
		RUNTIME_OUTPUT_DIRECTORY "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/Test")

project(TestDepthCapture)
add_executable(${PROJECT_NAME} TestDepthCapture.cpp)
target_include_directories(${PROJECT_NAME} PRIVATE "${CMAKE_SOURCE_DIR}/modules/Core/include")
target_include_directories(${PROJECT_NAME} PRIVATE "${CMAKE_SOURCE_DIR}/modules/IO/include")
target_link_libraries(${PROJECT_NAME} Core Visualization IO)
set_target_properties(${PROJECT_NAME} PROPERTIES
		FOLDER "apps/test"
		RUNTIME_OUTPUT_DIRECTORY "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/Test")

project(TestPCDFileFormat)
add_executable(${PROJECT_NAME} TestPCDFileFormat.cpp)
target_include_directories(${PROJECT_NAME} PRIVATE "${CMAKE_SOURCE_DIR}/modules/Core/include")
target_include_directories(${PROJECT_NAME} PRIVATE "${CMAKE_SOURCE_DIR}/modules/IO/include")
target_link_libraries(${PROJECT_NAME} Core Visualization IO)
set_target_properties(${PROJECT_NAME} PROPERTIES
		FOLDER "apps/test"
		RUNTIME_OUTPUT_DIRECTORY "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/Test")

project(TestFileDialog)
add_executable(${PROJECT_NAME} TestFileDialog.cpp)
target_include_directories(${PROJECT_NAME} PRIVATE "${CMAKE_SOURCE_DIR}/modules/Core/include")
target_include_directories(${PROJECT_NAME} PRIVATE "${CMAKE_SOURCE_DIR}/modules/IO/include")
target_link_libraries(${PROJECT_NAME} Core IO tinyfiledialogs)
set_target_properties(${PROJECT_NAME} PROPERTIES
		FOLDER "apps/test"
		RUNTIME_OUTPUT_DIRECTORY "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/Test")

project(TestImage)
add_executable(${PROJECT_NAME} TestImage.cpp)
target_include_directories(${PROJECT_NAME} PRIVATE "${CMAKE_SOURCE_DIR}/modules/Core/include")
target_include_directories(${PROJECT_NAME} PRIVATE "${CMAKE_SOURCE_DIR}/modules/IO/include")
target_link_libraries(${PROJECT_NAME} Core IO)
set_target_properties(${PROJECT_NAME} PROPERTIES
		FOLDER "apps/test"
		RUNTIME_OUTPUT_DIRECTORY "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/Test")

project(TestPoseGraph)
add_executable(${PROJECT_NAME} TestPoseGraph.cpp)
target_include_directories(${PROJECT_NAME} PRIVATE "${CMAKE_SOURCE_DIR}/modules/Core/include")
target_include_directories(${PROJECT_NAME} PRIVATE "${CMAKE_SOURCE_DIR}/modules/IO/include")
target_link_libraries(${PROJECT_NAME} Core IO)
set_target_properties(${PROJECT_NAME} PROPERTIES
		FOLDER "apps/test"
		RUNTIME_OUTPUT_DIRECTORY "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/Test")

project(TestRegistrationRANSAC)
add_executable(${PROJECT_NAME} TestRegistrationRANSAC.cpp)
target_include_directories(${PROJECT_NAME} PRIVATE "${CMAKE_SOURCE_DIR}/modules/Core/include")
target_include_directories(${PROJECT_NAME} PRIVATE "${CMAKE_SOURCE_DIR}/modules/IO/include")
target_link_libraries(${PROJECT_NAME} Core IO Visualization)
set_target_properties(${PROJECT_NAME} PROPERTIES
		FOLDER "apps/test"
		RUNTIME_OUTPUT_DIRECTORY "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/Test")

if(OPEN3D_BUILD_LIBREALSENSE)
    project(TestRealSense)
    add_executable(${PROJECT_NAME} TestRealSense.cpp)
    target_include_directories(${PROJECT_NAME} PRIVATE "${CMAKE_SOURCE_DIR}/modules/Core/include")
    target_link_libraries(${PROJECT_NAME} Core Visualization realsense)
    set_target_properties(${PROJECT_NAME} PROPERTIES
			FOLDER "apps/test"
			RUNTIME_OUTPUT_DIRECTORY "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/Test")
endif(OPEN3D_BUILD_LIBREALSENSE)
