project(ManuallyCropPointCloud)
add_executable(${PROJECT_NAME} ManuallyCropPointCloud.cpp)
target_include_directories(${PROJECT_NAME} PRIVATE "${CMAKE_SOURCE_DIR}/modules/Core/include")
target_include_directories(${PROJECT_NAME} PRIVATE "${CMAKE_SOURCE_DIR}/modules/IO/include")
target_include_directories(${PROJECT_NAME} PRIVATE "${CMAKE_SOURCE_DIR}/modules/Visualization/include")
target_link_libraries(${PROJECT_NAME} Visualization Core IO)
set_target_properties(${PROJECT_NAME} PROPERTIES FOLDER "samples/tools")
 
