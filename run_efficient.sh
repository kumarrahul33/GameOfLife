g++ -o efficient.out efficient.cpp
# take a input from commnad line
if [[ -n "$1" ]]; then
    ./efficient.out < $1 > output.txt
else
    ./efficient.out < input.txt > output.txt
fi
