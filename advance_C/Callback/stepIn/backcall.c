//  http://towerjoo.github.com/blog/2012/12/14/c-callback-learning/

#include<stdio.h>

// use typedef to ease the declaration
typedef int (*pNotifyChange)(int nProgress);

// the callback function, which should match the
// the signature of the callback function, i.e
// pNotifyChange here
int onNotify(int nProgress){
    printf("Current progress: %d\n", nProgress);
    return 1;
}

// the caller which will consume the callback
int download(pNotifyChange notify){
    int i = 0;
    int step = 20;
    for (; i <= 100; i += step){
        notify(i);  // callback is called here
    }
    return 0;
}

// main entry point
int main(){
    pNotifyChange notify = onNotify;  
    download(notify);

	// 是否多此一举呢？ 直接 download(onNotify)；	不就结了？！！！

    return 0;
}



// 毁掉函数的精髓  Main函数中去调用download（）函数，
// download（）函数以 另外一个函数的指针作为参数，
// 并在其中对该函数进行调用
// 常常用typedef 提前定义函数指针

