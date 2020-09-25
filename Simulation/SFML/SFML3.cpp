


//   PARA COMPILAR

//   g++ SFML3.cpp -lsfml-system -lsfml-graphics -lsfml-window -lsfml-audio

//==================================================================================


#include <SFML/Graphics.hpp>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>



//-----------------------------------------------------------------------
void Pause (int milliseconds) {
    struct timespec ts;
    ts.tv_sec = 0;//milliseconds / 1000;
    ts.tv_nsec = (milliseconds % 1000) * 1000000;
    nanosleep(&ts, NULL);
}


//-----------------------------------------------------------------------
int Gx = 0;

void show (sf::RenderWindow *window) {

   sf::RectangleShape rect (sf::Vector2f (30, 30));

   for (int i = 0; i <= 5; i++)
      for (int j = 0; j <= 5; j++) {
         rect.setFillColor (sf::Color(Gx * i, 20 * j, (250-Gx) * j));
         rect.setPosition  (i*32, j*32);
         window->draw (rect);
      }
}


//-----------------------------------------------------------------------
int main() {

   sf::RenderWindow window(sf::VideoMode(500, 500), "Exemplo SFML");

   while (window.isOpen()) {

      sf::Event event;

      while (window.pollEvent(event)) 
         if ( (event.type == sf::Event::Closed) ||
             ((event.type == sf::Event::KeyPressed) &&
              (event.key.code == sf::Keyboard::Escape)
             )
            )
            return 0;

      window.clear();
       
      show (&window);
       
      window.display();
      
      Gx = (Gx + 2) % 250;
      Pause (100);
      
   }

   return 0;
}
