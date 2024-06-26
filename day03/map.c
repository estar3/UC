//虚拟地址空间布局
#include<stdio.h>
#include<stdlib.h>
const int const_global = 1;//常全局变量
int init_global = 2;//初始化全局变量
int uninit_global;//未初始化全局变量

int main(int argc,char* argv[],char* envp[]){
    const static int const_static = 3;//常静态变量
    static int init_static = 4;//初始化静态变量
    static int uninit_static;//未初始化静态变量
    const int const_local= 5;//常局部变量
    int local;//局部变量
    int* heap = malloc(sizeof(int));//堆变量
    *heap = 6;
    char* string = "abc";//字面值常量
    printf("------参数和环境变量-------\n");
    printf("        命令行参数:%p\n",argv);
    printf("          环境变量:%p\n",envp);
    printf("------------栈区-----------\n");
    printf("        常局部变量:%p\n",&const_local);
    printf("          局部变量:%p\n",&local);
    printf("------------堆区-----------\n");
    printf("            堆变量:%p\n",heap);
    printf("-----------BSS区-----------\n");
    printf("  未初始化全局变量:%p\n",&uninit_global);
    printf("  未初始化静态变量:%p\n",&uninit_static);
    printf("------------数据区---------\n");
    printf("    初始化全局变量:%p\n",&init_global);
    printf("    初始化静态变量:%p\n",&init_static);
    printf("------------代码区---------\n");
    printf("              函数:%p\n",main);
    printf("        常全局变量:%p\n",&const_global);
    printf("        常静态变量:%p\n",&const_static);
    printf("        字面值常量:%p\n",string);
    printf("---------------------------\n");
    return 0;
}







