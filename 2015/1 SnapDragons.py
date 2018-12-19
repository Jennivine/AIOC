I,O = open("snapin.txt", "r"), open("snapout.txt","w")
board1, board2, rose1, rose2, scarlet1, scarlet2 = [int(x) for x in I.readline().split()]

#do something

if ((scarlet1 - rose1) + (scarlet2 - rose2)) % 2 == 1:
    O.write("ROSE")
elif ((scarlet1 - rose1) + (scarlet2 - rose2)) % 2 == 0:
    O.write("SCARLET")


O.close(),I.close()
