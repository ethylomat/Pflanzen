//
// Created by Lennart Stipulkowski on 2019-04-11.
//

#include "Word.h"

Word::Word(std::string str){
    word = str;
    pointer = &word[0];
}

void Word::increment_pointer(){
    pointer++;
    if (*pointer == '\0'){
        pointer = &word[0];
    }
    return;
}

char Word::get_pointer_value(){
    return *pointer;
}

char Word::next_value(){
    char ret = get_pointer_value();
    increment_pointer();
    return ret;
}