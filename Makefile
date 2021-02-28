main: main.cc
	g++ -std=c++14 -g -Wall -o langtong_ant main.cc board.cc cell.cc ant.cc
board.o: board.cc
	g++ -std=c++14 -g -Wall -o board board.cc
cell.o: cell.cc
	g++ -std=c++14 -g -Wall -o cell cell.cc
ant.o: ant.cc
	g++ -std=c++14 -g -Wall -o ant ant.cc
clean: 
	rm -f langtong_ant 
