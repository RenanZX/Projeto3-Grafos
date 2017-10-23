#include "grafos.hpp"

Grafo::Grafo()
{

}

Grafo::~Grafo()
{

}

void Grafo::InsereVertice(int id,std::tuple<string,int,std::vector<string>> professorValor)
{
	Vertice novovertice;
	novovertice.valor = id;
	novovertice.peso = 0;
	novovertice.ProfessorValor = professorValor;
	lista_v.push_back(novovertice);
}

void InsereVertice(int id,std::tuple<string,int> escolaValor)
{
	Vertice novovertice;
	novovertice.valor = id;
	novovertice.peso = 0;
	novovertice.EscolaValor = escolaValor;
	lista_v.push_back(novovertice);	
}

void Grafo::InsereAresta(int v1,int v2,int peso)
{
	int i = 0;

	while((i!=lista_v.size())&&(v1 != lista_v[i].valor)){
		i++;
	}
	if(i == lista_v.size()){
		return;
	}
	int j = 0;
	while((j!=lista_v.size())&&(v2 != lista_v[j].valor)){
		j++;
	}
	if(j == lista_v.size()){
		return;
	}
	Vertice novaAresta;
	novaAresta.valor = v2;
	novaAresta.peso = peso;
	lista_v[i].listaAdjArest.push_back(novaAresta);
}

void Grafo::ImprimirGrafo()
{
	int i=0,j=0;

	for(i=0;i<lista_v.size();i++){
		cout << lista_v[i].valor;
		for(j=0;j < lista_v[i].listaAdjArest.size();j++){
			cout << "->" << lista_v[i].listaAdjArest[j].valor;
		}
		cout << endl;
	}
}

Caminho Grafo::getMaiorCaminho(int v)throw(runtime_error)
{
	Caminho maiorCaminho_v;
	maiorCaminho_v.somapesos = 0;
	Caminho maiorCaminho;
	Caminho candidatoMaior;
	int i=0;

	maiorCaminho.path.push_back(v);
	maiorCaminho.somapesos = 0;

	while((i!=lista_v.size())&&(lista_v[i].valor != v)){
		i++;
	}
	if(i == lista_v.size()){
		throw runtime_error("Impossivel Calcular Maior Caminho");
	}

	int j=0;
	if(!lista_v[i].listaAdjArest.empty()){
		for(j=0;j<lista_v[i].listaAdjArest.size();j++){
			try{
				candidatoMaior = getMaiorCaminho(lista_v[i].listaAdjArest[j].valor);
				candidatoMaior.somapesos+=lista_v[i].listaAdjArest[j].peso;
			}catch(runtime_error &e){
			}
			if(candidatoMaior.somapesos > maiorCaminho_v.somapesos){
				maiorCaminho_v = candidatoMaior;
			}
		}
	}
	maiorCaminho.path.insert(maiorCaminho.path.end(),maiorCaminho_v.path.begin(),maiorCaminho_v.path.end());
	maiorCaminho.somapesos+=maiorCaminho_v.somapesos;
	return maiorCaminho;
}

bool Grafo::ExistemArestas(int v){
	int i =0;

	while((i!=lista_v.size())&&(v!=lista_v[i].valor)){
		i++;
	}
	if((i == lista_v.size())||(lista_v[i].listaAdjArest.empty())){
		return false;
	}
	return true;
}

bool Grafo::EstaMarcado(int n){
	int i = 0;

	while((i!=marcados.size())&&(marcados[i] != n)){
		i++;
	}
	if(i == marcados.size()){
		return false;
	}
	return true;
}

void Grafo::Marcar(int v){
	marcados.push_back(v);
}

void Grafo::LimparMarcas(){
	marcados.clear();
}

void Grafo::VisitaNo(Vertice n){
	int j = 0;
	if(!EstaMarcado(n.valor)){
		Marcar(n.valor);
		for(j=0;j < n.listaAdjArest.size();j++){
			VisitaNo(n.listaAdjArest[j]);
		}
		Ordenado.push_back(n.valor);
	}
}

void Grafo::Ordem_Topologica(){
	std::vector<Vertice> S = lista_v;
	Vertice n;

	for(int i=0;i<S.size();i++){
		n = S[i];
		VisitaNo(n);
	}
	LimparMarcas();
}

void EmparelhareImprimir(Grafo grafo)
{

}