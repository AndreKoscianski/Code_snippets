#include <stdio.h>

void f() {

   puts ("---ai caramba!");
   
	asm(".intel_syntax");
   asm("pop ax");
	asm(".att_syntax");

   puts ("---danou-se!"); 
 
}

int main () {

  puts ("la vou eu");
  f();
  puts ("voltei");

  return 0;
}
