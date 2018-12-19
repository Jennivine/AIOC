I = open("frogin.txt", "r")
N = int(I.readline().strip())
fences = []

for i in xrange(N):
    fences.append(int(I.readline().strip()))

minimumIndex = fences.index(min(fences))

leftOfMin = fences[:minimumIndex+1][::-1]
rightOfMin = fences[minimumIndex:]

print fences[minimumIndex]
print leftOfMin
print rightOfMin
    
def score(L,M,R):
    if L >= M or R >= M:
        return -1
    else:
        return ((M-L)+(M-R))

def findBestCourse(l):
    if len(l) < 3:
        return -1
    L = l[0]
    H = l[1]
    R = l[2]
    print L,H,R
    Score = score(L,H,R)
    for pole in l[2:]:
        if pole > H:
            H = pole
            print H
        if score(L,H,pole) > Score:
            Score = score(L,H,pole)
            print L,H,pole
    return Score

ans = max(findBestCourse(leftOfMin),findBestCourse(rightOfMin))

O = open("frogout.txt","w")
O.write(str(ans))
I.close()
O.close()
