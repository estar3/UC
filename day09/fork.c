//创建子进程
#include<stdio.h>
#include<unistd.h>

int main(void){
    //创建子进程
    printf("%d进程:我是父进程,我要创建子进程了\n",getpid());
    pid_t a = fork();
    if(a == -1){
        perror("fork");
        return -1;
    }
    if(a == 0){
        printf("%d进程:这是子进程的代码\n",getpid());
        return 0;
    }
    printf("%d进程:这是父进程的代码\n",getpid());

    pid_t b = fork();
    if(b == 0){
        printf("%d进程:我是二儿子\n",getpid());
        return 0;
    }
    printf("%d进程:我有创建了一个子进程\n",getpid());

    return 0;

    /*if(a == 0){
        printf("%d进程:锅包肉\n",getpid());
        return 0;
    }else{
        printf("%d进程:地三鲜\n",getpid());
        return 0;
    }

    printf("%d进程:铁锅炖大鹅\n",getpid());
    return 0;*/

}
