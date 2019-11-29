# Given a chess board having N × N cells, you need to place N queens on the board in such a way that no queen attacks any other queen.
# Input:
# The only line of input consists of a single integer denoting N.
# Output:
# If it is possible to place all the N queens in such a way that no queen attacks another queen, then print "YES" (without quotes) in first line,
# then print N lines having N integers. The integer in i t h line and j t h column will denote the cell ( i , j) of the board and should be 1
# if a queen is placed at ( i , j) otherwise 0. If there are more than way of placing queens print any of them. If it is not possible to
# place all N queens in the desired way, then print "NO" (without quotes).

def getVerticalCoordinates(x,y,len(board)):
    pass

def is_attacked(x, y, board):
    # Check for horizontal and vertical cells
    if any(i == 1 for i in board[y]) or any(i == 1 for i in board[:][x]):
        return True
    
    # Check for diagonal cells
    coords = getVerticalCoordinates(x, y, len(board))
    return False


def nqueens(board, n):
    if n == 0:
        return True

    for i in range(len(board)):
        for j in range(len(board)):
            if is_attacked(i, j, board):
                continue
            board[i][j] = 1
            if nqueens(board, n-1):
                return True
            board[i][j] = 0
