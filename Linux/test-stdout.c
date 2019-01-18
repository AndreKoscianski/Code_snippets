#include <stdio.h>

int main (void) {

   FILE *arq = fopen ("test.txt", "wt");

   fprintf (arq   , "%s \n", "Hello");
   fprintf (stdout, "%s \n", "Surprise!");

   return 0;
}
