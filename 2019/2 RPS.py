with open("rpsin.txt") as f:
    N = int(f.readline().strip())
    r_o, p_o, s_o = (map(int, f.readline().strip().split()))
    r, p, s = (map(int, f.readline().strip().split()))

ans = 0

# def_winning moves
paper_win = min(p, r_o)
scissors_win = min(s, p_o)
rock_win = min(r, s_o)

p -= paper_win
r_o -= paper_win

s -= scissors_win
p_o -= scissors_win

r -= rock_win
s_o -= rock_win

ans = paper_win + scissors_win + rock_win

# make draw moves if possible
paper_draw = min(p, p_o)
scissors_draw = min(s, s_o)
rock_draw = min(r, r_o)

p -= paper_draw
p_o -= paper_draw

s -= scissors_draw
s_o -= scissors_draw

r -= rock_draw
r_o -= rock_draw

# make losing moves :(
ans -= p+s+r

o = open("rpsout.txt", "w")
o.write("%d\n" % ans)
o.close()
