with open("hirein.txt") as f:
    N = int(f.readline().strip())
    
    monks = []
    for i in range(N):
        monks.append(int(f.readline().strip()))
    monks = sorted(monks)

    S = int(f.readline().strip())
    student_jobs = []
    for i in range(S):
        student_jobs.append(int(f.readline().strip()))
    student_jobs = sorted(student_jobs)

    M = int(f.readline().strip())
    master_jobs = []
    for i in range(M):
        master_jobs.append(int(f.readline().strip()))
    master_jobs = sorted(master_jobs)

counterN = 0
counterS = 0
counterM = 0
ans = 0

while counterN < N and counterS < S:
    if monks[counterN] <= student_jobs[counterS]:
        ans += 1
        counterN += 1
        counterS += 1
    else:
        counterS += 1


while counterN < N and counterM < M:
    if monks[counterN] >= master_jobs[counterM]:
        ans += 1
        counterN += 1
        counterM += 1
    else:
        counterN += 1

with open("hireout.txt", "w") as o:
    o.write(str(ans) + "\n")
    
