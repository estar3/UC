//重定向
#include <stdio.h>
#include <fcntl.h> //open
#include <unistd.h> //close

int main(void)
{
    close(STDOUT_FILENO); //关1
    int fd = open("./redir.txt", O_WRONLY | O_CREAT | O_TRUNC, 0664);
    if(fd == -1)
    {
        perror("open:");
        return -1;
    }

    close(STDIN_FILENO); //关0
    int fd1 = open("./in.txt", O_RDONLY);
    if(fd1 == -1)
    {
        perror("open:");
        return -1;
    }
    int a,b;
    scanf("%d%d",&a,&b);
    printf("fd = %d + %d = %d\n", a, b, a+b);
    

    return 0;
}