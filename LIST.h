#pragma once
class LIST
{
public:
	LIST();
	int insert(char);     //Insert a new character  and return the index of the recently inserted node
	LIST* traverse();
	char  get(int);       //Get the data indexed by j
	~LIST();

private:
	char data;         //The data that would be stored in the node is in the form of a single character
	int j;            // The index of the node in the linkedlist_____Head is indexed 0
	LIST* next;

	friend class Board;
};

