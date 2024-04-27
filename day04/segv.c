//段错误演示
#include<stdio.h>

int main(void){
    //int *p = (int*)0x12345678;
    int* p = NULL;
    printf("p = %p\n",p);
    //*p = 1;  //段错误

    const static int i = 1;
    *(int*)&i = 2;
    printf("i = %d\n",i);
    return 0;
}

