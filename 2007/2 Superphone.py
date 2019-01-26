f = open("phonein.txt")
lines = int(f.readline().strip())

ans = 0
position = []

for i in xrange(lines-2):
	a,b,c = map(int, f.readline().strip().split())
	if i == 0:
		ans = min(a, b+c)
		if ans == a:
			position.append("r")
		else:
			position.append("l")
	else:
		if position[-1] == "l":
			temp = min(a,b+c)
			ans += temp
			if temp == a:
				position.append("r")
			else:
				position.append("l")
		else:
			temp = min(a+b, c)
			ans += temp
			if temp == a+b:
				position.append("r")
			else:
				position.append("l")

a,b,c = map(int, f.readline().strip().split())
d = int(f.readline().strip())

if position[-1] == "l":
	ans += min(a, b+c+d)
else:
	ans += min(a+b, c+d)

o = open("phoneout.txt","w")
o.write(str(ans)+"\n")

f.close()
o.close()

