//
// Created by charm on 14/11/2023.
//

#include <iostream>
#include "Button.h"
#include "MouseEvent.h"

Button::Button()
: Button("C"){}

Button::Button(const std::string text)
: Button(text, {10,10}){}

Button::Button(const std::string text, sf::Vector2f size)
: Button(text, size, Font::getFont(ARIAL)){}

Button::Button(const std::string text, sf::Vector2f size, sf::Font& font){
    button.setSize(size);
    button.setFillColor(defaultColor);
    setupText(text, font);
}

void Button::setupText(const std::string &text, sf::Font &font) {
    this->buttonNumber.setFont(font);
    this->buttonNumber.setString(text);
    setCharacterSize();
    Position::centerText(button, this -> buttonNumber);
}

void Button::setSize(sf::Vector2f size) {
    button.setSize(size);
    setCharacterSize();
    Position::centerText(button, buttonNumber);
}

void Button::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    if(!getState(HIDDEN)){
        states.transform = button.getTransform();
        window.draw(button);
        window.draw(buttonNumber, states);
    }
}

void Button::setText(const std::string &text) {
    this->buttonNumber.setString(text);
    Position::centerText(button, buttonNumber);
}

std::string Button::getText() {
    return buttonNumber.getString();
}

void Button::setPosition(sf::Vector2f position) {
    button.setPosition(position);
}

void Button::eventHandler(sf::RenderWindow &window, sf::Event event) {
    if(MouseEvents::isClicked(button,window)){
        enableState(CLICKED);
    }
    else
        disableState(CLICKED);
}

void Button::update(){
    if(getState(CLICKED))
        button.setFillColor(clickColor);
    else
        button.setFillColor(defaultColor);
}

void Button::setCharacterSize(){
    unsigned int size = 16;
    this->buttonNumber.setCharacterSize(size);
    Position::centerText(button, buttonNumber);
}

sf::FloatRect Button::getGlobalBounds() const {
    return button.getGlobalBounds();
}

float Button::getOutlineThickness() const{
    return button.getOutlineThickness();
}

