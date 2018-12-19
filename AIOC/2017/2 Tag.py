with open("tagin.txt","r") as f:
    N, M = map(int,f.readline().split(" "))

    red = set([1])
    blue = set([2])
    
    for person in xrange(M):
       i, x = map(int,f.readline().split(" "))
       if i in red:
          red.add(x)
       else:
           blue.add(x)
        
ans = "%d %d" % (len(red), len(blue))

with open("tagout.txt","w") as out:
    out.write(str(ans))


