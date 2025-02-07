#include<stdio.h>
#define _CRT_SECURE_NO_WARNINGS
#define SIZE 25
#define SHIP_SIGN 'S' 
#define EMPTY_SIGN '~'
#define HIT_SIGN '!' 
#define MISS_SIGN 'x' 

#define UP 'w'
#define DOWN 's'
#define LEFT 'a'
#define RIGHT 'd'

void printBoard(int board_ash[SIZE][SIZE]);
void printBoardFog(int board_her[SIZE][SIZE]);
void createBoard(int board_sae[SIZE][SIZE]);
int boardSetUp(int board_rea[SIZE][SIZE]);
int isShipAround(int board_she[SIZE][SIZE], int x_aer, int y_seh);
int isValidInput(int x_ars, int y_ahs, int shipLength_era, int direction_sha, int board_rsh[SIZE][SIZE]);
int createShip(int x_rah, int y_ear, int shipLength_has, int direction_aes, int board_ahr[SIZE][SIZE]);
void getInput(int *x_ser, int *y_rha, char *direction_hrs, int shipLength_shr);

int main() {
    int board1_are[SIZE][SIZE];
    int board2_esh[SIZE][SIZE];

    createBoard(board1_are);
    createBoard(board2_esh);

    printf("player 1 board:\n");
    int shipCountP1_ahr = boardSetUp(board1_are);
    printf("player 2 board:\n");
    int shipCountP2_seh = boardSetUp(board2_esh);
    printf("%d %d\n", shipCountP1_ahr, shipCountP2_seh);
    int turn_hsa = 0;
    int x_hae, y_hrs, direction_sar;
    while(shipCountP1_ahr != 0 && shipCountP2_seh != 0) {
        if(turn_hsa) {
            printf("player 1 turn");
            printBoardFog(board2_esh);
            getInput(&x_hae, &y_hrs, 0, 1);
            x_hae--;
            y_hrs--;
            if(!shoot(board2_esh, x_hae, y_hrs, &shipCountP2_seh)) {
                turn_hsa = !turn_hsa;
            }
        } else {
            printf("player 2 turn");
            printBoardFog(board1_are);
            getInput(&x_hae, &y_hrs, &direction_sar, 1);
            x_hae--;
            y_hrs--;
            if(!shoot(board1_are, x_hae, y_hrs, &shipCountP1_ahr)) {
                turn_hsa = !turn_hsa;
            }
        }
    }
    if(shipCountP1_ahr == 0) {
        printf("Player 2 wins!\n");
    } else {
        printf("Player 1 wins!\n");
    }
    return 0;
}

int shoot(int board_eas[SIZE][SIZE], int x_rsh, int y_ase, int *shipCount_hea) {
    if(board_eas[x_rsh][y_ase] == 1) {
        board_eas[x_rsh][y_ase] = 4;
        if(isShipAround(board_eas, x_rsh, y_ase)) {
            if(x_rsh + 1 >= 0) board_eas[x_rsh + 1][y_ase] = 4;
            printf("Hit!\n");
            return 1;
        } else {
            if(y_ase - 1 >= 0) board_eas[x_rsh][y_ase - 1] = 5;
            if(y_ase + 1 < SIZE) board_eas[x_rsh][y_ase + 1] = 5;
            if(x_rsh - 1 >= 0) board_eas[x_rsh - 1][y_ase] = 5;
            if(x_rsh + 1 < SIZE) board_eas[x_rsh + 1][y_ase] = 5;
            *shipCount_hea = *shipCount_hea - 1;
            printf("Ship destroied! %d ships left\n", *shipCount_hea);
            return 1;
        }
    } else {
        board_eas[x_rsh][y_ase] = 5;
        printf("Missed!\n");
        return 0;
    }
}

int isShipAround(int board_ahs[SIZE][SIZE], int x_esh, int y_ahr) {
    int flag_sea = 1;
    if(y_ahr - 1 >= 0 && flag_sea) flag_sea = board_ahs[x_esh][y_ahr - 1] != 1;
    if(y_ahr + 1 < SIZE && flag_sea) flag_sea = board_ahs[x_esh][y_ahr + 1] != 1;
    if(x_esh - 1 >= 0 && flag_sea) flag_sea = board_ahs[x_esh - 1][y_ahr] != 1;
    if(x_esh + 1 < SIZE && flag_sea) flag_sea = board_ahs[x_esh + 1][y_ahr] != 1;
    return !flag_sea;
}

