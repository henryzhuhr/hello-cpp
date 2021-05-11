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


配置方式同步
修改.git文件夹内的config文件：
```bash
[core]
    repositoryformatversion = 0
    filemode = true
    bare = false
    logallrefupdates = true
[remote "origin"]
    url = git@github.com:chloneda/demo.git
    fetch = +refs/heads/*:refs/remotes/github/*
[branch "master"]
    remote = origin
    merge = refs/heads/master
```
将上述文件内容[remote "origin"]内容复制，修改origin名称，内容如下：
```bash
[core]
    repositoryformatversion = 0
    filemode = true
    bare = false
    logallrefupdates = true
[remote "github"]
    url = git@github.com:chloneda/demo.git
    fetch = +refs/heads/*:refs/remotes/github/*
[remote "gitee"]
    url = git@gitee.com:chloneda/demo.git
    fetch = +refs/heads/*:refs/remotes/gitee/*
[branch "master"]
    remote = origin
    merge = refs/heads/master
```
查看远程库
通过以上两种方式的任一种方式配置完成后，我们用``git remote -v``查看远程库信息：
```bash
gitee   git@gitee.com:chloneda/demo.git (fetch)
gitee   git@gitee.com:chloneda/demo.git (push)
github  git@github.com:chloneda/demo.git (fetch)
github  git@github.com:chloneda/demo.git (push)
```
可以看到两个远程库，说明配置生效了。

上传代码
```bash
git add .
git commit -m "update"
```
提交到github
```bash
git push github master
```
提交到码云
```bash
git push gitee master
```
更新代码
```bash
# 从github拉取更新
git pull github
```
```bash
# 从gitee拉取更新
git pull gitee
```


git config user.name "HenryZhu"
git config user.email "296509195@qq.com"