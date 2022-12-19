#include <iostream>
#include <stdlib.h>
#include <string>
#include <stdbool.h>
#include <vector>
#include <random>

using namespace std;

bool isPlayerTurn = true;
bool ended = false;

struct Piece {
	// 0 for none, 1 for white 2 for black
	int attribute;
	bool isKing = false;
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
	//check if the piece is a king
	bool checkKing = board[i][j].isKing;
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
			//if it is the king then enking it
			if (checkKing) {
				board[i - 1][j - 1].isKing = true;
			}
			//reset
			board[i][j].attribute = 0;
			board[i][j].isKing = false;
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
				//if it is the king then enking it
				if (checkKing) {
					board[i - 2][j - 2].isKing = true;
				}
				// set that piece to null since it is eaten
				board[i - 1][j - 1].attribute = 0;
				//reset
				board[i][j].attribute = 0;
				board[i][j].isKing = false;
				//changer turn
				isPlayerTurn = !isPlayerTurn;
			}
		}
	}

}

void upperRight(int i, int j) {
	int type = board[i][j].attribute;
	bool checkKing = board[i][j].isKing;

	if (isEdge(i - 1, j + 1)) {
		printf("Invalid Move");
	}
	else {
		int typenext = board[i - 1][j + 1].attribute;
		if (typenext == 0) {
			board[i - 1][j + 1].attribute = type;
			if (checkKing) {
				board[i - 1][j + 1].isKing = true;
			}
			board[i][j].attribute = 0;
			board[i][j].isKing = false;
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
				if (checkKing) {
					board[i - 2][j + 2].isKing = true;
				}
				board[i - 1][j + 1].attribute = 0;
				board[i][j].attribute = 0;
				board[i][j].isKing = false;
				isPlayerTurn = !isPlayerTurn;
			}
		}
	}
}

void downRight(int i, int j) {
	int type = board[i][j].attribute;
	bool checkKing = board[i][j].isKing;

	if (isEdge(i + 1, j + 1)) {
		printf("Invalid Move");
	}
	else {
		int typenext = board[i + 1][j + 1].attribute;
		if (typenext == 0) {
			board[i + 1][j + 1].attribute = type;
			if (checkKing) {
				board[i + 1][j + 1].isKing = true;
			}
			board[i][j].attribute = 0;
			board[i][j].isKing = false;
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
				if (checkKing) {
					board[i + 2][j + 2].isKing = true;
				}
				board[i + 1][j + 1].attribute = 0;
				board[i][j].attribute = 0;
				board[i][j].isKing = false;
				isPlayerTurn = !isPlayerTurn;
			}
		}
	}
}

