//
// Created by Lennart Stipulkowski on 2019-04-12.
//

#include "Sun.h"
#include <string>
#include <vector>
#include "Vec2D.h"
#include "Terminal.h"

Sun::Sun() {
    sun_strings = {
            "       .       ",
            "     \\ | /.    ",
            "   '-.;;;.-'   ",
            "  -==;;;;;==-  ",
            "   .-';;;'-.   ",
            "     / | \\.    ",
            "       '       ",
    };
}

void Sun::print_sun(Terminal& term, Vec2D pos){
    for (int i = 0; i < sun_strings.size(); ++i) {
        for (int j = 0; j < sun_strings[i].size(); ++j) {
            term.set_cell_color(pos.x + j, pos.y + i, sun_strings[i][j], 4);
        }
    }
}