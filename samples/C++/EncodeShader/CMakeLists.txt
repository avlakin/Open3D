project(EncodeShader)
add_executable(${PROJECT_NAME} EncodeShader.cpp)
set_target_properties(${PROJECT_NAME} PROPERTIES FOLDER "samples/tools")
set_runtime_output_directory(${PROJECT_NAME} "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/Tools")
