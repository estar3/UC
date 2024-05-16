//子进程是否会继承父进程的信号处理方式
#include<stdio.h>
#include<unistd.h>
#include<signal.h>
#include<sys/wait.h>
//信号处理函数
void sigfun(int signum){
    printf("%d进程:捕获到%d号信号\n",getpid(),signum);
}
int main(void){
    //忽略2号信号
    if(signal(SIGINT,SIG_IGN) == SIG_ERR){
        perror("signal");
        return -1;
    }
    //捕获3号信号
    if(signal(SIGQUIT,sigfun) == SIG_ERR){
        perror("signal");
        return -1;
    }
    //创建子进程
    pid_t pid = fork();
    if(pid == -1){
        perror("fork");
        return -1;
    }
    //子进程代码暂时不结束 
    if(pid == 0){
        printf("%d进程:我是子进程\n",getpid());
        sleep(20);
        return 0;
    }
    //父进程代码
    if(wait(NULL) == -1){
        perror("wait");
        return -1;
    }
    printf("%d进程:回收了子进程的僵尸\n",getpid());
    return 0;
}



