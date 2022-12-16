#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;

//Structure of the pieces/board spaces, with their team representing either the player, computer, or a black space, and whether or not they are a king.
struct Piece {
	char team;
	int king=0;
};

//The board we will be using throughout the game.
Piece board[8][8];

//The function that desplays and updates the board, it prints the checked pattern and the character value of the pieces.
void display(Piece board[8][8]){
	printf("\n");
	printf("\a");
	for(int i=0; i<8; i++){
		printf("\n  +---+---+---+---+---+---+---+---+");
		printf("\n%d | %c | %c | %c | %c | %c | %c | %c | %c |",i,board[i][0].team,board[i][1].team,board[i][2].team,board[i][3].team,board[i][4].team,board[i][5].team,board[i][6].team,board[i][7].team);
		}
	printf("\n  +---+---+---+---+---+---+---+---+");
	printf("\n    A   B   C   D   E   F   G   H\n");
}


//Functions that allow the pieces to move in each of the legal checkers directions. This includes the possiblity of taking a piece, and has more options for a king piece.
void upperLeft(int i,int j){
	if(board[i][j].team=='X'){
		if(i>0&&j>0){
			char temp=board[i-1][j-1].team;
			if(temp=='0'){
				if(i>1&&j>1){
					if(board[i-2][j-2].team==' '){
						temp=board[i-2][j-2].team;
						board[i-2][j-2].team=board[i][j].team;
						board[i-2][j-2].king=board[i][j].king;
						board[i-1][j-1].team=temp;
						board[i-1][j-1].king=0;
						board[i][j].team=temp;
						board[i][j].king=0;
					}
					else{
						printf("Not a valid move, please try again\n");
					}
				}
				else{
					printf("Not a valid move, please try again\n");
				}
			}
			else{
				if(temp=='X'){
					printf("Not a valid move, please try again\n");
				}
				else{
					board[i-1][j-1].team=board[i][j].team;
					board[i-1][j-1].king=board[i][j].king;
					board[i][j].team=temp;
					board[i][j].king=0;
				}
			}
		}
		else{
			printf("Not a valid move, please try again\n");
		}
	}
	else{
		printf("Not a valid move, please try again\n");
	}
}
void upperRight(int i,int j){
	if(board[i][j].team=='X'){
		if(i>0&&j<7){
			char temp=board[i-1][j+1].team;
			if(temp=='0'){
				if(i>1&&j<6){
					if(board[i-2][j+2].team==' '){
						temp=board[i-2][j+2].team;
						board[i-2][j+2].team=board[i][j].team;
						board[i-2][j+2].king=board[i][j].king;
						board[i-1][j+1].team=temp;
						board[i-1][j+1].king=0;
						board[i][j].team=temp;
						board[i][j].king=0;
					}
					else{
						printf("Not a valid move, please try again\n");
					}
				}
				else{
					printf("Not a valid move, please try again\n");
				}
			}
			else{
				if(temp=='X'){
					printf("Not a valid move, please try again\n");
				}
				else{
					board[i-1][j+1].team=board[i][j].team;
					board[i-1][j+1].king=board[i][j].king;
					board[i][j].team=temp;
					board[i][j].king=0;
				}
			}
		}
		else{
			printf("Not a valid move, please try again\n");
		}
	}
	else{
		printf("Not a valid move, please try again\n");
	}
}
void lowerLeft(int i, int j){
	if(board[i][j].team=='X'&&board[i][j].king==1){
		if(i<7&&j>0){
			char temp=board[i+1][j-1].team;
			if(temp=='0'){
				if(i<6&&j>1){
					if(board[i+2][j-2].team==' '){
						temp=board[i+2][j-2].team;
						board[i+2][j-2].team=board[i][j].team;
						board[i+2][j-2].king=board[i][j].king;
						board[i+1][j-1].team=temp;
						board[i+1][j-1].king=0;
						board[i][j].team=temp;
						board[i][j].king=0;
					}
					else{
						printf("Not a valid move, please try again\n");
					}
				}
				else{
					printf("Not a valid move, please try again\n");
				}
			}
			else{
				if(temp=='X'){
					printf("Not a valid move, please try again\n");
				}
				else{
					board[i+1][j-1].team=board[i][j].team;
					board[i+1][j-1].king=board[i][j].king;
					board[i][j].team=temp;
					board[i][j].king=0;
				}
			}
		}
		else{
			printf("Not a valid move, please try again\n");
		}

	}
	else{
		printf("Not a valid move, please try again\n");
	}
}
void lowerRight(int i, int j){
	if(board[i][j].team=='X'&&board[i][j].king==1){
		if(i<7&&j<7){
			char temp=board[i+1][j+1].team;
			if(temp=='0'){
				if(i<6&&j<6){
					if(board[i+2][j+2].team==' '){
						temp=board[i+2][j+2].team;
						board[i+2][j+2].team=board[i][j].team;
						board[i+2][j+2].king=board[i][j].king;
						board[i+1][j+1].team=temp;
						board[i+1][j+1].king=0;
						board[i][j].team=temp;
						board[i][j].king=0;
					}
					else{
						printf("Not a valid move, please try again\n");
					}
				}
				else{
					printf("Not a valid move, please try again\n");
				}
			}
			else{
				if(temp=='X'){
					printf("Not a valid move, please try again\n");
				}
				else{
					board[i+1][j+1].team=board[i][j].team;
					board[i+1][j+1].king=board[i][j].king;
					board[i][j].team=temp;
					board[i][j].king=0;
				}
			}
		}
		else{
			printf("Not a valid move, please try again\n");
		}
	}
	else{
		printf("Not a valid move, please try again\n");
	}
}

//The main function, which builds the pieces in the board, runs the menu and game.
int main(){
	for(int i=0;i<8;i++){
		for(int j=0;j<8;j++){
			board[i][j].team=' ';
			if(i%2==0&&j%2==1&&i!=4){
				if(i<3){
					board[i][j].team='0';
				}
				else{
					board[i][j].team='X';
				}
			}
			if(i%2==1&&j%2==0&&i!=3){
				if(i<3){
					board[i][j].team='0';
				}
				else{
					board[i][j].team='X';
				}
			}
		}
	}
	printf("\n\nComputer Science Checkers!!\n\n\n");
	display(board);
	char input;
	int x;
	int y;
	int z;
	while(input!=EOF){
		printf("\nPlease enter the location of the piece you would like to move!\n");
		input=getchar();
		while(isspace(input)){
			input=getchar();	
		}
		int no=1;
		while(no){
			y=input-'A';
			input=getchar();
			x=input-'0';
			if(y<0|y>7|x<0|x>7){
				printf("Please try again! Yo\n");
				input=getchar();
			}
			else{
				no=0;	
			}
		}
		printf("\nPlease type one of \nA: to move up and to the left\nB: to move up and to the right\nC: to move down and to the left\nD: to move down and to the right\n");
		input=getchar();
		while(isspace(input)){
			input=getchar();
		}
		no=1;
		while(no){
			z=input-'A';
			if(z<0|z>3){
				printf("Please try again! HI\n");
				input=getchar();
			}
			else{
				no=0;
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
					lowerLeft(x,y);
				}
				else{
					lowerRight(x,y);
				}
			}
		}
		display(board);
	}

	return 0;
}

