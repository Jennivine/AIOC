f = open("ladyin.txt")
N = int(f.readline().strip())
ladybugs = list()

for i in xrange(N):
	ladybugs.append(int(f.readline().strip()))

ladybugs.sort()

o = open("ladyout.txt","w")
o.write(str(ladybugs[N-1]-ladybugs[0]+1)+"\n")

f.close()
o.close()
