main: main.cc
	g++ -std=c++14 -g -Wall -o tablero main.cc board.cc
board.o: board.cc
	g++ -std=c++14 -g -Wall -o board board.cc
clean: 
	rm -f tablero 
