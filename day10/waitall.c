//回收多个子进程
#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<errno.h>
int main(void){
    //创建多个子进程
    for(int i = 0;i < 5;i++){
        pid_t pid = fork();
        if(pid == -1){
            perror("fork");
            return -1;
        }
        if(pid == 0){
            printf("%d进程:我是子进程\n",getpid());
            sleep(1 + i);
            return i;
        }
    }
    //回收多个子进程
    for(;;){
        int s;//用来输出子进程的终止状态
        pid_t pid = wait(&s);
        if(pid == -1){
            if(errno == ECHILD){
                printf("没有子进程回收\n");
                break;
            }else{
                perror("wait");
                return -1;
            }
        }
        printf("%d进程:回收了%d进程\n",getpid(),pid);
        if(WIFSIGNALED(s)){
            printf("异常终止:%d\n",WTERMSIG(s));
        }else{
            printf("正常终止:%d\n",WEXITSTATUS(s));
        }
    }

    return 0;
}






