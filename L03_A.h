//
// Created by JoshuaChang on 2020/2/20.
//
//__cplusplus 是由c++编译器定义的宏，用于表示当前处于c++环境

#ifdef __cplusplus
extern "C"{
#endif

void test(int x, int y);

#ifdef __cplusplus
}
#endif
//extern 关键字 可用于变量或者函数之前，表示真实定义在其他文件，编译器遇到此关键字就会去其他模块查找