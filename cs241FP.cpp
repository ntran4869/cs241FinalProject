#include <iostream>
#include <stdlib.h>
#include <string>
#include <stdbool.h>

using namespace std;

bool isPlayerTurn = true;
bool ended = false;

struct Piece {
	// 0 for none, 1 for white 2 for black
	int attribute;
	bool isKing = false;
	Piece* upleft, * upright, * dleft, * dright;
	std::string getString()
	{
		std::string baseSymbol;

		if (attribute == 1)
			baseSymbol = "W";
		else if (attribute == 2)
			baseSymbol = "B";
		else
			baseSymbol = " ";

		if (isKing)
			baseSymbol += "K";
		else
			baseSymbol += " "; // add a space in the non-king state just to keep consistency

		return baseSymbol;
	}

};

// create player
struct Player {
	int team;
	//Constructor
	Player(int x) {
		team = x;
	}

};

Piece board[8][8];

void display(Piece board[8][8]) {
	printf("\n");
	printf("\a");
	for (int i = 0; i < 8; i++) {
		printf("\n  +---+---+---+---+---+---+---+---+");
		printf("\n%d   ", i);
		for (int j = 0; j < 8; j++) {
			cout << board[i][j].getString();
			printf("  ");
		}
	}
	printf("\n  +---+---+---+---+---+---+---+---+");
	printf("\n    A   B   C   D   E   F   G   H\n");

}

bool isEdge(int i, int j) {
	if (i < 0 || j < 0 || i > 7 || j >7) {
		return true;
	}
	return false;
}

// upper left for white and kings only
void upperLeft(int i, int j) {
	// get the type
	int type = board[i][j].attribute;
	// check upper left. if null -> move, if white -> invalid move, if black -> eat and jump

	// check edge first
	if (isEdge(i - 1, j - 1)) {
		printf("Invalid Move");
	}
	else {
		//get neighbor piece type
		int typenext = board[i - 1][j - 1].attribute;
		if (typenext == 0) {
			//that piece is null => move
			board[i - 1][j - 1].attribute = type;
			//reset
			board[i][j].attribute = 0;
			// move eligible -> change to next player turn
			isPlayerTurn = !isPlayerTurn;
			return;
		}
		//same type => invalid
		if (type == typenext) {
			printf("Invalid Move--");
		}
		else {
			//check edge jump spot
			if (isEdge(i - 2, j - 2) || board[i - 2][j - 2].attribute != 0) {
				printf("Invalid Move--");
			}
			else {
				// set
				board[i - 2][j - 2].attribute = type;
				// set that piece to null since it is eaten
				board[i - 1][j - 1].attribute = 0;
				//reset
				board[i][j].attribute = 0;
				//changer turn
				isPlayerTurn = !isPlayerTurn;
			}
		}
	}

}

void upperRight(int i, int j) {
	int type = board[i][j].attribute;

	if (isEdge(i - 1, j + 1)) {
		printf("Invalid Move");
	}
	else {
		int typenext = board[i - 1][j + 1].attribute;
		if (typenext == 0) {
			board[i - 1][j + 1].attribute = type;
			board[i][j].attribute = 0;
			isPlayerTurn = !isPlayerTurn;
			return;
		}
		if (type == typenext) {
			printf("Invalid Move");
		}
		else {
			if (isEdge(i - 2, j + 2) || board[i - 2][j + 2].attribute != 0) {
				printf("Invalid Move");
			}
			else {
				board[i - 2][j + 2].attribute = type;
				board[i - 1][j + 1].attribute = 0;
				board[i][j].attribute = 0;
				isPlayerTurn = !isPlayerTurn;
			}
		}
	}
}

void downRight(int i, int j) {
	int type = board[i][j].attribute;

	if (isEdge(i + 1, j + 1)) {
		printf("Invalid Move");
	}
	else {
		int typenext = board[i + 1][j + 1].attribute;
		if (typenext == 0) {
			board[i + 1][j + 1].attribute = type;
			board[i][j].attribute = 0;
			isPlayerTurn = !isPlayerTurn;
			return;
		}
		if (type == typenext) {
			printf("Invalid Move");
		}
		else {
			if (isEdge(i + 2, j + 2) || board[i + 2][j + 2].attribute != 0) {
				printf("Invalid Move");
			}
			else {
				board[i + 2][j + 2].attribute = type;
				board[i + 1][j + 1].attribute = 0;
				board[i][j].attribute = 0;
				isPlayerTurn = !isPlayerTurn;
			}
		}
	}
}

void downLeft(int i, int j) {
	int type = board[i][j].attribute;

	if (isEdge(i + 1, j - 1)) {
		printf("Invalid Move");
	}
	else {
		int typenext = board[i + 1][j - 1].attribute;
		if (typenext == 0) {
			board[i + 1][j - 1].attribute = type;
			board[i][j].attribute = 0;
			isPlayerTurn = !isPlayerTurn;
			return;
		}
		if (type == typenext) {
			printf("Invalid Move");
		}
		else {
			if (isEdge(i + 2, j - 2) || board[i + 2][j - 2].attribute != 0) {
				printf("Invalid Move");
			}
			else {
				board[i + 2][j - 2].attribute = type;
				board[i + 1][j - 1].attribute = 0;
				board[i][j].attribute = 0; 
				isPlayerTurn = !isPlayerTurn;
			}
		}
	}
}

