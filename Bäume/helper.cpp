//
// Created by Lennart Stipulkowski on 2019-04-11.
//

#include <random>
#include <iostream>
#include "Vec2D.h"


float get_random(){
    static std::random_device rd;
    static std::mt19937 gen(rd());
    static std::uniform_int_distribution<> r(0, 1);
    return r(gen);
}


bool get_random(float x){
    if (get_random() <= x){
        return true;
    }
    return false;
}


int get_random(int a, int b){
    std::random_device rseed;
    std::mt19937 rng(rseed());
    std::uniform_int_distribution<> dist(a,b);

    return dist(rng);
}

float distance(Vec2D &a, Vec2D &b){
    float dx, dy;
    dx = abs(a.x - b.x);
    dy = abs(a.y - b.y);
    return std::sqrt(dx*dx + dy*dy);
}