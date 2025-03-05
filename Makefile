CCFLAGS=-Wall -pedantic -Werror
CC=gcc

all: dirs build

dirs:
	mkdir -p bin

build:
	$(CC) $(CCFLAGS) ./src/*.c -o bin/solver.out