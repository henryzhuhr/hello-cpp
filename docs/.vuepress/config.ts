import { defineUserConfig } from 'vuepress'
import type { DefaultThemeOptions } from 'vuepress'

export default defineUserConfig<DefaultThemeOptions>({
  // 站点配置
  base: '/Hello-Cpp/',// XXX
  lang: 'zh-CN',
  title: 'Hello C++',
  description: 'blog for C++',

  // 主题和它的配置
  theme: '@vuepress/theme-default',
  themeConfig: {
    logo: 'https://vuejs.org/images/logo.png',
    navbar: [
      // NavbarItem
      {
        text: 'Home',
        link: '/',
      },
      // NavbarGroup
      {
        text: '3rd-party',
        children: [
          {
            text: 'Opencv',
            link: '/3rd_patry/opencv/opencv.md',
            activeMatch: '/3rd_patry/opencv/',
          },
          {
            text: 'glog',
            link: '/3rd_patry/glog/glog.md',
            activeMatch: '/3rd_patry/glog/',
          },
          {
            text: 'gflags',
            link: '/3rd_patry/gflags/gflags.md',
            activeMatch: '/3rd_patry/gflags/',
          },
        ],
      },
    ],
  },
})