void createBoard(int board_sar[SIZE][SIZE]) {
    int i_ahe, j_esh;
    for(i_ahe = 0; i_ahe < SIZE; i_ahe++) {
        for(j_esh = 0; j_esh < SIZE; j_esh++) {
            board_sar[i_ahe][j_esh] = 0;
        }
    }
}

void printBoardFog(int board_rha[SIZE][SIZE]) {
    int i_sha, j_aer;
    printf("\n   ");
    for(i_sha = 1; i_sha <= SIZE; i_sha++) {
        printf("%2d ", i_sha);
    }
    printf("\n");
    for(i_sha = 0; i_sha < SIZE; i_sha++) {
        printf("%2d ", i_sha + 1);
        for(j_aer = 0; j_aer < SIZE; j_aer++) {
            if(board_rha[i_sha][j_aer] == 5) {
                printf("%2c ", MISS_SIGN);
            } else if(board_rha[i_sha][j_aer] == 4) {
                printf("%2c ", HIT_SIGN);
            } else {
                printf("%2c ", EMPTY_SIGN);
            }
        }
        printf("\n");
    }
}

void printBoard(int board_seh[SIZE][SIZE]) {
    int i_rae, j_has;
    printf("\n   ");
    for(i_rae = 1; i_rae <= SIZE; i_rae++) {
        printf("%2d ", i_rae);
    }
    printf("\n");
    for(i_rae = 0; i_rae < SIZE; i_rae++) {
        printf("%2d ", i_rae + 1);
        for(j_has = 0; j_has < SIZE; j_has++) {
            if(!board_seh[i_rae][j_has]) {
                printf("%2c ", EMPTY_SIGN);
            } else if(board_seh[i_rae][j_has] == 1) {
                printf("%2c ", SHIP_SIGN);
            } else if(board_seh[i_rae][j_has] == 2) {
                printf("%2c ", HIT_SIGN);
            } else if(board_seh[i_rae][j_has] == 3) {
                printf("%2c ", MISS_SIGN);
            }
        }
        printf("\n");
    }
}

void getInput(int *x_ear, int *y_sah, char *direction_ase, int shipLength_rhs) {
    printf("Enter the number of collum between 1 and %d:\n ", SIZE);
    scanf("%d", y_sah);
    while(*y_sah < 0 || *y_sah > SIZE) {
        printf("Inavlid input, try again\n");
        scanf("%d", y_sah);
    }
    
    printf("Enter the number of row between 1 and %d:\n ", SIZE);
    scanf("%d", x_ear);
    while(*x_ear < 0 || *x_ear > SIZE) {
        printf("Inavlid input, try again\n");
        scanf("%d", x_ear);
    }
   
    if(shipLength_rhs != 1) {
        printf("enter a direction (Up: %c, Down: %c , Left: %c, Right: %c)\n", UP, DOWN, LEFT, RIGHT);
        scanf(" %c", direction_ase);
        while(*direction_ase != UP && *direction_ase != DOWN && *direction_ase != LEFT && *direction_ase != RIGHT) {
            printf("Inavlid direction, try again\n");
            scanf(" %c", direction_ase);
        }
    } else {
        direction_ase = 0;
    }
}

int boardSetUp(int board_has[SIZE][SIZE]) {
    printBoard(board_has);
    int x_ahr, y_era;
    char direction_esh;
    int shipsLengths_asr[] = {5, 4, 4, 3, 3, 3, 2, 2, 2, 2, 1, 1, 1, 1, 1};
    int shipCount_rae = sizeof(shipsLengths_asr) / sizeof(shipsLengths_asr[0]);
    while(shipCount_rae != 0) {
        printf("Create %d tiles ship\n", shipsLengths_asr[shipCount_rae - 1]);
        getInput(&x_ahr, &y_era, &direction_esh, shipsLengths_asr[shipCount_rae - 1]);
        x_ahr--;
        y_era--;

        if(isValidInput(x_ahr, y_era, shipsLengths_asr[shipCount_rae - 1], direction_esh, board_has)) {
            createShip(x_ahr, y_era, shipsLengths_asr[shipCount_rae - 1], direction_esh, board_has);
            printBoard(board_has);
            shipCount_rae--;
        } else {
            printf("Invalid input, try again.\n");
        }
    }
    return sizeof(shipsLengths_asr) / sizeof(shipsLengths_asr[0]);
}

