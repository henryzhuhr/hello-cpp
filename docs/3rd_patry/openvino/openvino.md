


## Linux 编译

clone 源码
```sh
https://github.com/openvinotoolkit/openvino.git
```

clone 子模块
```sh
cd openvino
# from Github
git submodule update --init --recursive
# from Gitee
bash ./scripts/submodule_update_with_gitee.sh
```

安装依赖
```sh
./install_build_dependencies.sh
```

