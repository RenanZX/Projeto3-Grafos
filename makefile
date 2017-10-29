CXXFLAGS= -Wall
all:programa limpar
programa: main.o grafos.o dados.o
	g++ -o Projeto3 grafos.o dados.o main.o

main.o: main.cpp grafos.hpp dados.hpp
	g++ $(CXXFLAGS) -c main.cpp

grafos.o: grafos.cpp grafos.hpp
	g++ $(CXXFLAGS) -c grafos.cpp

dados.o: dados.cpp dados.hpp
	g++ $(CXXFLAGS) -c dados.cpp

limpar:
	rm -rf *.o