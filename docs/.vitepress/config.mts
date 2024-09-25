import { DefaultTheme, defineConfig } from 'vitepress'


/**
 * 侧边栏配置
 */
const sidebar: DefaultTheme.Sidebar = [
  {
    text: 'C++11',
    items: [
      { text: 'C++ 11', link: '/cxx11/cxx11' },
      { text: 'Lambda 表达式', link: '/cxx11/lambda' },
      { text: 'std::function / 函数适配器 std::bind', link: '/cxx11/std_function_bind' },
      { text: '右值引用', link: '/cxx11/lvalue_rvalue' },
      { text: '可变参数模板', link: '/cxx11/variadic_templates' },
      { text: '智能指针', link: '/cxx11/smart_pointer.md' },

    ]
  },
  {
    text: 'STL',
    items: [
      { text: 'vector', link: '/cxx_stl/vector' },
      { text: 'stack', link: '/cxx_stl/stack' },
    ]
  },
  {
    text: 'CMake',
    items: [
      { text: '编译可执行文件', link: '/cmake/compile-executable_file' },
      { text: '编译库', link: '/cmake/compile-library' },
    ]
  },
  {
    text: '3rd-party 第三方库',
    items: [
      { text: 'opencv', link: '/3rd_patry/opencv/opencv' },
      { text: 'glog', link: '/3rd_patry/glog/glog' },
      { text: 'gflags', link: '/3rd_patry/gflags/gflags' },
    ]
  },
  {
    text: '学习资料',
    items: [
      { text: '现代 C++ 教程：高速上手 C++ 11/14/17/20', link: 'https://changkun.de/modern-cpp/zh-cn/00-preface' },
      { text: 'glog', link: '/3rd_patry/glog/glog' },
      { text: 'Light-City/CPlusPlusThings-C++那些事', link: 'https://github.com/Light-City/CPlusPlusThings' },
    ]
  },
]

/**
 * 主题配置 https://vitepress.dev/reference/default-theme-config
 */
const themeConfig: DefaultTheme.Config = {
  sidebar: sidebar,
  socialLinks: [
    { icon: 'github', link: 'https://henryzhuhr.github.io/hello-cpp' }
  ],
  externalLinkIcon: true,
  footer: {
    message: 'Powered By <a href="https://vitepress.dev/">Vitepress</a>',
    copyright: `All rights reserved © 2024-${new Date().getFullYear()} <a href="https://github.com/HenryZhuHR?tab=repositories">HenryZhuHR</a>`
  },
  outline: {
    label: '页面导航'
  },
  lastUpdated: {
    text: '最后更新于',
    formatOptions: {
      dateStyle: 'short',
      timeStyle: 'medium'
    }
  },
  search: {   // 本地搜索: https://vitepress.dev/zh/reference/default-theme-search#local-search
    provider: 'local',
  }
}

/**
 * 站点配置 https://vitepress.dev/reference/site-config
 */
export default defineConfig({
  base: '/hello-cpp/',
  title: "Hello Cpp",
  description: "C++ Learning Log",
  themeConfig: themeConfig,
})