void initBoard() {
	// setup board initially
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (i % 2 == 0 && j % 2 == 1 && i != 3 && i != 4) {
				if (i < 3) {
					board[i][j].attribute = 2;
				}
				else {
					board[i][j].attribute = 1;
				}
			}
			else if (i % 2 == 1 && j % 2 == 0 && i != 3 && i != 4) {
				if (i < 3) {
					board[i][j].attribute = 2;
				}
				else {
					board[i][j].attribute = 1;
				}
			}
			else {
				board[i][j].attribute = 0;
			}
		}
	}
}

void makeKing() {
	for (int i = 0; i < 8; i++) {
		if (board[0][i].attribute == 1) {
			board[0][i].isKing = true;
		}
		if (board[7][i].attribute == 2) {
			board[7][i].isKing = true;
		}
	}
}

void checkEndGame() {
	int blackCount = 0;
	int whiteCount = 0;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (board[i][j].attribute == 1) {
				whiteCount++;
			}
			else if (board[i][j].attribute == 2) {
				blackCount++;
			}
		}
	}

	if (whiteCount == 0) {
		printf("Congratualtions! BLACK wins");
		ended = true;
	}
	else if (blackCount == 0) {
		printf("Congratualtions! WHITE wins");
		ended = true;
	}
}

void runGame() {
	string input;

	printf("\n\nComputer Science Checkers!!\n\n\n");

	printf("What mode do you want to play \n");
	printf("1 for PvP, 2 for PvC, or zero to escape\n");

	//condition 1 or 2 or 0 exit
	//input = getchar();

	// set up new player obj
	Player Player1(1);
	Player Player2(2);

	

	display(board);
	//number & letter of the coordinates
	int numbr, letter;
	//boolean to see if game ended
	checkEndGame();
	while (!ended) {
		if (isPlayerTurn) {
			printf("It's your turn, WHITE \n");
		}
		else
			printf("It's your turn, BLACK \n");
		while (true) {

			printf("\nPlease enter the location of the piece you would like to move!\n");

			try {
				getline(cin, input);
				if (input.length() < 2) {
					throw ("Please enter a coordinate on the board in the form '[letter][number]'. Letter in Capital");
				}
				letter = input[0] - 'A';
				numbr = input[1] - '0';
				//printf("%d --> %d", letter, numbr);
				if (letter > 7 && letter < 0 && numbr > 7 && numbr < 0) {
					throw ("Piece out of bound");
				}
				break;
			}
			catch (const char* e) // catch incorrect parse or our throw exception
			{
				cout << e << '\n';
				cin.ignore(32767, '\n');
				cin.clear();
			}
			
		}

		/*
		 * True -> P1 (white) False -> P2 (black)
		 */


		if (isPlayerTurn) {
			//Check their piece condition
			if (board[numbr][letter].attribute == 1) {
				printf("Which Direction? \n");
				//Capital Letter Here
				printf("A for top left, B for top right \n");
				if (board[numbr][letter].isKing) {
					printf("C for bottom left, D for bottom right \n");
				}
				getline(cin, input);

				if (input[0] - 'A' == 0) {
					upperLeft(numbr, letter);
					// valid move -> switch turn
				}
				else if (input[0] - 'A' == 1) {
					upperRight(numbr, letter);
				}
				else if (input[0] - 'A' == 2 && board[numbr][letter].isKing){
					downLeft(numbr, letter);
				}
				else if (input[0] - 'A' == 3 && board[numbr][letter].isKing) {
					downRight(numbr, letter);
				}
				else
					printf("Not a valid call \n");
			}
			else
				printf("It is not your piece, choose again! \n");
		}
		// BLACK turn
		else {
			//Check their piece condition
			if (board[numbr][letter].attribute == 2) {
				printf("Which Direction? \n");
				//Capital Letter Here
				printf("A for down left, B for down right \n");
				if (board[numbr][letter].isKing) {
					printf("C for top left, D for top right \n");
				}
				getline(cin, input);

				if (input[0] - 'A' == 0) {
					downLeft(numbr, letter);
					// valid move -> switch turn
				}
				else if (input[0] - 'A' == 1) {
					downRight(numbr, letter);
				}
				else if (input[0] - 'A' == 2 && board[numbr][letter].isKing) {
					upperLeft(numbr, letter);
				}
				else if (input[0] - 'A' == 3 && board[numbr][letter].isKing) {
					upperRight(numbr, letter);
				}
				else
					printf("Not a valid call \n");
			}
			else
				printf("It is not your piece, choose again! \n");
		}
		//check if any piece is eligible for king
		makeKing();
		display(board);
	}
}

int main() {
	initBoard();
	runGame();
	return 0;
}


// TODO: Get with input 