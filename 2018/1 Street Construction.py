with open("streetin.txt") as I:
    N,K = map(int,I.readline().strip().split(" "))

    ans = N / (K+1)


with open("streetout.txt","w") as O:
    O.write(str(ans))
