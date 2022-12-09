#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void display(char board[8][8]){
	printf("\n");
	printf("\a");
	for(int i=0; i<8; i++){
		printf("\n  +---+---+---+---+---+---+---+---+");
		printf("\n%d | %c | %c | %c | %c | %c | %c | %c | %c |",i,board[i][0],board[i][1],board[i][2],board[i][3],board[i][4],board[i][5],board[i][6],board[i][7]);
		}
	printf("\n  +---+---+---+---+---+---+---+---+");
	printf("\n    0   1   2   3   4   5   6   7\n");
}

int main(){
	char board[8][8];
	for(int i=0;i<8;i++){
		for(int j=0;j<8;j++){
			board[i][j]=' ';
			if(i%2==0&&j%2==1&&i!=4){
				if(i<3){
					board[i][j]='0';
				}
				else{
					board[i][j]='X';
				}
			}
			if(i%2==1&&j%2==0&&i!=3){
				if(i<3){
					board[i][j]='0';
				}
				else{
					board[i][j]='X';
				}
			}
		}
	}
	printf("\n\nComputer Science Checkers!!\n\n\n");
	display(board);
	return 0;
}

