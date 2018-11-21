N = 0

# The variables below track how many of each delta_type we have.
A  = 0   # (1,1,1)
B1 = 0   # (1,0,0) or (0,1,1)
B2 = 0   # (0,1,0) or (1,0,1)
B3 = 0   # (0,0,1) or (1,1,0)
C  = 0   # (1,0,0) or (0,1,0) or (0,0,1) -- these combine with any B

# Returns N and three strings "GATTAC...": (3, ("GAC", "TTA", "ATC"))
def read_input():
  with open("chimin.txt") as f:
    N = int(f.readline())
    lion = f.readline().strip()
    snak = f.readline().strip()
    goat = f.readline().strip()
    return (N, (lion, snak, goat))

def sort_into_buckets(strings):
  lion, snake, goat = strings
  for i in xrange(N):
    genes = (lion[i], snake[i], goat[i])
    update_bucket_count(genes)

def num_in_common(genes):
  a,b,c = genes
  if a == b and b == c:
    return 3
  elif a == b or a == c or b == c:
    return 2
  else:
    return 1

# This adds 1 to one of the global variables A, B1, B2, B3, C, depending on the
# arrangement of the genes.
def update_bucket_count(genes):
  global A, B1, B2, B3, C
  nc = num_in_common(genes)
  if nc == 3:
    A += 1
  elif nc == 1:
    C += 1
  else:
    a,b,c = genes
    if b == c:         # (0,1,1) or (1,0,0)
      B1 += 1
    elif a == c:       # (1,0,1) or (0,1,0)
      B2 += 1
    elif a == b:       # (1,1,0) or (0,0,1)
      B3 += 1

def print_buckets(msg, score):
  print
  print msg
  print "score: %-6d | A: %6d  B1: %6d  B2: %6d  B3: %6d  C: %6d" % \
      (score, A, B1, B2, B3, C)

def solve():
  global A, B1, B2, B3, C
  score = 0
  print_buckets("Init", score)
  # Exhaust A. These are free points.
  score += A; A = 0
  print_buckets("Exhaust A", score)
  # Combine B* triplets
  # Reason: one of each bucket B genes combines together nicely to increase
  #         the score by two
  smallestB_sum = min(B1,B2,B3)
  for n in xrange(smallestB_sum):
      score += 2
  B1 -= smallestB_sum
  B2 -= smallestB_sum
  B3 -= smallestB_sum
  print_buckets("Combine B* triplets", score)
  # Try to exhaust C using B as much as possible.
  # Reason: any B can be combined with a C. We'd like to run the Cs down because
  # they combine better with B than they do with each other.
  x = min(B1, C); score += x; B1 -= x; C -= x
  print_buckets("Pair Cs with B1s", score)
  x = min(B2, C); score += x; B2 -= x; C -= x
  print_buckets("Pair Cs with B2s", score)
  x = min(B3, C); score += x; B3 -= x; C -= x
  print_buckets("Pair Cs with B3s", score)
  # Now use remaining Bs, in like pairs. A B1 can combine with another B1 nicely
  # -- i.e.  (1,0,0) and (0,0,1). Likewise B2 and B3. So for each two B* we get
  # an increase of one point. After this, each B* bucket will have 0 or 1 in it.
  score += B1/2; B1 = B1%2
  score += B2/2; B2 = B2%2
  score += B3/2; B3 = B3%2
  print_buckets("Pair off B1-B1, B2-B2, B3-B3", score)
  # Now use remaining C. Three Cs combine to add one point.
  score += C/3;  C  = C%3
  print_buckets("Use remaining C", score)
  # Finally, there may be two loose Bs of different types that can be combined
  # for one more point.
  if (B1 + B2 + B3) < 2:
    pass
  elif (B1 + B2 + B3) == 2:
    score += 1
  print_buckets("Use final scraps of B", score)
  return score

def main():
  global N
  N, strings = read_input()
  # Process all the input to work out how many of each type we have:
  #   A, B1, B2, B3, C.
  sort_into_buckets(strings)
  # Now that we know how many of each type there are, we can solve the problem.
  answer  = solve()
  with open("chimout.txt", "w") as f:
    print >> f, answer
    print answer

main()
