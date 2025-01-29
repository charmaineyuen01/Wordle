//
// Created by charm on 5/12/2023.
//

#include "KeyBoard.h"

KeyBoard::KeyBoard() {
    //Keyboard
    for(int i=0; i<28; i++)
    {
        Button bn;
        bn.setSize({50, 60});
        button.push_back(bn);
        button.back().setText(keys[i]);
        if(i == 0)
            button.back().setPosition({55,660});
        if(i == 10)
            button.back().setPosition({80,730});
        if(i == 19)
            button.back().setPosition({80,800});
    }
    for (int i = 1; i < 28; i++)
    {
        if (i < 10)
            Position::right(button[i-1], button[i], 10);
        else if (i > 10 && i < 19)
            Position::right(button[i-1], button[i], 10);
        else if (i > 19 && i < 28)
            Position::right(button[i-1], button[i], 10);
    }
}

void KeyBoard::draw(sf::RenderTarget& window, sf::RenderStates states) const{
    for (const auto& i : button) {
        window.draw(i);
    }
}
