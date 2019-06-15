tarefa.o: tarefa.cpp tarefa.h
	g++ -c tarefa.cpp
main: main.cpp tarefa.o
	g++ main.cpp tarefa.o -std=c++11 -o main
clear:
	rm -rf main *.o
