//
// Created by Lennart Stipulkowski on 2019-04-11.
//

#ifndef PFLANZEN_WORD_H
#define PFLANZEN_WORD_H

#include<vector>
#include <string>

class Word {
private:
    char get_pointer_value();
    void increment_pointer();
    std::string word;
    char* pointer;
public:
    Word(std::string str);
    char next_value();
};


#endif //PFLANZEN_WORD_H
