//非阻塞回收
#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<errno.h>

int main(void){
    //创建子进程
    pid_t pid = fork();
    if(pid == -1){
        perror("fork");
        return -1;
    }
    //子进程代码,暂时不结束
    if(pid == 0){
        printf("%d进程:我是子进程,就不结束\n",getpid());
        sleep(10);
        return 0;
    }
    //父进程回收子进程
    for(;;){
        pid_t pid = waitpid(-1,NULL,WNOHANG);
        if(pid == -1){
            if(errno == ECHILD){
                printf("%d进程:没有子进程了\n",getpid());
                break;
            }else{
                perror("waitpid");
                return -1;
            }
        }else if(pid == 0){
            printf("%d进程:子进程在运行,干饭去\n",getpid());
            sleep(1);
        }else{
            printf("%d进程:回收%d进程\n",getpid(),pid);
        }
    }
    
    return 0;
}




