//
// Created by JoshuaChang on 2020/2/20.
//

#ifndef LEARNC_L02MYFPRINTF_H
#define LEARNC_L02MYFPRINTF_H

#endif //LEARNC_L02MYFPRINTF_H

#include <stdarg.h>

//my_sprintf(text,"id: %d, score:%d\n",2,1);

void my_sprintf(char *buffer, const char *fmt, ...) {
    va_list vaList;
    va_start(vaList, fmt);
    char *b = buffer;
    int count = 0;
    while (*fmt) {
        if (*fmt != '%') {
            count++;
            *b++ = *fmt++;
            continue;//不命中时（读取到%） 循环下一个
        }
        fmt++;
        switch (*fmt) {
            case 'd': {
                int i = va_arg(vaList, int);//取可变参数
                int j = 0;
                char temp[10];
                int sign = i < 0 ? 1 : 0;//正负号
                do {
                    int r = i % 10;//个位-十位-百位
                    r = r < 0 ? -r : r;
                    temp[j++] = r + '0';//int 转char arsc码
                } while (i /= 10);//一只除10，直到0时false
                //i= 888 tmp =  888
                // i= -123 tmp = 321-
                if (sign) { temp[j++] = '-'; }
                while (j > 0) {
                    char a = temp[--j];
                    *b++ = a;
                    count++;
                }
            }
                break;
            default:
                printf("xxxxx\n");
                break;
        }
        fmt++;
    }
    buffer[count] = '\0';
    va_end(vaList);
}