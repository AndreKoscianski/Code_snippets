#include <stdio.h>
#include <string.h>
#include <dirent.h>


void tratar (char *s) {

   if (!isdigit (*s)) return;

   char s2[100];

   sprintf (s2, "/proc/%s/stat", s);

   FILE *arq;
   arq =  fopen (s2, "rt");
   fgets  (s2, 100, arq);
   puts   (s2);
   fclose (arq);
}


int main () {

   struct dirent **namelist;

   int n;

   n = scandir ("/proc", &namelist, 0, alphasort);

   while (n--) {

      printf ("%s\n", namelist[n]->d_name);

      tratar (namelist[n]->d_name);
   }
     
   return 0;
}
