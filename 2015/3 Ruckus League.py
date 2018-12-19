I,O = open("ruckusin.txt", "r"), open("ruckusout.txt","w")

N, L, K, M = [int(x) for x in I.readline().split()]

group = [0 for i in xrange(N+1)]

#Int : MembersInfo
members = {}

group_num = 0

def make_new_group(i,x):
    global group_num
    group_num += 1
    group[i] = group_num
    group[x] = group_num
    
    mi = MembersInfo()
    mi.add_member(i)
    mi.add_member(x)
    members[group_num] = mi

def join_to_group(i,x):
    group[x] = group[i]
    members[group[i]].add_member(x)

def make_circle(i):
    get_group_num = group[i]
    members[get_group_num].make_circle()
    
def merge_groups(i,x):
    group_num1 = group[i]
    group_num2 = group[x]
    for n in members[group_num1].members:
        group[n] = group_num2

    members[group_num2].add_members(members[group_num1].members)

    del members[group_num1]
    

class MembersInfo:
    def __init__(self):
        self.members = []
        self.circle = False
    def add_member(self,n):
        self.members.append(n)
    def add_members(self,ns):
        self.members.extend(ns)
    def make_circle(self):
        self.circle = True
    def size(self):
        return len(self.members)

for j in xrange(L):
    i,x = map(int,I.readline().strip().split(" "))
    if group[i] == 0 and group[x] == 0:
        make_new_group(i,x)
    elif group[i] == 0 and group[x] > 0:
        join_to_group(x,i)
    elif group[i] > 0 and group[x] == 0:
        join_to_group(i,x)
    elif group[i] == group[x]:
        make_circle(i)
    else:
        merge_groups(i,x)
        
def num_singletons():
    total = 0
    for i in members:
        total += members[i].size()
    return N - total

singletons = num_singletons()

lines = list()
circles = list()

for i in members:
    person = members[i]
    if person.circle:
        circles.append(person.size())
    else:
        lines.append(person.size())

circles.sort(reverse=True)

ans = 0

def break_line(size,lr):
    global M
    max_group = size // M
    max_num_lollies = max_group - 1

    if size < M:
        return (0, lr)
    elif lr >= max_num_lollies:
        return (max_group,lr - max_num_lollies)
    else:
        return (lr+1,0)

def break_circle(size, lr):
    if size < M:
        return (0, lr)
    elif lr <= 1:
        return (1,lr)
    else:
        return break_line(size, lr-1)

def solve(lines, circles, singletons):
    lr = K
    answer = 0
    if M == 1:
        answer += singletons
    for size in lines:
        num, lr = break_line(size,lr)
        answer += num
    for size in circles:
        num, lr = break_circle(size,lr)
        answer += num

    return answer
        
ans = solve(lines, circles, singletons)

print >> O, "%d" %ans
O.close(),I.close()
