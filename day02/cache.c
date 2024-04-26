//输出缓冲区
#include<stdio.h>

int main(void){
    printf("铁锅炖大鹅");
    fprintf(stderr, "我是stderr,不需要经过缓冲区\n");
    for(;;);
    return 0;
}

