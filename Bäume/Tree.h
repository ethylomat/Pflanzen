#ifndef TREE_H
#define TREE_H

#include <vector>
#include "Vec2D.h"
#include "Node.h"
#include "Word.h"
#include <map>

using namespace std;

class Terminal;
class Node;
class Vec2D;

class Tree
{
public:
    Tree(Vec2D pos);
    ~Tree();
    bool death = false;
    void update();
    void draw(Terminal& term);
    void recursive_draw(Terminal& term, Node*);
    void array_draw(Terminal& term);
    void recursive_grow(Node*);
    void growNode(Node* n, Vec2D relative_pos, char symb);
    Vec2D select_growDirection(Node* n);
    bool is_free(Vec2D);
    bool is_free(Node*, Vec2D);
    void deleteNodes(Node* n);
    Vec2D stem_top = Vec2D(0,0);
private:

    vector<vector<char> > _char_array;
    Node _root;
    int _nutrients, _nutrients_start;
    //int ttl = 5000;
};

#endif
