//
// Created by charm on 4/12/2023.
//

#include "Box.h"

Box::Box()
: Box(3, {80,80,80}, sf::Color::White){}

Box::Box(int thickness, sf::Color outline, sf::Color fill){
    box.setOutlineThickness(thickness);
    box.setOutlineColor(outline);
    box.setFillColor(fill);
}

void Box::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    if(!getState(HIDDEN)){
        window.draw(box);
        window.draw(boxText);
    }
}

void Box::setSize(sf::Vector2f size) {
    box.setSize(size);
    Position::centerText(box, boxText);
}

void Box::setPosition(sf::Vector2f position) {
    box.setPosition(position);
}

sf::FloatRect Box::getGlobalBounds() const {
    return box.getGlobalBounds();
}

float Box::getOutlineThickness() const{
    return box.getOutlineThickness();
}

void Box::setText(const std::string &text){
    this->boxText.setString(text);
    boxText.setFont(Font::getFont(ARIAL));
    boxText.setCharacterSize(36);
    boxText.setFillColor(sf::Color::Black);
    Position::centerText(box, boxText);
}

std::string Box::getText(){
    return boxText.getString();
}

void Box::setFillColor(sf::Color color){
    box.setFillColor(color);
}