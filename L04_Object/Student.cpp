//
// Created by JoshuaChang on 2020/2/21.
//
#include <iostream>
using namespace std;
#include "Student.h"

Student::Student() {
    cout<<"构造方法"<<endl;
}
Student::~Student() {
    cout<<"析构方法 在对对象内存释放时调用"<<endl;
}
Student::Student(int i, int j) {
    this->i=i;
    this->j=j;
}

void Student::setJ(int j) {
    Student::j = j;
//或者    this->j=j;
}

void Student::setI(int i) const {
//    Student::i = i;
}

int Student::getI() const {
    return i;
}

int Student::getJ() const {
    return j;
}


//Student::Student(int i, int j) : i(i), j(j) {}//同样的写法
