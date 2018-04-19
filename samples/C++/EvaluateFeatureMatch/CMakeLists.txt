file(GLOB SOURCE_FILES "*.cpp")
project(EvaluateFeatureMatch)
add_executable(${PROJECT_NAME} ${SOURCE_FILES})
target_include_directories(${PROJECT_NAME} PRIVATE "${CMAKE_SOURCE_DIR}/modules/Core/include")
target_include_directories(${PROJECT_NAME} PRIVATE "${CMAKE_SOURCE_DIR}/modules/IO/include")
target_include_directories(${PROJECT_NAME} PRIVATE "${CMAKE_SOURCE_DIR}/modules/Visualization/include")
target_link_libraries(${PROJECT_NAME} Core IO Visualization)
set_target_properties(${PROJECT_NAME} PROPERTIES
		FOLDER "samples/experimental"
	RUNTIME_OUTPUT_DIRECTORY "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/Experimental")
