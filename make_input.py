import random
size = random.randint(10000, 30000) 
points = [[random.randint(0, 99), random.randint(0, 99)] for i in range(size)]

with open("input.txt", "w") as file:
    file.write(str(size) + "\n")
    for point in points:
        file.write(str(point[0]) + " " + str(point[1]) + "\n")
