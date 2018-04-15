#include <iostream>
#include <chrono>
#include <thread>

void printBoard(int board[9][9]){
	printf("==============================================\n");
	for(int i=0; i<9; i++){
		for(int j=0; j<9; j++){
			printf("%d\t", board[i][j]);
		}
		printf("\n");
	}
}

bool findSpot(int board[9][9], int & row, int & col){
	for(int i=0; i<9; i++){
		for(int j=0; j<9; j++){
			if(board[i][j] == 0){
				row = i;
				col = j;
				return false;
			}
		}
	}
	return true;
}

bool validBox(int board[9][9], int x, int y, int val){
	int cx = 3 * (x / 3) + 1;
	int cy = 3 * (y / 3) + 1;
	for(int i=-1; i<2; i++){
		for(int j=-1; i<2; i++){
			if(board[x+i][y+j] == val){
				return false;
			}
		}
	}
	return true;
}

bool isValid(int board[9][9], int x, int y, int val){
	for(int i=0; i<9; i++){
		if(board[i][y] == val){
			return false;
		}
		if(board[x][i] == val){
			return false;
		}
	}
	return validBox(board, x, y, val);
}

bool solve(int board[9][9],int x, int y){
	//std::this_thread::sleep_for(std::chrono::milliseconds(500));
	int x1 = x;
	int y1 = y;
	printf("Examining %d, %d.\n", x, y);
	printBoard(board);
	char n;
	//std::cin >> n;
	if(findSpot(board, x, y)){
		return true;
	}
	for(int val = 1; val<10; val++){
		if(isValid(board, x, y, val)){
			board[x][y] = val;
			if(solve(board, x, y))
			{
				return true;
			}
		}
	}
	printf("Backtracking.\n");
	board[x1][y1] = 0;
	return false;
}


int main(int argc, char** argv){
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

	bool complete = solve(board,0,0);
	if(complete){
		printf("Found a solution:\n\n");
	} else {
		printf("No solution found.");
	}
}
