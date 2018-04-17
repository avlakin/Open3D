# Require Python.
find_package(PythonInterp REQUIRED)

file(GLOB PY_ALL_HEADER_FILES "*.h")
file(GLOB PY_ALL_SOURCE_FILES "*.cpp")
file(GLOB PY_CORE_HEADER_FILES "Core/*.h")
source_group("Header Files\\Core" FILES ${PY_CORE_HEADER_FILES})
file(GLOB PY_CORE_SOURCE_FILES "Core/*.cpp")
source_group("Source Files\\Core" FILES ${PY_CORE_SOURCE_FILES})
file(GLOB PY_IO_HEADER_FILES "IO/*.h")
source_group("Header Files\\IO" FILES ${PY_IO_HEADER_FILES})
file(GLOB PY_IO_SOURCE_FILES "IO/*.cpp")
source_group("Source Files\\IO" FILES ${PY_IO_SOURCE_FILES})
file(GLOB PY_VISUALIZATION_HEADER_FILES "Visualization/*.h")
source_group("Header Files\\Visualization" FILES ${PY_VISUALIZATION_HEADER_FILES})
file(GLOB PY_VISUALIZATION_SOURCE_FILES "Visualization/*.cpp")
source_group("Source Files\\Visualization" FILES ${PY_VISUALIZATION_SOURCE_FILES})

# find the python site-packages location
execute_process(COMMAND ${PYTHON_EXECUTABLE} -m site --user-site OUTPUT_VARIABLE PYTHON_SITE_PACKAGES OUTPUT_STRIP_TRAILING_WHITESPACE)

project(open3d)
pybind11_add_module(${PROJECT_NAME}
	${PY_ALL_HEADER_FILES} ${PY_ALL_SOURCE_FILES}
	${PY_CORE_SOURCE_FILES} ${PY_CORE_HEADER_FILES}
	${PY_IO_SOURCE_FILES} ${PY_IO_HEADER_FILES}
	${PY_VISUALIZATION_SOURCE_FILES} ${PY_VISUALIZATION_HEADER_FILES}
)
target_link_libraries(${PROJECT_NAME} PRIVATE Core IO Visualization)

# configure installer to copy the python module to the python site-packages
install(TARGETS ${PROJECT_NAME} DESTINATION ${PYTHON_SITE_PACKAGES})

file(GLOB PY_HELPER_FILES "Helper/*.py")
project(PythonHelper)
add_custom_target(${PROJECT_NAME} ALL SOURCES ${PY_HELPER_FILES})
set_target_properties(${PROJECT_NAME} PROPERTIES FOLDER "Python")
add_custom_command(TARGET PythonHelper POST_BUILD
COMMAND ${CMAKE_COMMAND} -E copy_directory "${CMAKE_SOURCE_DIR}/Python/Helper/" "${CMAKE_LIBRARY_OUTPUT_DIRECTORY}/${CMAKE_CFG_INTDIR}")
add_dependencies(${PROJECT_NAME} PythonHelper)

if (OPEN3D_BUILD_PYTHON_BINDING_TESTS)
	file(GLOB PY_TEST_FILES "Test/*.py")
	project(PythonTest)
add_custom_target(${PROJECT_NAME} ALL SOURCES ${PY_TEST_FILES})
	set_target_properties(${PROJECT_NAME} PROPERTIES FOLDER "Python")
	add_custom_command(TARGET PythonTest POST_BUILD
		COMMAND ${CMAKE_COMMAND} -E copy_directory "${CMAKE_SOURCE_DIR}/Python/Test/" "${CMAKE_LIBRARY_OUTPUT_DIRECTORY}/${CMAKE_CFG_INTDIR}/Test")
	add_custom_command(TARGET PythonTest POST_BUILD
		COMMAND ${CMAKE_COMMAND} -E copy_directory "${CMAKE_SOURCE_DIR}/Test/TestData/" "${CMAKE_LIBRARY_OUTPUT_DIRECTORY}/${CMAKE_CFG_INTDIR}/TestData")
	add_dependencies(${PROJECT_NAME} PythonTest)
endif(OPEN3D_BUILD_PYTHON_BINDING_TESTS)

if (OPEN3D_BUILD_PYTHON_BINDING_TUTORIALS)
	file(GLOB PY_BASIC_TUTORIAL_FILES "Tutorial/Basic/*.py")
	source_group("Basic" FILES ${PY_BASIC_TUTORIAL_FILES})
	file(GLOB PY_ADVANCED_TUTORIAL_FILES "Tutorial/Advanced/*.py")
	source_group("Advanced" FILES ${PY_ADVANCED_TUTORIAL_FILES})
	file(GLOB PY_APPLICATION_TUTORIAL_FILES "Tutorial/Application/*.py")
	source_group("Application" FILES ${PY_APPLICATION_TUTORIAL_FILES})
	file(GLOB PY_RECONSTRUCTION_SYSTEM_TUTORIAL_FILES "Tutorial/ReconstructionSystem/*.py")
	source_group("ReconstructionSystem" FILES ${PY_RECONSTRUCTION_SYSTEM_TUTORIAL_FILES})
	project(PythonTutorial)
add_custom_target(${PROJECT_NAME} ALL SOURCES ${PY_BASIC_TUTORIAL_FILES} ${PY_ADVANCED_TUTORIAL_FILES} ${PY_APPLICATION_TUTORIAL_FILES} ${PY_RECONSTRUCTION_SYSTEM_TUTORIAL_FILES})
	set_target_properties(${PROJECT_NAME} PROPERTIES FOLDER "Python")
	add_custom_command(TARGET PythonTutorial POST_BUILD
		COMMAND ${CMAKE_COMMAND} -E copy_directory "${CMAKE_SOURCE_DIR}/Python/Tutorial/" "${CMAKE_LIBRARY_OUTPUT_DIRECTORY}/${CMAKE_CFG_INTDIR}/Tutorial")
	if (NOT OPEN3D_BUILD_PYTHON_BINDING_TESTS)
		add_custom_command(TARGET PythonTutorial POST_BUILD
			COMMAND ${CMAKE_COMMAND} -E copy_directory "${CMAKE_SOURCE_DIR}/Test/TestData/" "${CMAKE_LIBRARY_OUTPUT_DIRECTORY}/${CMAKE_CFG_INTDIR}/TestData")
	endif (NOT OPEN3D_BUILD_PYTHON_BINDING_TESTS)
	add_dependencies(${PROJECT_NAME} PythonTutorial)
endif(OPEN3D_BUILD_PYTHON_BINDING_TUTORIALS)
