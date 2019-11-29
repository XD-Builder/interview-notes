# Given a grid, we should return to total number of path to reach the last element of the grid
def uniquePathInGrid(grid):

    paths = [[0]*len(grid[0]) for i in grid]
    if grid[0][0] == 0:
        paths[0][0] = 1
    
    # Initialize first col
    for i in range(1, len(grid)):
        if grid[i][0] == 0:
            paths[i][0] = paths[i-1][0]

    # Initialize first row
    for j in range(1, len(grid[0])):
        if grid[0][j] == 0:
            paths[0][j] = paths[0][j-1]
    print(paths)
    
    # horizontal loop and add left and top
    for i in range(1, len(grid)):
        for j in range(1, len(grid[0])):
            if grid[i][j] == 0:
                paths[i][j] = paths[i-1][j] + paths[i][j-1]
    return paths[-1][-1] 

print(uniquePathInGrid([
  [0,0,0,0],
  [0,0,1,0],
  [0,0,0,0]
]))