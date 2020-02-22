//
// Created by JoshuaChang on 2020/2/21.
//
/**
 * 1、多线程同时读写同一份共享资源的时候，可能会引起冲突。
 * 需要引入线程“同步”机制，即各位线程之间有序地对共享资源进行操作。
 * 2、线程同步
 * 3、生产消费模型（条件变量）
 * 4、智能指针
 * 5.新特性
 */
#include <pthread.h>
#include <iostream>
#include <queue>
#include "safe_queue.h"
#include "Ptr.h"
#include <pthread.h>
#include <thread>
using namespace std;
pthread_mutex_t mutex1;//加入互斥锁
queue<int> queue1;

void *queue_task(void *args) {
    pthread_mutex_lock(&mutex1);//synchronized
    if (!queue1.empty()) {
        printf("取出数据:%d\n", queue1.front());
        queue1.pop();
    } else {
        printf("无数据\n");
    }
    pthread_mutex_unlock(&mutex1);
    return 0;
}

int main1() {//多线程 同步
    pthread_mutex_init(&mutex1, 0);//初始化
    for (int i = 0; i < 5; ++i) {
        queue1.push(i);
    }
    pthread_t pids[10];
    for (int j = 0; j < 10; ++j) {
        pthread_create(&pids[j], 0, queue_task, 0);
    }
    pthread_mutex_destroy(&mutex1);
    return 0;
}

SafeQueue<int> q;

void *get(void *args) {
    string *s = static_cast<string *>(args);
    while (1) {
        int i;
        // 使用条件变量：如果队列中没有数据 就卡在这里
        q.pop(i);

        /*if (i == -1) {//不使用条件变量 一直跑
			cout << "-1" << endl;
			continue;
		}*/
        cout << *s << " 取出数据" << i << endl;
    }
    return 0;
}

void *put(void *args) {
    string *s = static_cast<string *>(args);
    while (1) {
        int i;
        cin >> i;
        q.push(i);
        cout << *s << " 存入数据" << i << endl;
    }
    return 0;
}


int main2() {//生产者消费者
    pthread_t pid1, pid2;
    string string1 = "一号线程：";
    string string2 = "二号线程：";
    pthread_create(&pid1, 0, get, &string1);
    pthread_create(&pid2, 0, put, &string2);
    pthread_join(pid1, 0);
    return 0;
}

class A {
public:
    ~A() {
        cout << "释放A" << endl;
    }
};

void testPtr() {
//    A a;//在栈中，方法结束后释放
    A *a1 = new A;//堆内 要delete释放
//    delete a1;
//    shared_ptr<A>shared_a(a1);// a 引用计数:1
//    shared_ptr<A>shared_b(a1);// a 引用计数:2
//    引用计数为0时delete a1 （不用写delete）

    A *a2 = new A;
    //shared_a 处于栈当中
    Ptr<A> shared_a(a1); // a 引用计数:1
    //先创建了一个对象 变量是shared_b
    // a2 野生对象(没有智能指针指向a2了 )
    Ptr<A> shared_b;  // 1
    //再将 shared_b 变量 重新赋值
    shared_b = shared_a;
    //出方法 shared_a 与 shared_b 会被回收
    //delete a2;
}

/**
 * shared_ptr ：智能指针
 * 操作引用计数实现共享式拥有的概念。
 * 多个智能指针可以指向相同的对象，这个对象和其相关资源会在最后一个被销毁时释放。
 *
 * 虽然使用shared_ptr能够非常方便的为我们自动释放对象，但是还是会出现一些问题。
 * 最典型的就是循环引用问题。
 */
int main() {//智能指针
    //c++ 11 stl 两种类型智能指针
    // shared_ptr : 共享，内部实现了引用计数
//    testPtr();
    auto i=5;

    /**
     * 新特性
     * 类型推导auto decltype
     */
    vector <int >vector1={1,2,3,4,5};
    decltype(vector1) j;//推导vector1是j
    for (auto v :vector1) {
        cout<<v<<endl;
    }
//    const vector<int, std::__1::allocator<int>>::iterator &iter = vector1.begin();
    auto iter = vector1.begin();
    for (;iter!=vector1.end() ;iter++){
        cout<<"vector1:"<<*iter<<endl;
    }
    // [&] 表示外部变量都以引用的形式在lambda中使用，函数内部修改i的值会影响外部
    // 这里的 -> auto 自动推导在c++11不支持，c++14中对auto进行了扩展
    thread t1([&]{
        i=10;
        cout << "线程" << i << endl;
        return 1;
    });
//    _sleep(10);

}
