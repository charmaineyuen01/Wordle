//
// Created by charm on 5/12/2023.
//

#ifndef SFML_PROJECT_KEYBOARD_H
#define SFML_PROJECT_KEYBOARD_H

#include "Button.h"

class KeyBoard : public sf::Drawable, public States{
private:
    std::string keys[28] = {"Q", "W", "E", "R", "T", "Y", "U", "I", "O", "P", "A", "S", "D", "F", "G", "H", "J", "K", "L", "Enter", "Z", "X", "C", "V", "B", "N", "M", "Back"};

public:
    std::vector<Button> button;
    KeyBoard();
    void draw(sf::RenderTarget& window, sf::RenderStates states) const;
};


#endif //SFML_PROJECT_KEYBOARD_H
