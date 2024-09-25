[文章](https://www.jianshu.com/p/ab7a94115d10)

如何集成到项目中

find_package(xxx 1.0.0 CONFIG REQUIRED)
target_link_libraries(main PRIVATE xxx)
在踩坑的道路上，终归我是活着上岸了，不过也要感谢网友的文章，虽然它们带我下海，很多没有带我上岸：

1. [CSDN: cmake 生成供find_package使用的自定义模块](https://links.jianshu.com/go?to=%255Bhttps%3A%2F%2Fblog.csdn.net%2Fktigerhero3%2Farticle%2Fdetails%2F83863226%255D%28https%3A%2F%2Fblog.csdn.net%2Fktigerhero3%2Farticle%2Fdetails%2F83863226%29)
这篇算是启蒙之篇，感谢作者带我上路，但是它真的不支持vcpkg识别。

[知乎: CMake之install方法的使用](https://zhuanlan.zhihu.com/p/102955723)
篇幅写的很好，代码也很规矩，但是真的不能被vcpkg识别。

[CSDN: CMAKE_INSTALL_PREFIX无效的解决方案](https://blog.csdn.net/LaineGates/article/details/89761321)

[简书: CMake最佳实践](https://www.jianshu.com/p/3711361d10a5)
这篇文章的xxxConfig.cmake生成走了弯路，心疼下作者。

[CMake库打包以及支持find_package](https://murphypei.github.io/blog/2018/11/cmake-install-find-package)
这篇文章接近上岸了，但是xxxConfigVersion.cmake没必要自己写，可以自动生成的，心疼下作者。

[Tutorial: Easily supporting CMake install and find_package()](https://foonathan.net/2016/03/cmake-install/)这篇文章讲解也非常清晰，可参考性比较高。

[GitHub: package-example](https://github.com/forexample/package-example)
这篇文章帮我上岸了，但我也给它简化了一些步骤。



作者：生活简单些
链接：https://www.jianshu.com/p/ab7a94115d10
来源：简书
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。