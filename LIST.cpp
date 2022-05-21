#include "LIST.h"
#include <iostream>


LIST::LIST()
	:next(NULL), j(0), data('+')
{
}

LIST* LIST::traverse()
{
	LIST* Prev = this;
	while (Prev->next != NULL)
	{
		Prev = Prev->next;
	}
	return Prev;
}

int LIST::insert(char key)
{
	LIST* last = traverse();
	LIST* newlast = new LIST();
	newlast->data = key;
	newlast->j = last->j + 1;
	last->next = newlast;

	return newlast->j;
}

char LIST::get(int y)
{
	LIST* Node = this;
	for (int i = 0; i <= y; i++)
	{
		if (!Node)    return ' ';          // Character not found
		Node = Node->next;
	}
	return   (Node)? Node->data : ' ';
}

LIST::~LIST()
{
	delete next;
}