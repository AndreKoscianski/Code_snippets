#include <pthread.h>
#include <stdio.h>
#include <signal.h>
#include <sys/time.h>
#include <unistd.h>

int ok = 0;

void *inc_x(void *x_void_ptr) {

   int *x_ptr = (int *) x_void_ptr;

   ok = 1;

   while(++(*x_ptr) < 1000000);

   printf("x increment finished\n");

   return NULL;
}



void sigalrm_handler(int signum) {
  if (ok)
     pthread_yield();
}


void thetimer() {
  struct itimerval timer={0};
  char a[200];

  /* Initial timeout value */
  timer.it_value.tv_sec = 0;
  timer.it_value.tv_usec = 200000;

  /* We want a repetitive timer */
  timer.it_interval.tv_sec = 0;
  timer.it_interval.tv_usec = 100000;

  /* Register Signal handler
   * And register for periodic timer with Kernel*/
  signal(SIGALRM, &sigalrm_handler);
  setitimer(ITIMER_REAL, &timer, NULL);
}


int main() {

   int x = 0, y = 0;

   thetimer();

   puts ("here we go");
   getchar ();

   printf("Initial values x: %d, y: %d\n", x, y);

   pthread_t inc_x_thread;

   if (pthread_create(&inc_x_thread, NULL, inc_x, &x)) 
      return 1;

   while(++y < 1000000);

   /* wait for the second thread to finish */
   if (pthread_join(inc_x_thread, NULL))
      return 2;

   printf("Resultado final x: %d, y: %d\n", x, y);

return 0;

}
