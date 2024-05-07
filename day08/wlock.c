//文件锁
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
int main(int argc, char* argv[])
{
    //./a.out hello
    if(argc < 2)
    {
        fprintf(stderr, "用法：./a.out <字符串>\n");
        return 0;
    }
    //打开文件
    int fd = open("./conf.txt", O_WRONLY | O_CREAT | O_APPEND, 0664);
    if(fd == -1)
    {
        perror("open");
        return -1;
    }
    //加锁
    struct flock lock; //锁信息
    lock.l_type = F_WRLCK; //写锁
    lock.l_whence = SEEK_SET;
    lock.l_start = 0;
    lock.l_len = 0;//一直锁到文件尾
    lock.l_pid = -1; 
    //阻塞方式加锁
    /*if(fcntl(fd, F_SETLKW, &lock) == -1)
    {
        perror("fcntl");
        return -1;
    }*/
    //非阻塞方式加锁
    while(fcntl(fd, F_SETLK, &lock) == -1)      //-1的原因 --> 系统环境问题/参数不对/非阻塞方式加锁但锁没有加上
    {
        if(errno == EACCES || errno == EAGAIN)
        {
            printf("文件被锁定，加不上锁，不等了，干点别的去\n");
            sleep(1);
        }
        else
        {
            perror("fcntl");
            return -1;
        }
    }

    //写入数据 argv[0] --> "./a.out"    argv[1] --> "hello"
    for(int i = 0; i < strlen(argv[1]); i++)
    {
        write(fd, argv[1] + i, sizeof(argv[1][i]));
        sleep(1);
    }
    //解锁
    struct flock unlock;
    unlock.l_type = F_UNLCK;
    unlock.l_whence = SEEK_SET;
    unlock.l_start = 0;
    unlock.l_len = 0;
    unlock.l_pid = -1;

    if(fcntl(fd, F_SETLK, &unlock) == -1)
    {
        perror("fcntl");
        return -1;
    }
    //关闭文件
    close(fd);

    return 0;
}