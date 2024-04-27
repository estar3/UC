//内存映射
#include<stdio.h>
#include<string.h>
#include<sys/mman.h>

int main(void){
    //内存映射
    char* start = (char*)mmap(NULL,8192,PROT_READ | PROT_WRITE,MAP_PRIVATE | MAP_ANONYMOUS,0,0);
    if(start == MAP_FAILED){
        perror("mmap");
        return -1;
    }
    //使用
    strcpy(start,"小鸡炖蘑菇");//写入数据
    printf("%s\n",start);//读取数据
    //解除一个页映射
    if(munmap(start,4096) == -1){
        perror("munmap");
        return -1;
    }
    //printf("%s\n",start); //解除映射后,虚拟地址访问段错误
    //第二个页 可用
    char* p2 = start + 4096;
    strcpy(p2,"铁锅炖大鹅");
    printf("%s\n",p2);
    //解除第二个页映射
    if(munmap(p2,4096) == -1){
        perror("munmap");
        return -1;
    }
    return 0;
}




