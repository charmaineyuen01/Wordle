//
// Created by charm on 14/11/2023.
//

#ifndef SFML_PROJECT_BUTTON_H
#define SFML_PROJECT_BUTTON_H

#include <SFML/Graphics.hpp>
#include "font.h"
#include "MouseEvent.h"
#include "States.h"
#include "Position.h"

class Button : public sf::Drawable , public States {
private:
    sf::Text buttonNumber;
    sf::RectangleShape button;
    sf::Color defaultColor = {80,80,80}, clickColor = {210, 210, 210};
    void setupText(const std::string& text, sf::Font& font);
    void setCharacterSize();

public:
    Button();
    Button(const std::string text);
    Button(const std::string text, sf::Vector2f size);
    Button(const std::string text, sf::Vector2f size, sf::Font& font);
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    void setSize(sf::Vector2f size);
    void setText(const std::string &text);
    std::string getText();
    void setPosition(sf::Vector2f position);
    void eventHandler(sf::RenderWindow& window, sf::Event event);
    void update();
    sf::FloatRect getGlobalBounds() const;
    float getOutlineThickness() const;
};


#endif //SFML_PROJECT_BUTTON_H
