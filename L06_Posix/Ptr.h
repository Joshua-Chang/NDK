//
// Created by JoshuaChang on 2020/2/22.
//

#ifndef LEARNC_PTR_H
#define LEARNC_PTR_H

#endif //LEARNC_PTR_H

#include <iostream>

using namespace std;

template<typename T>
class Ptr {
public:
    Ptr() {
        count = new int(1);
    }

    Ptr(T *t) {
        count = new int(1);
        this->t = t;
    }

    ~Ptr() {
        --(*count);
        if (*count == 0) {
            if (t != NULL) {
                delete t;
                t = NULL;
            }
            delete count;
            count = NULL;
        }
    }

    Ptr(const Ptr<T> &p) {

        cout << "copy" << endl;

        ++(*p.count);

        t = p.t;
        count = p.count;
    }
    Ptr<T>&operator=( const Ptr<T>&p){
        cout << "operator=" << endl;
        ++(*p.count);
        if (--(*count) == 0) {
            if (t) {
                delete (t);
                t = 0;
            }
        }
        t = p.t;
        count = p.count;
        return *this;
    }

private:
    int *count;//引用计数
    T *t;//引用对象
};
