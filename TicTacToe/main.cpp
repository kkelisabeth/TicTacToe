/*
* Creator:    Kozlova Elizabeth Paula
*
* Title:      TicTacToe
*
* Description:
*			  This program accepts from two players positions and according to this position places either 'X' or 'O', and then displays the board.
*			  Afterwards it checks for the winner of the game and displays either Player1, Player2, or Draw.
*/


#include <iostream>
#include <iomanip>
using namespace std;

//defines a class, which will implement the TicTacToe game 
class TicTacToe
{
private:
	int NoOfMoves; //number of moves in the game 
	int Board[3][3]; //game board
public:
	TicTacToe(); //construsctor
	bool PlayMove(int, int, int); //check if the entered position is free 
	int Winner() const; //return the winner of the game 
	bool GameOver() const; // check if the game is over or not 
	void DisplayBoard() const; //display the game board
};

//constructor, which initializes NoOfMoves and all positions of the board to zero 
TicTacToe::TicTacToe()
{
	NoOfMoves = 0;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
			Board[i][j] = 0;
	}
}

//method, that checks if the entred position is free
//if the position is free, then it will assign to that position player's number
//if the position is not free, then it will return false 
bool TicTacToe::PlayMove(int Player, int row, int col)
{
	if (Board[row][col] == 0)
	{
		Board[row][col] = Player;
		NoOfMoves++;
	}
	else return false;

	return true;
}

//method, which returns the winner of the game 
//checks if either one of the rows, or one of the columns, or one of two diagonals belongs to one player 
int TicTacToe::Winner() const
{
	bool checkerHor = false;
	bool checkerVer = false;
	bool checkerDia1 = false;
	bool checkerDia2 = false;
	bool check1 = false, check2 = false, check3 = false;
	int winner = 0;

	//checks rows
	if (Board[0][0] != 0 && Board[0][0] == Board[0][1] && Board[0][1] == Board[0][2])
	{
		check1 = true;
		winner = Board[0][0];
	}
	if (Board[1][0] != 0 && Board[1][0] == Board[1][1] && Board[1][1] == Board[1][2])
	{
		check2 = true;
		winner = Board[1][0];
	}
	if (Board[2][0] != 0 && Board[2][0] == Board[2][1] && Board[2][1] == Board[2][2])
	{
		check3 = true;
		winner = Board[2][0];
	}
	if (check1 || check2 || check3) checkerHor = true;

	check1 = false;
	check2 = false;
	check3 = false;

	//checks columns
	if (Board[0][0] != 0 && Board[0][0] == Board[1][0] && Board[1][0] == Board[2][0])
	{
		check1 = true;
		winner = Board[0][0];
	}
	if (Board[0][1] != 0 && Board[0][1] == Board[1][1] && Board[1][1] == Board[2][1])
	{
		check2 = true;
		winner = Board[0][1];
	}
	if (Board[0][2] != 0 && Board[0][2] == Board[1][2] && Board[1][2] == Board[2][2])
	{
		check3 = true;
		winner = Board[0][2];
	}
	if (check1 || check2 || check3) checkerVer = true;

	//checks first diagonal
	if (Board[0][0] != 0 && Board[0][0] == Board[1][1] && Board[1][1] == Board[2][2])
	{
		checkerDia1 = true;
		winner = Board[0][0];
	}

	//checks second diagonal
	if (Board[2][0] != 0 && Board[2][0] == Board[1][1] && Board[1][1] == Board[0][2])
	{
		checkerDia2 = true;
		winner = Board[2][2];
	}

	//returns 1 or 2 if there is a winner 
	if (checkerHor || checkerVer || checkerDia1 || checkerDia2) return winner;

	//returns 0 if there is no winner 
	else return 0;
}

//method, which checks if the game is over or not 
bool TicTacToe::GameOver() const
{
	//checks if there is a winner or all moves were made, then it returns true
	if ((NoOfMoves == 9) || (Winner() != 0))
		return true;

	//if there is no winner and there are free positions on the board, it retirns false 
	else return false;
}

