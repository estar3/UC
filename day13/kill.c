//kill函数演示
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<signal.h>
#include<errno.h>
#include<sys/wait.h>
//信号处理函数
void sigfun(int signum){
    printf("%d进程:捕获到%d号信号\n",getpid(),signum);
}
//用来判断进程是否存在的函数
int isexist(pid_t pid){
    if(kill(pid,0) == -1){
        if(errno == ESRCH){//kill失败是因为进程Pid不存在
            return 1;
        }else{
            perror("kill");
            exit(-1);
        }
    }
    return 0;//kill成功,表示进程pid存在
}

int main(void){
    //创建子进程
    pid_t pid = fork();
    if(pid == -1){
        perror("fork");
        return -1;
    }
    //子进程对2号进行捕获
    if(pid == 0){
        printf("%d进程:我是子进程\n",getpid());
        /*if(signal(SIGINT,sigfun) == SIG_ERR){
            perror("signal");
            return -1;
        }*/
        sleep(10);
        return 0;
    }
    //父进程向子进程发送2号信号
    printf("%d进程:我要向子进程发送2号信号\n",getpid());
    getchar();
    if(kill(pid,SIGINT) == -1){
        perror("kill");
        return -1;
    }
    getchar();
    printf("子进程%s\n",isexist(pid) ? "不存在" : "存在");

    if(wait(NULL) == -1){
        perror("wait");
        return -1;
    }

    getchar();
    printf("子进程%s\n",isexist(pid) ? "不存在" : "存在");

    return 0;
}



