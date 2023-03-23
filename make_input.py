import random
size = random.randint(40, 180) 
points = [[random.randint(0, 200), random.randint(0, 200)] for i in range(size)]

with open("input.txt", "w") as file:
    file.write(str(size) + "\n")
    for point in points:
        file.write(str(point[0]) + " " + str(point[1]) + "\n")
