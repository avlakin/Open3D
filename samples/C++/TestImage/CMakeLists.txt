project(TestImage)
add_executable(${PROJECT_NAME} TestImage.cpp)
target_include_directories(${PROJECT_NAME} PRIVATE "${CMAKE_SOURCE_DIR}/modules/Core/include")
target_include_directories(${PROJECT_NAME} PRIVATE "${CMAKE_SOURCE_DIR}/modules/IO/include")
target_link_libraries(${PROJECT_NAME} Core IO)
set_target_properties(${PROJECT_NAME} PROPERTIES
		FOLDER "samples/test"
		RUNTIME_OUTPUT_DIRECTORY "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/Test")