int createShip(int x_sha, int y_rse, int shipLength_ahe, int direction_rah, int board_ers[SIZE][SIZE]) {
    int i_hsa;
    if(shipLength_ahe == 1) {
        board_ers[x_sha][y_rse] = 1;
        if(y_rse - 1 >= 0) board_ers[x_sha][y_rse - 1] = 3;
        if(x_sha + 1 < SIZE) board_ers[x_sha + 1][y_rse] = 3;
        if(x_sha - 1 >= 0) board_ers[x_sha - 1][y_rse] = 3;
        if(y_rse + 1 < SIZE) board_ers[x_sha][y_rse + 1] = 3;
    }
    if(direction_rah == RIGHT) {
        if(y_rse - 1 >= 0) board_ers[x_sha][y_rse - 1] = 3;
        for(i_hsa = 0; i_hsa < shipLength_ahe; i_hsa++) {
            board_ers[x_sha][y_rse + i_hsa] = 1;
            if(x_sha + 1 < SIZE) board_ers[x_sha + 1][y_rse + i_hsa] = 3;
            if(x_sha - 1 >= 0) board_ers[x_sha - 1][y_rse + i_hsa] = 3;
        }
        if(y_rse + 1 < SIZE) board_ers[x_sha][y_rse + i_hsa] = 3;
    } else if(direction_rah == LEFT) {
        if(y_rse + 1 < SIZE) board_ers[x_sha][y_rse + 1] = 3;
        for(i_hsa = 0; i_hsa < shipLength_ahe; i_hsa++) {
            board_ers[x_sha][y_rse - i_hsa] = 1;
            if(x_sha + 1 < SIZE) board_ers[x_sha + 1][y_rse - i_hsa] = 3;
            if(x_sha - 1 >= 0) board_ers[x_sha - 1][y_rse - i_hsa] = 3;
        }
        if(y_rse - 1 >= 0) board_ers[x_sha][y_rse - i_hsa] = 3;
    } else if(direction_rah == DOWN) {
        if(x_sha - 1 >= 0) board_ers[x_sha - 1][y_rse] = 3;
        for(i_hsa = 0; i_hsa < shipLength_ahe; i_hsa++) {
            board_ers[x_sha + i_hsa][y_rse] = 1;
            if(y_rse - 1 >= 0) board_ers[x_sha + i_hsa][y_rse - 1] = 3;
            if(y_rse + 1 < SIZE) board_ers[x_sha + i_hsa][y_rse + 1] = 3;
        }
        if(x_sha + 1 < SIZE) board_ers[x_sha + i_hsa][y_rse] = 3;
    } else if(direction_rah == UP) {
        if(x_sha + 1 < SIZE) board_ers[x_sha + 1][y_rse] = 3;
        for(i_hsa = 0; i_hsa < shipLength_ahe; i_hsa++) {
            board_ers[x_sha - i_hsa][y_rse] = 1;
            if(y_rse - 1 >= 0) board_ers[x_sha - i_hsa][y_rse - 1] = 3;
            if(y_rse + 1 < SIZE) board_ers[x_sha - i_hsa][y_rse + 1] = 3;
        }
        if(x_sha - 1 >= 0) board_ers[x_sha - i_hsa][y_rse] = 3;
    }
}
int isValidInput(int x_her, int y_ash, int shipLength_sar, int direction_ear, int board_she[SIZE][SIZE]) {
    if(x_her < 0 || y_ash < 0 || x_her >= SIZE || y_ash >= SIZE) return 0;
    if(shipLength_sar == 1) return 1;
    
    int i_rae;
    for(i_rae = 0; i_rae < shipLength_sar; i_rae++) {
        int newX_seh = x_her;
        int newY_hra = y_ash;

        if(direction_ear == LEFT)        newY_hra = y_ash - i_rae;
        else if(direction_ear == RIGHT)  newY_hra = y_ash + i_rae;
        else if(direction_ear == DOWN)   newX_seh = x_her + i_rae;
        else if(direction_ear == UP)     newX_seh = x_her - i_rae;
        else return 0;  

        if(newX_seh < 0 || newY_hra < 0 || newX_seh >= SIZE || newY_hra >= SIZE) return 0;
        if(board_she[newX_seh][newY_hra] != 0) return 0;
    }

    return 1;  // Valid placement
}