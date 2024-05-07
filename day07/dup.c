//文件描述符的复制
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

int main(void)
{
    //打开文件 得到文件描述符oldfd
    int oldfd = open("./dup.txt", O_CREAT | O_WRONLY | O_TRUNC, 0664);
    printf("oldfd = %d\n", oldfd);
    if(oldfd == -1)
    {
        perror("open");
        return -1;
    }
    //复制文件描述符oldfd --> newfd
    //int newfd = dup(oldfd);
    int newfd = dup2(oldfd, 1);
    printf("newfd = %d\n", newfd);
    if(newfd == -1)
    {
        perror("dup");
        return -1;
    }
    //通过oldfd向文件中写入数据hello world! 12
    char* buf = "hello world!";
    if(write(oldfd, buf, strlen(buf)) == -1)
    {
        perror("write");
        return -1;
    }
    //通过newfd修改文件读写位置
    if(lseek(newfd, -6, SEEK_END) == -1)
    {
        perror("lseek");
        return -1;
    } 
    //通过oldfd再次向文件写入数据Linux!
    buf = "Linux!";
    if(write(oldfd, buf, sizeof(buf)) == -1)
    {
        perror("write");
        return -1;
    }
    //关闭文件
    close(oldfd);
    close(newfd);
    return 0;
}