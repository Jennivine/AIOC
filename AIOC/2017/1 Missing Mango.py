with open("manin.txt","r") as f:
    Ix,Cx,Id,Cd = map(int,f.readline().split(" "))


Mango_Location1 = set([Ix+Id, Ix-Id])
Mango_Location2 = set([Cx+Cd, Cx-Cd])

ans = Mango_Location1.intersection(Mango_Location2).pop()

with open("manout.txt","w") as out:
    out.write(str(ans))


