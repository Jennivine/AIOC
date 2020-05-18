with open ("surfin.txt") as f:
        R, C = tuple(f.readline().strip().split())
        grid = []

        for i in range(int(R)):
                grid.append(list(f.readline().strip()))

# trace grid and cache ending points
cache = [[None for i in range(int(C))] for j in range(int(R))]

def trace(r,c):
        # you could have worked if smh you're python
        if cache[r][c]:
                return cache[r][c]
        
        if grid[r][c] == "*" or grid[r][c] == "+":
                cache[r][c] = (r,c)
                return (r,c)
        
        else:
                pathDirection = grid[r][c]
                if pathDirection == "v":
                        cache[r][c] = trace(r+1, c)
                        return cache[r][c]
                elif pathDirection == ">":
                        cache[r][c] = trace(r, c+1)
                        return cache[r][c]

ans = 0

for i in range(int(R)-1,-1,-1):
        for j in range(int(C)-1,-1,-1):
                path = grid[i][j]
                
                if path == "+":
                        cache[i][j] = "y" # where the pope is
                if path == "*":
                        cache[i][j] = "n"
                        
                elif path == ">":
                        cache[i][j] = cache[i][j+1]
                elif path == "v":
                        cache[i][j] = cache[i+1][j]

                if cache[i][j] == "n":
                        ans += 1
            
with open("surfout.txt", "w") as f:
        f.write(str(ans))
