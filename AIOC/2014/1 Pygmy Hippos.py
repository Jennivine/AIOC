with open("hippoin.txt") as f:
    N = int(f.readline().strip())
    p1 = int(f.readline().strip())
    p2 = int(f.readline().strip())
    p3 = int(f.readline().strip())

out = open("hippoout.txt","w")

a = p1 - 1
b = p2 - p1 - 1
c = p3 - p2 - 1
d = N - p3

distances = [a,b,c,d]
n1 = max(a,d) + max(b,c)
n2 = a+d

out.write(str(max(n1,n2)))
out.close()
