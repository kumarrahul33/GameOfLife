g++ game_of_life.cpp
# take a input from commnad line
if [[ -n "$1" ]]; then
    # echo "The first parameter is not empty"
    ./a.out < $1 > output.txt
else
    ./a.out < input.txt > output.txt
fi
