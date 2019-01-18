#include <stdlib.h>
#include <stdio.h>

int main () {

   pid_t pid;
   int   i;

   for (i = 0; i < 10; i++) {

      pid = fork();

      if (pid > 0) printf ("Zombie pid = %d created\n", pid);
      else         {puts   ("Buh!"); exit (0);}

   }

   puts ("waiting");
   getchar ();
   return 0;

}
