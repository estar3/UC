//exit函数演示
#include<stdio.h>
#include<stdlib.h>//exit
#include<unistd.h>
//退出处理函数
void doit(void){
    printf("我是退出处理函数\n");
}
//退出处理函数
void doit2(int status,void* arg){
    printf("status = %d\n",status);
    printf("arg = %s\n",(char*)arg);
}

int fun(void){
    printf("fun函数被调用\n");
    exit(0);
    //_exit(0);
    return 10;
}

int main(void){
    //注册退出处理函数
    atexit(doit);
    on_exit(doit2,"hello");
    int ret = fun();
    printf("fun函数返回%d\n",ret);
    return 0;
}

