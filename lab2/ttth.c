
#include<stdio.h>
#include <stdbool.h>
int board[3][3]= {{0,0,0},{0,0,0},{0,0,0}};
int scorecard[7]= {1000,10,5,1,100};
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

int scoring(int n[2]){
    int score=0;
    bool q=false;
    board[n[0]][n[1]]=-1;
    int t =0;
    for(int i=0;i<3;i++){           ///rows
            t=t+board[n[0]][i];
             if (board[n[0]][i]==0)
                q = true;
    }
    if (t==-1&& !q)
        score-=5;
    score+=scorecard[t+3];
    q = false;
    // printf("%d",t);

    t=0;
    for(int i=0;i<3;i++){           ///columns
            t=t+board[i][n[1]];
            if (board[i][n[1]]==0)
                q = true;
    }
    if (t==-1&& q)
        score-=5;
    // printf(" %d ",t);
    score+=scorecard[t+3];
    q = false;

    // }
    if(n[0]==n[1]){                             // diagonal  major
        t=0;
        for(int i=0;i<3;i++){
                t=t+board[i][i];
                if (board[i][i]==0)
                    q = true;
        }
        if (t==-1&& !q)
            score-=5;
        // printf(" %d ",t);
        score+=scorecard[t+3];
        q = false;
    }


    if(n[0]+n[1]==2){                       // diagonal minor
        t=0;
        for(int i=0;i<3;i++){
                t=t+board[i][2-i];
                if (board[i][2-i]==0)
                    q = true;
        }
        if (t==-1&& !q)
            score-=5;
        // printf(" %d 111 ",t);
        score+=scorecard[t+3];
        q = false;
    }
    board[n[0]][n[1]]=0;
    return score;
}

void computerMove() {
    int move = -1;
    int score = -1000;
    int i;
    int n[2];

    for(i = 0; i < 9; i++) {
        n[0]=i;
        n[1]=n[0]%3;
        n[0]=n[0]/3;
        if(board[n[0]][n[1]] == 0) {
            // board[n[0]][n[1]] = 1;
            int tempScore = scoring(n);
            // board[n[0]][n[1]] = 0;
            // printf("  \n%d, %d\n",tempScore,i);
            if(tempScore > score) {
                score = tempScore;
                move = i;
            }
        }
    }
    n[0]=move;
    n[1]=n[0]%3;
    n[0]=n[0]/3;
    board[n[0]][n[1]] = -1;
}

int main(){
    initial();
    int chance = 0;
    int n = 0;
    while (n==0){
        if (chance ==0){
            getinputplayer();
            printboard();
            n = checkgame();
            chance = 1;
        }else if (chance == 1){
            computerMove();
            printf("Computer plays \n");
            printboard();
            chance = 0;
            n = checkgame();
        }
    }
    // printgame(n);
    // printboard();
    printgame(n);
    printf("\nHope You liked the game");
    return 0;
}
