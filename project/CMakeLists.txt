aux_source_directory(. APP_SRC_DIR)

include_directories(${PROJECT_SOURCE_DIR})
include_directories(${PROJECT_SOURCE_DIR}/core)
include_directories(${PROJECT_SOURCE_DIR}/kernel)
include_directories(${PROJECT_SOURCE_DIR}/architecture)
include_directories(${PROJECT_SOURCE_DIR}/project)
include_directories(${PROJECT_SOURCE_DIR}/platform/windows)

add_executable(${PROJECT_NAME} ${APP_SRC_DIR})

target_link_libraries(
    ${PROJECT_NAME}
    -mwindows
    -lmingw32
    PLATFORM_WIN_LIB
    ARCH_LIB
    KERNEL_LIB
    CORE_LIB
    -lwinmm
    -lws2_32
    -ldsound
    -lcomdlg32
    -ld2d1
)