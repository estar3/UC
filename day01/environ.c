//环境变量
#include<stdio.h>

int main(int argc,char* argv[],char* envp[]){
    extern char** environ;
    /*for(char**pp = environ;*pp;pp++){
        printf("%s\n",*pp);
    }*/
    printf("environ = %p\n",environ);
    printf("envp    = %p\n",envp);
    for(char** pp = envp;*pp;pp++){
        printf("%s\n",*pp);
    }
    return 0;
}

