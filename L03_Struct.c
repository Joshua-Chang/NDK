//
// Created by JoshuaChang on 2020/2/20.
//
/**
 * 1、结构体：结构体是C编程中一种用户自定义的数据类型，类似于Java的JavaBean (没有作用域都是public)
 * 2、共用体：在相同的内存位置 存储不同的数据 ,共用体内存总数：最大成员的字节大小 多在条件判断时省内存
 */
#include <stdio.h>
//创建方法一：默认声明
struct Student{
    int i;//4字节
    short j;//2字节
} s1,s2;//s1，s2表示Student的变量，变量可以不定义；
//创建方法二：别名声明:创建一个别名为Teacher的结构体
typedef struct {
    int i;
    int j;
}Teacher;
#pragma pack(2)//指定以2 字节对齐(1 或者2的倍数 其他的无效成为默认的最长变量的字节数对齐)
typedef struct
{
    short a;
    int b;
    short c;
}MyStruct1;
#pragma pack()//还原
typedef struct
{
    short a;
    short c;
    int b;
}MyStruct2;

typedef union{
    short i;
    int j;
}myUnion;

int main(){

    struct Student student;
    student.i=1;
    student.j=2;
    s1.i=10;
    s1.j=20;
    Teacher teacher;
    teacher.i=1;
    teacher.j=10;
    /**
     * 结构体字节对齐
     * 最好先定义短字节、在定义长字节
     */

    printf("%d\n", sizeof(student));

    //自然对齐
//1、某个变量存放的起始位置相对于结构的起始位置的偏移量是该  变量字节数 的整数倍；
//2、结构所占用的总字节数是结构中字节数最长的变量的字节数的整数倍。
// short = 2  补 2
// int = 4
// short = 2  补 2
    printf("%d\n", sizeof(MyStruct1));//12
    printf("%d\n", sizeof(MyStruct2));//8 // 2个short在一起组成一个 4

    MyStruct2 myStruct;
    myStruct.a=1;
    myStruct.b=1;
    myStruct.c=1;
    printf("%#x %#x %#x\n",&myStruct.a,&myStruct.b,&myStruct.c);


    myUnion myUnion1;
    myUnion1.i=10;
    printf("%d %#X\n",myUnion1.i,&myUnion1.i);
    myUnion1.j=11;
    printf("%d %#X\n",myUnion1.i,&myUnion1.i);
    printf("%d %#X\n",myUnion1.j,&myUnion1.j);

    return 0;
}

