//信号处理
#include<stdio.h>
#include<unistd.h>
#include<signal.h>

typedef void (*sighandler_t)(int);

//信号处理函数
void sigfun(int signum){
    printf("%d进程:捕获到%d号信号\n",getpid(),signum);
}

int main(void){
    //忽略2号信号
    sighandler_t ret = signal(SIGINT,SIG_IGN);
    if(ret == SIG_ERR){
        perror("signal");
        return -1;
    }
    printf("ret = %p\n",ret);//第一次处理返回 NULL
    //捕获2号信号
    ret = signal(SIGINT,sigfun);
    if(ret == SIG_ERR){
        perror("signal");
        return -1;
    }
    printf("ret = %p\n",ret);//上一次忽略处理,返回SIG_IGN -> 0x1
    //恢复默认处理
    ret = signal(SIGINT,SIG_DFL);
    if(ret == SIG_ERR){
        perror("signal");
        return -1;
    }
    printf("ret = %p\n",ret);
    printf("sigfun = %p\n",sigfun);
    for(;;);
    return 0;
}
