#include<stdio.h>
#include <stdlib.h>
#include<math.h>
#define _CRT_SECURE_NO_WARNINGS
#define N 9
void printGrid(int grid[N][N]);
void userInput(int * row,int * col);
int hitShip(int board[N][N], int x, int y);
int checkValidPos(int board[N][N] ,int col1, int row1, int row2, int col2, int maxSize);
void createShip(int board[N][N], int col1, int row1, int col2, int row2);
void boardSetUp(int board[N][N]);
void shipBlock(int board[N][N], int col, int row);
int main(){
    int board1[N][N];
    int board2[N][N];
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            board1[i][j] = 0;
            board2[i][j] = 0;
        }
    }
    //createShip(board,1,1,3,1);
    printGrid(board1);
    //boardSetUp(board1);
    //boardSetUp(board2);

    
    
    createShip(board1,0,0,0,0);
    createShip(board1,2,1,2,3);
    createShip(board1,5,6,2,6);
    createShip(board1,8,3,8,7);
  

    printGrid(board1);
    printf("GAME OVER");
    return 0;
}
void boardSetUp(int board[N][N]){
    int row1;int row2; int col1; int col2;
    int shipCount;
    for (int i = 5; i > 0; i--)
    {
        shipCount = 6-i;
        
        while(shipCount > 0){

            printf("enter %d tile ship\n", i);

            userInput(&row1,&col1);
            userInput(&row2,&col2);

            col1 -= 'a';
            row1 -= '1';
            col2 -= 'a';
            row2 -= '1';
            if(checkValidPos(board ,col1 ,row1 ,col2, row2, i)){
                printf("%d:%d , %d:%d \n", col1 , row1 , col2 , row2 );

                createShip(board, col1 , row1 , col2 , row2 );
                printGrid(board);
                shipCount--;
            }else{
                printf("Invalid position\n");
            }
            
        }
    }
}
void gameLoop(int board1[N][N], int board2[N][N], int shipCount1, int shipCount2){
    int row1, col1; int row2, col2;
    int player1Turn = 0;
    while(shipCount1 > 0 || shipCount2 > 0){
        printf("Player 1 turn\n");
        userInput(&row1,&col1);
        row1 -= 'a';
        col1 -= '1';
        if(hitShip(board1,row1,col1)){
            if(isDestroyed(board1,row1,col1)){
                printf("Player 1 destroyed a ship! %d ships left\n", shipCount1);
                shipCount1--;
            } else{
                printf("Player 1 hit a ship %d ships left\n", shipCount1);
            }
        }else{
            
        }
    }
        

}
void isDestroyed(int board[N][N], int row ,int col){
    return board[row+1][col] != 1 && board[row][col+1] != 1 && board[row][col-1] != 1 && board[row-1][col]; 
}
int checkValidPos(int board[N][N] ,int col1, int row1, int col2, int row2, int maxSize){

    if(col1 < 0 || col1 > N || row1 < 0 || row1 >  N || col2 < 0 || col2 > N || row2 < 0 || row2 > N){
        printf("out of range\n");
        return 0;
    }

    if(col1 != col2 && row1 != row2){
        printf("cant place a ship on a slant\n");
        return 0;
    }

    if(col1 == col2){
        if(maxSize < abs(row1-row2)){
            printf("ship too long\n");
            return 0;
        } 
        for (int i = 0; i < abs(row1-row2); i++)
        {
            if(board[row1+i][col1] == 1 || board[row1+i][col1] == 2){
                printf("ship in the way1\n");
                return 0;
            }
        }
    } else if(row1 == row2){
        if(maxSize <  abs(col1-col2)){
            printf("ship too long\n");
            return 0;
        }
        for (int i = 0; i < abs(col1-col2); i++)
        {
            if(board[row1][col1+i] == 1 || board[row1][col1+i] == 2){
                printf("ship in the way2\n");
                return 0;
            }
        }
    }

    printf("checking position\n");
    return 1;
     
}

void userInput(int* row,int* col){
        printf("Enter a coordinate (column row):\n");
        char input[2];
        gets(input);
        *col = input[0];
        *row = input[1];

        
        
}
void shipBlock(int board[N][N], int col, int row){
    if(row+1 < N && board[row+1][col] != 1){
        board[row+1][col] = 2;
    }
     if(row-1 > 0 && board[row-1][col] != 1){
        board[row-1][col] = 2;
    }
     if(col+1 < N && board[row][col+1] != 1){
        board[row][col+1] = 2;
    }
     if(col-1 > 0 && board[row][col-1] != 1){
        board[row][col-1] = 2;
    }
}
void createShip(int board[N][N], int col1, int row1, int col2, int row2){
    printf("%d:%d , %d:%d \n", col1 , row1 , col2 , row2 );
    

    if(col1 == col2){
        int row;
        if(row1 > row2){
            row = row2;
        }else{
            row = row1;
        }

        for (int i = 0; i <= abs(row1-row2); i++)
        {
            board[row+i][col1] = 1;
            shipBlock(board,col1,row+i);

        }
        }else if(row1 == row2){
            int col;
            if(col1 > col2){
                col = col2;
            }else{
                col = col1;
            }
            for (int i = 0; i <= abs(col1-col2); i++)
            {
                board[row1][col+i] = 1;
                shipBlock(board,col+i,row1);

            }
        }
    else{
        printf("Invalid placement, try again\n");
    }

}

int hitShip(int board[N][N], int x, int y){
    if(board[x][y] == 1){
        board[x][y] = 3;
        printf("Hit!\n");
        return 1;
    }
    else{
        printf("Missed!\n");
        return 0;
    }
}
void printGrid(int grid[N][N]) {
    printf("\n");
    int emptySgin = '-';
    int shipSign = 'o';
    printf("   ");
    for (char i = 'a'; i < 'a'+N; i++) {
        printf("%2c ", i);
    }
    printf("\n");

    for (int i = 0; i < N; i++) {
        printf("%2d ", i+1); 
        for (int j = 0; j < N; j++) {
            if(!grid[i][j]){
                printf("%2c ",emptySgin);
            } else if(grid[i][j] == 1){
                printf("%2c ", shipSign);
            } else if(grid[i][j] == 2){
                printf("%2c ", 'X');
            }
        }
        printf("\n");
    }
}
// 0 - empty
// 1 - ship
// 2 - ship hit
// 3 - miss
