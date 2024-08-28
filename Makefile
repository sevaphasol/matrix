CC = g++

SRC_DIR = src
BIN_DIR = bin

all: matrix

matrix: bin\main.o bin\matrix.o
	g++ bin\main.o bin\matrix.o -o matrix

bin\main.o: src\main.cpp
	g++ -c -I include src\main.cpp -o bin\main.o

matrix.o: src\matrix.cpp
	g++ -c -I include src\matrix.cpp -o bin\matrix.o
