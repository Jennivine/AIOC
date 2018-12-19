with open("snakein.txt","r") as f:
    target_x, target_y = map(int,f.readline().split(" "))

current_x, current_y = 0,0
current_direction = "U"
path = ""

def update_direction(turn):
    global current_direction
    d = current_direction
    if turn == "left":
        if d == "U":
            current_direction = "L"
        elif d == "D":
            current_direction = "R"
        elif d == "L":
            current_direction = "D"
        elif d == "R":
            current_direction = "U"
    else:
        if d == "U":
            current_direction = "R"
        elif d == "D":
            current_direction = "L"
        elif d == "L":
            current_direction = "U"
        elif d == "R":
            current_direction = "D"

def turn_left(x,y):
    global current_direction
    d = current_direction
    if d == "U":
        return (x-1,y)
    elif d == "D":
        return (x+1,y)
    elif d == "L":
        return (x,y-1)
    elif d == "R":
        return (x,y+1)

def turn_right(x,y):
    global current_direction
    d = current_direction
    if d == "U":
        return (x+1,y)
    elif d == "D":
        return (x-1,y)
    elif d == "L":
        return (x,y+1)
    elif d == "R":
        return (x,y-1)

def distance_from_target(square):
    global target_x, target_y
    x, y = square
    return ((x-target_x)**2 + (y-target_y)**2)

while (current_x,current_y) != (target_x, target_y):
    #calculate the point the snake will end up on either way &
    #measure distance from target

    left = turn_left(current_x,current_y)
    left_distance_from_target = distance_from_target(left)
    
    right = turn_right(current_x,current_y)
    right_distance_from_target = distance_from_target(right)

    if left_distance_from_target < right_distance_from_target:
        current_x, current_y = left
        update_direction("left")
        path += "L"
    else:
        current_x, current_y = right
        update_direction("right")
        path += "R"

with open("snakeout.txt","w") as out:
    out.write(path)
