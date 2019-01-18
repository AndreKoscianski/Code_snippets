#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <stdio.h>

int main (void) {

   int fd;
   FILE *f;

   fd = open("saida.txt", O_CREAT|O_TRUNC|O_WRONLY,0666);
    f = fopen("saida2.txt","wt");

   if (!fork()) {
      write (fd,"child ",6);
      fputs ("child ", f); 
      _exit(0);
   } else {
      int status;
      wait (&status);
      write (fd,"mom!! ",6);
      fputs ("mom!! ", f);
   }
   return 0;
}
