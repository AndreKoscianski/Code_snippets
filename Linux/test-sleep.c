
/*
gcc -Wa,-alhds -masm=intel -save-temps
*/

#include <unistd.h>


int main () {

   puts ("\nGoing sleep.");
   sleep(10);
   puts ("Im back");


   return 0;

}
