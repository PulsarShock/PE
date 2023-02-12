aux_source_directory(. PLATFORM_WIN_DIR)

include_directories(${PROJECT_SOURCE_DIR})
include_directories(${PROJECT_SOURCE_DIR}/core)
include_directories(${PROJECT_SOURCE_DIR}/kernel)
include_directories(${PROJECT_SOURCE_DIR}/architecture)
include_directories(${PROJECT_SOURCE_DIR}/project)
include_directories(${PROJECT_SOURCE_DIR}/platform/windows)

add_library(PLATFORM_WIN_LIB STATIC ${PLATFORM_WIN_DIR})