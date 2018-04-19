file(GLOB HEADER_FILES "*.h")
file(GLOB SOURCE_FILES "*.cpp")
project(TrimMeshBasedOnPointCloud)
add_executable(${PROJECT_NAME} ${HEADER_FILES} ${SOURCE_FILES})
target_include_directories(${PROJECT_NAME} PRIVATE "${CMAKE_SOURCE_DIR}/modules/Core/include")
target_include_directories(${PROJECT_NAME} PRIVATE "${CMAKE_SOURCE_DIR}/modules/IO/include")
target_link_libraries(${PROJECT_NAME} Core IO Visualization)
set_target_properties(${PROJECT_NAME} PROPERTIES
		FOLDER "apps/experimental"
	RUNTIME_OUTPUT_DIRECTORY "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/Experimental")
