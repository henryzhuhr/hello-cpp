---
outline: deep
---
# CMake基础：编译可执行文件


## 项目结构

```bash
.
├── demo
│   ├── CMakeLists.txt
│   └── hello-world
│       ├── CMakeLists.txt
│       └── hello-world.cpp
└─CMakeLists.txt
```

在此，需要做一些约定，但这不是必须的，应该根据项目需要进行目录构建。

在这里，我们约定 `demo` 目录下存放所有的示例程序，例如在本 demo 中的程序是 `hello-world` ，因此源文件存放在 `demo/hello-world` 下，包含 `hello-world.cpp` 文件。

> 可能会疑问，为什么主程序不是 `main.cpp` ，而是 `hello-world.cpp` 。一方面是为了改变大家的刻板印象，因为大多数教程都是 `main.cpp` ，另一方面是为了说明，源文件的名称并不是固定的，可以随意命名，只要在 `CMakeLists.txt` 中指定即可。

## 编写源文件

入门地，我们先编写一个简单的 `hello-world.cpp` 文件，内容如下

```cpp
#include <iostream>
#include <string>
int main(int argc, char* argv[]) {
    std::string name = (argc == 2) ? argv[1] : "Cpp";
    if (argc > 2) {
        std::cout << "Usage: " << argv[0] << " [name]" << std::endl;
        return -1;
    }
    std::cout << "Hello " << name << std::endl;
    return 0;
}
```


程序的入口是 main 函数，它接受两个参数：`argc` 和 `argv[]`。`argc` 表示命令行参数的数量， `argv` 是一个字符指针数组，包含了实际的参数值。其中，`argv[0]` 是程序的名称，`argv[1]` 是第一个参数，以此类推。

因此，我们可以通过 `argc` 和 `argv[]` 来判断是否有参数传入，如果有参数传入，则输出参数值，否则输出默认值 `Cpp`。

