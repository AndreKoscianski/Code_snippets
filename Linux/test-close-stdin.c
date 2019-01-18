#include <stdio.h>

int main (void) {

   if (close(0)) puts ("ops0");
   if (close(1)) puts ("ops1");

   puts ("uh-te-re-re");

   return 0;
}
