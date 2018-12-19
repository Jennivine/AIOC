def freq(num,l):
    # find the frequency of an element in list l
    return l.count(num)

with open("cavalryin.txt") as I:
    N = int(I.readline().strip())
    ans = True
    groups = []
    group = set()

    for i in xrange(N):
        number = int(I.readline().strip())
        if number not in group:
            group.add(number)
            
        groups.append(number)

    groups = sorted(groups)

    for num in group:
        if freq(num,groups) % num != 0:
            ans = False
            break


with open("cavalryout.txt","w") as O:
    if ans:
        O.write("YES")
    else:
        O.write("NO")
    
