//
// Created by charm on 14/11/2023.
//
#include "Wordle.h"

Wordle::Wordle() {
    p = &grid.box[0];
}

void Wordle::eventHandler(sf::RenderWindow &window, sf::Event event) {
    //todo delete the line below later
    for(auto& i : keyboard.button)
    {
        i.eventHandler(window, event);
        if(MouseEvents::isClicked(i,  window)){
            enableState(CLICKED);
            if (i.getText() == "Back"){
                typeBack();
            }
            else if(i.getText() == "Enter"){
                c.trials(grid, getGuess(), trial);
                trial++;
            }
            else {
                typeChar(i.getText());
            }
        }
        else{
            disableState(CLICKED);
        }
    }
}

void Wordle::typeChar(const std::string text){
    p->setText(text);
    p++;
}

void Wordle::typeBack(){
    p--;
    p->setText("");
}

std::string Wordle::getGuess(){
    p = p-5;
    std::string guess;
    for (int i = 0; i < 5; ++i) {
        guess += p->getText();
        p++;
    }
    return guess;
}

void Wordle::draw(sf::RenderTarget& window, sf::RenderStates states) const{
    window.draw(background, states);
    window.draw(grid, states);
    window.draw(keyboard, states);
}