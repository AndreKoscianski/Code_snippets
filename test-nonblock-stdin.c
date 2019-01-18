// C program to implement one side of FIFO 
// This side reads first, then reads 
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <fcntl.h> 

int main()  { 

   char s[100];

   int flags = fcntl (fileno(stdin), F_GETFL, 0);
   fcntl (fileno(stdin), F_SETFL, flags | O_NONBLOCK);

   while (1) {

      fgets (s, 80, stdin); 

      printf ("Here it is = %s\n", s);

   }

   return 0;
}
