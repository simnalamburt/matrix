HEADERS = matrix.hpp rain.hpp

default: matrix

matrix: main.o matrix.o rain.o
	g++ -o matrix main.o matrix.o rain.o -lncurses

main.o: main.cpp $(HEADERS)
	g++ -o main.o -c main.cpp
matrix.o: matrix.cpp $(HEADERS)
	g++ -o matrix.o -c matrix.cpp
rain.o: rain.cpp $(HEADERS)
	g++	-o rain.o -c rain.cpp

clean:
	-rm -f main.o matrix.o rain.o
	-rm -f matrix
