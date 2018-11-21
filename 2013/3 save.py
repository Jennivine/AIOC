def myRound(x, base=5):
    return int(base * round(float(x)/base))

def notExhausted(a,b):
    if len(a) > len(b):
        return (3,a[len(b)-len(a):])
    else:
        return (4,b[len(a)-len(b):])

with open('savein.txt', 'r') as I:
    N = int(I.readline())
    bucketOf3 = []
    bucketOf4 = []
    total = 0
    
    for _ in xrange(N):
        price = int(I.readline())
        
        if price % 5 in set([0,1,2]):
            total += myRound(price)
        else:
            # the prices go into two separate buckets
            if price % 5 == 3:
                bucketOf3.append(price)
            else:
                bucketOf4.append(price)

    for i in xrange(min(len(bucketOf3),len(bucketOf4))):
        # the two buckets are matched pairwise
        # to fully exhaust the bucket with fewer prices
        total += myRound(bucketOf3[i]+bucketOf4[i])

    if abs(len(bucketOf3) - len(bucketOf4)) != 0:
        # the rest is exhausted by itself
        whichBucket, notEx = notExhausted(bucketOf3,bucketOf4)
        length = len(notEx)

        if whichBucket == 3:
            # break into groups of 4s and round
            List = [notEx[i:i+4] for i in range(0,len(notEx),4)]
            for l in List:
                total += myRound(sum(l))
        else:
            # break into groups of 3s and round
            List = [notEx[i:i+3] for i in range(0,len(notEx),3)]
            for l in List:
                total += myRound(sum(l))

with open('saveout.txt','w') as O:
    O.write(str(total))
