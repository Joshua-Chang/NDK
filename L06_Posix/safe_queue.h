//
// Created by JoshuaChang on 2020/2/21.
//

#ifndef LEARNC_SAFE_QUEUE_H
#define LEARNC_SAFE_QUEUE_H

#endif //LEARNC_SAFE_QUEUE_H

#include <queue>
#include <pthread.h>

using namespace std;
template <typename T>
class SafeQueue{
public:
    SafeQueue() {
        pthread_mutex_init(&mutex,0);
        pthread_cond_init(&cond,0);
    }
    ~SafeQueue() {
        pthread_mutex_destroy(&mutex);
        pthread_cond_destroy(&cond);
    }
    void push(T t){//插入
        pthread_mutex_lock(&mutex);
        q.push(t);
        //notify
//        pthread_cond_signal(&cond);//由系统唤醒一个线程
        pthread_cond_broadcast(&cond);//广播 对应多个消费者的时候 多个线程等待唤醒所有
        pthread_mutex_unlock(&mutex);
    }
    //需求：queue为空时等待，直到下一次push产生数据（java：wait notify或者 条件变量）
    void pop(T& t){//取出 赋值到t
        pthread_mutex_lock(&mutex);

        /*if (!q.empty){
            t=q.front();//取队首
            q.pop();
        }*/

        //使用条件变量（挂起 释放锁）
        while (q.empty()){//可能被意外唤醒 所以while循环 不用if（！q.empty()）
            pthread_cond_wait(&cond,&mutex);//wait
        }
        t=q.front();
        q.pop();

        pthread_mutex_unlock(&mutex);
    }

private:
    queue<T>q;
    pthread_mutex_t mutex;//互斥锁
    pthread_cond_t cond;//条件变量

};
