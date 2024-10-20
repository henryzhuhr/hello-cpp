# 安装启动

## 基于容器的开发

### docker 环境准备和启动项目

按照下列链接中的步骤准备好 docker 环境：
1. [Docker 环境准备](https://henryzhuhr.github.io/hello-docker/starter.html)
2. VSCode中安装 Docker 插件
   - [Docker](https://marketplace.visualstudio.com/items?itemName=ms-azuretools.vscode-docker)
   - [Dev Containers](https://marketplace.visualstudio.com/items?itemName=ms-vscode-remote.remote-containers)
3. 点击VSCode （最）左下角「打开远程窗口」，弹出的命令中，点击「**在容器中重新打开 / Reopen in Container**」

![](./images/vscode-open-remote.png)

4. 也可以在**命令面板**中搜索并执行命令 「**Dev Containers: Rebuild Container Without Cache / 开发容器：重新生成无缓存的容器**」（特别是修改了 `Dockerfile` 或 `docker-compose.yml` 时，必须执行此命令）

> [!TIP]
> - 在 VSCode 中键入 `Ctrl+Shift+P` 调出**命令面板** ，或者在菜单栏中选择 `查看(View)` -> `命令面板(Command Palette)` 调出**命令面板**
> - 如果构建失败，可以尝试在 Docker Desktop 中删除对应容器(`hello-cpp-ubuntu-dev`)和对应镜像(`hello-cpp-ubuntu-dev:latest`)后重试。如果仍然构建失败，请参考 [_使用 Dev Containers 插件的过程_](https://henryzhuhr.github.io/hello-docker/develop-in-vscode.html#使用-dev-containers-插件的过程) 。


### 运行 demo

进入容器后，在终端中可以通过下面的命令查看当前环境相关信息：

```bash
cat /etc/os-release  # 检查当前系统发行版
cat /etc/lsb-release # 检查当前系统发行版
uname -m          # 查看系统架构
cat /proc/cpuinfo # 查看CPU信息
cat /proc/meminfo # 查看内存信息
```

确认后，可以运行 demo：
```bash
bash scripts/build.sh
```

输出如下，可以看到构建过程、安装目录 `/usr/local/bin/main` 和最后的输出 `Hello Cpp/root `：
```bash
...
[100%] Built target main
Install the project...
-- Install configuration: ""
-- Installing: /usr/local/bin/main
Hello Cpp
Hello root
```


### 扩展开发环境

如果需要扩展开发环境，可以在 `Dockerfile` 中添加对应的软件包安装命令，然后执行 `Dev Containers: Rebuild Container Without Cache` 命令重新构建容器。