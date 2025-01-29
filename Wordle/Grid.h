//
// Created by charm on 5/12/2023.
//

#ifndef SFML_PROJECT_GRID_H
#define SFML_PROJECT_GRID_H
#include "Box.h"
#include <vector>

class Grid : public sf::Drawable, public States{
private:

public:
    std::vector<Box> box;
    Grid();
    void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    Grid(std::vector<std::string>&word);


};


#endif //SFML_PROJECT_GRID_H
