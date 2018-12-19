with open("archin.txt", "r") as I:
    n,a,b = map(int, list(I.readline().strip().split(" ")))
    best = 0
    worst = 0

    # number of people I beated in day1
    beated1 = n-a

    # number of people that beat me in day1
    beat1 = n-beated1-1

    # number of people I beated in day2
    beated2 = n-b

    # number of people that beat me in day1
    beat2 = n-beated2-1

    totalBeated = beated1 + beated2
    totalBeat = beat1 + beat2

    if totalBeated - n < 0:
        #print "1"
        worst = n
    else:
        #print "2"
        worst =  n -(totalBeated - n) - 1

    if totalBeat - n < 0:
        #print "3"
        best = 1
    else:
        #print "4"
        best = totalBeat - n + 2
    
with open("archout.txt","w") as O:
    O.write("%d %d" %(best,worst))

