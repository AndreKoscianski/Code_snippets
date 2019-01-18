#include <stdio.h>

int main (void) {

   char buf[] = "abcdefghijklmno";

   puts (buf);
   puts (buf);
   puts (buf);

   gets (buf);

   puts (buf);

   puts ("finished");

   return 0;
}
