# 包含目录
include_directories(${PROJECT_SOURCE_DIR}/include)

# 添加可执行文件 hello-world
add_executable(hello-world hello-world.cpp)

# 定义安装规则
install(TARGETS hello-world DESTINATION bin)


# 定义 uninstall 目标
include(GNUInstallDirs)

add_custom_target(uninstall
    COMMAND ${CMAKE_COMMAND} -E echo "Uninstalling..."
    COMMAND ${CMAKE_COMMAND} -E remove -f "${CMAKE_INSTALL_PREFIX}/bin/hello-world"
)