//
// Created by JoshuaChang on 2020/2/21.
//

#include <iostream>
#include "Student.h"

using namespace std;
void test(){
    Student student;//栈中
}//释放
void testFriend(Student *student){
    student->i=100;
}
int main(){
    test();
    Student *student=new Student(1,2);
    testFriend(student);
    cout<<student->getI()<<endl;
    cout<<student->getJ()<<endl;
    delete student;
    student=0;
}
