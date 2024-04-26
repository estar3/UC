//错误处理
#include<stdio.h>
#include<string.h>// strerror();
#include<stdlib.h>
#include<errno.h> // 全局变量 errno

int main(void){
    void* p = malloc(0xffffffffffffffff);
    if(p == NULL){//malloc 失败-->原因-->编号-->errno
        fprintf(stderr,"errno = %d\n",errno);
        fprintf(stderr,"malloc:%s\n",strerror(errno));
        perror("malloc");
        return -1;
    }
    free(p);
    FILE*fp = fopen("cache.c","r");
    //if(errno){
    if(fp == NULL){
        perror("fopen");
        return -1;
    }
    fclose(fp);
    return 0;
}

