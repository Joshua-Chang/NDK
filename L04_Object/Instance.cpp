//
// Created by JoshuaChang on 2020/2/21.
//

#include "Instance.h"
Instance *Instance ::instance=0;

Instance::Instance() {}

Instance* Instance::getInstance() {
    //C++11以后，编译器保证内部静态变量的线程安全性
    if(!instance){
        instance=new Instance();
    }
    return instance;
}