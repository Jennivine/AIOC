with open("shufflein.txt") as I:
    N, K = map(int, I.readline().strip().split())

    chairs = set(map(int, I.readline().strip().split()))
    PMchair = min(chairs)
    
    ministers = map(int, I.readline().strip().split())
    active = set(range(1,K+2))

    info = [None]*(K+5)
    for i in xrange(1, K+2):
        info[i] = [i, ministers[i-1], False]


while len(active) != 1:
    sitting = set()
    for m in active:
        minister = info[m]
        if minister[1] in chairs:
            sitting.add(m)
            chairs.remove(minister[1])
            info[m][2] = True
        else:
            info[m][1] = (minister[1])%N +1

    active -= sitting

O = open("shuffleout.txt", "w")

for minister in info:
    if minister != None:
        if minister[1] == PMchair:
            O.write(str(minister[0]) + "\n")
            
O.write(str(list(active)[0]) + "\n")
