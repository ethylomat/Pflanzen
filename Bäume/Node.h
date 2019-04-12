//
// Created by Lennart Stipulkowski on 2019-04-10.
//

#ifndef PFLANZEN_NODE_H
#define PFLANZEN_NODE_H

#include "Vec2D.h"
#include <vector>

class Node {
public:
    Node();

    char symb;
    bool death = false;
    Vec2D pos;
    Node* parent = nullptr;
    std::vector<Node*> nodes;
};


#endif //PFLANZEN_NODE_H