void downLeft(int i, int j) {
	int type = board[i][j].attribute;
	bool checkKing = board[i][j].isKing;

	if (isEdge(i + 1, j - 1)) {
		printf("Invalid Move");
	}
	else {
		int typenext = board[i + 1][j - 1].attribute;
		if (typenext == 0) {
			board[i + 1][j - 1].attribute = type;
			if (checkKing) {
				board[i + 1][j - 1].isKing = true;
			}
			board[i][j].attribute = 0;
			board[i][j].isKing = false;
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
				if (checkKing) {
					board[i + 2][j - 2].isKing = true;
				}
				board[i + 1][j - 1].attribute = 0;
				board[i][j].attribute = 0; 
				board[i][j].isKing = false;
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

//parameters: coordiates and an array showing eligible directions.
//This is only for black piece AI only
vector<int> moveAble(int i, int j){
	vector<int> arr;
	
	//black -> invalid
	if (board[i + 1][j + 1].attribute == 2 || isEdge(i + 1, j + 1)) {
		;
	}
	//white -> check +2 coordinates to see if its eligible for jump
	else if (board[i + 1][j + 1].attribute == 1) {
		if (isEdge(i + 2, j + 2) || board[i + 1][j + 1].attribute != 0) {
			;
		}
		arr.push_back(1);
	}
	else {
		arr.push_back(1);
	}

	if (board[i + 1][j - 1].attribute == 2 || isEdge(i + 1, j - 1)) {
		;
	}
	//white -> check +2 coordinates to see if its eligible for jump
	else if (board[i + 1][j - 1].attribute == 1) {
		if (isEdge(i + 2, j - 2) || board[i + 1][j - 1].attribute != 0) {
			;
		}
		arr.push_back(2);
	}
	else {
		arr.push_back(2);
	}
	return arr;

}

vector<int> getMoveAI() {
	vector<vector<int>> allMoves;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			// is the AI pieces
			if (board[i][j].attribute == 2) {
				//get all applicable direction 1 for dleft 2 for dright
				vector<int> allMove = moveAble(i, j);
				// looping thru the coordinates and append direction to coordinates -> get a big array
				for (int x = 0; x < allMove.size(); x++) {
					allMoves.push_back({ allMove[x],i,j});
				}
			}
		}
	}

	// Generate a random number aka move for the AI 
	// ref: https://stackoverflow.com/questions/7560114/random-number-c-in-some-range

	std::random_device rd; // obtain a random number from hardware
	std::mt19937 gen(rd()); // seed the generator
	std::uniform_int_distribution<> distr(0, allMoves.size()-1); // define the range
	
	int ranNum = distr(gen) ;
	//printf("----%d----", ranNum);
	for (int i = 0; i < allMoves.size(); i++) {
		if (i == ranNum) {
			return allMoves[i];
		}
	}
}

void decodeAImove(vector<int> move) {
	if (move.empty()) {
		printf("Congratualtions! WHITE wins");
	}
	else {
		int x_coord = move[1];
		int y_coord = move[2];
		//printf("%d -> %d -> %d \n", move[0], move[1], move[2]);
		//DownLeft
		if (move[0] == 1) {
			downLeft(x_coord, y_coord);
		}
		//DownRight
		else if (move[0] == 2) {
			downRight(x_coord, y_coord);
		}
	}
}

string input;
//number & letter of the coordinates
int numbr, letter;

void getInput() {
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
			if (letter > 7 || letter < 0 || numbr > 7 || numbr < 0) {
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
}

void userMove() {
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
		else if (input[0] - 'A' == 2 && board[numbr][letter].isKing) {
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

void runGame() {
	

	printf("\n\nComputer Science Checkers!!\n\n\n");

	printf("What mode do you want to play \n");
	printf("1 for PvP, 2 for PvC, or zero to escape\n");

	//condition 1 or 2 or 0 exit
	bool startgame = false;
	while (!startgame) {
		getline(cin, input);
		if (input == "0") {
			ended = true;
			break;
		}
		else if (input == "1") {
			startgame = true;
			//boolean to see if game ended
			checkEndGame();
			display(board);
			while (!ended) {
				if (isPlayerTurn) {
					printf("It's your turn, WHITE \n");
				}
				else
					printf("It's your turn, BLACK \n");
				getInput();

				/*
				 * True -> P1 (white) False -> P2 (black)
				 */


				if (isPlayerTurn) {
					//Check their piece condition
					userMove();
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
		else if (input == "2") {
			startgame = true;
			checkEndGame();
			display(board);
			while (!ended) {
				if (isPlayerTurn) {
					printf("It's your turn, WHITE \n");
					getInput();
					userMove();
				}
				else {
					decodeAImove(getMoveAI());
				}
				printf("BLACK has made their move! \n");
				makeKing();
				display(board);
			}
		}
		else
			printf("Please select the right option \n");
	}
}

void setallKing() {
	for (int i = 0; i < 8; i++) {
		board[0][i].attribute = 1;
		board[1][i].attribute = 2;
	}
}
int main() {
	initBoard();
	//setallKing();
	runGame();
	return 0;
}


// TODO: Get with input 