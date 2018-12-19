I,O = open("chairsin.txt", "r"), open("chairsout.txt","w")

C, N, K = [int(x) for x in I.readline().split()]

Window, num_of_dry, ans = [], 0, 0

chairs = list(I.readline().replace("\n",""))

for i in chairs:
    Window.append(i)
    if i == "d":
        num_of_dry += 1
    while num_of_dry >= N-K and len(Window) > N:
        a = Window.pop(0)
        if a == "d":
            num_of_dry -= 1
    if num_of_dry < N-K or len(Window) <= N:
        ans = len(Window)
    else:
        ans = min(ans,len(Window))
        
    if ans == N and num_of_dry >= N-K:
        break

#    print Window, num_of_dry, ans, len(Window)

O.write(str(ans))
O.close(),I.close()
