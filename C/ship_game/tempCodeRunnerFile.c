#include<stdio.h>
#define _CRT_SECURE_NO_WARNINGS
#define SIZE 8
#define SHIP_SIGN 'S' 
#define EMPTY_SIGN '~'
#define HIT_SIGN '!' 
#define MISS_SIGN 'x' 

#define UP 'w'
#define DOWN 's'
#define LEFT 'a'
#define RIGHT 'd'

void printBoard(int board[SIZE][SIZE]);
void printBoardFog(int board[SIZE][SIZE]);
void createBoard(int board[SIZE][SIZE]);
int boardSetUp(int board[SIZE][SIZE]);
int isShipAround(int board[SIZE][SIZE],int x , int y);
int isValidInput(int x , int y , int shipLength , int direction, int board[SIZE][SIZE]);
int createShip(int x , int y , int shipLength , int direction, int board[SIZE][SIZE] );
void getInput(int *x , int *y ,char *direction, int shipLength);
int main(){
    int board1[SIZE][SIZE];
    int board2[SIZE][SIZE];

    createBoard(board1);
    createBoard(board2);


    printf("player 1 board:\n");
    int shipCountP1 = boardSetUp(board1);
    printf("player 2 board:\n");
    int shipCountP2 = boardSetUp(board2);
    printf("%d %d\n",shipCountP1,shipCountP2);
    int turn = 0;
    int x,y, direction;
    while(shipCountP1 != 0 && shipCountP2 != 0){
        if(turn){
            printf("player 1 turn");
            printBoardFog(board2);
            getInput(&x,&y,0,1);
            x--;
            y--;
            if(!shoot(board2,x,y,&shipCountP2)){
                turn =!turn;
            }
        } else{
            printf("player 2 turn");
            printBoardFog(board1);
            getInput(&x,&y,&direction,1);
            x--;
            y--;
            if(!shoot(board1,x,y,&shipCountP1)){
                turn =!turn;

            }
        }

    }
    if(shipCountP1 == 0){
        printf("Player 2 wins!\n");
    } else{
        printf("Player 1 wins!\n");
    }




    return 0;
}

int shoot(int board[SIZE][SIZE],int x , int y ,int *shipCount){

    if(board[x][y] == 1){
        board[x][y] = 4;
        if(isShipAround(board,x,y)){
            if(x+1 >= 0) board[x+1][y] = 4;
            printf("Hit!\n");
            return 1;
        }
        else{
            if(y-1 >= 0 ) board[x][y-1] = 5;
            if(y+1 < SIZE ) board[x][y+1] = 5;
            if(x-1 >= 0 ) board[x-1][y] = 5;
            if(x+1 < SIZE) board[x+1][y] = 5;
            *shipCount= *shipCount-1;
            printf("Ship destroied! %d ships left\n",*shipCount);
            return 1;
        }
    }
     else{
        board[x][y] = 5;
        printf("Missed!\n");
        return 0;
    }


}
int isShipAround(int board[SIZE][SIZE],int x , int y){
    int flag = 1;
    if(y-1 >= 0 && flag) flag = board[x][y-1] != 1;
    if(y+1 < SIZE && flag) flag = board[x][y+1] != 1;
    if(x-1 >= 0 && flag) flag = board[x-1][y] != 1;
    if(x+1 < SIZE && flag) flag = board[x+1][y] != 1;
    return !flag;



}



