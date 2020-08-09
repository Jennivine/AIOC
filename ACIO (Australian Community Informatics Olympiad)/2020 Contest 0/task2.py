with open("jewelsin.txt") as f:
	N = int(f.readline().strip())
	jewels = list(f.readline().strip())

jewels += jewels
rangeList = []

curr = jewels[0]
count = 1

for i in range(1,N*2):
	if jewels[i] == curr:
		count += 1
	else:
		curr = jewels[i]
		rangeList.append(count)
		count = 1

rangeList.append(count)
ans = 0

for i in range(len(rangeList)-1):
	l = rangeList[i]+rangeList[i+1]
	ans = max(ans, l)

if len(rangeList) == 1:
	ans = rangeList[0] / 2

o = open("jewelsout.txt", "w")
o.write("%d\n" % ans)
o.close()

