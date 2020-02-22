//
// Created by JoshuaChang on 2020/2/21.
//
/**
 * 容器 stl:标准模板库
 * 序列式 与 关联式
 * 序列式容器 ： 元素排列顺序与元素本身无关，由添加顺序决定的
 * vector、list、dequeue、queue、stack  priority queue
 * 关联式容器:元素是按关键字来保存和访问的 支持高效的关键字查找与访问
 * set map
 * 异常
 */
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <fstream>

using namespace std;


vector<int> vec;

void testVec() {
    vec.push_back(1);
    vec.push_back(2);
    vec.clear();
    cout << "testVec: clear " << vec.capacity() << endl;
    //swap  替换来释放
    vector<int> v;
    v.swap(vec);
    cout << "testVec: swap " << vec.capacity() << endl;
}


class Type {
public:
    int i;

    Type(int i) : i(i) {}
};

struct TypeLess
{
    constexpr bool operator()(const Type& _Left, const Type& _Right) const
    {

        return (_Left.i < _Right.i);
    }
};


class Parent {
public:
    int i;
    virtual void test() {
        cout << "parent" << endl;
    }
};
class Child :public Parent {
public:
    void test() {
        cout << "child" << endl;
    }
};


void testExeceptioon1() {
    throw "yic";
}
void testExeceptioon2() {
    throw exception();
}
void testExeceptioon3() {
    Child child ;
    child.i=10086;
    throw child;
}

int main() {
    /**
     * vector：连续存储的元素，支持快速随机访问
     */

//    声明

    vector<int> vec_1;
    // 声明有一个元素空间
    vector<int> vec_2(1);
    // 6个元素 值都是1
    vector<int> vec_3(6, 1);
    vector<int> vec_4(vec_3);

//    使用
    vec_1.push_back(10);//增
    vec_1.push_back(20);
    vec_1.push_back(30);
    vec_1.pop_back();//删

    cout << vec_1[0] << endl;//取:根据下标
    cout << vec_1.at(0) << endl;//取:根据下标
    cout << vec_1.front() << endl;//取:队首
    cout << vec_1.back() << endl;//取:队尾

    cout << "容积：" << vec_1.capacity() << endl;//容积

    vec_1.clear();//清空(清空元素 但内存继续占着)
    vec_1.erase(vec_1.begin(), vec_1.end());//清空1到2
    testVec();//swap  替换来释放

/**
 * queue：先进先出的值的排列
 * priority_queue:优先级队列
 */
    queue<int> q;
    q.push(1);//增
    q.push(2);
    q.pop();//取
    cout << q.front() << endl;

//    priority_queue<int> priorityQueue;//默认最大到在最前面
    //!!!!!!!!!!!!!!! 注意> >一定要隔开
//    priority_queue<int, vector<int>, less<int> > priorityQueue;//默认最大到在最前面
    priority_queue<int, vector<int>, greater<int> > priorityQueue;//默认最大到在最前面
    priorityQueue.push(2);
    priorityQueue.push(3);
    priorityQueue.push(1);
    cout << priorityQueue.top() << endl;

    // 不知道如何给 Type 排序
    // TypeLess : 自定义 TypeLess 对type进行排序指定
    priority_queue<Type,vector<Type>,TypeLess>typePriorityQueue;
    typePriorityQueue.push(Type(2));
    typePriorityQueue.push(Type(1));
    typePriorityQueue.push(Type(3));
    cout <<"Type默认优先级 排列"<< typePriorityQueue.top().i << endl;


    /**
     * stack：后进先出的值的排列
     */

    stack<int> s;
    s.push(1);
    s.push(2);
    s.pop();
    cout << s.top() << endl;


    /**
     * set 集合 元素不可重复
     */
    set<int> set1={1,2,3,4};
    pair<set<int>::iterator, bool> _pair=set1.insert(5);//返回pair k ：迭代器 V；是否成功
    set1.insert(1);
    set1.insert(1);
    set1.erase(1);//清除指定
    cout<<"set size: "<<set1.size()<<endl;
    //使用迭代器
    const set<int>::iterator &iteratorBegin = set1.begin();//指向容器中第0个元素
    const set<int>::iterator &iteratorEnd = set1.end();//指向容器中 最后一个的下一个元素

    vector <int> vector1;
    vector1.push_back(10);
    vector1.push_back(20);
    vector<int>::iterator it=vector1.begin();
    for (; it<vector1.end(); ){
        if (*it==10){
            it=vector1.erase(it);
        } else{
            it++;
        }
    }
    it = vector1.begin();
//    for (;it<vector1.end() ;++it){
    for (;it!=vector1.end() ;++it){
        cout<<"vector1:"<<*it<<endl;
    }

    map<int,string>map1;
    map<int, string> map2 = { {1,"A"},{2,"B"} };
    map2.insert({3,"C"});
    map2[3]="D";

    //新式转换
    //转换操作符
    //const_cast : 主要 修改类型的const 与 volatile 属性
    const char *p = "123";
    char *b = const_cast<char*>(p);

    // 编译时确定
    Child  *p1 = new Child;
    Parent  *c1 = static_cast<Parent*>(p1);
    //输出c
    c1->test();
    //dynamic_cast 父类必须有一个 虚函数
    // 动态绑定: 运行时候 确定调用的函数
    Child  *p11 = new Child;
    Parent  *c11 = dynamic_cast<Parent*>(p11);
    if (!c11) {
        cout << "转换失败" << endl;
    }
    else {
        cout << "转换成功" << endl;
        c11->test();
    }

    float i = 10;
    float *j = &i;
    //&i float指针，指向一个地址，转换为int类型，j就是这个地址
//    int k = reinterpret_cast<int>(j);



    /**
     * 异常
     */


    try {
        testExeceptioon1();
    }
    catch (const char* e) {
        cout << "异常:" <<e<< endl;
    }

    try {
        testExeceptioon2();
    }
    catch (exception e) {
        cout << "异常:" <<e.what()<< endl;
    }
    try {
        testExeceptioon3();
    }
    catch (Child child) {
        cout << "异常:" <<child.i<< endl;
    }


    /**
     * 文件读写流
     */

    // 文本形式写入
//    FILE *f1=fopen("/Users/joshuachang/CLionProjects/LearnC/L05_Container/a.txt","w");
//    fprintf(f1,"hello world %d",80);

    FILE *f2=fopen("/Users/joshuachang/CLionProjects/LearnC/L05_Container/a.txt","r");
    char buffer [1024];
//    while (!feof(f2)){
//        fscanf(f2, "%s", buffer);
//        cout<<"read text: "<<buffer<<endl;
//    }
    fgets(buffer,1024,f2);
    cout << "读取到文件：" << buffer << endl;


//    fclose(f1);
    fclose(f2);


    //操作一张图片 一个视频 二进制的形式
//    fwrite();

    char data[100];
    ofstream outfile;
    outfile.open("/Users/joshuachang/CLionProjects/LearnC/L05_Container/b.txt");
    cout<<"input ...";
    //cin 接收终端的输入
    cin >> data;
    // 向文件写入用户输入的数据
    outfile << data << endl;
    // 关闭打开的文件
    outfile.close();


    // 以读模式打开文件
    ifstream infile;
    infile.open("/Users/joshuachang/CLionProjects/LearnC/L05_Container/b.txt");

    cout << "读取文件" << endl;
    infile >> data;
    cout << data << endl;

    // 关闭
    infile.close();


    return 0;
}
