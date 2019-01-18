/*------------------------------------------------------


para compilar

  g++ threads.cpp -lpthread

  ------------------------------------------------------
*/




#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#include <pthread.h> 
#include <semaphore.h>

pthread_t tid1, tid2;

static sem_t Gsem;

int Gn = 0;

#define NLOOP 10222000

void *doSomeThing (void *arg) {

    unsigned long  i = 0;

    printf ("Meu processo eh %d\n", getpid());

    if (pthread_equal (pthread_self(), tid1)) {

        printf("Primeira Thread em execucao, id = %d\n", (int)pthread_self());

        for(i = 0; i < NLOOP; i++) {
              ++Gn;
        }

    } else {

        printf("Segunda Thread em execucao, id = %d\n", (int)pthread_self());

        for(i = 0; i < NLOOP; i++) {
              --Gn;
        }
    }

    return NULL;
}



//===========================================================

int main (void) {


    if (pthread_create (&tid1, NULL, &doSomeThing, NULL)) {puts ("erro1"); exit(0);}
    if (pthread_create (&tid2, NULL, &doSomeThing, NULL)) {puts ("erro2"); exit(0);}

    pthread_join (tid1, NULL);
    pthread_join (tid2, NULL);

    printf ("\nResultado Final = %d\n", Gn);

    return 0;
}
