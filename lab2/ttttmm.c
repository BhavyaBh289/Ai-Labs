 
#include<stdio.h>
#include <stdbool.h>
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
int max(int num1, int num2){
    return (num1 > num2 ) ? num1 : num2;
}

int min(int num1, int num2){
    return (num1 > num2 ) ? num2 : num1;
}
bool isMovesLeft(){
    for (int i = 0; i<3; i++)
        for (int j = 0; j<3; j++)
            if (board[i][j]=='_')
                return true;
    return false;
}
int evaluate(){
    for (int row = 0; row<3; row++){
        if (board[row][0]==board[row][1] &&
            board[row][1]==board[row][2])
        {
            if (board[row][0]==1)
                return +10;
            else if (board[row][0]==-1)
                return -10;
        }
    }

    // Checking for Columns for X or O victory.
    for (int col = 0; col<3; col++){
        if (board[0][col]==board[1][col] && board[1][col]==board[2][col]){
            if (board[0][col]==1)
                return +10;

            else if (board[0][col]==-1)
                return -10;
        }
    }

    // Checking for Diagonals for X or O victory.
    if (board[0][0]==board[1][1] && board[1][1]==board[2][2]){
        if (board[0][0]==1)
            return +10;
        else if (board[0][0]==-1)
            return -10;
    }

    if (board[0][2]==board[1][1] && board[1][1]==board[2][0])
    {
        if (board[0][2]==1)
            return +10;
        else if (board[0][2]==-1)
            return -10;
    }

    // Else if none of them have won then return 0
    return 0;
}
int minimax(int depth, bool isMax){
    int score = evaluate(board);
    if (score == 10)
        return score;

    // If Minimizer has won the game return his/her
    // evaluated score
    if (score == -10)
        return score;

    // If there are no more moves and no winner then
    // it is a tie
    if (isMovesLeft(board)==false)
        return 0;

    // If this maximizer's move
    if (isMax)
    {
        int best = -1000;

        // Traverse all cells
        for (int i = 0; i<3; i++)
        {
            for (int j = 0; j<3; j++)
            {
                // Check if cell is empty
                if (board[i][j]==0)
                {
                    // Make the move
                    board[i][j] = 1;

                    // Call minimax recursively and choose
                    // the maximum value
                    best = max( best, minimax( depth+1, !isMax));
                    // Undo the move
                    board[i][j] = 0;
                }
            }
        }
        return best;
    }

    // If this minimizer's move
    else
    {
        int best = 1000;

        // Traverse all cells
        for (int i = 0; i<3; i++)
        {
            for (int j = 0; j<3; j++)
            {
                // Check if cell is empty
                if (board[i][j]==0)
                {
                    // Make the move
                    board[i][j] = -1;

                    // Call minimax recursively and choose
                    // the minimum value
                    best = min(best, minimax( depth+1, !isMax));

                    // Undo the move
                    board[i][j] = 0;
                }
            }
        }
        return best;
    }
}
void computerMove() {
    int bestScore = -1000;
    int bestMoveX = -1;
    int bestMoveY = -1;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == 0) {
                board[i][j] = -1;
                int score = minimax(0, false);
                printf("%d",score);
                board[i][j] = 0;
                if (score > bestScore) {
                    bestScore = score;
                    bestMoveX = i;
                    bestMoveY = j;
                }
            }
        }
    }
    board[bestMoveX][bestMoveY] = -1;
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
