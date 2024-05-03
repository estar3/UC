//标准IO
#include <stdio.h>

int main(void)
{
    FILE* fp = fopen("./stdio.txt", "w");
    if(fp == NULL)
    {
        perror("fopen");
        return -1;
    }
    for(int i = 0; i < 1000000; i++)
    {
        fwrite(&i, sizeof(i), 1, fp);
    }
    fclose(fp);

    return 0;
}