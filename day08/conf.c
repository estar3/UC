//写冲突
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char* argv[])
{
    //./a/out hello
    if(argc < 2)
    {
        fprintf(stderr, "用法：./a.out <字符串>\n");
        return -1;
    }
    //打开文件
    int fd = open("./conf.txt", O_WRONLY | O_CREAT | O_APPEND, 0644);
    if(fd == -1)
    {
        perror("open");
        return -1;
    }
    //写入数据 argv[0] --> "./a.out" argv[1] --> "hello"
    for(int i = 0; i < strlen(argv[1]); i++)
    {
        write(fd, &argv[1][i], sizeof(argv[1][i]));
        sleep(1);
    }
    //关闭文件
    close(fd);

    return 0;
}