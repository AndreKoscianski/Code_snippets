


//   PARA COMPILAR

//   g++ SFML1.cpp -lsfml-system -lsfml-graphics -lsfml-window -lsfml-audio

//==================================================================================


#include <SFML/Graphics.hpp>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int main() {

    sf::RenderWindow window(sf::VideoMode(500, 500), "Exemplo SFML");

    while (window.isOpen()) {

        sf::Event event;

        while (window.pollEvent(event)) 
           if ((event.type == sf::Event::Closed) ||
               ((event.type == sf::Event::KeyPressed) &&
                (event.key.code == sf::Keyboard::Escape)
               )
              )
              return 0;

        window.clear();
        window.display();
    }

    return 0;
}
