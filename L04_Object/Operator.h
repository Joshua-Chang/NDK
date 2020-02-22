//
// Created by JoshuaChang on 2020/2/21.
//

#include <iostream>
using namespace std;

#ifndef LEARNC_OPERATOR_H
#define LEARNC_OPERATOR_H

#endif //LEARNC_OPERATOR_H
class Test {
public:int i;
public:
    Test(){}
//    Test(Test &test){//浅拷贝
//        this->i=test.i;
//        cout<<"拷贝对象"<<endl;
//    }

//成员函数的运算符重载
    Test operator+(const Test& test){
        Test temp;
        temp.i=this->i+test.i;
        return temp;
    }
    //非成员函数的运算符重载

};
class Test2{
public:int i;
};