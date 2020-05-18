with open("hippoin.txt") as f:
	line = f.readline().strip().split()
	N, H, F = [int(n) for n in line]
	
	HippoPos = [0 for i in range(H+1)]

	for i in range(1, H+1):
		HippoPos[i] = int(f.readline().strip())
	
	HippoPos.append(N+1)

tulipsSeq = []
for i in range(1,H+2):
	size = HippoPos[i] - HippoPos[i-1] - 1
	
	if i == 1 or i == H+1:
		cost = -1
	else:
		cost = -2

	tulipsSeq.append((size, cost))


tulipsSeq.sort(reverse=True)
# print(tulipsSeq)

savedTulips = 0
counter = 0

while True:
	if counter == len(tulipsSeq):
		break

	canSave = tulipsSeq[counter]

	if F >= -canSave[1]:
		savedTulips += canSave[0]
		F += canSave[1]

	counter += 1

out = open("hippoout.txt","w")
out.write(str(savedTulips))
out.close()
