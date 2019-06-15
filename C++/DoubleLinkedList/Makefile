#teste de comentario
#makefile

#regra para criar o .o da classe lista
List.o: List.h List.cpp
	g++ -c List.cpp

Node.o: Node.h Node.cpp
	g++ -c Node.cpp

main: Node.o List.o main.cpp
	g++ Node.o List.o main.cpp -o main

clean:
	@rm -f *.o main
