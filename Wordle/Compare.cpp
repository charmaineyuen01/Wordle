//
// Created by charm on 5/12/2023.
//

#include "Compare.h"
std::string Compare::answer = getAnswers();
std::vector<std::string> Compare::answers;

std::string Compare::getAnswers(){
    std::ifstream fin;
    fin.open("5LetterNouns.txt");
    std::string line;
    while (std::getline(fin, line)){
        answers.push_back(line);
    }
    std::string answer = answers[rand() % (answers.size() - 1)];
    for (int i = 0; i < 5; ++i) {
        answer[i] = toupper(answer[i]);
    }
    return answer;
}

void Compare::trials(Grid& grid, std::string guess, int trial){
    //Alphabet not in the word.
    for (int i = 0; i < 5; ++i) {
        grid.box[i + trial*5].setFillColor({211,211,211});
    }
    //Alphabet in the word.
    for (int i = 0; i < 5; ++i) {
        //Alphabet not in correct order.
        for (int k = 0; k < 5; ++k){
            if (guess[k] == answer[i]){
                grid.box[k + trial*5].setFillColor({200,182,83});
            }
        }
        //Alphabet in correct order.
        if (guess[i] == answer[i]){
            grid.box[i + trial*5].setFillColor({108,169,101});
        }
    }
}

//void changeKeyboard(KeyBoard& keyboard, std::string guess){
//
//}


//void alphabetChange(char alpha[], std::string guess, std::string answer, char canvas[6][5], int trial)
//{
//    for (int i = 0; i < 26; ++i) {
//        if (alpha[i] == toupper(alpha[i]))
//            alpha[i] = alpha[i];
//        else {
//            for (int j = 0; j < 5; ++j) {
//                if (alpha[i] == guess[j] && guess[j] == answer[j]) {
//                    alpha[i] = toupper(guess[j]);
//                } else if (alpha[i] == canvas[trial][j]) {
//                    alpha[i] = tolower(guess[j]);
//                } else if (alpha[i] == guess[j]) {
//                    alpha[i] = '_';
//                }
//            }
//        }
//    }
//}
