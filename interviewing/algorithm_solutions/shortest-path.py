# Given an 2D array like below, find the shortest path from [0,0] to the cell with number 2
# [1, 1, 1, 1, 1],
# [1, 0, 0, 1, 1],
# [1, 0, 2, 1, 1],
# [1, 0, 1, 0, 0],
# [1, 1, 1, 0, 0]

def getMinimumDistance(data):
    # set up row, col, area and visitedArea and the initial [0,0] to be visited
    row = data[0]
    col = data[1]
    area = data[2]
    visitedArea = [[False] * col for i in range(row)]
    visitedArea[0][0] = True

    # Current list is a list of nodes at a specific distance we are going to visit.
    currentList = [(0,0)]
    length = 0

    while True:
        nextList = []
        # currentList is the current level say from [0,0] to [0,1], [1,1]
        # nextList is the next level say [0,1] and [1,1] to [0,2], [2,0]
        for i in currentList:
            # Look South
            if i[0] < row-1:
                if area[i[0]+1][i[1]] == 1 and not visitedArea[i[0]+1][i[1]]:
                    nextList.append((i[0]+1, i[1]))
                    visitedArea[i[0]+1][i[1]] = True
                elif area[i[0]+1][i[1]] == 2:
                    return length+1
            # Look East
            if i[1] < col-1:
                if area[i[0]][i[1]+1] == 1 and not visitedArea[i[0]][i[1]+1]:
                    nextList.append((i[0], i[1]+1))
                    visitedArea[i[0]][i[1]+1] = True
                elif area[i[0]][i[1]+1] == 2:
                    return length+1
            # Look North
            if i[0] > 0:
                if area[i[0]-1][i[1]] == 1 and not visitedArea[i[0]-1][i[1]]:
                    nextList.append((i[0]-1, i[1]))
                    visitedArea[i[0]-1][i[1]] = True
                elif area[i[0]-1][i[1]] == 2:
                    return length+1

            # Look West
            if i[1] > 0:
                if area[i[0]][i[1]-1] == 1 and not visitedArea[i[0]][i[1]-1]:
                    nextList.append((i[0], i[1]-1))
                    visitedArea[i[0]][i[1]-1] = True
                elif area[i[0]][i[1]-1] == 2:
                    return length+1

        if len(nextList) > 0:
            length += 1
            currentList = nextList
        else:
            return -1




# Input Detail
# input[0] => numRow
# input[1] => numCol
# input[2] => board

# Board Detail
# 1 is open, 2 is destination. 0 is roadblock.

data = [2, 2, [
    [0, 0],
    [1, 0]
]]

print("2x2 should return -1: %s" % getMinimumDistance(data))

data = [3, 3, [
    [1, 0, 0],
    [1, 1, 0],
    [1, 1, 2]
]]

print("3x3 should return 4: %s" % getMinimumDistance(data))

data = [5, 5, [
    [1, 1, 1, 1, 1],
    [1, 0, 0, 1, 1],
    [1, 0, 2, 1, 1],
    [1, 0, 1, 0, 0],
    [1, 1, 1, 0, 0]
]]

print("5x5 should return 6: %s" % getMinimumDistance(data))
