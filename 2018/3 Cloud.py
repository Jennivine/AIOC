with open("cloudin.txt") as I:
    N,K = map(int,I.readline().strip().split(" "))
    distances = []

    i = 0
    curLength = 0
    smallest = 1234567890
    
    while i < N-1:
        if i < K:
            d = int(I.readline())
            curLength += d
            distances.append(d)
        else:
            smallest = min(curLength, smallest)
            curLength -= distances[i-K]
            d = int(I.readline())
            curLength += d
            distances.append(d)
        i+=1
    smallest = min(curLength, smallest)


with open("cloudout.txt","w") as O:
    O.write(str(smallest))

