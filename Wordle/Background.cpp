//
// Created by charm on 14/11/2023.
//

#include "Background.h"

Background::Background()
:Background({700,880}, {0,0}, sf::Color::White){}

Background::Background(sf::Vector2f size, sf::Vector2f position, sf::Color color){
    setSize(size);
    setPosition(position);
    setFillColor(color);
}

void Background::eventHandler(sf::RenderWindow &window, sf::Event event) {
    sf::Vector2f mpos = (sf::Vector2f) sf::Mouse::getPosition(window);
    if(getGlobalBounds().contains(mpos)){
        enableState(HOVERED);
    }
    else{
        disableState(HOVERED);
    }
}

void Background::update() {
    Shape::update();
}
