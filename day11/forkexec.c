//fork + exec
#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
int main(void){
    //创建子进程
    pid_t pid = fork();
    if(pid == -1){
        perror("fork");
        return -1;
    }
    //子进程代码
    if(pid == 0){
        if(execl("./new","new","hello",NULL) == -1){
            perror("execl");
            return -1;
        } 
        //return 0;
    }
    //父进程代码
    int s;//用阿里输出终止状态
    if(waitpid(pid,&s,0) == -1){
        perror("waitpid");
        return -1;
    }
    if(WIFEXITED(s)){
        printf("正常终止:%d\n",WEXITSTATUS(s));
    }else{
        printf("异常终止:%d\n",WTERMSIG(s));
    }

    //创建第二个子进程
    pid = fork();
    if(pid == -1){
       perror("fork");
       return -1;
    }
    if(pid == 0){
        if(execl("/bin/ls","ls","-l","--color=auto",NULL) == -1){
            perror("execl");
            return -1;
        }
    }

    if(waitpid(pid,&s,0) == -1){
        perror("waitpid");
        return -1;
    }
    if(WIFEXITED(s)){
        printf("正常终止:%d\n",WEXITSTATUS(s));
    }else{
        printf("异常终止:%d\n",WTERMSIG(s));
    }
    return 0;
}



