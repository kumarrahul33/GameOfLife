g++ -o main.out gol.cpp
# take a input from commnad line
if [[ -n "$1" ]]; then
    ./main.out < $1 > output2.txt
else
    ./main.out < input.txt > output2.txt
fi
