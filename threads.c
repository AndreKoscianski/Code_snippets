#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>

pthread_t tid1, tid2;

int Gn = 0;

//#define NLOOP 0xFFFFFFFF
#define NLOOP 10222000

void* doSomeThing(void *arg) {

    unsigned long i = 0;
    pthread_t id = pthread_self();

    if (pthread_equal(id,tid1)) {
        printf("\n First thread processing\n");
        for(i=0; i < NLOOP; i++) 
           ++Gn;
    } else {
        printf("\n Second thread processing\n");
        for(i=0; i < NLOOP;i++) 
           --Gn;
    }

    return NULL;
}



int main(void) {

    if (pthread_create (&tid1, NULL, &doSomeThing, NULL)) {puts ("erro1"); exit(0);}
    if (pthread_create (&tid2, NULL, &doSomeThing, NULL)) {puts ("erro2"); exit(0);}

    void *ret1, *ret2;

    pthread_join (tid1, NULL);
    pthread_join (tid2, NULL);

    printf ("\nResultado Final = %d\n", Gn);

    return 0;
}
