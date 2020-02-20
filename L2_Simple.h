//
// Created by JoshuaChang on 2020/2/20.
//
/**
 * 约定使用大写
 * 宏变量
 * 宏函数 优点：只文本替换 不作函数调用的开销 缺点：不会执行代码检查，生成目标增大
 * 文本替换 代码中所有的I 就会被预处理器 替换为 1
 */
#define DEBUG
//#undef DEBUG
#define I 1
#define TEST(i) printf("%d\n",i)
#define ADD(x,y) x*y;
#define TEST1(x) if(x){\
    \
}else{ \
    \
}
#pragma once //只会被引入一次

/*
 * 内联函数：和宏函数工作模式相似，但写法不一样；
 * 1、如果太复杂，会被编译器看作普通函数来编译（while、switch）
 * 2、有代码检查
 */

inline int test2(int x,int y){
    return x*y;
}
