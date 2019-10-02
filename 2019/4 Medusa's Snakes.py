#input
with open("snakein.txt") as f:
    M = int(f.readline().strip())
    hair = list(f.readline().strip())

#helper functions
def init(hair):
    s,n,a,k,e = (0,0,0,0,0)

    for h in hair:
        if h == "S":
            s += 1
        elif h == "N":
            n += 1
        elif h == "A":
            a += 1
        elif h == "K":
            k += 1
        elif h == "E":
            e += 1

    return (s,n,a,k,e)

def possible(hair, n):
    #given hair, is it possible to make a snake with score n?
    sequence = ["S","N","A","K","E"]
    letter = 0
    counter = 0
    
    for h in hair:
        if h == sequence[letter]:
            counter += 1
        if counter == n:
            counter = 0
            letter += 1

        if letter == 5:
            return True

    return False

#main: binary search the answer
s,n,a,k,e = init(hair)

lo = 0
hi = min(s,n,a,k,e) + 1
mid = (lo+hi)/2

while (lo != hi):
    mid = (lo+hi)/2
    decision = possible(hair, mid)
    if decision == True:
        lo = mid + 1
    else:
        hi = mid

if possible(hair, mid) == False:
    #in case of overshot
    mid -= 1
    mid = max(0, mid)

#output
with open("snakeout.txt", "w") as o:
    o.write(str(mid) + "\n")
