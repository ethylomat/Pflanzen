#ifndef TERMINAL_H
#define TERMINAL_H

#include <string>

enum color{
    GREEN,
    BLUE,
};

class Terminal
{
public:
	/**
	* Initializes the terminal with a given width and height.
	*
	* @param width The width of the terminal
	* @param height The height of the terminal
	*/
    Terminal(int width, int height);

	/**
	* Gives the width of the terminal in cells.
	*/
	int width() const;

	/**
	* Gives the height of the terminal in cells.
	*/
	int height() const;

	/**
	* Gets the keyboard input. Simply returns the pressed key.
	*
	* @returns The pressed key character.
	*/
	char get_key() const;

	/**
	* Set a given cell at coordinates (x, y) to the given symbol.
	* Access outside of the bounds of the terminal is ignored.
	*
	* @param x The x coordinate
	* @param y The y coordinate
	* @param symbol The symbol to set the cell to
	*/
	void set_cell(int x, int y, char symbol);

    void set_cell_color(int x, int y, char symbol, int color);

	/**
	* Draws text starting at the given cell coordinates (x, y).
	* Access outside of the bounds of the terminal is ignored.
	*
	* @param x The x coordinate
	* @param y The y coordinate
	* @param text The text to draw to the terminal.
	*/
	void draw_text(int x, int y, const std::string& text);

	/**
	* Clears the terminal. Call this on every frame for interactive
	* applications like games.
	*/
	void clear();

	/**
	* Closes the terminal and resets everything to normal.
	*/
	void close();

	/**
	* Pauses the Application for a short amount of time. Time is
	* given in milliseconds.
	*
	* @param ms Time in milliseconds.
	*/
	void sleep(int ms);
};

#endif
