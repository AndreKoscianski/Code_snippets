#include <stdio.h>

void f() {

   puts ("---ai caramba!");
   
   // funciona, estraga retorno (leave)---------
   //asm("mov %ebp,666");

   // nao funciona (leave) ---------
	asm(".intel_syntax");
   asm("pop eax");
   asm(".att_syntax");
   
   
   puts ("---danou-se!"); 
}


void g () {

   int n;

   puts ("-chamando f()!");
   
   // funciona-------------
   //asm("mov $_f, %eax");
   //asm("push %eax");
   //asm("ret");

   // funciona-------------
   //asm("mov $_f, %eax");
   //asm("jmp %eax");
   
   // funciona ---------
	//asm(".intel_syntax");
   //asm("mov eax, offset _f");
   //asm("jmp eax");
   //asm(".att_syntax");

   // funciona ---------
	//asm(".intel_syntax");
   //asm("mov eax, offset _f");
   //asm("push eax");
   //asm("ret");
   //asm(".att_syntax");

   puts ("-voltei!"); 
}

int main () {

  puts ("la vou eu");
  f();
  puts ("voltei");

  return 0;
}
