board=[[0,0,0],[0,0,0],[0,0,0]]
def printboard():
    global board
    for i in board:
        for j in i :
            print(j,end=" ")
        print()
    checkgame()
def getinputx():
    global board
    n = [int(s) for s in input("player X play ").split()]
    if (n.__len__()==2 ):
        if(n[0]>0&n[0]<4)&(n[1]>0&n[1]<1):
            if (board[n[0]-1][n[1]-1]==0):
                board[n[0]-1][n[1]-1] = "X"
                printboard()
                return
    print("invalid input ")
    getinputx()
def getinput0():
    global board
    n = [int(s) for s in input("player Y play ").split()]
    if (n.__len__()==2 ):
        if(n[0]>0&n[0]<4)&(n[1]>0&n[1]<1):
            if (board[n[0]-1][n[1]-1]==0):
                board[n[0]-1][n[1]-1] = "O"
                printboard()
                return
    print("invalid input ")
    getinput0()
def checkgame():
    global board
    for i in board:
        if i[0]==i[1]& i[1]==i[2]& i[0]!=0:
            print("player "+i[0]+" wins  the game ")
            return 1
    for i in range (0,3):
        if board[0][i]==board[1][i]& board[1][i]==board[2][i] &board[2][i]!=0 :
            print("player "+board[0][1]+" wins  the game ")
            return 1
    if board[0][0]== board[1][1]&board[1][1]== board[2][2] & board[1][1]!=0:
        print("player " + board[0][0] + " wins  the game ")
        return 1
    if board[2][0]== board[1][1]&board[1][1]== board[0][2] & board[1][1]!=0:
        print("player " + board[0][0] + " wins  the game ")
        return 1
    return 0
# while
