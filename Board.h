#pragma once
#include "LIST.h"
class Board
{
public:
	Board(int, int);
	char const peak(int, int); 
	bool insert(int, char);
	bool const isfull(int);
	void display();
	~Board();

private:
	const int width;
	const int height;
	LIST* BOARD = new LIST[width];        // The board of the game
	//Helper functions
	bool chkHor(int, int);               //Check if horizontal allignment occured 
	bool chkVer(int, int);              // Check if vertical allignment occured
	bool chkSkL(int, int);             // Check if skew left allignment occured
	bool chkSkR(int, int);            // Check if skew right allignment occured

};

