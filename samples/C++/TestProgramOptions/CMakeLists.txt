project(TestProgramOptions)
add_executable(${PROJECT_NAME} TestProgramOptions.cpp)
target_include_directories(${PROJECT_NAME} PRIVATE "${CMAKE_SOURCE_DIR}/modules/Core/include")
target_link_libraries(${PROJECT_NAME} Core)
set_target_properties(${PROJECT_NAME} PROPERTIES FOLDER "samples/test")
set_runtime_output_directory(${PROJECT_NAME} "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/Test")

