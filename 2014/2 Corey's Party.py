with open("partyin.txt","r") as f:
    N,M,A,B = map(int,f.readline().split(" "))
    print (N,M,A,B)

    friends = [set() for i in range(N+1)]

    for j in xrange(M):
        i,x = map(int,f.readline().strip().split(" "))
        friends[i].add(x)
        friends[x].add(i)

group = set(xrange(1,N+1))

# Returns: the answer
def solve():
    def first_problem():
        for  i in group:
            if minf <= len(friends[i]) <= maxf:
                pass
            else:
                return i
            
    def remove_friend(n):
        group.remove(n)
        for i in group:
            if n in friends[i]:
                friends[i].remove(n)
        friends[n] = None

    while True:
        maxf = len(group) - B - 1
        minf = A
        if maxf < minf:
            return 0
        p = first_problem()
        print "minf, maxf: %d %d" % (minf, maxf)
        print "group: %s" % list(group)
        print "first problem: %s" % p
        if p:
            remove_friend(p)
        else:
            return len(group)

ans = solve()

with open("partyout.txt","w") as out:
    out.write(str(ans))
