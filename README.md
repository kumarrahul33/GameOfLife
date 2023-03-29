# GAME OF LIFE

## Instructions to run the game
1. To make random inputs `python make_input.py`
2. To run the game `./run.sh`
3. To run preexisting inputs `./run.sh <input_file>`. The available inputs are toad.txt, glider.txt and pendtadecathlon.txt. 
4. To start animation plot `python animate.py`

## Instructions to change the god function
To change the god function just change the input to the GameOfLife class constructor
1 - God function 1: `game = GameOfLife(1)`
2 - God function 2: `game = GameOfLife(2)`
any other number - Defalut god function of Game of Life: e.g. `game = GameOfLife(0)`

## Instructions to change the animation speed
To change the animation speed just change the `interval` variable in the `animate.py` file. The default value is 100 ms.