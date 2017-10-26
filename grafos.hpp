#ifndef GRAFOS_H
#define GRAFOS_H
#include <iostream>
#include <string>
#include <stdexcept>
#include <vector>

using namespace std;

typedef struct PValor{
  string nome;
  int habilitacoes;
  std::vector<string> listaEscola;
}profValor;

typedef struct EValor{
  string nome;
  int habilitacoes;
}escolaValor;

class Vertice{ /*classe do vertice*/
friend class Grafo;
private:
  profValor ProfessorValor;
  escolaValor EscolaValor;
  int valor;
  int elos;
  std::vector<Vertice> listaAdjArest; /*lista de Adjacencia*/
};

class Caminho{ /*classe contendo um caminho do grafo*/
friend class Grafo;
private:
  int somapesos; /*somatorio dos pesos das arestas do caminho*/
  std::vector<int> path; /*caminho*/
};

class Grafo{
private:
  int elementoverificado;
  std::vector<Vertice> lista_v; /*lista de vertices do grafo*/
  bool TADEscola();
  bool TADProfessor();
  bool TADValor();
  bool VerificarRequisitos(int habilitacoes,string escola);
  void Emparelhar(Grafo grafo);
public:
  Grafo(); /*construtor e destrutor do grafo*/
  ~Grafo();
  void InsereVertice(profValor professorValor);
  void InsereVertice(escolaValor escolaValor);
  void InsereVertice(int valor);
  void ImprimirGrafo(); /*imprime o grafo*/
  void EmparelhareImprimir(Grafo grafo); /*recebe um grafo para emparelhar e imprime o grafo emparelhado*/
};

#endif