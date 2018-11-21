'''Question 1: Magic Square'''
import sys

with open("magicin.txt","r") as f: #won't run because magicin.txt doesn't exist
    inputs = tuple(f.read().split(" "))
#create example file according to AIO training site

def solve( inputs):
    a,b,c = inputs
    a = int(a)
    b = int(b)
    c = int(c)
    return [[a,b,c],
            [c,a,b],
            [b,c,a]]

def report(rows, out):
    for row in rows:
        out.write(" ".join(map(str,row)))
        out.write("\n")
        
def question1():
#writes the file:
#with open("magicout.txt", "w") as out:
    report(solve(inputs), sys.stdout) #system standard output.
#puts answer in console for convenience's sake (for the time being)
