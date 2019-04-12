#include "helper.h"
#include "Tree.h"
#include "Terminal.h"
#include <stdlib.h>
#include <cstdlib>
#include <random>
#include <math.h>


using namespace std;

Tree::Tree(Vec2D pos) {
    _root.symb = '#';
    _root.pos = pos;
    _root.parent = nullptr;

    for (int i = 0; i < 500; i++){
        vector<char> RowVector(500);
        _char_array.push_back(RowVector);
    }
    _nutrients = get_random(40,100);
    _nutrients_start = _nutrients;
    _char_array[_root.pos.x][_root.pos.y] = '#';
}

Tree::~Tree(){
    Node* Iterator;
    Iterator = &_root;
    deleteNodes(Iterator);
}

void Tree::deleteNodes(Node* n){
    Node* parent = nullptr;
    if (n->nodes.size() != 0){
        for (int i = 0; i < n->nodes.size(); ++i) {
            deleteNodes(n->nodes[i]);
        }
    } else if (n->parent != nullptr) {
        parent = n->parent;
        parent->nodes.clear();
        //free(n);
        deleteNodes(parent);
    }
    return;
}

void Tree::update(){
    Node* n;
    n = &_root;
    recursive_grow(n);
    return;
}

void Tree::draw(Terminal& term)
{
    Node* n;
    n = &_root;
    recursive_draw(term, n);
}

void Tree::array_draw(Terminal& term){
    for (int i = 0; i < _char_array.size(); ++i) {
        for (int j = 0; j < _char_array[i].size(); ++j) {
            term.set_cell(i, j, _char_array[i][j]);
        }
    }
}

void Tree::recursive_draw(Terminal& term, Node* n){
    for (int i = 0; i < n->nodes.size(); ++i) {
        recursive_draw(term, n->nodes[i]);
    }
    term.set_cell(n->pos.x, n->pos.y, n->symb);
}

Vec2D Tree::select_growDirection(Node* n){
    int x = n->pos.x;
    int y = n->pos.y;

    int dx = get_random(-1, 1);
    int dy = get_random(-1, 1);

    if (_char_array[x+dx][y+dy] == ' '){
        if (dx){
            return Vec2D(dx, dy);
        }
    }
    return Vec2D(0,0);
}

bool Tree::is_free(Vec2D a){
    if (_char_array[a.x][a.y] == ' '){
        return true;
    }
    return false;
}

bool Tree::is_free(Node* n, Vec2D a) {
    Vec2D pos;
    pos = n->pos + a;
    return is_free(pos);
}

void Tree::recursive_grow(Node* n) {
    death = true;
    //ttl--;
    if (!n->death){
        death = false;
        if(n->nodes.size() <= 1 && get_random(_nutrients/_nutrients_start)){
            if (n->symb == '#' && get_random(0.999)){ // Am Stamm
                growNode(n, Vec2D(0, -1), '#');
            } else if (get_random(0.5 * 1/distance(n->pos, stem_top))){
                if (get_random(0.8)) {
                    if (get_random(0.3)) {
                        growNode(n, Vec2D(-1, -1), '\\');
                    }

                    if (get_random(0.3)) {
                        growNode(n, Vec2D(1, -1), '/');
                    }

                    if (get_random(0.1)) {
                        growNode(n, Vec2D(-1, -1), '_');
                    }

                    if (get_random(0.3)) {
                        growNode(n, Vec2D(1, -1), '_');
                    }

                    if (n->pos.y < stem_top.y && get_random(0.15)) {
                        growNode(n, Vec2D(-1, 1), '/');
                    }

                    if (n->pos.y < stem_top.y && get_random(0.15 * abs(n->pos.y))) {
                        growNode(n, Vec2D(1, 1), '\\');
                    }
                }
            } else {
                if (get_random(0.2)){
                    char fruit = '*';
                    if (get_random(0.1)){
                        fruit = '%';
                    }
                    if (n->symb == '\\'){
                        growNode(n, Vec2D(-1,-1), fruit);
                    } else if (n->symb == '/') {
                        growNode(n, Vec2D(1,-1), fruit);
                    }
                }
            }
        } else {
            for (int i = 0; i < n->nodes.size(); ++i) {
                recursive_grow(n->nodes[i]);
            }
        }
    }
    if (_nutrients == 0){
        death = true;
    }
}

void Tree::growNode(Node* n, Vec2D relative_pos, char symb){
    Vec2D pos;
    pos = n->pos + relative_pos;

    if (_char_array.size() > pos.x && _char_array[0].size() > pos.y) {
        if (!_char_array[pos.x][pos.y]) {
            Node *new_node;
            new_node = new Node();
            new_node->pos = pos;
            new_node->symb = symb;
            new_node->parent = n;

            if (symb == '*' && get_random(0.3)) {
                new_node->death = true;
            }

            if (symb == '#') {
                stem_top = Vec2D(pos.x, pos.y);
            }

            _char_array[new_node->pos.x][new_node->pos.y] = symb;

            n->nodes.insert(n->nodes.begin(), new_node);
            _nutrients--;
        }
    }
    return;
}