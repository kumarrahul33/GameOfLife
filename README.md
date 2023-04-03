# GAME OF LIFE

## Instructions to run the game
1. To make random inputs `python make_input.py`
2. To run the game `./run.sh`
3. To run preexisting inputs `./run.sh <input_file>`. The available inputs are toad.txt, glider.txt and pendtadecathlon.txt. 
4. To start animation plot `python animate.py`
5. make sure that the SIZE_OF_MATRIX is in the animate.py file. 

# TASK 2 : game_of_life.cpp
## Instructions to change the god function
To change the god function just change the input to the GameOfLife class constructor
1 - God function 1: `game = GameOfLife(1)`
2 - God function 2: `game = GameOfLife(2)`
any other number - Defalut god function of Game of Life: e.g. `game = GameOfLife(0)`

## Instructions to change the animation speed
To change the animation speed just change the `interval` variable in the `animate.py` file. The default value is 100 ms.

# TASK 3 : efficient.cpp gol.cpp
## Instructions to run the non-optimized verions
run `time ./main.sh`
## Instructions to run the efficient version
run `time ./run_efficient.sh`
the time infront will tell the time taken to run the program.

## Method used for optimizations
1. The matrix is divided into blocks and the elements in the block are kept close to one another in the array in the program. This done to best utilize caching. 
For example, a matrix of 9x9 with 3x3 blocks is stored like the following:
0,0 0,1 1,0 1,1 0,2 0,3 1,2 1,3 0,4 0,5 1,4 1,5 0,6 0,7 1,6 1,7 2,0 2,1 3,0 3,1 2,2 2,3 3,2 3,3 2,4 2,5 3,4 3,5 2,6 2,7 3,6 3,7 4,0 4,1 5,0 5,1 4,2 4,3 5,2 5,3 4,4 4,5 5,4 5,5 4,6 4,7 5,6 5,7 6,0 6,1 7,0 7,1 6,2 6,3 7,2 7,3 6,4 6,5 7,4 7,5 6,6 6,7 7,6 7,7
2. Wherever possible bit operation are use inplace of usual arithmetic operators.