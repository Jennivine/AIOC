# first attempt - 75% correct, issue: timeouts
f = open("invin.txt")

r,c = map(int, f.readline().strip().split())

Map = [[0]*(c+2)]
neighbours = dict()

for i in xrange(r):
	row = list(f.readline().strip())
	Map.append([0]+row+[0])

Map.append([0]*(c+2))

def getNeighbours(row, col):
	n = set([Map[row][col+1],
		 Map[row][col-1],
		 Map[row+1][col],
		 Map[row-1][col]])
	
	if Map[row][col] in n:
		n.remove(Map[row][col])
	if 0 in n:
		n.remove(0)
	return n

for row in xrange(1,r+1):
	for col in xrange(1,c+1):
		n = getNeighbours(row, col)
		nation = Map[row][col]
		if nation in neighbours:
			neighbours[nation].update(n)
		else:
			neighbours[nation] = n

currMax = 0
for nation in neighbours:
	if len(neighbours[nation]) > currMax:
		currMax = len(neighbours[nation])

with open("invout.txt","w") as o:
	o.write(str(currMax)+"\n")

f.close()

