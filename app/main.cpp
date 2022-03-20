#include <iostream>
#include <string>
#include "IntList.h"

int main(int argc, char* argv[])
{
    // {
    //     const int a = 1;
    //     int       b = a;
    // }
    // {

    //     // const int 变量可以给 int 变量赋值
    //     // const int * 不可以给 int* 赋值
    //     int        num = 1;
    //     const int* a   = &num;
    //     int*       b;
    //     b = (int*)a;
    //     printf("%d %d %d\n", num, *a, *b);
    //     // 但是你依旧不可以通过b修改 a的值，在c++里面这叫做未定义行为
    //     // 有个const_cast 就是专门用来改变这种底层const 的
    // }
    IntList list=IntList();
    return 0;
}
