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
        # print(lines[1].count(['']))
        # for line in lines:
        #     for point in line:
        #             if point==['']:
        #                 print(lines.index(line))
        #                 print(line.index(point))
        #                 print('empty')
        # print(lines[2])
        # print(len(lines))
        lines = remove_useless_line(lines,[['']])
        # print(lines[2])
        # print(len(lines))
        # for line in lines:
        #     for point in line:
        #         for i in range(len(point)):
        #             try:
        #                 point[i] = int(point[i])
        #             except:
        #                 print(point)
        #                 print('error')
        lines = [[[int(point[0]), int(point[1])] for point in point_xy] for point_xy in lines]
        # lines.remove([''])

        # print(lines[0])
        return lines
        # print(int(lines[0][0][0]))

points = take_input()

# plt.rcParams["figure.figsize"] = [7.00, 3.50]
# plt.rcParams["figure.autolayout"] = True

fig, ax = plt.subplots()

def update(i):
    # im_normed = np.random.rand(6, 6)
    mat = np.zeros((200,200))
    for point in points[i]:
        mat[point[0],[point[1]]] = 1
    ax.imshow(mat)
    ax.set_axis_off()

anim = FuncAnimation(fig, update, frames=len(points), interval=50)

plt.show()
# animate(points)





