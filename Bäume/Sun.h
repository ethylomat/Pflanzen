//
// Created by Lennart Stipulkowski on 2019-04-12.
//

#ifndef PFLANZEN_SUN_H
#define PFLANZEN_SUN_H

#include<string>
#include<vector>
#include "Vec2D.h"
#include "Terminal.h"

class Sun {
public:
    Sun();
    void print_sun(Terminal& term, Vec2D pos);
private:
    std::vector<std::string> sun_strings;
};


#endif //PFLANZEN_SUN_H
