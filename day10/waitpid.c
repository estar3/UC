//回收特定子进程
#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>

int main(void){
    //创建多个子进程
    pid_t pids[5];//存储子进程的ID
    for(int i = 0;i < 5;i++){
        pids[i] = fork();
        if(pids[i] == -1){
            perror("fork");
            return -1;
        }
        if(pids[i] == 0){
            printf("%d进程:我是老%d\n",getpid(),i+1);
            sleep(i+1);
            return 0;
        }
    }
    //父进程回收子进程    
    for(int i = 4;i >= 0;i--){
        printf("我要收%d进程的僵尸\n",pids[i]);
        pid_t pid = waitpid(pids[i],NULL,0);
        if(pid == -1){
            perror("waitpid");
            return -1;
        }
        printf("我回收了%d进程的僵尸\n",pid);
    }
    return 0;
}




