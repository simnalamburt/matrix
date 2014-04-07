HEADERS = matrix.hpp rain.hpp

default: matrix

matrix: main.o matrix.o rain.o
	g++ -o matrix main.o matrix.o rain.o -lncurses

main.o: main.cpp $(HEADERS)
	g++ -std=c++11 -o main.o -c main.cpp
matrix.o: matrix.cpp $(HEADERS)
	g++ -std=c++11 -o matrix.o -c matrix.cpp
rain.o: rain.cpp $(HEADERS)
	g++ -std=c++11	-o rain.o -c rain.cpp

clean:
	-rm -f main.o matrix.o rain.o
	-rm -f matrix
