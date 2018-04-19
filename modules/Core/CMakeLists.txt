file(GLOB CORE_ALL_SOURCE_FILES "src/*.cpp")
file(GLOB CORE_UTILITY_SOURCE_FILES "src/Utility/*.cpp")
source_group("Source Files\\Utility" FILES ${CORE_UTILITY_SOURCE_FILES})
file(GLOB CORE_GEOMETRY_SOURCE_FILES "src/Geometry/*.cpp")
source_group("Source Files\\Geometry" FILES ${CORE_GEOMETRY_SOURCE_FILES})
file(GLOB CORE_CAMERA_SOURCE_FILES "src/Camera/*.cpp")
source_group("Source Files\\Camera" FILES ${CORE_CAMERA_SOURCE_FILES})
file(GLOB CORE_REGISTRATION_SOURCE_FILES "src/Registration/*.cpp")
source_group("Source Files\\Registration" FILES ${CORE_REGISTRATION_SOURCE_FILES})
file(GLOB CORE_ODOMETRY_SOURCE_FILES "src/Odometry/*.cpp")
source_group("Source Files\\Odometry" FILES ${CORE_ODOMETRY_SOURCE_FILES})
file(GLOB CORE_INTEGRATION_SOURCE_FILES "src/Integration/*.cpp")
source_group("Source Files\\Integration" FILES ${CORE_INTEGRATION_SOURCE_FILES})
project(Core)
add_library(${PROJECT_NAME}
	${CORE_ALL_SOURCE_FILES}
	${CORE_UTILITY_SOURCE_FILES}
	${CORE_GEOMETRY_SOURCE_FILES}
	${CORE_CAMERA_SOURCE_FILES}
	${CORE_REGISTRATION_SOURCE_FILES}
	${CORE_ODOMETRY_SOURCE_FILES}
	${CORE_INTEGRATION_SOURCE_FILES}
)
target_include_directories(${PROJECT_NAME} PRIVATE "${CMAKE_SOURCE_DIR}/modules/Core/include")
target_link_libraries(${PROJECT_NAME} ${JSONCPP_LIBRARIES})
set_target_properties(${PROJECT_NAME} PROPERTIES FOLDER "modules" OUTPUT_NAME "${CMAKE_PROJECT_NAME}${PROJECT_NAME}-${OPEN3D_VERSION}")
