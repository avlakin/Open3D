include_directories(${JPEG_INCLUDE_DIR} ${PNG_INCLUDE_DIRS})

file(GLOB IO_ALL_HEADER_FILES "*.h")
file(GLOB IO_ALL_SOURCE_FILES "*.cpp")
file(GLOB IO_RPLY_FILES "../../3rdparty/rply/*.h" "../../3rdparty/rply/*.c")
source_group("../3rdparty\\RPly" FILES ${IO_RPLY_FILES})
file(GLOB IO_LIBLZF_FILES "../../3rdparty/liblzf/*.h" "../../3rdparty/liblzf/*.c")
source_group("../3rdparty\\liblzf" FILES ${IO_LIBLZF_FILES})
file(GLOB IO_DIRENT_FILES "../../3rdparty/dirent/*.h")
source_group("../3rdparty\\dirent" FILES ${IO_DIRENT_FILES})
file(GLOB IO_CLASSIO_HEADER_FILES "ClassIO/*.h")
source_group("Header Files\\ClassIO" FILES ${IO_CLASSIO_HEADER_FILES})
file(GLOB IO_CLASSIO_SOURCE_FILES "ClassIO/*.cpp")
source_group("Source Files\\ClassIO" FILES ${IO_CLASSIO_SOURCE_FILES})
file(GLOB IO_FILEFORMAT_HEADER_FILES "FileFormat/*.h")
source_group("Header Files\\FileFormat" FILES ${IO_FILEFORMAT_HEADER_FILES})
file(GLOB IO_FILEFORMAT_SOURCE_FILES "FileFormat/*.cpp")
source_group("Source Files\\FileFormat" FILES ${IO_FILEFORMAT_SOURCE_FILES})

project(IO)
add_library(${PROJECT_NAME}
	${IO_ALL_HEADER_FILES} ${IO_ALL_SOURCE_FILES}
	${IO_RPLY_FILES} ${IO_LIBLZF_FILES} ${IO_DIRENT_FILES}
	${IO_CLASSIO_HEADER_FILES} ${IO_CLASSIO_SOURCE_FILES}
	${IO_FILEFORMAT_HEADER_FILES} ${IO_FILEFORMAT_SOURCE_FILES}
)
target_link_libraries(${PROJECT_NAME} Core tinyfiledialogs ${JPEG_LIBRARIES} ${PNG_LIBRARIES} ${JSONCPP_LIBRARIES})
set_target_properties(${PROJECT_NAME} PROPERTIES FOLDER "modules" OUTPUT_NAME "${CMAKE_PROJECT_NAME}${PROJECT_NAME}-${OPEN3D_VERSION}")
