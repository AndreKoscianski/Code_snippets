/*------------------------------------------------------

para compilar

  g++ threadsAB.cpp -lpthread

  ------------------------------------------------------
*/


#include <stdio.h>
#include <pthread.h> 


pthread_t tid1, tid2;


void *function (void *arg) {

    unsigned long  k = 50000;

    char x = 'A' + (pthread_self() == tid1);
	 
    while (k--) putchar (x);

    return NULL;
}



//===========================================================

int main (void) {

    if (pthread_create (&tid1, NULL, function, NULL)) {puts ("erro1"); return -1;}
    if (pthread_create (&tid2, NULL, function, NULL)) {puts ("erro2"); return -1;}

    pthread_join (tid1, NULL);
    pthread_join (tid2, NULL);

    return 0;
}
