//
// Created by charm on 5/12/2023.
//

#ifndef SFML_PROJECT_COMPARE_H
#define SFML_PROJECT_COMPARE_H

#include <string>
#include <fstream>
#include "Grid.h"
#include "KeyBoard.h"

class Compare{
private:
    static std::vector<std::string> answers;
    static std::string answer;

public:
    static std::string getAnswers();
    static void trials(Grid& grid, std::string guess, int trial);
    //static void changeKeyboard(KeyBoard& keyboard);
};


#endif //SFML_PROJECT_COMPARE_H
