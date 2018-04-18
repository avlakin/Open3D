add_subdirectory(ManuallyAlignPointCloud)

project(EncodeShader)
add_executable(${PROJECT_NAME} EncodeShader.cpp)
set_target_properties(${PROJECT_NAME} PROPERTIES FOLDER "apps/tools")

project(MergeMesh)
add_executable(${PROJECT_NAME} MergeMesh.cpp)
target_link_libraries(${PROJECT_NAME} IO Core)
set_target_properties(${PROJECT_NAME} PROPERTIES FOLDER "apps/tools")

project(ConvertPointCloud)
add_executable(${PROJECT_NAME} ConvertPointCloud.cpp)
target_link_libraries(${PROJECT_NAME} IO Core)
set_target_properties(${PROJECT_NAME} PROPERTIES FOLDER "apps/tools")

project(ManuallyCropPointCloud)
add_executable(${PROJECT_NAME} ManuallyCropPointCloud.cpp)
target_link_libraries(${PROJECT_NAME} Visualization IO Core)
set_target_properties(${PROJECT_NAME} PROPERTIES FOLDER "apps/tools")

project(ViewGeometry)
add_executable(${PROJECT_NAME} ViewGeometry.cpp)
target_link_libraries(${PROJECT_NAME} Visualization IO Core)
set_target_properties(${PROJECT_NAME} PROPERTIES FOLDER "apps/tools")
