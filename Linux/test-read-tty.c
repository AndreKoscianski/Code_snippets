#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <stdio.h>

int main (void) {

   int fd, n;
   char buf[] = "abcdefghijklmno";

   fd = open("/dev/pts/2", O_RDONLY);

   if (-1 == fd) {puts ("failed"); return 0;}

   FILE *arq = fopen ("/dev/pts/2", "rt");

   if (NULL == arq) {puts ("f-failed"); return 0;}

   puts (buf);
   n = read (fd, buf, 3); 
/*   fgets (buf, 3, arq); */
   puts (buf);

   if (1 > n) {puts ("cannot read"); return 0;}

   puts (buf);

   return 0;
}
