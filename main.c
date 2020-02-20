#include <stdio.h>//系统默认目录和cmake配置目录
#include "L1_Simple.h"//相对目录
void test(){
    printf("test\n");
};
unsigned int i=10;
int j=9;

//u_int32_t
/**
 * java 中的long 相当于C longlong
 * @return
 */
int main() {
    printf("Hello, World!\n");
    printf("%d\n",i);
    printf("%u\n",j);

    char str[100];
//    sprintf(str, "img/png_%d.png", 1);
    sprintf(str, "img/png_%s.png", "pic1");
    printf("%s\n", str);

//使用 0 补到3个字符
    sprintf(str, "img/png_%03d.png", 1);
    printf("%s\n", str);
    test();
    test1();
    test3();
    return 0;
}
