
/*
gcc -Wa,-alhds -masm=intel -save-temps
*/

#include <stdio.h>

int Gi;

void f() {
   Gi = Gi + 1;
}


int main () {

   int A = 0;

   A = A + 1;

   printf("Ok, %d\n", A);

   return 0;

}
