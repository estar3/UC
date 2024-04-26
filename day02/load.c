//动态库的动态加载
#include<stdio.h>
#include<dlfcn.h>// dlopen dlsym dlclose dlerror

int main(void){
    //将动态库载入内存
    void* handle = dlopen("./shared/libmath.so",RTLD_NOW);
    if(handle == NULL){//dlopen 失败
        fprintf(stderr,"dlopen:%s\n",dlerror());
        return -1;
    }
    //获取库中函数的地址
    int (*add)(int,int) = dlsym(handle,"add");
    if(add == NULL){
        fprintf(stderr,"dlsym:%s\n",dlerror());
        return -1;
    }
    int (*sub)(int,int) = dlsym(handle,"sub");
    if(sub == NULL){
        fprintf(stderr,"dlsym:%s\n",dlerror());
        return -1;
    }
    void (*show)(int,char,int,int) = dlsym(handle,"show");
    if(show == NULL){
        fprintf(stderr,"dlsym:%s\n",dlerror());
        return -1;
    }
    //使用  
    int a = 123,b = 456;
    show(a,'+',b,add(a,b));
    show(a,'-',b,sub(a,b));
    //卸载动态库
    if(dlclose(handle)){
        fprintf(stderr,"dlclose:%s\n",dlerror());
        return -1;
    }
    return 0;
}








