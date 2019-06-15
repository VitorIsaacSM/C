# Vitor Isaac Sitton Maia
#makefile

#regra para criar o .o da classe lista
List.o: List.h List.cpp
	g++ -c List.cpp

#cria o .o da classe Entrada (node)
Entrada.o: Entrada.h Entrada.cpp
	g++ -c Entrada.cpp

#cria o executavel main
main: Entrada.o List.o main.cpp
	g++ Entrada.o List.o main.cpp -o main

#deleta todos os .o's e o executavel main
clean:
	@rm -f *.o main
