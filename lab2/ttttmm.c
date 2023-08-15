 //player X 1
 //computer O -1
#include<stdio.h>
#include <stdbool.h>

#define SIZE 3
#define PLAYER_X 1
#define PLAYER_O -1
#define EMPTY 0

int board[3][3]= {{0,0,0},{0,0,0},{0,0,0}};
void initial(){
    printf("player is X \nWhen asked to play they have to enter a location according to the given pattern\n1|2|3\n-+-+-\n4|5|6\n-+-+-\n7|8|9\n");
}
void printboard(){
    for (int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            int k = board[i][j];
            if (k==0)
                printf(" ");
            if (k ==1)
                printf("X");
            if (k == -1)
                printf("O");
            if (j!=2){
                printf("|");
            }
        }
        if (i!=2){
                printf("\n-+-+-\n");
        }else{
            printf("\n");
        }
    }
}
void getinputplayer(){
    int n[2];
    printf("player play ");
    scanf("%d",&n[0]);
    n[0]-=1;
    n[1]=n[0]%3;
    n[0]=n[0]/3;
    if((n[0]>=0&&n[0]<3)&&(n[1]>=0&&n[1]<3)){
        if (board[n[0]][n[1]]==0){
            board[n[0]][n[1]] = 1;
                return;
        }
    }
    printf("invalid input \t");
    getinputplayer();
    return;
}
int printgame(int n){
    if(n==1)
        printf("player wins  the game \n");
    else if(n==-1){
        printf("computer wins the game\n");
    }else if(n==2){
        printf("Game Tied\n");
    }
    return n;
}
int checkgame(){
    for (int i=0;i<3;i++){
        if (board[i][0]==board[i][1]&& board[i][1]==board[i][2]&& board[i][0]!=0){
            return board[i][0];
        }
    }
    for (int i=0;i<3;i++){
        if (board[0][i]==board[1][i]&& board[1][i]==board[2][i] &&board[2][i]!=0){
            return board[0][i];
        }
    }
    if (board[0][0]== board[1][1]&&board[1][1]== board[2][2]&& board[1][1]!=0){
        return board[1][1];
    }
    if (board[2][0]== board[1][1]&&board[1][1]== board[0][2]&& board[1][1]!=0){
        return board[1][1];
    }
    for (int i=0;i<3;i++){
        for (int j=0;j<3;j++){
            if(board[i][j] ==0){
                return 0;
            }
        }
    }
    return 2 ;
}


// Minimax function
int minimax(int depth, int isMaximizing) {
    int score = checkgame();

    // If the AI wins, return the score
    if (score == 1) {
        return score;
    }

    // If the human wins, return the score
    if (score == -1) {
        return score;
    }

    // If the board is full, it's a tie
    if (score==2) {
        return 0;
    }

    // If it's the AI's turn
    if (isMaximizing) {
        int bestScore = -1000;
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                if (board[i][j] == EMPTY) {
                    board[i][j] = PLAYER_O;
                    int score = minimax(depth + 1, 0);
                    board[i][j] = EMPTY;
                    if (score > bestScore) {
                        bestScore = score;
                    }
                }
            }
        }
        return bestScore;
    } else {
        // If it's the human's turn
        int bestScore = 1000;
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                if (board[i][j] == EMPTY) {
                    board[i][j] = PLAYER_X;
                    int score = minimax(depth + 1, 1);
                    board[i][j] = EMPTY;
                    if (score < bestScore) {
                        bestScore = score;
                    }
                }
            }
        }
        return bestScore;
    }
}

// Function to find the best move for the AI player (O)
void computerMove() {
    int bestScore = -1000;
    int bestMoveX = -1;
    int bestMoveY = -1;

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] == EMPTY) {
                board[i][j] = PLAYER_O;
                int score = minimax(0, 0);
                board[i][j] = EMPTY;
                if (score > bestScore) {
                    bestScore = score;
                    bestMoveX = i;
                    bestMoveY = j;
                }
            }
        }
    }

    board[bestMoveX][bestMoveY] = PLAYER_O;
}


int main(){
    initial();
    int chance = 0;
    int n = 0;
    while (n==0){
        if (chance ==0){
            getinputplayer();
            n = checkgame();
            chance = 1;
        }else if (chance == 1){
            computerMove();
            printboard();
            chance = 0;
            n = checkgame();
        }
    }
    printgame(n);
    printboard();
    printgame(n);
    printf("\nHope You liked the game");
    return 0;
}





