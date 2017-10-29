#ifndef GRAFOS_H
#define GRAFOS_H
#include <iostream>
#include <string>
#include <stdexcept>
#include <vector>

using namespace std;

typedef struct EValor{
  string nome;
  int habilitacoes;
  int vagas;
  bool operator==(const struct EValor& v2){
    if((nome == v2.nome)&&(habilitacoes == v2.habilitacoes)&&(vagas == v2.vagas)){
      return true;
    }
    return false;
  }
  bool operator!=(const struct EValor& v2){
    if((nome != v2.nome)&&(habilitacoes != v2.habilitacoes)&&(vagas != v2.vagas)){
      return true;
    }
    return false;
  }
}escolaValor;

typedef struct PValor{
  string nome;
  int habilitacoes;
  std::vector<string> listaEscola;
  bool professor_livre;
  bool operator==(const struct PValor& v2){
    if((nome == v2.nome)&&(habilitacoes == v2.habilitacoes)&&(professor_livre == v2.professor_livre)){
      return true;
    }
    return false;
  }
  bool operator!=(const struct PValor& v2){
    if((nome != v2.nome)&&(habilitacoes != v2.habilitacoes)&&(professor_livre != v2.professor_livre)){
      return true;
    }
    return false;
  }
}profValor;

class Vertice{ /*classe do vertice*/
friend class Grafo;
private:
  profValor ProfessorValor;
  escolaValor EscolaValor;
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
  void Inicializar_valores();
  int ExisteProfessorLivre();
  void LiberarProfessor(const profValor& professor,const escolaValor& escola);
  int PiorProfessor(int index_escola);
  void Emparelhar(Grafo grafo);
  int getValorEscola(string escola);
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