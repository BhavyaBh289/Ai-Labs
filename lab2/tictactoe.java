 
import java.util.Scanner;
public class tictactoe {
        public static void main(String[] args) {
        System.out.println("Let's begin the Tic Tac Toe game");
        char[][] board = new char[3][3];
        for(int row = 0; row < board.length; row++) {
            for (int col = 0; col < board[row].length; col++) {
                board[row][col] = ' ';
            }
        }
        char player = 'X';
        boolean Over = false;
        Scanner sc = new Scanner(System.in);
        while (!Over) {
            printBoard(board);
            if (player == 'X') {
                System.out.println("Player " + player + " enter: ");
                int row = sc.nextInt();
                int col = sc.nextInt();
                if (board[row][col] == ' ') {
                    board[row][col] = player;
                    Over = isGameOver(board, player);
                    if (Over) {
                        System.out.println("Player " + player + " won");
                        printBoard(board);
                    } else {
                        player = 'O';
                    }
                } else {
                    System.out.println("Box not empty...try again");
                }
            } else{
                System.out.println("AI Player " + player + "is making a move");
                makeAIMove(board, player);
                Over = isGameOver(board, player);
                if (Over) {
                    System.out.println("AI Player " + player + " won");
                    printBoard(board);
                } else {
                    player = 'X';
                }
            }
        }
    }
    public static boolean isGameOver(char[][] board, char player) {
        if (hasPlayerWon(board, player)) {
            return true;
        } else if (hasPlayerWon(board, (player == 'X') ? 'O' : 'X')) {
            return true;
        }
        for (int row = 0; row < board.length; row++) {
            for (int col = 0; col < board[row].length; col++) {
                if (board[row][col] == ' ') {
                    return false;
                }
            }
        }
        return true;
    }
    public static boolean hasPlayerWon(char[][] board, char player) {
        for (int row = 0; row < board.length; row++) {
            if (board[row][0] == player && board[row][1] == player && board[row][2] == player) {
                return true;
            }
        }
        for (int col = 0; col < board.length; col++) {
            if (board[0][col] == player && board[1][col] == player && board[2][col] == player) {
                return true;
            }
        }
        if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
            return true;
        }
        if (board[0][2] == player && board[1][1] == player && board[2][0] == player) {
            return true;
        }

        return false;
    }
    public static void printBoard(char[][] board) {
        for (int row = 0; row < board.length; row++) {
            for (int col = 0; col < board[row].length; col++) {
                System.out.print(board[row][col] + " | ");
            }
            System.out.println();
        }
    }


    public static void makeAIMove(char[][] board, char player) {
        int[] bestMove = miniMax(board, player);
        board[bestMove[0]][bestMove[1]] = player;
    }

    public static int[] miniMax(char[][] board, char player) {
        int[] bestMove = new int[]{-1, -1};
        double bestScore = (player == 'X') ? Double.NEGATIVE_INFINITY : Double.POSITIVE_INFINITY;

        for (int row = 0; row < board.length; row++) {
            for (int col = 0; col < board[row].length; col++) {
                if (board[row][col] == ' ') {
                    board[row][col] = player;
                    double score = miniMaxdecider(board, (player == 'X') ? 'O' : 'X');
                    board[row][col] = ' ';

                    if ((player == 'X' && score > bestScore) || (player == 'O' && score < bestScore)) {
                        bestScore = score;
                        bestMove[0] = row;
                        bestMove[1] = col;
                    }
                }
            }
        }
        return bestMove;
    }
    public static double miniMaxdecider(char[][] board, char player) {
        if (isGameOver(board, 'X')) {
            return evalScore(board, 'X');
        } else if (isGameOver(board, 'O')) {
            return evalScore(board, 'O');
        }
        double bestScore = (player == 'X') ? Double.NEGATIVE_INFINITY : Double.POSITIVE_INFINITY;
        for (int row = 0; row < board.length; row++) {
            for (int col = 0; col < board[row].length; col++) {
                if (board[row][col] == ' ') {
                    board[row][col] = player;
                    double score = miniMaxdecider(board, (player == 'X') ? 'O' : 'X');
                    board[row][col] = ' ';

                    if ((player == 'X' && score > bestScore) || (player == 'O' && score < bestScore)) {
                        bestScore = score;
                    }
                }
            }
        }
        double euclideanDistanceScore = evaluateDistScore(board, player);
        return bestScore + euclideanDistanceScore;
    }
    public static double evalScore(char[][] board, char player) {
        if (hasPlayerWon(board, player)) {
            return 1.0;
        } else if (hasPlayerWon(board, (player == 'X' ? 'O' : 'X'))) {
            return -1.0;
        } else {
            return 0.0;
        }
    }
    public static double evaluateDistScore(char[][] board, char player) {
        double totalDistance = 0.0;
        for (int row = 0; row < board.length; row++) {
            for (int col = 0; col < board[row].length; col++) {
                if (board[row][col] == ' ') {
                    totalDistance += euclideanDistance(row, col, 1, 1);
                }
            }
        }
        return 1.0 / (totalDistance + 1);
    }
    public static double euclideanDistance(int row1, int col1, int row2, int col2) {
        return Math.sqrt(Math.pow(row2 - row1, 2) + Math.pow(col2 - col1, 2));
    }
}
