//暂停 pause函数
#include<stdio.h>
#include<unistd.h>
#include<signal.h>
#include<sys/wait.h>
//信号处理函数
void sigfun(int signum){
    printf("%d进程:%d号信号处理开始\n",getpid(),signum);
    sleep(3);
    printf("%d进程:%d号信号处理结束\n",getpid(),signum);
}

int main(void){
    //创建子进程
    pid_t pid = fork();
    if(pid == -1){
        perror("fork");
        return -1;
    }
    //子进程睡觉
    if(pid == 0){
        //对2号信号进行捕获
        if(signal(SIGINT,sigfun) == SIG_ERR){
            perror("signal");
            return -1;
        }
        printf("%d进程:我是子进程,我要一睡不醒\n",getpid());
        int res = pause();
        printf("%d进程:pause函数返回%d\n",getpid(),res);
        return 0;
    }
    //父进程发信号,打断子进程睡觉
    printf("%d进程:我是父进程,要给子进程发送2号信号\n",getpid());
    getchar();
    if(kill(pid,SIGINT) == -1){
        perror("kill");
        return -1;
    }
    if(wait(NULL) == -1){
        perror("wait");
        return -1;
    }
    return 0;
}
