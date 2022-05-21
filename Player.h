#pragma once
#include"Board.h"
#include<iostream>
class Player
{
public:
	Player();   //default constructor

	Player( char, std::string, Board*);

	void setname( std::string);
	std::string const getname();
	bool insert(int);

private:
	Board* playBoard;              // The board that players can modify
    char P;                        // The character/piece colour the player will play with
	std::string name;
};

