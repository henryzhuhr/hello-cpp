import { defineUserConfig } from 'vuepress'
import type { DefaultThemeOptions } from 'vuepress'
import path from 'path'
import { navbar } from './navbar'

export default defineUserConfig<DefaultThemeOptions>({
  // 站点配置
  base: '/Hello-Cpp/',// XXX
  lang: 'zh-CN',
  title: 'Hello C++',
  description: 'blog for C++',
  head: [
    ['link', { rel: 'icon', href: '/logo/cpp.svg' }],
    [
      'meta',
      {
        name: 'keywords',
        content: 'C++,vuepress,markdown,github pages',
      },
    ],
  ],
  // 主题和它的配置
  theme: '@vuepress/theme-default',
  themeConfig: {
    logo: '/logo/cpp.svg',
    logoDark: '/logo/cpp-dark.svg',
    repo: 'https://github.com/HenryZhuHR/Hello-Cpp',
    navbar: navbar,
    plugins: [
      path.resolve(__dirname, './plugin/copy-code/lib/index.ts'),
    ]
  },
})