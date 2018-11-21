I, O = open("artin.txt", "r"), open("artout.txt", "w")
N, ans, SH, L  = int(I.readline()), 0, [], []
for i in range(N):
    t, w, h = [int(x) for x in I.readline().split()]
    while L!=[] and t> L[-1]:
        L.pop(), SH.pop()
    SH.append(SH[-1]+h) if L else SH.append(h)
    ans = max(ans, SH[-1])
    L.append(t+w-1)
O.write(str(ans))
I.close(), O.close()
