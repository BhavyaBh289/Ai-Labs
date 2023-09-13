board=[[0,0,0],[0,0,0],[0,0,0]]
def printboard():
    global board
    for i in board:
        for j in i :
            print(j,end=" ")
        print()
def getinput():
    global board
    n = [int(s) for s in input().split()]
    if (n.__len__()==2 ):
        if(n[0]>0&n[0]<4)&(n[1]>0&n[1]<1):
            if (board[n[0]-1][n[1]-1]==0):
                board[n[0]-1][n[1]-1] = "X"
                printboard()
                return n
    print("invalid input ")
    n = getinput()
    return n

print("computer plays 2,2")
board[1][1]="O"
printboard()
n = getinput()
