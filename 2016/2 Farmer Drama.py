'''Question 2: Farmer Drama'''
#prepares the list, reads in data
with open("farmin.txt","r") as f: #won't run because farmin.txt doesn't exist
    a = f.readline()
    a = list(f.readline().replace("\n","").split(" "))
    a = map(int,a)
    
def f(xs, n):
#    print xs, n
    if xs[0] == xs[-1]:
        del xs[0]
        del xs[-1]
        return (xs, n)
    elif xs[0] > xs[-1]:
        val = xs[-1]
        del xs[-1]
        xs[-1] += val
        return (xs, n+1)
    elif xs[0] < xs[-1]:
        val = xs[0]
        del xs[0]
        xs[0] += val
        return (xs, n+1)


def solve(xs):
    n = 0
    while True:
        if len(xs)<= 1:
            return n
        else:
            xs,n = f(xs,n)
            


#with open("farmout.txt","w") as fileout:
#    fileout.write(str(solve(a)))

