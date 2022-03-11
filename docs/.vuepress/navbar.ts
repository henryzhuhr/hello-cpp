import type { NavbarConfig } from '@vuepress/theme-default'


const CXX11 = {
    text: 'C++11',
    children: [
        {
            text: 'Lambda 表达式',
            link: '/cxx11/lambda.md',
        },
        {
            text: 'function / std::bind',
            link: '/cxx11/std_function_bind.md',
        },
        {
            text: '右值引用',
            link: '/cxx11/lvalue_rvalue.md',
        },
        {
            text: '可变参数模板',
            link: '/cxx11/variadic_templates.md',
        },
    ],
}
const STL = {
    text: 'STL',
    children: [
        {
            text: 'vector',
            link: '/STL/vector.md',
        },
        {
            text: 'stack',
            link: '/STL/stack.md',
        },
    ],
}
const CMake = {
    text: 'C++11',
    children: [
        {
            text: '编译可执行文件',
            link: '/cmake/compile-executable_file.md',
        },
        {
            text: '编译库',
            link: '/cmake/compile-library.md',
        },
    ],
}

const _3rdparty = {
    text: '3rdparty',
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
}

export const navbar: NavbarConfig = [
    {
        text: 'Home',
        link: '/',
    },
    {
        text: 'Base',
        children: [
            CXX11,
            STL,
        ],
    },
    {
        text: 'Tools',
        children: [
            CMake,
            _3rdparty,
        ],
    },
]
