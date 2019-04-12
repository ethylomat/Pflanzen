#include "Terminal.h"

#if defined(_WIN32)
#include <curses.h>
#else
#include <ncurses.h>
#endif

Terminal::Terminal(int width, int height)
{
	initscr();
	resize_term(height, width);

	cbreak();
	keypad(stdscr, true);
	noecho();
	curs_set(0);
	timeout(0);


    start_color();

    init_pair(1, COLOR_GREEN, COLOR_BLACK);
	init_pair(2, COLOR_RED, COLOR_BLACK);
	init_pair(3, COLOR_WHITE, COLOR_BLACK);
	init_pair(4, COLOR_YELLOW, COLOR_BLACK);

	init_pair(11, COLOR_WHITE, COLOR_GREEN);
	init_pair(12, COLOR_WHITE, COLOR_RED);
	init_pair(13, COLOR_BLACK, COLOR_WHITE);
}

int Terminal::width() const
{
	return COLS;
}

int Terminal::height() const
{
	return LINES;
}

void Terminal::set_cell(int x, int y, char symbol)
{
	short color;
	switch (symbol){
		case '|':
			color = 2;
			break;
		case '#':
			color = 2;
			break;
		case '/':
			color = 1;
			break;
		case '\\':
			color = 1;
			break;
		case '%':
			color = 3;
			break;
		default:
			color = 1;
			break;
	}
	attron(COLOR_PAIR(color));
	mvaddch(y, x, symbol);
	attron(COLOR_PAIR(color));
}

void Terminal::set_cell_color(int x, int y, char symbol, int color)
{
	attron(COLOR_PAIR(color));
	mvaddch(y, x, symbol);
	attron(COLOR_PAIR(color));
}

void Terminal::draw_text(int x, int y, const std::string& text)
{
	mvaddstr(y, x, text.c_str());
}

void Terminal::clear()
{
	::clear();
}

void Terminal::close()
{
	endwin();
	curs_set(1);
}

void Terminal::sleep(int ms)
{
	napms(ms);
}

char Terminal::get_key() const
{
	return wgetch(stdscr);
}
