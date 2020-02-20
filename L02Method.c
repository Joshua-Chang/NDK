//
// Created by JoshuaChang on 2020/2/20.
//
/**
 * 1、函数
 * 2、函数指针
 * 3、可变参数
 * 4、typedef别名
 * 5、实现sprintf
 */
#include <stdio.h>
#include <stdarg.h>
#include "L02mysprintf.h"

void change(int i) {
    i = 10;
}

void change2(int *i) {
    *i = 10;
}

void change3(int **i) {
    int j = 100;
    *i = &j;
}

int add(int num, ...) {
    int sum=0;
    va_list list;//...接收的
    va_start(list,num);// 初始化  valist指向第一个可变参数 (...)
    for (size_t i = 0; i < num; i++) {
        int j=va_arg(list, int);//访问所有赋给 valist 的参数
        printf("%d\n",j);
        sum+=j;
    }
    va_end(list);//清理为 valist 内存
    return sum;
}
//接受一个函数作为参数
//void(*p)(char*) 函数
// void 返回值
// (*p) p变量用来表示这个函数
// (char*) 函数的参数列表
void say(void(*p)(char*), char *msg){
    p(msg);
}

void println(char* msg){
    printf("println:%s\n",msg);
}

//创建别名
typedef void (*Func)(char*);
typedef void (*Success)(char*);
typedef void (*Failure)(char*);

void http(int i,Success success,Failure failure){
    if(i){
        success("成功");
    } else{
        failure("失败");
    }
}
void httpOK(char* msg){
    printf("%s\n",msg);
}
void httpErr(char* msg){
    printf("%s\n",msg);
}
int main() {
    int i1 = 1;
    change(i1);
    printf("%d\n", i1);
    change2(&i1);
    printf("%d\n", i1);
    int *p1 = &i1;
    int **p2 = &p1;
    change3(p2);
    printf("%d\n", i1);

    /**
     * 可变参数
     */
    printf("%d\n",add(5, 1, 2, 3,4, 'a'));


    /**
     * 函数指针是指向函数的指针变量
     * 接受一个函数作为参数(java的回调)
     */
    void (*p)(char*)=println;//声明一个变量p
    say(p,"hello");
    say(println,"hello");
    Func func=println;
    say(func,"hello");


    http(200,httpOK,httpErr);

    char *text [200];
    my_sprintf(text,"id: %d, score:%d\n",25,-11);
    printf(text);
//    my_sprintf("id: %d, score:%d\n",2,1,1);

    return 0;
}
