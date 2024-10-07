### install 命令

在 CMake 中，`install(TARGETS ...)` 命令用于指定如何将构建的目标（例如可执行文件或库）安装到系统中，特别是在在打包和分发软件时需要使用。

`install(TARGETS ...)` 命令的基本语法（函数签名/Signatures）如下
```cmake
install(TARGETS <target>... [EXPORT <export-name>]
        [RUNTIME_DEPENDENCIES <arg>...|RUNTIME_DEPENDENCY_SET <set-name>]
        [<artifact-option>...]
        [<artifact-kind> <artifact-option>...]...
        [INCLUDES DESTINATION [<dir> ...]]
        )
```
> 完整命令和使用可以参考官方文档 [_install_](https://cmake.org/cmake/help/latest/command/install.html)（中文 [_安装_](https://cmake-doc.readthedocs.io/zh-cn/latest/command/install.html)）

一步步来看

- `TARGETS`，指定了要安装的目标，后面跟着一个或多个由 `add_executable()` 或 `add_library()` 创建的目标名称。
- `ARCHIVE`、`LIBRARY`、`RUNTIME` 等关键字，指定了目标的不同类型。它们可以用来为不同类型的输出设置不同的安装规则。比如静态库可以用 `ARCHIVE`，动态库用 `LIBRARY`，可执行文件用 `RUNTIME`。
- `DESTINATION`，指定安装路径。默认情况下，这个路径是相对于 `CMAKE_INSTALL_PREFIX` 变量的值。如果用户没有特别指定 `CMAKE_INSTALL_PREFIX`，那么默认会使用系统的标准位置（通常是 `/usr/local` 在类 Unix 系统上）。
