//
// Created by JoshuaChang on 2020/2/20.
//
/**
 * 1、预处理器:是执行文本替换工作的（都以#开头）
 */
#include <stdio.h>
#include "L2_Simple.h"
int main(){
//#ifdef DEBUG
    printf("%d\n",I);
    TEST(8);
    int add1=ADD(1,10);
    TEST(add1);
    int add2=ADD(1+10,10+10);//实际获得1+10*10+10 记得加括号才能正确
    TEST(add2);
    TEST1(0);
    return 0;
}
