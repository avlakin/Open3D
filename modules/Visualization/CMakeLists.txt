# some black magic to automatically create a header file from shader files
file(GLOB SHADER_FILES "${CMAKE_SOURCE_DIR}/modules/Visualization/src/Shader/GLSL/*.glsl")
SET(SHADER_OUTPUT_DIR "${CMAKE_SOURCE_DIR}/modules/Visualization/include/Open3D/Visualization/Shader")
add_custom_command(
	OUTPUT Shader.h
	COMMAND EncodeShader Shader.h
	WORKING_DIRECTORY ${SHADER_OUTPUT_DIR}
	DEPENDS EncodeShader
)
foreach(file ${SHADER_FILES})
	add_custom_command(
		OUTPUT Shader.h
		COMMAND EncodeShader Shader.h ${file}
		WORKING_DIRECTORY ${SHADER_OUTPUT_DIR}
		DEPENDS EncodeShader
		APPEND
	)
endforeach(file)

project(VisualizationHelper)
add_custom_target(${PROJECT_NAME} ALL
DEPENDS Shader.h)
set_target_properties(${PROJECT_NAME} PROPERTIES
	FOLDER "housekeepers")

source_group("Source Files\\Shader\\GLSL" FILES ${SHADER_FILES})
file(GLOB VISUALIZATION_ALL_SOURCE_FILES "src/*.cpp")
file(GLOB VISUALIZATION_UTILITY_SOURCE_FILES "src/Utility/*.cpp")
source_group("Source Files\\Utility" FILES ${VISUALIZATION_UTILITY_SOURCE_FILES})
file(GLOB VISUALIZATION_SHADER_SOURCE_FILES "src/Shader/*.cpp")
source_group("Source Files\\Shader" FILES ${VISUALIZATION_SHADER_SOURCE_FILES})
file(GLOB VISUALIZATION_VISUALIZER_SOURCE_FILES "src/Visualizer/*.cpp")
source_group("Source Files\\Visualizer" FILES ${VISUALIZATION_VISUALIZER_SOURCE_FILES})

project(Visualization)
add_library(${PROJECT_NAME}
	${SHADER_FILES}
	${VISUALIZATION_ALL_SOURCE_FILES}
	${VISUALIZATION_UTILITY_SOURCE_FILES}
	${VISUALIZATION_SHADER_SOURCE_FILES}
	${VISUALIZATION_VISUALIZER_SOURCE_FILES}
)
target_include_directories(${PROJECT_NAME} PRIVATE "${CMAKE_SOURCE_DIR}/modules/Core/include")
target_include_directories(${PROJECT_NAME} PRIVATE "${CMAKE_SOURCE_DIR}/modules/IO/include")
target_include_directories(${PROJECT_NAME} PRIVATE "${CMAKE_SOURCE_DIR}/modules/Visualization/include")
add_dependencies(${PROJECT_NAME} VisualizationHelper)
target_link_libraries(${PROJECT_NAME} Core IO ${GLFW_LIBRARIES} ${GLEW_LIBRARIES})

if (OPEN3D_HEADLESS_RENDERING)
	find_package(OSMesa REQUIRED)
	include_directories(${OSMESA_INCLUDE_DIR})
	target_link_libraries(${PROJECT_NAME} ${OSMESA_LIBRARY})
else ()
	find_package(OpenGL REQUIRED)
	target_link_libraries(${PROJECT_NAME} ${OPENGL_LIBRARIES})
endif ()
set_target_properties(${PROJECT_NAME} PROPERTIES
	FOLDER "modules"
	OUTPUT_NAME "${CMAKE_PROJECT_NAME}${PROJECT_NAME}-${OPEN3D_VERSION}")
