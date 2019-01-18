/*

Para compilar
 g++ -std=c++11 -pthread teste.cpp

*/

#include <string>
#include <iostream>
#include <thread>

void f (char letra) {

   int k = 200;

   while (--k)
      std::cout << letra << '-';
}

int main () {

   std::thread t1 (f, 'A');
   std::thread t2 (f, 'B');

   t1.join();
   t2.join();

   return 0;
}
