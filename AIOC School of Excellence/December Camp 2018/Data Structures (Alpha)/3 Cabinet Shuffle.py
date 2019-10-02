with open("shufflein.txt") as I:
    N, K = map(int, I.readline().strip().split())

    chairs = map(int, I.readline().strip().split())
    PMchair = min(chairs)

    getIndex = {}
    for i in range(len(chairs)):
        getIndex[chairs[i]] = i
    
    ministers = map(int, I.readline().strip().split())

    # make look-up table
    dist_chair_to_chair = {}
    for i in range(len(chairs)-1):
        dist_chair_to_chair[chairs[i]] = chairs[i+1] - chairs[i]
    dist_chair_to_chair[chairs[-1]] = N-chairs[-1]+chairs[0]

# helper functions
def nextChairs(ministers):
    ''' time-consuming but hopefully only get called onces'''
    # maps each minister to the next chair at the start of the game
    ls = []
    counter = 0
    for pos in ministers:
        while counter < len(chairs) and chairs[counter] < pos:
            counter += 1
            
        if counter < len(chairs):
            ls.append(chairs[counter])
        else:
            ls.append(chairs[0])

    return ls
        

def getDistance(minister, chair):
    if minister <= chair:
        distance = chair-minister
    else:
        distance = N-minister+chair

    return distance

def nextState(state):
    global PM
    eliminate = min(state)
    shift = eliminate[0]
    chair = eliminate[2]
    newState = []

    if chair == PMchair:
        PM = eliminate[3]

    # update dictionary
    chair_num = getIndex[chair]
    dist_chair_to_chair[chairs[(chair_num-1)%3]] += dist_chair_to_chair[chair]
    

    for data in state:
        distance, minister_pos, chair_target, minister_num = data

        minister_pos += shift
        if minister_pos > N:
            minister_pos -= N
        distance -= shift

        if distance != 0 and chair_target == chair:
            distance += dist_chair_to_chair[chair_target]
            chair_target = minister_pos + distance
            if chair_target > N:
                chair_target -= N
            newState.append((distance, minister_pos, chair_target, minister_num))
            
    return newState

# make data structure to represent the ministers
PM = 0
state = [] 
next_chair = nextChairs(ministers)

for i in range(len(ministers)):
    distance = getDistance(ministers[i], next_chair[i]) # distance between minister and chair
    state.append((distance, ministers[i], next_chair[i], i+1))
'''
# "simulate" the game, but not really?
while len(state) > 1:
    state = nextState(state)

print PM, state[0][3]
'''
with open("shuffleout.txt", "w") as O:
    O.write(str(PM) + "\n")
    O.write(str(state[0][3]))


