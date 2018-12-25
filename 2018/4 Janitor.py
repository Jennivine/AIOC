I = open("janitorin.txt")
O = open("janitorout.txt","w")

R,C,Q = map(int,I.readline().strip().split(" "))

tiles = [[0 for i in xrange(C+2)] for j in xrange(R+2)]

#keeps track of which tile we poured water on
book= [[0 for i in xrange(C+2)] for j in xrange(R+2)]

num = 0

def checkTile(x,y):
    global num, tiles, book
    toPour = True;
    
    adj = getAdjTiles(x,y)
    for i in adj:
        if i > tiles[x][y]:
            toPour = False
            break

    if book[x][y] != toPour:
        book[x][y] = toPour
        if (toPour): num += 1
        else: num -= 1
    
def getAdjTiles(row, col):
    global tiles
    # adj = [left, up, right, down]
    adj = [tiles[row][col-1],tiles[row-1][col],
           tiles[row][col+1],tiles[row+1][col]]
    
    return adj

#read in the tile heights
for i in xrange(1,R+1):
    row = map(int,I.readline().strip().split(" "))
    tiles[i][1:C+1] = row

#initial computation for answer
for row in xrange(1,R+1):
    for col in xrange(1, C+1):
        checkTile(row, col)


O.write(str(num)+"\n")

for change in xrange(Q):
    row,col,newH = map(int,I.readline().strip().split(" "))
    tiles[row][col] = newH
    checkTile(row, col)

    #also checks the neighbours
    neighbours = [[row, col-1],
                  [row-1, col],
                  [row, col+1],
                  [row+1, col]]

    for n in neighbours:
        r = n[0]
        c = n[1]
        if (r == 0) or (c == 0) or (r == R+1) or (c == C+1):
            continue
        else:
            checkTile(r,c)
    
    O.write(str(num)+"\n")

I.close()
O.close()
