//
// Created by JoshuaChang on 2020/2/21.
//
/**
 * 1、析构方法
 * 2、常量函数
 * 3、友元函数/类
 */
#ifndef LEARNC_STUDENT_H
#define LEARNC_STUDENT_H


class Student {//跟c一样可以在声明实现，也可以去原文件实现
    int i;//默认为private
public:
    Student();

    Student(int i, int j);

//默认的无參构造方法
    ~Student();//析构方法

    void setJ(int j);
    void setI(int i) const;//常量函数：函数后写上const，表示不会也不允许修改类中的成员
    int getI() const;
    int getJ() const;
//析构方法
private:
    int j;
protected:
    int k;
public:
    int l;

    friend void testFriend(Student *);
    friend class Teacher;
};

class Teacher{//友元类内的所有方法都是相应的友元方法
public:
    void call(Student *s){
        s->j=10086;
    }
};
#endif //LEARNC_STUDENT_H
