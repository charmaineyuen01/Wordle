//
// Created by charm on 5/12/2023.
//

#include "Grid.h"

Grid::Grid() {
    //Board
    for(int i=0; i<30; i++) {
        Box bx;
        bx.setSize({80, 80});
        box.push_back(bx);
        if (i == 0)
            box.back().setPosition({100, 30});
    }
    for (int i = 1; i < 30; i++)
    {
        if (i % 5 == 0)
            Position::below(box[i-5], box[i], 20);
        else
            Position::right(box[i-1], box[i], 20);
    }
}

void Grid::draw(sf::RenderTarget& window, sf::RenderStates states) const{
    for (const auto& i : box) {
        window.draw(i);
    }
}
