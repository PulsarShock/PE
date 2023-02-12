aux_source_directory(. ARCH_DIR)

include_directories(${PROJECT_SOURCE_DIR})
include_directories(${PROJECT_SOURCE_DIR}/core)
include_directories(${PROJECT_SOURCE_DIR}/kernel)
include_directories(${PROJECT_SOURCE_DIR}/architecture)
include_directories(${PROJECT_SOURCE_DIR}/project)
include_directories(${PROJECT_SOURCE_DIR}/platform/windows)

add_library(ARCH_LIB STATIC ${ARCH_DIR})