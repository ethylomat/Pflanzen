#include "Game.h"
#include "Word.h"
#include "helper.h"
#include <random>

Game::Game(Terminal& term) :
    _elapsed_time(0.f),
    _score(0), 
    _game_over(false),
    _is_done(false),
    _term(term)
{

}

bool Game::is_done() 
{
    return _is_done;
}

void Game::add_tree(){
    Tree t = Tree(Vec2D(get_random(10, _term.width()), 30));
    _trees.push_back(t);
}

void Game::update(float dt) 
{
    char pressed = _term.get_key();
    switch (pressed) {
        case 'r':
            _game_over = false;
            _trees.clear();
            break;
        case 'a':
            add_tree();
            draw();
            break;
        case 'q':
            _is_done = true;
            break;
        case 'x':
            for (auto &tree: _trees) {
                tree.update();
            }
            break;
        default:
            break;
    }

    _elapsed_time += dt;
    if (_elapsed_time >= 0.1f) 
    {
        if (!_game_over) {
            for (auto &tree: _trees) {
                tree.update();
            }
        }
        _elapsed_time = 0.f;
    }
}

void Game::draw() 
{
    if (_game_over) {
        draw_game_over();
        return;
    }
    
    _term.clear();


    /*
     // Showing Terminal dimensions:

    _term.set_cell(0,0,'*');
    _term.set_cell(_term.width()-1,0,'*');
    _term.set_cell(_term.width()-1,_term.height()-1,'*');
    _term.set_cell(0,_term.height()-1,'*');
    */

    for (auto &tree: _trees) {
        tree.draw(_term);
    }

    for (int x = 0; x < _term.width()-1; ++x) {
        _term.set_cell_color(x, 31, '-', 1);
    }

    _sun.print_sun(_term, Vec2D(10,4));

    _term.sleep(100);
}

void Game::draw_game_over() 
{
    std::string score_text = "Game Over! You got '" + std::to_string(_score) + "' points.";
    std::string reset_text = "Press 'r' to restart.";

    int half_width = _term.width() / 2;
    int half_height = _term.height() / 2;

    _term.draw_text(half_width - score_text.size()/2, half_height, score_text);
    _term.draw_text(half_width - reset_text.size()/2, half_height + 1, reset_text);
}

