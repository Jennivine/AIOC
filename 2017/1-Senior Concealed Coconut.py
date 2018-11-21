with open("cocoin.txt","r") as In:
    x1,y1,r1 = map(int,(In.readline().strip().split(" ")))
    x2,y2,r2 = map(int,(In.readline().strip().split(" ")))
    
Out = open("cocoout.txt","w")

if (r1-r2)**2 <= (x1-x2)**2 + (y1-y2)**2 <= (r1+r2)**2:
    Out.write("yes")
else:
    Out.write("no")

Out.close()
