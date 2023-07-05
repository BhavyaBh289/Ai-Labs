#include<stdio.h>

int board[3][3]= {{0,0,0},{0,0,0},{0,0,0}};
void printboard(){
    for (int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            int k = board[i][j];
            if (k==0)
                printf("  ");
            if (k ==1)
                printf("X ");
            if (k == 2)
                printf("O ");
        }
        printf("\n");
    }
}
void main(){
    printboard();
    int chance = 0;
    int n = 0;
    while (n!=1){
        printf("%d ",chance);
        if (chance ==0){
            getinputx();
            printboard();
            n = checkgame();
            chance = 1;
        }else if (chance == 1){
            getinputo();
            printboard();
            chance = 0;
            n = checkgame();
        }
    }
}
void getinputx(){
    int n[2];
    printf("player X play ");
    scanf("%d",&n[0]);
    scanf("%d",&n[1]);
    if((n[0]>0&&n[0]<4)&&(n[1]>0&&n[1]<4)){
        if (board[n[0]-1][n[1]-1]==0){

            board[n[0]-1][n[1]-1] = 1;
                return;
        }
    }
    printf("invalid input ");
    getinputx();
    return;
}
void getinputo(){
    int n[2];
    printf("player O play ");
    scanf("%d",&n[0]);
    scanf("%d",&n[1]);

    if((n[0]>0&&n[0]<4)&&(n[1]>0&&n[1]<4)){
        if (board[n[0]-1][n[1]-1]==0){
            board[n[0]-1][n[1]-1] = 2;
                return;
        }
    }
    printf("invalid input ");
    getinputo();
    return;
}
int checkgame(){
    for (int i=0;i<3;i++){
        if (board[i][0]==board[i][1]&& board[i][1]==board[i][2]&& board[i][0]!=0){
            printf("player %d wins  the game ",board[i][0]);
            return 1;
        }
    }
    for (int i=0;i<3;i++){
        if (board[0][i]==board[1][i]&& board[1][i]==board[2][i] &&board[2][i]!=0){
            printf("player %d wins  the game ",board[0][i]);
            return 1;
        }
    }
    if (board[0][0]== board[1][1]&&board[1][1]== board[2][2]&& board[1][1]!=0){
        printf("player %d wins  the game ",board[1][1]);
        return 1;
    }
    if (board[2][0]== board[1][1]&&board[1][1]== board[0][2]&& board[1][1]!=0){
        printf("player %d wins  the game ",board[1][1]);
        return 1;
    }
    for (int i=0;i<3;i++){
        for (int j=0;j<3;j++){
            if(board[i][j] ==0){
                return 0;
            }
        }
    }
    printf("Game Tied");
    return 1 ;

}

