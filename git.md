命令方式同步
先删除已关联的名为origin的远程库：
```bash
git remote rm origin
```
然后，再关联GitHub的远程库：
```bash
git remote add github git@github.com:chloneda/demo.git
```
接着，再关联码云的远程库：
```bash
git remote add gitee git@gitee.com:HenryZhu/DataStructure-Cpp.git
```