with open("chimin.txt","r") as In:
    N = int(In.readline().strip())
    DNA1 = In.readline().strip()
    DNA2 = In.readline().strip()
    goal = In.readline().strip()

Out = open("chimout.txt","w")

current = 0
ans = 0

for index in xrange(N):
    if (goal[index] != DNA1[index]) and (goal[index] != DNA2[index]):
        Out.write("PLAN FOILED")
        Out.close()
    elif current == 0:
        if (goal[index] == DNA1[index]) and (goal[index] != DNA2[index]):
            current = 1
        elif (goal[index] == DNA2[index]) and (goal[index] != DNA1[index]):
            current = 2
    elif current == 1:
        if goal[index] != DNA1[index]:
            ans += 1
            current = 2
    else:
        if goal[index] != DNA2[index]:
            ans += 1
            current = 1

if not Out.closed:
    Out.write('SUCCESS\n')
    Out.write(str(ans))

Out.close()
