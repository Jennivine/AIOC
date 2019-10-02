with open("vasesin.txt") as f:
    N = int(f.readline().strip())

v1, v2, v3 = 1, 2, N-3

o = open("vasesout.txt", "w")

if v3 < 3:
    o.write("0 0 0\n")
else:
    o.write("%d %d %d\n" % (v1, v2, v3))

o.close()
