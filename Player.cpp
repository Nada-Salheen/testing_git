#include "Player.h"
#include "Board.h"


Player::Player(char p, std::string Name, Board* PLAYBOARD)
	: P(p),name(Name), playBoard(PLAYBOARD)
{

}

void Player::setname(std::string Name)
{
	name = Name;
}

std::string const Player:: getname()
{
	return name;
}

bool Player::insert(int x)
{
	return playBoard->insert(x, this->P);
}
