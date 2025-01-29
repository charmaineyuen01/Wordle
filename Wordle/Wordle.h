//
// Created by charm on 14/11/2023.
//

#ifndef SFML_PROJECT_CALCULATOR_H
#define SFML_PROJECT_CALCULATOR_H

#include "Background.h"
#include "Button.h"
#include "Box.h"
#include "Position.h"
#include "KeyBoard.h"
#include "Grid.h"
#include "Compare.h"
#include <SFML/Graphics.hpp>
#include <iostream>

class Wordle : public sf::Drawable, public States{
private:
    int trial = 0;
    Background background;
    Box * p;
    KeyBoard keyboard;
    Grid grid;
    Compare c;
    void typeChar(const std::string text);
    void typeBack();
    std::string getGuess();

public:
    Wordle();
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    void eventHandler(sf::RenderWindow& window, sf::Event event);
};
#endif //SFML_PROJECT_CALCULATOR_H
