//
// Created by JoshuaChang on 2020/2/21.
//
#include <pthread.h>
#include <iostream>
using namespace std;
void * pthreadtask(void* args){//void* 相当于任意类型
    int * i= static_cast<int*>(args);
    cout << "posix线程:" << *i << endl;
    return 0;
}
void * pthreadtask1(void* args){//void* 相当于任意类型
    string *s= static_cast<string *>(args);
    cout << "posix线程1:" << *s << endl;
    return 0;
}
int main(){
    pthread_t pid;
    pthread_t pid1;
    pthread_attr_t attr;	//线程属性
    pthread_attr_t attr1;	//线程属性
    pthread_attr_init(&attr);
    pthread_attr_init(&attr1);

    int i=100;
    pthread_create(&pid,&attr,pthreadtask,&i);
    string *t_name=new string(" this is a thread");
    pthread_create(&pid1,&attr1,pthreadtask1,t_name);
//    线程创建默认是非分离的，当pthread_join()函数返回时，创建的线程终止，释放自己占用的系统资源
//设置是否为分离线程
//PTHREAD_CREATE_DETACHED 分离
//PTHREAD_CREATE_JOINABLE 非分离
//    pthread_attr_setdetachstate(&attr,PTHREAD_CREATE_DETACHED);
//    分离线程不能被其他线程等待,pthread_join无效，线程自己玩自己的。


    //设置调度策略

//返回0 设置成功
//    pthread_attr_setschedpolicy(&attr, SCHED_FIFO);
    // SCHED_FIFO
//	实时调度策略，先到先服务 一旦占用cpu则一直运行。一直运行直到有更高优先级任务到达或自己放弃。
// SCHED_RR
//	实时调度策略，时间轮转 系统分配一个时间段，在时间段内执行本线程

    //设置优先级

//获得对应策略的最小、最大优先级
//    int max = sched_get_priority_max(SCHED_FIFO);
//    int min = sched_get_priority_min(SCHED_FIFO);
//    sched_param param;
//    param.sched_priority = max;
//    pthread_attr_setschedparam(&attr, &param);


    pthread_join(pid,0);
    pthread_attr_destroy(&attr);
    pthread_attr_destroy(&attr1);
//    cout << "posix线程: 执行完毕" << endl;

    return 0;
}

