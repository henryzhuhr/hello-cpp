修改.git内config
```bash
[remote "origin"]
	url = https://gitee.com/<用户名>/<仓库名字>.git
	url = https://github.com/<用户名>/<仓库名字>.git
	fetch = +refs/heads/*:refs/remotes/origin/*
```bash