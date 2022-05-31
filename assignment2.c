// Program:  Tic Tac Toe
// Purpose:  Creating a dynamic tic tac toe game which takes move from a input file
// Author :  Ali Yetkin Irmak
// Date   :  10/04/2022

#include <stdio.h>
#include <stdlib.h>



int **initialize_board(int board_size){

	int x,y;
	
	board = (int **) malloc (sizeof(int *) * board_size);
	
	for ( x=0; x<board_size; x++){
	
		board[x] = malloc (sizeof(int) * board_size);
		
		for ( y=0; y<board_size; y++){
		
			board[x][y] = '-';
			
		}
	
	}
	
	return board;
	
}

void print_state(int **board){

	int x,y;
	
	for ( x=0; x<board_size; x++) {
	
		for ( y=0; y<board_size; y++) {
		
			printf("%c",board[x][y]);			
		
		}
	
	}

}

int validate_move(int col, int row, int **board){

	if ( col >= board_size || row >= board_size || col < 0 || row < 0 ) return 0;
	
	else if ( board[row][col] == 'X' || board[row][col] == 'O' ) return 0;
	
	else return 1;

}

void update_board(int marker, int **board, int col, int row){

	board[row][col] = marker;

}

int check_winner(int **board){

	int check_rows(int **board){
	
		int x,y,cx,co;
		
		for ( x=0; x<board_size; x++ ){
			
			cx = 0;
			co = 0;
		
			for ( y=0; y<board_size; y++ ){
				
				if ( board[x][y] = 'X' ) {
					
					cx++;
				
				}
				
				else if ( board[x][y] = 'O') {
				
					co++;
					
				}
				
				else if ( cx == board_size || co == board_size ) {
				
					return 1;
					break;
				
				}
				
			}
		
			return 0;	
		}
		
	}
		
	int check_cols(int **board){
	
		int x,y,cx,co;
		
		for ( y=0; y<board_size; y++ ){
			
			cx = 0;
			co = 0;
		
			for ( x=0; x<board_size; x++){
				
				if ( board[x][y] = 'X' ) {
					
					cx++;
				
				}
				
				else if ( board[x][y] = 'O') {
				
					co++;
					
				}
				
				else if ( cx == board_size || co == board_size ) {
				
					return 1;
					break;
				
				}
				
			}
		
			return 0;	
			
		}
		
	}

	int check_diag(int **board){
	
		int x,y,cx,co;
		
		x=0;
		
		for ( y=0; y<board_size; y++ ) {
		
			if ( board[x][y] = 'X' ) {
					
				cx++;
				
			}
				
			else if ( board[x][y] = 'O') {
				
				co++;
					
			}
			
			else if ( cx == board_size || co == board_size ) {
				
					return 1;
					break;
				
				}
			
			x++;
			
		}
		
		for ( y=board_size; y<=0; y-- ) {
		
			if ( board[x][y] = 'X' ) {
					
				cx++;
				
			}
				
			else if ( board[x][y] = 'O') {
				
				co++;
					
			}
			
			else if ( cx == board_size ) {
				
				return cx;
				break;
				
			}
				
			else if ( co == board_size ) {
				
				return co;
				break;
				
			}
			
			x++;
		
		}
		
		return 0;
	
	}
	
	if ( check_rows(int **board) == 1 || check_cols(int **board) == 1 || check_diag(int **board) == 1 ) return 1;
	
	else return 0;
	
}

int main(int argc, char **argv){

    FILE *fpt;

	if ( argc = NULL || argv = NULL ) printf("Please enter valid values");
	
	else {

        fpt = fopen("input.txt","r");

        int row,col;
		char line[1000];

        argc = board_size;
        rounds = 0;

        maxrounds = board_size * board_size;
		board = initialize_board(board_size);

        while (fgets(line, sizeof(line), fp))
		{
			fscanf(line,"%d,%d,%c", &row, &col, &marker);
			if (validate_move(col,row,board) = 1)
			{
				update_board(marker,board,col,row);
				print_state(board);

				if (check_winner(board) = 1)
				{
					printf("We have a winner!!!");
				}
					
			}
			else printf("Plese check your input file");
		}

        fclose(fpt);

	}

}