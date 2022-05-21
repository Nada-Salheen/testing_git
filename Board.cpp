#include "Board.h"
#include "LIST.h"
#include<iostream>
#include<cstdlib>

using namespace std;

Board::Board(int W, int H)
	:width(W), height(H)
{
}

char const Board::peak(int x, int y)
// get the data in the board__ x-y coordinate __ranges:: x:1->Width, y:1->height
// return '-' if the coordinate doesn't exist
{
    if (x<1 || x>width || y > height || y <= 0)     return ' ';               // not in the board dimensions

	LIST* column = BOARD + (x-1);
	
	return column->get(y-1);
}

bool Board::insert(int x, char P)
// insert a piece in a certain column
// then check if someone won
{
	if (x<1 || x>width)             // not in the width range
	{
		cout << "Out of dimensions!!!\nPenality:your turn will be skipped!!!!\n";
        system("pause");
		return false;
	}
	int y = (BOARD + (x - 1))->insert(P);     // Insert a new element in column (x-1) and get the new height of the column
    if (y > height)
    {
        cout << "Out of dimensions!!!\nPenality:your turn will be skipped!!!!\n";
        system("pause");
        return false;
    }
   
    // Check winning condition
    if (chkHor(x, y))
        return true;
    else if (chkVer(x, y))
        return true;
    else if (chkSkL(x, y))
        return true;
    else
        return chkSkR(x, y);
}

bool const Board::isfull(int I)
//check if the column full
{
    LIST* column = BOARD + (I - 1);     // Obtain the column indexed by I
    column = column->traverse();        // reach the last node in the column
    
    int Height = column->j;             // Get the height of the column as the index of the last node
    
    if (Height >= height)
        return true;
    else
        return false;
}

void Board::display()
{
    system("cls");
    for (int i = height; i >= 1; i--)
    {
        for (int b = 0; b <= 6; b++) cout << char(218) << char(196) << char(191) << ' ';
        cout << '\n';
        for (int j = 1; j <= width; j++)
        {
            cout << char(179) << peak(j, i) << char(179) << ' ';
        }
        cout << endl;
        for (int b = 0; b <= 6; b++) cout << char(192) << char(196) << char(217) << ' ';
        cout << endl;
    }
}

bool Board::chkHor(int x, int y)
{
    char m = peak(x, y), n = 0;
    for (int i = -3; i < 3; i++)
    {
        if (peak(x + i, y) ==  m)
        {
            n++;
            if (n == 4)
                return true;
        }
        else n = 0;
    }
    return false;
}

bool Board::chkVer(int x, int y)
{
    char m = peak(x, y), n = 0;
    for (int i = -3; i < 3; i++)
    {
        if (peak(x, y + i) ==  m)
        {
            n++;
            if (n == 4)
                return true;
        }
        else n = 0;
    }
    return false;
}

bool Board::chkSkL(int x, int y)
{
    char m = peak(x, y), n = 0;
    for (int i = -3; i < 3; i++)
    {
        if (peak(x + i, y + i) ==  m)
        {
            n++;
            if (n == 4)
                return true;
        }
        else n = 0;
    }
    return false;
}

bool Board::chkSkR(int x, int y)
{
    char m = peak(x, y), n = 0;
    for (int i = -3; i < 3; i++)
    {
        if (peak(x + i, y - i) ==  m)
        {
            n++;
            if (n == 4)
                return true;
        }
        else n = 0;
    }
    return false;
}

Board::~Board()
{
	delete[] BOARD;
}