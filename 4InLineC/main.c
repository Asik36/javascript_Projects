#include <stdio.h>

#define _CRT_SECURE_NO_WARNINGS
#define WIDTH 7
#define HEIGHT 6
#define SIZE (WIDTH * HEIGHT)
void print_board(long long int player1_bitboard, long long int player2_bitboard);
void drop_piece(int column, long long int *bitboard,long long int *all_pieces, int column_heights[WIDTH]);
void gameLoop();
int check_winner(long long int bitboard);
int main(){
    
    gameLoop();
    return 0;
}

void drop_piece(int column, long long int *bitboard,long long int *all_pieces, int column_heights[WIDTH]) {
   
    // Calculate the bitmask for the new piece in the current column
    long long int move = (1ULL << (column_heights[column] * WIDTH + column));
    column_heights[column]++;

    *bitboard |= move;  // Add the piece to the player's bitboard
    *all_pieces |= move; // Mark the cell as occupied

}
void print_board(long long int player1_bitboard, long long int player2_bitboard) {
    for (int row = HEIGHT - 1; row >= 0; row--) {
        for (int col = 0; col < WIDTH; col++) {
            long long int pos = 1ULL << (row * WIDTH + col);

            if (player1_bitboard & pos) {
                printf(" X ");
            } else if (player2_bitboard & pos) {
                printf(" O ");
            } else {
                printf(" . ");
            }
        }
        printf("\n");
    }
    printf("\n");
}

int check_winner(long long int bitboard) {
    
    // Check horizontal
    long long int temp = bitboard & (bitboard >> 1);
    if (temp & (temp >> 2)) return 1;

    // Check vertical
    temp = bitboard & (bitboard >> WIDTH);
    if (temp & (temp >> (2 * WIDTH))) return 1;

    // Check diagonal (\)
    temp = bitboard & (bitboard >> (WIDTH + 1));
    if (temp & (temp >> (2 * (WIDTH + 1)))) return 1;

    // Check diagonal (/)
    temp = bitboard & (bitboard >> (WIDTH - 1));
    if (temp & (temp >> (2 * (WIDTH - 1)))) return 1;

    return 0;
}


void gameLoop(){
    long long int player1_bitboard = 0; // Player 1's pieces
    long long int player2_bitboard = 0; // Player 2's pieces
    long long int all_pieces = 0;       // All occupied cells
    int column_heights[WIDTH] = {0};    // Collum pices num

    int turn = 0;
    int moves = 0;
    int max_moves = WIDTH * HEIGHT;
    int isWin = 0;
    int column;

    while(!isWin){
        column= -1;
        print_board(player1_bitboard, player2_bitboard);
        if(moves == max_moves){
            printf("It's a draw!\n");
            isWin = 1;
        }else{
            printf("Player %d, enter a column (0-%d): ", turn+1, WIDTH - 1);
            fflush(stdin);  
            scanf("%d", &column);
            
            if (column < 0 || column >= WIDTH ) {
                printf("Invalid column! Try again.\n");
            
            }else if( column_heights[column] >= HEIGHT){
                    printf("column full! Try again.\n");
            }
            else if(turn){ // If player 1's turn

                drop_piece(column, &player1_bitboard,&all_pieces, column_heights);
                if(check_winner(player1_bitboard)){
                    print_board(player1_bitboard , player2_bitboard);
                    printf("Player 1 (X) wins!\n");
                    isWin = 1;
                }
                turn =!turn;
                moves++;
            }else{ // If players 2's turn
                drop_piece(column, &player2_bitboard,&all_pieces,column_heights);
                if(check_winner(player2_bitboard)){
                    print_board(player1_bitboard , player2_bitboard);
                    printf("Player 2 (O) wins!\n");
                    isWin = 1;
                }
                turn =!turn;
                moves++;
            }
        }
        

    }
 
}
