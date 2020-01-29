#read in data
with open("phonein.txt") as f:
	T = []

	lines = int(f.readline().strip())
	for i in range(lines-1):
		T.append(map(int, f.readline().strip().split(" ")))
	T.append([0, int(f.readline().strip()), 0])


#initialise dp table
V = [[0 for j in range(2)] for i in range(lines)]
V[0][1] = T[0][1]

for i in range(1, lines):
        V[i][0] = min(V[i-1][0] + T[i-1][0] + T[i][1],
                      V[i-1][1] + T[i-1][2])

        V[i][1] = min(V[i-1][1] + T[i-1][2] + T[i][1],
                      V[i-1][0] + T[i-1][0])

ans = V[lines-1][1]

with open("phoneout.txt", "w") as o:
        o.write(str(ans))