//method, which displays the board
void TicTacToe::DisplayBoard() const
{
	const int HEIGHT = 2, WIDTH = 4, ROWS = 3, COLS = 3;
	system("CLS");

	for (int i = 0; i <= ROWS * HEIGHT; i++)
	{
		for (int j = 0; j <= COLS * WIDTH; j++)
		{
			if (i == 0 && j == 0) cout << char(201);
			else if (i == 0 && j == COLS * WIDTH) cout << char(187);
			else if (i == ROWS * HEIGHT && j == 0) cout << char(200);
			else if (i == ROWS * HEIGHT && j == COLS * WIDTH) cout << char(188);
			else if (i % HEIGHT == 0 && j == 0) cout << char(204);
			else if (i % HEIGHT == 0 && j == COLS * WIDTH) cout << char(185);
			else if (i == 0 && j % WIDTH == 0) cout << char(203);
			else if (i == ROWS * HEIGHT && j % WIDTH == 0) cout << char(202);
			else if (i % HEIGHT == 0 && j % WIDTH == 0) cout << char(206);
			else if (i % HEIGHT == 0) cout << char(205);
			else if (j % WIDTH == 0) cout << char(186);
			else if ((i + HEIGHT / 2) % HEIGHT == 0 && (j + WIDTH / 2) % WIDTH == 0)
			{
				if (Board[i / HEIGHT][j / WIDTH] == 0)
					cout << ' ';
				else if (Board[i / HEIGHT][j / WIDTH] == 1)
					cout << 'X';
				else
					cout << 'O';
			}
			else cout << ' ';
		}
		cout << endl;
	}
}

//main driver
int main()
{
	TicTacToe Game;
	int Player1 = 1, Player2 = 2;
	int row, column;
	int moves = 0;

	do
	{
		//accepts position from the Player1 
		cout << "Player1 enter position: " << endl;
		cout << setw(5) << "Row: ";
		cin >> row;

		//checks if the entered value is valid or not
		while (row < 0 || row > 2)
		{
			cout << "Invalid position. Please, enter again. Row: ";
			cin >> row;
		}
		cout << setw(5) << "Column: ";
		cin >> column;

		//checks if the entered value is valid or not
		while (column < 0 || column > 2)
		{
			cout << "Invalid position. Please, enter again. Column: ";
			cin >> column;
		}

		//checks if the entered position is free or not
		//if not, it asks to reenter the position 
		while (!Game.PlayMove(Player1, row, column))
		{
			cout << "The position is not free. Please, enter another position. ";
			cout << setw(5) << "Row: ";
			cin >> row;

			//checks if the entered value is valid or not
			while (row < 0 || row > 2)
			{
				cout << "Invalid position. Please, enter again. Row: ";
				cin >> row;
			}
			cout << setw(5) << "Column: ";
			cin >> column;

			//checks if the entered value is valid or not
			while (column < 0 || column > 2)
			{
				cout << "Invalid position. Please, enter again. Column: ";
				cin >> column;
			}
		}

		//assigns the position to Player1
		Game.PlayMove(Player1, row, column);
		moves++;

		//displays the board
		Game.DisplayBoard();
		if (moves >= 5)
			if (Game.GameOver()) break;
		//accepts position from the Player2
		cout << "Player2 enter position: " << endl;
		cout << setw(5) << "Row: ";
		cin >> row;

		//checks if the entered value is valid or not
		while (row < 0 || row > 2)
		{
			cout << "Invalid position. Please, enter again. Row: ";
			cin >> row;
		}
		cout << setw(5) << "Column: ";
		cin >> column;

		//checks if the entered value is valid or not
		while (column < 0 || column > 2)
		{
			cout << "Invalid position. Please, enter again. Column: ";
			cin >> column;
		}

		//checks if the entered position is free or not 
		//if it is not, then it asks to reenter the position 
		while (!Game.PlayMove(Player2, row, column))
		{
			cout << "The position is not free. Please, enter another position. ";
			cout << setw(5) << "Row: ";
			cin >> row;

			//checks if the entered value is valid or not
			while (row < 0 || row > 2)
			{
				cout << "Invalid position. Please, enter again. Row: ";
				cin >> row;
			}
			cout << setw(5) << "Column: ";
			cin >> column;

			//checks if the entered value is valid or not
			while (column < 0 || column > 2)
			{
				cout << "Invalid position. Please, enter again. Column: ";
				cin >> column;
			}
		}

		//assigns the position to the Player2
		Game.PlayMove(Player2, row, column);
		moves++;

		//displays the board
		Game.DisplayBoard();

		if (moves >= 5)
			if (Game.GameOver()) break;
	} while ((moves < 5) || (!Game.GameOver() && moves >= 5)); //continues the loop while number of moves is less than 5 (it is impossible to win the game in less than 5 moves)
	//or continues the loop while number of moves is more than or equal to 5, but there is no winner 

//displays the winner
	if (Game.Winner() != 0)
	{
		if (Game.Winner() == 1)
			cout << "Player1 is the Winner. Congratulations!" << endl;
		else if (Game.Winner() == 2)
			cout << "Player2 is the Winner. Congratulations!" << endl;
	}

	//displays "Draw" if there is no winner 
	else
		cout << "Draw" << endl;

	return 0;
}