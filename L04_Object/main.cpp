//
// Created by JoshuaChang on 2020/2/21.
//
/**
 * 1.重载：函数重载（同java）
 * 2.操作符重载
 * 3.继承 虚函数
 * 4、模版编程
 * 模板函数  java 泛型方法
 * 模板类	java泛型类
 */
#include <iostream>
#include "Student.h"
#include "Instance.h"
#include "Operator.h"
#include "Extends.h"

using namespace std;
void test(){
    Student student;//栈中
}//释放
void testFriend(Student *student){
    student->i=100;
}
void print(int i) {
    cout << "整数为: " << i << endl;
}

void print(double  f) {//函数重载（C没有）
    cout << "浮点数为: " << f << endl;
}

//非成员函数的运算符重载 （也可以定义在类外边，要多传自身参数）

Test2 operator+(const Test2 & test1,const Test2 & test2){
    Test2 temp;
    temp.i=test1.i+test2.i;
    return temp;
}


template <typename T>
//或者template <class T>
T max(T a,T b){
    return a>b?a:b;
}

template <class T,class E>
class Demo{
public:T test(T t,E e){
        return t+e;
    }
};

int main(){
//    max(1,2);
//    max(1.1f,2.2f);
    Demo<int ,float >demo;
    cout<<demo.test(1,5.1f)<<endl;

    test();
    Student *student=new Student(1,2);
    testFriend(student);
    cout<<student->getI()<<endl;
    cout<<student->getJ()<<endl;
    delete student;
    student=0;

    Instance::getInstance();


    Test test1,test2;
    test1.i=100;
    test2.i=200;
    //1、拷贝temp 对象 给一个 临时对象
    //2、临时对象拷贝给 test3
    //回收临时对象
    Test test3 = test1 + test2;
//    Test test3 = test1.operator+(test2) ;


    cout<<"test1+test2="<<test3.i<<endl;

    Test2 t1,t2;
    t1.i=100;
    t2.i=200;
    cout<<"t1+t2="<<(t1+t2).i<<endl;

    //继承
    Child child;
//    child.test();
    /**
     * 静态多态：在编译期间 就确定了 函数的调用地址
     */
    Parents *p=new Child;
    // 动态多态 :  运行时确定调用
    // 虚函数 父类方法设为virtual
    // 构造方法 永远不要设为虚函数
    // 析构方法 声明为虚函数
    // Parent *p = new Child;
    // 如果在child中 申请了 堆内存 不为虚函数 永远不会调用child的析构函数

    //===========================================

    p->test();

}
