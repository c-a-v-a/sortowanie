SRC=$(wildcard ./src/*.c)
BIN=./sort

sort: $(SRC)
	gcc -o $(BIN) $^ -O2
