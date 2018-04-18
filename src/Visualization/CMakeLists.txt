# some black magic to automatically create a header file from shader files
file(GLOB SHADER_FILES "Shader/GLSL/*.glsl")
add_custom_command(
	OUTPUT ${CMAKE_SOURCE_DIR}/Visualization/Shader/Shader.h
	COMMAND EncodeShader Shader.h
	WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/Visualization/Shader/
	DEPENDS ${SHADER_FILES} EncodeShader
)
foreach(file ${SHADER_FILES})
	add_custom_command(
		OUTPUT ${CMAKE_SOURCE_DIR}/Visualization/Shader/Shader.h
		COMMAND EncodeShader Shader.h ${file}
		WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/Visualization/Shader/
		DEPENDS ${SHADER_FILES} EncodeShader
		APPEND
	)
endforeach(file)
project(ShaderFileTarget)
add_custom_target(${PROJECT_NAME} ALL
DEPENDS ${CMAKE_SOURCE_DIR}/Visualization/Shader/Shader.h)
set_target_properties(${PROJECT_NAME} PROPERTIES FOLDER "utils")

source_group("Source Files\\Shader\\GLSL" FILES ${SHADER_FILES})
file(GLOB VISUALIZATION_ALL_HEADER_FILES "*.h")
file(GLOB VISUALIZATION_ALL_SOURCE_FILES "*.cpp")
file(GLOB VISUALIZATION_UTILITY_HEADER_FILES "Utility/*.h")
source_group("Header Files\\Utility" FILES ${VISUALIZATION_UTILITY_HEADER_FILES})
file(GLOB VISUALIZATION_UTILITY_SOURCE_FILES "Utility/*.cpp")
source_group("Source Files\\Utility" FILES ${VISUALIZATION_UTILITY_SOURCE_FILES})
file(GLOB VISUALIZATION_SHADER_HEADER_FILES "Shader/*.h")
source_group("Header Files\\Shader" FILES ${VISUALIZATION_SHADER_HEADER_FILES})
file(GLOB VISUALIZATION_SHADER_SOURCE_FILES "Shader/*.cpp")
source_group("Source Files\\Shader" FILES ${VISUALIZATION_SHADER_SOURCE_FILES})
file(GLOB VISUALIZATION_VISUALIZER_HEADER_FILES "Visualizer/*.h")
source_group("Header Files\\Visualizer" FILES ${VISUALIZATION_VISUALIZER_HEADER_FILES})
file(GLOB VISUALIZATION_VISUALIZER_SOURCE_FILES "Visualizer/*.cpp")
source_group("Source Files\\Visualizer" FILES ${VISUALIZATION_VISUALIZER_SOURCE_FILES})

project(Visualization)
add_library(${PROJECT_NAME}
	${SHADER_FILES}
	${VISUALIZATION_ALL_HEADER_FILES} ${VISUALIZATION_ALL_SOURCE_FILES}
	${VISUALIZATION_UTILITY_HEADER_FILES} ${VISUALIZATION_UTILITY_SOURCE_FILES}
	${VISUALIZATION_SHADER_HEADER_FILES} ${VISUALIZATION_SHADER_SOURCE_FILES}
	${VISUALIZATION_VISUALIZER_HEADER_FILES} ${VISUALIZATION_VISUALIZER_SOURCE_FILES}
)
add_dependencies(${PROJECT_NAME} ShaderFileTarget)
target_link_libraries(${PROJECT_NAME} Core IO ${GLFW_LIBRARIES} ${GLEW_LIBRARIES})

if (OPEN3D_HEADLESS_RENDERING)
	find_package(OSMesa REQUIRED)
	include_directories(${OSMESA_INCLUDE_DIR})
	target_link_libraries(${PROJECT_NAME} ${OSMESA_LIBRARY})
else ()
	find_package(OpenGL REQUIRED)
	target_link_libraries(${PROJECT_NAME} ${OPENGL_LIBRARIES})
endif ()
set_target_properties(${PROJECT_NAME} PROPERTIES FOLDER "modules" OUTPUT_NAME "${CMAKE_PROJECT_NAME}${PROJECT_NAME}-${OPEN3D_VERSION}")
