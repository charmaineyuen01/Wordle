//
// Created by charm on 4/12/2023.
//

#ifndef SFML_PROJECT_BOX_H
#define SFML_PROJECT_BOX_H

#include <SFML/Graphics.hpp>
#include "font.h"
#include "MouseEvent.h"
#include "States.h"
#include "Position.h"
#include <fstream>

class Box : public sf::Drawable , public States {
private:
    sf::Text boxText;
    sf::RectangleShape box;

public:
    Box();
    Box(int thickness, sf::Color outline, sf::Color fill);
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    void setSize(sf::Vector2f size);
    void setPosition(sf::Vector2f position);
    sf::FloatRect getGlobalBounds() const;
    float getOutlineThickness() const;
    void setText(const std::string &text);
    std::string getText();
    void setFillColor(sf::Color color);


//    void setText(const std::string &text);
//    std::string getText();
//    void setPosition(sf::Vector2f position);
//    void eventHandler(sf::RenderWindow& window, sf::Event event);
//    void update();
};


#endif //SFML_PROJECT_BOX_H
