#include<iostream>
#include<time.h>
#include<Windows.h>
#include"Board.h"
#include"Player.h"
#include <chrono>
using namespace std::chrono;
using namespace std;

int main()
{
	
	const int delay = 500;        //delay time for game course
	//Computer player
	int choose;
	srand(time(0));
	cout << "Welcome to connect 4 game !!!!!!!!" << endl << endl;
	cout << "Do You want to play against a friend or the computer? \n";
	cout << "Choose '1' for a computer and '2' for a friend \n";
	cin >> choose;
	auto start = high_resolution_clock::now();
	// Board initialization
	const int Width = 7, Height =6;
	/*cout << "Enter the board dimensions as Width x Height: ";     cin >> Width >> Height;*/
	Board play_board(Width, Height);
	system("cls");

	// Initializing players
	const char first_player_piece = 254, second_player_piece = 15;
	string first_player_name, second_player_name;

	if (choose == 1)
	{
		cout << "Enter your name: "; cin >> first_player_name;
		second_player_name = "Computer";
		system("cls");
		Player Player1(first_player_piece, first_player_name, &play_board);
		Player computer_player(second_player_piece, second_player_name, &play_board);

		//winning conditions
		bool Win1 = false, Win2 = false;
		//Input from player
		int I;

		//مجرى اللعبة
		while (true)
		{
			play_board.display();
			cout << "Your turn " << Player1.getname() <<" !!!\nInsert your piece in a certain column : "; cin >> I;
			Win1 = Player1.insert(I);
			play_board.display();

			if (Win1)
			{
				Sleep(delay);
				system("cls");
				cout << "!!!!!!!!!!!CONGRATULATIONS YOU HAVE WON!!!!!!!!!!\n";
				break;
			}
			// making the computer smarter: it won't insert in a certain column
			bool isFull = true;
			while (isFull)
			{
				I = (rand() % Width) + 1;
				isFull = play_board.isfull(I);
			}
			
			cout << "Computer's turn!!!\n";
			Win2 = computer_player.insert(I);
			Sleep(delay);
			play_board.display();

			if (Win2)
			{
				Sleep(delay);
				system("cls");
				cout << "!!!!!!!!!!!HARD LUCK THE COMPUTER HAS WON!!!!!!!!!!\n";
				break;
			}
		}
	}
	else
	{
		cout << "Enter the name of first player: "; cin >> first_player_name;
		system("cls");
		cout << "Enter the name of second player: ";  cin >> second_player_name;
		system("cls");

		Player Player1(first_player_piece, first_player_name, &play_board);
		Player Player2(second_player_piece, second_player_name, &play_board);

		//winning conditions
		bool Win1 = false, Win2 = false;
		//Input from player
		int I;

		//مجرى اللعبة
		while (true)
		{
			play_board.display();
			cout << Player1.getname() << " turn!!!\nInsert your piece in a certain column:    "; cin >> I;
		
			Win1 = Player1.insert(I);
			play_board.display();

			if (Win1)
			{
				Sleep(delay);
				system("cls");
				cout << "!!!!!!!!!!!CONGRATULATIONS " << Player1.getname() << " WON!!!!!!!!!!\n";
				break;
			}

			cout << Player2.getname() << " turn!!!\nInsert your piece in a certain column:    "; cin >> I;

			Win2 = Player2.insert(I);
			play_board.display();

			if (Win2)
			{
				Sleep(delay);
				system("cls");
				cout << "!!!!!!!!!!!CONGRATULATIONS "<< Player2.getname() <<" WON!!!!!!!!!!\n";
				break;
			}
		}

	}
	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stop - start);
	cout << "Time taken by function: "
		<< duration.count()/1000000.0 << " seconds" << endl;


}