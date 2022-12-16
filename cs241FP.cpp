#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
using namespace std;

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
			return;
		}
		//same type => invalid
		if (type == typenext) {
			printf("Invalid Move--");
		}
		else {
			//check edge jump spot
			if (isEdge(i - 2, j - 2) || board[i-2][j-2].attribute != 0) {
				printf("Invalid Move--");
			}
			else {
				// set
				board[i - 2][j - 2].attribute = type;
				// set that piece to null since it is eaten
				board[i - 1][j - 1].attribute = 0;
				//reset
				board[i][j].attribute = 0;
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

void runGame(){
	printf("\n\nComputer Science Checkers!!\n\n\n");
	display(board);
	char input;
	int x,y,z;
	bool no=true;
	while(input!=EOF){
		printf("\nPlease enter the location of the piece you would like to move!\n");
		input=getchar();
		while(isspace(input)){
			input=getchar();
		}
		no=true;
		while(no){
			y=input-'A';
			input=getchar();
			x=input-'0';
			if(y<0|y>7|x<0|x>7){
				printf("Please try again! Fam\n");
				input=getchar();
			}
			else{
				no=false;
			}
		}
		printf("\nPlease type one of \nA: to move up and to the left\nB: to move up and to the right\nC: to move down and to the left\nD: to move down and to the right\n");
		input=getchar();
		while(isspace(input)){
			input=getchar();
		}
		no=true;
		while(no){
			z=input-'A';
			if(z<0|z>3){
				printf("Please try again! Yo\n");
				input=getchar();
			}
			else{
				no=false;
				input=getchar();
			}
		}
		if(z==0){
			upperLeft(x,y);
		}
		else{
			if(z==1){
				upperRight(x,y);
			}
			else{
				if(z==2){
					downLeft(x,y);
				}
				else{
					downRight(x,y);
				}
			}
		}
		display(board);
	}

}

int main(){
	initBoard();
	runGame();
	return 0;
}


// TODO: Get with input 
	
