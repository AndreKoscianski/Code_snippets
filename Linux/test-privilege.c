#include <stdio.h>

int main (void) {

   puts ("here I go");

   __asm__ ("inb $0x12, %al");

   puts ("done!");

   return 0;
}
