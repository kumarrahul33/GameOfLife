import random as rd
size = 256 
points = [0]*(size*size)
for i in range(size*size):
    temp = rd.random()
    points[i] = 0 if (temp > 0.5) else 1 


count = 0
for i in range(size*size):
    if points[i] == 1:
        count += 1
with open("input.txt", "w") as file:
    file.write(str(count) + "\n")
    for i in range(size*size):
        if points[i] == 1:
            file.write(str(i%size) + " " + str(i//size) + "\n")

# count the number of 1 in points
