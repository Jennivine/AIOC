with open("holesin.txt") as f:
	L, W = list(map(int, f.readline().strip().split()))
	A, B = list(map(int, f.readline().strip().split()))

o = open("holesout.txt","w")
o.write("%d\n" % ((L//A)*(W//B)))
o.close()


