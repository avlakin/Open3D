project(TestLineSet)
add_executable(${PROJECT_NAME} TestLineSet.cpp)
target_include_directories(${PROJECT_NAME} PRIVATE "${CMAKE_SOURCE_DIR}/modules/Core/include")
target_include_directories(${PROJECT_NAME} PRIVATE "${CMAKE_SOURCE_DIR}/modules/IO/include")
target_include_directories(${PROJECT_NAME} PRIVATE "${CMAKE_SOURCE_DIR}/modules/Visualization/include")
target_link_libraries(${PROJECT_NAME} Core IO Visualization)
set_target_properties(${PROJECT_NAME} PROPERTIES FOLDER "samples/test")
set_runtime_output_directory(${PROJECT_NAME} "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/Test")

