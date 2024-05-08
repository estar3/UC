//access函数演示
#include<stdio.h>
#include<unistd.h>

int main(int argc,char* argv[]){
    // ./a.out  hello.c
    // hello.c可读,可写,可执行
    // hello.c不存在
    printf("文件:%s",argv[1]);
    if(access(argv[1],F_OK) == -1){
        //不存在
        printf("不存在\n");
    }else{
        //存在
        if(access(argv[1],R_OK) == -1){
            printf("不可读,");
        }else{
            printf("可读,");
        }
        
        if(access(argv[1],W_OK) == -1){
            printf("不可写,");
        }else{
            printf("可写,");
        }

        if(access(argv[1],X_OK) == -1){
            printf("不可执行\n");
        }else{
            printf("可执行\n");
        }
    }
    return 0;
}
