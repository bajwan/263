#include <iostream>

int board[9][9] = {{ 0, 3, 0, 0, 0, 0, 0, 2, 0 },
                           { 0, 9, 0, 0, 0, 0, 0, 8, 5 },
                           { 5, 0, 0, 0, 8, 0, 4, 0, 0 },
                           { 4, 0, 7, 2, 0, 6, 8, 9, 0 },
                           { 0, 1, 0, 8, 0, 9, 0, 4, 0 },
                           { 0, 8, 9, 5, 0, 1, 3, 0, 2 },
                           { 0, 0, 3, 0, 1, 0, 0, 0, 9 },
                           { 9, 4, 0, 0, 0, 0, 0, 1, 0 },
                           { 0, 7, 0, 0, 0, 0, 0, 3, 0 }
        };

bool solve(){

}

void printBoard(){
	for(int i=0; i<9; i++){
		for(int j=0; j<9; j++){
			printf("%d\t", board[i][j]);
		}
		printf("\n");
	}
}

int main(int argc, char** argv){
	printBoard();
	bool complete = solve(board);
	if(complete){
		printf("Found a solution:\n\n");
		printBoard();
	}
}
