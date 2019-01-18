#include <stdlib.h>
#include <stdio.h>

int main () {

   pid_t pid;
   int   i;
   char  c;
   
   do {
      for (i = 0; i < 10; i++) {

         pid = fork();

         if (pid > 0) printf ("Zombie pid = %d created\n", pid);
         else         exit (0);

      }   
      c = getchar();

   }   while ('Z' == c);

   return 0;

}
