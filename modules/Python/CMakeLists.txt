# Require Python.
find_package(PythonInterp REQUIRED)

file(GLOB PY_ALL_SOURCE_FILES "src/*.cpp")
file(GLOB PY_CORE_SOURCE_FILES "src/Core/*.cpp")
source_group("Source Files\\Core" FILES ${PY_CORE_SOURCE_FILES})
file(GLOB PY_IO_SOURCE_FILES "src/IO/*.cpp")
source_group("Source Files\\IO" FILES ${PY_IO_SOURCE_FILES})
file(GLOB PY_VISUALIZATION_SOURCE_FILES "src/Visualization/*.cpp")
source_group("Source Files\\Visualization" FILES ${PY_VISUALIZATION_SOURCE_FILES})

# find the python site-packages location
if (NOT PYTHON_SITE_PACKAGES)
	#set(GET_SITE_PACKAGE ${PYTHON_EXECUTABLE} -m site --user-site)
	#set(PYTHON_CODE "import site\; print([path for path in site.getsitepackages() if path.endswith('packages')][-1])")
	set(PYTHON_CODE "from distutils import sysconfig\; print(sysconfig.get_python_lib())")
	set(GET_SITE_PACKAGE ${PYTHON_EXECUTABLE} -c "${PYTHON_CODE}")
	execute_process(COMMAND ${GET_SITE_PACKAGE} OUTPUT_VARIABLE PYTHON_SITE_PACKAGES OUTPUT_STRIP_TRAILING_WHITESPACE)
	set(PYTHON_SITE_PACKAGES ${PYTHON_SITE_PACKAGES} CACHE PATH "Where to install the python packages." FORCE)
endif()

project(open3d_python)
pybind11_add_module(${PROJECT_NAME}
	${PY_ALL_SOURCE_FILES}
	${PY_CORE_SOURCE_FILES}
	${PY_IO_SOURCE_FILES}
	${PY_VISUALIZATION_SOURCE_FILES}
)
target_include_directories(${PROJECT_NAME} PRIVATE "${CMAKE_SOURCE_DIR}/modules/Core/include")
target_include_directories(${PROJECT_NAME} PRIVATE "${CMAKE_SOURCE_DIR}/modules/IO/include")
target_include_directories(${PROJECT_NAME} PRIVATE "${CMAKE_SOURCE_DIR}/modules/Visualization/include")
target_include_directories(${PROJECT_NAME} PRIVATE "${CMAKE_SOURCE_DIR}/modules/Python/include")
target_link_libraries(${PROJECT_NAME} PRIVATE Core IO Visualization)
set_target_properties(${PROJECT_NAME} PROPERTIES FOLDER "bindings" OUTPUT_NAME "open3d")

# configure installer to copy the python module to the python site-packages
install(TARGETS ${PROJECT_NAME} DESTINATION ${PYTHON_SITE_PACKAGES})
