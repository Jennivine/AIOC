f = raw_input()
N, K = map(int, f.strip().split())

def d(s):
    return "D"+s

def h(s):
    return "H"+s

def recursion(number, max_ope):
    if number == 1:
        return [""]
    if max_ope == 0:
        return []

    if number % 2 == 1:
        return  map(d, recursion(number-1, max_ope-1))
    else:
        return (map(d, recursion(number-1, max_ope-1)) +
                map(h, recursion(number/2, max_ope-1)) )

answer = recursion(N, K)

for operation_chain in answer:
    operation = list(operation_chain[::-1])
    for i,o in enumerate(operation):
        if o == "D":
            operation[i] = "+"
        else:
            operation[i] = "*"
    print "".join(operation)

print
