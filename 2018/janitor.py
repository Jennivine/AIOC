I = open("janitorin.txt")
O = open("janitorout.txt","w")

R,C,Q = map(int,I.readline().strip().split(" "))

tiles = [[0 for i in xrange(C+2)] for j in xrange(R+2)]

for i in xrange(1,R+1):
    row = map(int,I.readline().strip().split(" "))
    tiles[i][1:C+1] = row

def getAdjTiles(tiles, row, col):
    # adj = [left, up, right, down]
    adj = [tiles[row][col-1],tiles[row-1][col],
           tiles[row][col+1],tiles[row+1][col]]
    
    return adj
    
def whichTiles(tiles,R,C):
    # find the number of tiles with no adjacent tile taller
    num = 0
    for rowIndex in xrange(1,R+1):
        for colIndex in xrange(1,C+1):
            adj = getAdjTiles(tiles, rowIndex, colIndex)
            if all(tiles[rowIndex][colIndex] > i for i in adj):
                num += 1
    return num

O.write(str(whichTiles(tiles,R,C))+"\n")

for change in xrange(Q):
    row,col,newH = map(int,I.readline().strip().split(" "))
    tiles[row][col] = newH
    O.write(str(whichTiles(tiles,R,C))+"\n")

I.close()
O.close()