> 简单的命令行参数可以使用上述方法，但是对于复杂的命令行参数，可以使用 [`CLI11`](https://github.com/CLIUtils/CLI11)(依赖C++11)、[`argparse`](https://github.com/p-ranav/argparse)(依赖C++17)、[gfalgs](https://github.com/gflags/gflags)、`getopt` 或者 `boost::program_options`(依赖 boost) 等库来处理。


## 使用 CMake 构建项目

### 根目录 CMakeLists.txt

根目录下的 `CMakeLists.txt` 为整个项目做一些基本配置，包括项目所需CMake最低版本、项目名称、编译器等，文件内容如下

```cmakelist
# CMakeLists.txt
cmake_minimum_required(VERSION 3.10 FATAL_ERROR)
project(hello-cpp) 
add_subdirectory(demo)
```

`cmake_minimum_required` 规定构建当前项目的所需CMake的最低版本，当构建项目使用的CMake不满足做个最低版本要求，则会出现报错，添加 `FATAL_ERROR` 则在不满足条件的情况下产生致命报错
```cmake
cmake_minimum_required(VERSION 3.10)
cmake_minimum_required(VERSION 3.10 FATAL_ERROR)
```
> CMake语法不区分大小写（即 `cmake_minimum_required `与 `CMAKE_MINIMUN_REQUIRED` 是一样的），但是参数区分大小写的


`project` 声明项目名称(`hello-cpp`)，该语句必须在设置编译器后面，同时也可以添加参数 `LANGUAGES` 来显式声明项目的编程语言
```cmake
project(hello-cpp)
project(hello-cpp LANGUAGES CXX)
```
> CXX代表C++，C++是CMake默认的编程语言

完成对整个项目的基本配置，我们就可以添加子目录 `add_subdirectory` 来进行编译，我们添加子目录 `demo` 来编译可执行文件
```cmake
add_subdirectory(demo)
```

在这条语句之后，构建系统会在 `demo` 目录下寻找 `CMakeLists.txt` 文件，然后执行 `demo/CMakeLists.txt` 中的内容。

### 扩展根目录 CMakeLists.txt

上述一小节中的 `CMakeLists.txt` 只是对项目做了基本配置，但是可以对项目做更多配置，例如设置编译器、编译选项、链接选项等

可以在 `CMakeLists.txt` 中选择编译器、设置编译器的标准，并且导出编译命令生成 `compile_commands.json` 文件

```cmake
cmake_minimum_required(VERSION 3.10 FATAL_ERROR)
# 设置编译器
set(CMAKE_C_COMPILER /usr/bin/gcc)      // [!code ++]
set(CMAKE_CXX_COMPILER /usr/bin/g++)    // [!code ++]
# 设置 C++ 标准为 C++11
set(CMAKE_CXX_STANDARD 11)              // [!code ++]
# 导出编译命令
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)   // [!code ++]
# C++ 编译选项
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Werror") // [!code ++]
project(hello-cpp) # 必须在设置编译器后面
add_subdirectory(demo)
```

`compile_commands.json` 文件是一个 JSON 文件，包含了编译器的编译命令，可以结合 clangd 工具链来进行代码补全、语法检查等。


### demo 目录 CMakeLists.txt

`demo/CMakeLists.txt` 文件就比较简单了，仅仅用于组织程序，文件内容如下
    
```cmake
# demo/CMakeLists.txt
add_subdirectory(hello-world)
```

在随后更多的示例中，我们会在 `demo` 目录下添加更多的示例程序，因此在 `demo/CMakeLists.txt` 中添加 `add_subdirectory` 来编译更多的示例程序，可以注释掉不需要的示例程序，只编译需要的示例程序。

### hello-world 目录 CMakeLists.txt

`demo/hello-world/CMakeLists.txt` 文件用于配置编译可执行文件，文件内容如下

```cmake
# demo/hello-world/CMakeLists.txt
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
    # 你可以添加更多的 remove 命令来删除其他安装的文件
)
```

该文件较为重要，因此在随后的部分中会详细介绍。

## 配置编译可执行文件

### 引入头文件

`demo/hello-world/CMakeLists.txt` 文件中，首先是包含目录 `include_directories`，这里我们没有包含任何头文件，因此可以省略
```cmake
include_directories(${PROJECT_SOURCE_DIR}/include)
```

### 添加可执行文件

`add_executable` 用于添加可执行文件，文件名为 `hello-world`，源文件为 `hello-world.cpp`
```cmake
add_executable(hello-world hello-world.cpp)
```
如果有多个源文件，可以通过 `add_executable` 来添加多个源文件，例如
```cmake
add_executable(hello-world hello-world.cpp other.cpp)
```

但是需要确保 `hello-world.cpp` 和 `other.cpp` 中的 `main` 函数只有一个，否则会出现重复定义的错误。

### 定义安装规则

`install` 用于定义安装规则，将可执行文件 `hello-world` 安装到 `bin` 目录下
```cmake
install(TARGETS hello-world DESTINATION bin)
```
当然也可以写成另一种方式便于理解
```cmake
install(TARGETS     hello-world 
        DESTINATION bin
)
```

- `TARGETS` 指定要安装的目标，`TARGETS hello-world` 表示安装 `hello-world` 可执行文件
- `DESTINATION` 指定安装路径，`DESTINATION bin` 表示安装到 `bin` 目录下。该路径应该是一个相对路径，相对于 `CMAKE_INSTALL_PREFIX` 的路径
- `CMAKE_INSTALL_PREFIX` 是安装目录，默认是 `/usr/local`
- 可以通过 `cmake -DCMAKE_INSTALL_PREFIX=/path/to/install` 来指定安装目录
- 如果不在外部指定的情况下，会安装到系统默认的安装目录，通常是 `/usr/local/bin` 下；如果指定了安装目录，那么会安装到 `/path/to/install/bin` 下



> 安装命令 install 的细节在此不展开

### 定义 uninstall 目标

`add_custom_target` 用于定义自定义目标，这里定义了 `uninstall` 目标，用于卸载安装的文件
```cmake
add_custom_target(uninstall
    COMMAND ${CMAKE_COMMAND} -E echo "Uninstalling..."
    COMMAND ${CMAKE_COMMAND} -E remove -f "${CMAKE_INSTALL_PREFIX}/bin/hello-world"
)
```

## 构建项目

编写完项目的全部 `CMakeLists.txt` 文件后，接下来就是如何构建项目了。

CMake 是一个**跨平台构建系统生成器 (cross-platform build system generator)**，CMake 本身并不直接构建项目，而是根据用户提供的配置文件(`CMakeLists.txt`)，生成适合不同构建工具（Unix Makefile、Ninja、Visual Studio等）的构建文件，然后使用构建工具来构建项目。

> 「构建文件」描述构建系统应当如何操作才能编译代码，例如 `Makefile`、`build.ninja`、`.sln` 等文件

不同系统平台下有默认的构建工具，例如：
- GNU/Linux 和 macOS 系统上，`Unix Makefile` 是默认的生成器
- Windows上，`Visual Studio` 是默认的生成器
- Windows上，可以安装 `MinGW` 来使用 `MinGW Makefiles`

![](./images/cmake-process.svg)

使用 CMake 配置项目并生成构建器 (generator) ，可以通过 `cmake -h` 查看可用的生成器（`*` 标记的是默认生成器）:
```bash
cmake -h
# Generators
# The following generators are available on this platform (* marks default):
# * Unix Makefiles               = Generates standard UNIX makefiles.
#   Ninja                        = Generates build.ninja files.
# ...
```

一般的生成构建文件流程是，首先新建一个目录 `build` ，在 `build` 目录下，通过指定上级目录的 `CMakeLists.txt` 来调用 CMake 配置项目并生成构建器
```bash
mkdir -p build && cd build
cmake ..            # CMakeLists.txt 在上级目录
cmake .. -G "Ninja" # 或指定平台可用的生成器
```


> 可以直接在项目根目录下中执行 `cmake .` 构建构建，这是源代码内构建，但是这种做法会在根目录（源代码目录）下生成配置文件，会将源代码和项目的生成树混合，这是非常不推荐的。因此，一般来说，需要在源代码外构建项目，即在源代码目录外新建一个目录 `build` ，并在 `build` 目录下构建项目。


当出现如下输出，则已经成功配置项目(`Configuring done`)，并且生成了构建文件(`Generating done`)
```bash
-- Configuring done
-- Generating done
```

你可以在 `build` 目录下，看到下列文件（这里以 `Unix Makefile` 为例）：
```bash
build
├── CMakeCache.txt
├── CMakeFiles
├── cmake_install.cmake
├── compile_commands.json
├── demo
│   ├── CMakeFiles
│   ├── cmake_install.cmake
│   ├── hello-world
│   │   ├── CMakeFiles
│   │   ├── cmake_install.cmake
│   │   └── Makefile
│   └── Makefile
└── Makefile
```
可以看到 `build` 目录的结构和源代码结构是一样的，每一个 `CMakeLists.txt` 文件都会生成一个对应的 `Makefile` 和 `CMakeFiles` 目录，用于编译项目，还有一些其他文件：
- `Makefile` : 命令 `make` 将运行指令来编译项目。
- `CMakefiles` ：临时文件目录，CMake用于检测操作系统、编译器等。
- `CMakeCache.txt` ：如文件名所示，CMake缓存。CMake在重新运行配置时使用这个文件，如果重新配置项目，会生成新的 `CMakeCache.txt` 文件。
- `cmake_install.cmake` ：处理安装规则的CMake脚本，在项目安装时使用。
- `compile_commands.json` ：编译命令文件，用于 clangd 工具链。


## 编译项目

随后就可以开始编译可执行文件
```bash
make
# or
cmake --build .
```

你可以在 `build` 目录下，看到下列文件：
```bash
build
├── CMakeCache.txt
├── CMakeFiles
├── cmake_install.cmake
├── compile_commands.json
├── demo
│   ├── CMakeFiles
│   ├── cmake_install.cmake
│   ├── hello-world
│   │   ├── CMakeFiles
│   │   ├── cmake_install.cmake
│   │   ├── hello-world
│   │   └── Makefile
│   └── Makefile
└── Makefile
```

编译后就可以看到生成的可执行文件 `demo/hello-world/hello-world`，可以直接执行，但是这种目录中的可执行文件不太方便，可以通过 `make install` 安装到指定目录下
```bash
make install
```

安装后，可执行文件会被安装到 `/usr/local/bin` 目录下，可以直接执行
```bash
hello-world
```
或切换到 `/usr/local/bin` 目录下执行
```bash 
cd /usr/local/bin
./hello-world
```

如果不希望安装到 `/usr/local/bin` 目录下，可以通过 `-DCMAKE_INSTALL_PREFIX` 来指定安装目录
```bash
cmake -DCMAKE_INSTALL_PREFIX=.. ..
make install
```

然后可以在 `../bin` 目录下执行
```bash
# 这时候的目录是在 build 目录下，因此需要返回上级目录
cd ../bin
./hello-world
```

## clangd 的使用

[clangd](https://clangd.llvm.org/installation)