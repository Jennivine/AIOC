with open("pairsin.txt") as f:
	N, A, B = list(map(int, f.readline().strip().split()))
	skills = list(map(int, f.readline().strip().split()))
	skills.sort()

ans = 0
l = r = N-1

'''
# subtask 1: brute force cos why not
for i in range(N-1):
	for j in range(i+1, N):
		s = skills[i] + skills[j]
		if s >= A and s <= B:
			ans += 1
'''

# subtask 2: skills = 1 2 3 4 5 ... N, sorted skills in ascending order
for s in range(N):
	l = max(l, s)
	r = max(r, s)
	
	while l > s and skills[s] + skills[l] >= A:
		l -= 1
	while r > s and skills[s] + skills[r] > B:
		r -= 1

	ans += r-l
	# print("i: %d, skills: %d, lower: %d, upper: %d, ans: %d" % (i, skills[i], lower, upper, ans))

o = open("pairsout.txt", "w")
o.write("%d\n" % ans)
o.close()