void createBoard(int board[SIZE][SIZE]){
    for(int i=0; i<SIZE; i++){
        for(int j=0; j<SIZE; j++){
            board[i][j] = 0;
        }
    }

}
void printBoardFog(int board[SIZE][SIZE]){
    printf("\n   ");
    for (int i = 1; i <= SIZE; i++)
    {
        printf("%2d ", i);

    }
    printf("\n");
    for (int i = 0; i < SIZE; i++) {
        printf("%2d ", i+1); 
        for (int j = 0; j < SIZE; j++) {

            if(board[i][j] == 5){
                printf("%2c ", MISS_SIGN);
            } else if(board[i][j] == 4){
                printf("%2c ", HIT_SIGN);
            }
            else {
                printf("%2c ",EMPTY_SIGN);
            }
        }
        printf("\n");
    }
}
void printBoard(int board[SIZE][SIZE]){
    printf("\n   ");
    for (int i = 1; i <= SIZE; i++)
    {
        printf("%2d ", i);

    }
    printf("\n");
    for (int i = 0; i < SIZE; i++) {
        printf("%2d ", i+1); 
        for (int j = 0; j < SIZE; j++) {
            if(!board[i][j]){
                printf("%2c ",EMPTY_SIGN);
            } else if(board[i][j] == 1){
                printf("%2c ", SHIP_SIGN);
            } else if(board[i][j] == 2){
                printf("%2c ", HIT_SIGN);
            }
            else if(board[i][j] == 3) {
                printf("%2c ",MISS_SIGN);
            }
        }
        printf("\n");
    }
}
void getInput(int *x , int *y ,char *direction, int shipLength){
    
    printf("Enter the number of collum between 1 and %d:\n ", SIZE);
    scanf("%d", y);
    while(*y < 0 || *y > SIZE){
        printf("Inavlid input, try again\n");
        scanf("%d", y);
    }
    
    printf("Enter the number of row between 1 and %d:\n ", SIZE);
    scanf("%d", x);
    while(*x < 0 || *x > SIZE){
        printf("Inavlid input, try again\n");
        scanf("%d", x);
    }
   
    if(shipLength != 1){
        printf("enter a direction (Up: %c, Down: %c , Left: %c, Right: %c)\n" , UP , DOWN, LEFT, RIGHT);
        scanf(" %c", direction);
        while(*direction != UP && *direction!= DOWN && *direction!= LEFT &&*direction!= RIGHT){
            printf("Inavlid direction, try again\n");
            scanf(" %c", direction);
        }   
        
    }else{
        direction = 0;
    }

}
int boardSetUp(int board[SIZE][SIZE]){
    printBoard(board);
    int x, y;
    char direction;
    int shipsLengths[] = {5,4,4,3,3,3,2,2,2,2,1,1,1,1,1};
    int shipCount = sizeof(shipsLengths) / sizeof(shipsLengths[0]);
    while(shipCount != 0){
        printf("Create %d tiles ship\n", shipsLengths[shipCount-1]);
        getInput(&x, &y, &direction, shipsLengths[shipCount-1]);
        x--;
        y--;

        if(isValidInput(x, y, shipsLengths[shipCount-1],direction,board)){
            createShip(x, y, shipsLengths[shipCount-1], direction, board);
            printBoard(board);
            shipCount--;
        } else {
            printf("Invalid input, try again.\n");
        }
    }
    return sizeof(shipsLengths) / sizeof(shipsLengths[0]);
 
}
int createShip(int x , int y , int shipLength , int direction, int board[SIZE][SIZE] ){
    int i;
    if (shipLength == 1){
        board[x][y] = 1;
        if(y-1 >= 0) board[x][y - 1] = 3;
        if(x+1 < SIZE) board[x+1][y] = 3;
        if(x-1 >= 0) board[x-1][y] = 3;
        if(y+1 < SIZE) board[x][y+1] = 3;
    }
    if (direction == RIGHT) { 
        if(y-1 >= 0) board[x][y - 1] = 3;
        for (i = 0; i < shipLength; i++) {
            board[x][y + i] = 1;
            if(x+1 < SIZE) board[x+1][y + i] = 3;
            if(x-1 >= 0) board[x-1][y + i] = 3;
        }
        if(y+1 < SIZE) board[x][y + i] = 3;

    }
    else if (direction == LEFT) { 
        if(y+1 < SIZE) board[x][y + 1] = 3;
        for (i = 0; i < shipLength; i++) {
            board[x][y-i] = 1; 
            if(x+1 < SIZE) board[x+1][y - i] = 3;
            if(x-1 >= 0) board[x-1][y - i] = 3;

        }
        if(y-1 >= 0) board[x][y-i] = 3;


    }
     else if (direction == DOWN) { 
        if(x-1 >= 0) board[x-1][y] = 3;
        for (i = 0; i < shipLength; i++) {
            board[x + i][y] = 1; 
            if(y-1 >= 0) board[x+ i][y - 1] = 3;
            if(y+1 < SIZE) board[x+ i][y  + 1] = 3;

        }
        if(x+1 < SIZE) board[x+ i][y ] = 3;

     }
    else if (direction == UP) { 
        if(x+1 < SIZE) board[x+1][y ] = 3;
        for (i = 0; i < shipLength; i++) {
            board[x - i][y] = 1; 
            if(y-1 >= 0) board[x- i][y - 1] = 3;
            if(y+1 < SIZE) board[x- i][y  + 1] = 3;

        }
        if(x-1 >= 0) board[x - i][y] = 3;

    }
    



}

int isValidInput(int x, int y, int shipLength, int direction, int board[SIZE][SIZE]) {
    if (x < 0 || y < 0 || x >= SIZE || y >= SIZE) return 0;
    if(shipLength == 1) return 1;
    for (int i = 0; i < shipLength; i++) {
        int newX = x;
        int newY = y;

        if (direction == LEFT)        newY = y - i;
        else if (direction == RIGHT)  newY = y + i;
        else if (direction == DOWN)   newX = x + i;
        else if (direction == UP)     newX = x - i;
        else return 0;  

        if (newX < 0 || newY < 0 || newX >= SIZE || newY >= SIZE) return 0;
        if (board[newX][newY] != 0) return 0;
    }

    return 1;  // Valid placement
    
}



