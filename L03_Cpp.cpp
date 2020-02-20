//
// Created by JoshuaChang on 2020/2/20.
//
/**
 * 1、C与C++兼容
 * 2、引用类型
 * 3、字符串
 * 4、命名空间 namespace相当于java中的包 :: 域作用符
 */
//如果需要在C++中调用C实现的库中的方法
//指示编译器这部分代码使用C的方式进行编译而不是C++
//extern "C"{
#include "L03_A.h"
//}
#include <iostream>

using namespace std;
void change(int &j) {
    j = 11;
}


namespace A{
    namespace B{
        void test(){};
    }
}
//using namespace A;
using namespace A::B;
int ii;
int main() {
    cout << ".." << endl;
    test(1, 2);

    ii=11;
    int ii=10;
    cout << ii<<"  "<<::ii << endl;	//操作重名的全局变量的时候 可以使用域作用符
    ii=8;
    ::ii=9;
    cout << ii<<"  "<<::ii << endl;

    int i = 10;
    int &j = i;
    // int&  引用类型
    // 10这个内存地址 给了个别名 j
    change(j);
    cout << j << endl;

    //3、字符串
    //c 使用 NULL \0 结尾的一个字符数组
    char str1[] = {'h', 'e', 'l', '\0'};
    char *str2 = "hello";    //默认给我们在末尾增加 \0
    cout << "str1 " << str1 << endl;
    cout << "str2 " << str2 << endl;
    char str3[10];
    strcpy(str3, str1);
    strcat(str3, str1);
    cout << "str2==str1 ? " << strcmp(str1, str2) << endl;
    cout << "str2 e first index: " << strchr(str2, 'e') << endl;
    cout << "str3 " << str3 << " length:" << strlen(str3) << endl;

    //c++ string 类  #include <string> iostream 内有包含
    string string1 = "hello";
    //调用构造方法
    string string2("hello");
    string string3(str1);
    string *string4 = new string("hello");    //申请内存 调用构造方法

    // 拼接字符串
    // + 操作符重载:重新定义 的 行为
    string string5=string1+string2;
    string1.append(str3);

    cout<<string1.c_str()<<endl;	//获得c的字符串
    string1.size();
    string1.empty();

    //指针调用方法
    // 1、出方法 清理栈
    // 2、指针 4/8 对象 x个字节 效率更高
    string4->empty();//==(*string4).empty();
    string4->size();


    //释放内存
    delete string4;
    //malloc = free
    // new = delete
    // new 数组 = delete[]

//    A::B::test();
//    B::test();
    test();
    return 0;
}
