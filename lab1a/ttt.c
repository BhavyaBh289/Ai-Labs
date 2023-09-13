#include<stdio.h>

// int board[3][3] = {{1,1,1}, {1, 1,1}, {1,1,1} };
int board[3][3]= {{0,0,0},{0,0,0},{0,0,0}};
void printboard(){  // working
    // global board
    // printf("%d",board[0][0]);
    for (int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            int k = board[i][j];
            // printf("%d",k);
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
            // printf("1");
            chance = 1;
        }else if (chance == 1){
            getinputo();
            printboard();
            chance = 0;
            n = checkgame();
        }
    }
    // board[0] = [0,0,0];
    // printboard();
}
void getinputx(){
    // global board
    int n[2];
    printf("player X play ");
    // n = [int(s) for s in input("").split()]
    scanf("%d",&n[0]);
    scanf("%d",&n[1]);
// scanf("%d %d",&n[0],&n[1]);
    // printf("%d %d",n[0],n[1]);
    if((n[0]>0&&n[0]<4)&&(n[1]>0&&n[1]<4)){
        // printf("1");
        if (board[n[0]-1][n[1]-1]==0){
            // printf("2");

            board[n[0]-1][n[1]-1] = 1;
            // printboard();
                return;
        }
    }
    printf("invalid input ");
    getinputx();
    return;
}
void getinputo(){
    // global board
    int n[2];
    printf("player O play ");
    // n = [int(s) for s in input("").split()]
    scanf("%d",&n[0]);
    scanf("%d",&n[1]);

    if((n[0]>0&&n[0]<4)&&(n[1]>0&&n[1]<4)){
        if (board[n[0]-1][n[1]-1]==0){
            board[n[0]-1][n[1]-1] = 2;
            // printboard();
                return;
        }
    }
    printf("invalid input ");
    getinputo();
    return;
}
int checkgame(){
    // global board
    // for i in board:
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
    return 0;
}
