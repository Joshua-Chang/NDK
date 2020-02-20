//
// Created by JoshuaChang on 2020/2/20.
//
/**
 * 1、指针
 * 2、数组指针
 * 3、多级指针
 * 4、const
 */
#include <stdio.h>

int main() {
    //指针
    int i1 = 10;
    int *p1 = &i1;//* 指针p1 指针p1的值为i1的地址
    printf("i1 address:%#x ,p1:%#x ,&p1:%#x\n sizeof(p)=%d\n", &i1, p1, &p1, sizeof(p1));
    printf("*p1=%d\n", *p1);
    *p1 = 100;//* 解引用 p1指向一个内存地址，使用*解出这个地址的值 即为 10
    printf("*p1=%d\n", *p1);
    p1++;
    printf("*p1=%d\n", *p1);


//对指针 进行算数运算
//数组是一块连续内存 分别保存 11-55
    int i2[] = {11, 22, 33, 44, 55};
    int *p2 = i2;//将数组名赋值给一个指针，这时候指针指向数组首元素地址
    for (size_t i = 0; i < 5; i++) {
        //自增++ 运算符比 解引用* 高,但++在后为先用后加
        //如果++在前则输出 22-55+xx

        printf("%d\n", *p2++);

//        printf("%d\n", *(i2+i));
    }

    //直接输出数组名会得到数组首元素的地址
    printf("%#x\n", i2);
    //解引用
    printf("%d\n", *i2);


    /**
     * 数组指针：
     */
    int array1[2][3] = {{1, 2, 3},
                        {4, 5, 6}};
//  等于  int array[6]={1,2,3,4,5,6};//一块六个连续的内存
//  等于  int array[2][3]={1,2,3,4,5,6};//一块连续两个内存，分别有三个连续内存
    int (*array_p1)[3] = array1;
    int v = *(*(array_p1 + 1) + 1);
    printf("array[2][2]=%d=%d\n", v, array1[1][1]);

    /**
     * 指针数组
     */
    int *array_p2[3]={&i1,&i1,&i1};



    /**
     * const  相当于java的final
     * const 修饰谁表示谁不可变 从右往左看
     */
    char temp[]="hello";
    const char *p_2=temp;//*p2不可变 p2可变 //指针p_2 指向一个类型为const char的数据
    char const *p_3=temp;//（const 不能修饰* 往前找）等于p2
//    p_2[0]='v';
//    *p_2=&i1;指针地址不可变
    p_2="world";//指针值可变

    char * const p_4=temp;//p4不可变 *p4可变
//    p_4="world"//指针值不可变
    p_4[0]='x';
    *p_4='a';//指针地址可变

    const char *const p_5=temp;
    char const *const p_6=temp;
    //都不可以变

    /**
     * 多级指针
     */
    int x=10;
    int *px=&x;
    int **ppx=&px;//指针的指针

    printf("px=%#x pxx=%#x\n",px,ppx);
    printf("*px=%d *pxx=%#x **pxx=%d\n",*px,*ppx,**ppx);

}