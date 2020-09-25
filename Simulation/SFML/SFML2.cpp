


//   PARA COMPILAR

//   g++ SFML2.cpp -lsfml-system -lsfml-graphics -lsfml-window -lsfml-audio

//==================================================================================


#include <SFML/Graphics.hpp>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>



//-----------------------------------------------------------------------
void show (sf::RenderWindow *window) {

   sf::RectangleShape rect (sf::Vector2f (30, 30));

   for (int i = 0; i <= 5; i++)
      for (int j = 0; j <= 5; j++) {
         rect.setFillColor(sf::Color(50 * i, 0 * j,20 * j));
         rect.setPosition (i*32, j*32);
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
   }

   return 0;
}
