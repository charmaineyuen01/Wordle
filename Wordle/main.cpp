#include <iostream>
#include <SFML/Graphics.hpp>
#include <ctime>
#include "Wordle.h"
int main()
{
    srand(time(0));
    sf::RenderWindow window({700, 880}, "Wordle");
    window.setFramerateLimit(60);

    Wordle wordle;
    while(window.isOpen())
    {
        sf::Event event;
        while(window.pollEvent(event))
        {
            if(sf::Event::Closed == event.type)
                window.close();
            wordle.eventHandler(window, event);
        }

        //  b.update();
        window.clear();
        window.draw(wordle);
        window.display();
    }
    return 0;
}