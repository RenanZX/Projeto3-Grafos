all:programa limpar
programa: main.o grafos.o dados.o
	g++ -o Projeto2 grafos.o dados.o main.o

main.o: main.cpp grafos.hpp dados.hpp
	g++ -c main.cpp

grafos.o: grafos.cpp grafos.hpp
	g++ -c grafos.cpp

dados.o: dados.cpp dados.hpp
	g++ -c dados.cpp

limpar:
	rm -rf *.o