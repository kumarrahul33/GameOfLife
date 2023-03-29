from matplotlib import pyplot as plt
from matplotlib.animation import FuncAnimation
import matplotlib.pyplot as plt
import numpy as np

def remove_useless_line(list,item):
    res = [i for i in list if i != item]
    return res


def take_input():
    #read from a file output.txt
    with open("output.txt") as f:
        lines = f.readlines()
        # print(lines[0].strip("\n"))
        lines = [line.strip() for line in lines]
        lines = [line.strip(",") for line in lines]
        lines = [line.split(",") for line in lines]
        lines = [[point.split("-") for point in point_xy] for point_xy in lines]
        lines = remove_useless_line(lines,[['']])
        lines = [[[int(point[0]), int(point[1])] for point in point_xy] for point_xy in lines]

        return lines

points = take_input()


fig, ax = plt.subplots()

def update(i):
    ax.cla()
    mat = np.zeros((100,100))
    for point in points[i]:
        mat[point[0],[point[1]]] = 1
    ax.imshow(mat)
    ax.set_axis_off()


anim = FuncAnimation(fig, update, frames=range(len(points)), interval=100)

plt.show()





