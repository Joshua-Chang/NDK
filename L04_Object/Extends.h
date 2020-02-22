//
// Created by JoshuaChang on 2020/2/21.
//
/**
 *
 * public	基类的public、protected成员也是派生类相应的成员，基类的private成员不能直接被派生类访问，但是可以通过调用基类的公有和保护成员来访问。
 * protected	基类的公有和保护成员将成为派生类的保护成员
 * private	基类的公有和保护成员将成为派生类的私有成员
 *
 */
#include <iostream>

using namespace std;
#ifndef LEARNC_EXTENDS_H
#define LEARNC_EXTENDS_H

#endif //LEARNC_EXTENDS_H

class Parents {
public:
    virtual void test() {//虚函数动态多态
        cout<<"Parents"<<endl;
    }
    virtual void test1()=0;//纯虚函数（java抽象方法）子类必须重写
};
class Parents1 {
public:
};

//默认为私有继承，子类不可访问父类方法(可以重写父类方法，达到使用自己方法的目的)
class Child : public Parents, private Parents1 {
    void test() {
//        Parents::test();//相当于super
        cout<<"child"<<endl;
    }

public:
    void test1()  {

    }
};
