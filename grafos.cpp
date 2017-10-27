#include "grafos.hpp"

Grafo::Grafo()
{
	elementoverificado = 0;
}

Grafo::~Grafo()
{

}

void Grafo::InsereVertice(profValor professorValor)
{
	Vertice novovertice;
	novovertice.valor = -1;
	novovertice.elos = 0;
	novovertice.EscolaValor.nome = "";
	novovertice.EscolaValor.habilitacoes = 0;
	novovertice.ProfessorValor = professorValor;
	lista_v.push_back(novovertice);
}

void Grafo::InsereVertice(escolaValor escolaValor)
{
	Vertice novovertice;
	novovertice.valor = -1;
	novovertice.elos = 0;
	novovertice.ProfessorValor.nome = "";
	novovertice.ProfessorValor.habilitacoes = 0;
	novovertice.EscolaValor = escolaValor;
	lista_v.push_back(novovertice);	
}

void Grafo::InsereVertice(int valor)
{
	Vertice novovertice;
	novovertice.elos = 0;
	novovertice.valor = valor;
	novovertice.ProfessorValor.nome = "";
	novovertice.ProfessorValor.habilitacoes = 0;
	novovertice.EscolaValor.nome = "";
	novovertice.EscolaValor.habilitacoes = 0;
	lista_v.push_back(novovertice);	
}

void Grafo::ImprimirGrafo()
{
	int i=0,j=0;

	if(TADEscola()){
		for(i=0;i<(signed)lista_v.size();i++){
			cout << "Escola:" << lista_v[i].EscolaValor.nome << "\n habilitacoes:" << lista_v[i].EscolaValor.habilitacoes;
			for(j=0;j < (signed)lista_v[i].listaAdjArest.size();j++){
				cout << "professores contratados:" << lista_v[i].listaAdjArest[j].ProfessorValor.nome << ",";
			}
			cout << "." << endl;
		}
	}else if(TADProfessor()){
		for(i=0;i<(signed)lista_v.size();i++){
			cout << "Professor:" << lista_v[i].ProfessorValor.nome << "\n habilitacoes:" << lista_v[i].ProfessorValor.habilitacoes;
			for(j=0;j < (signed)lista_v[i].listaAdjArest.size();j++){
				cout << "Escola alocada:" << lista_v[i].listaAdjArest[j].EscolaValor.nome << ",";
			}
			cout << "." << endl;
		}
	}else{
		for(i=0;i<(signed)lista_v.size();i++){
			cout << lista_v[i].valor;
		for(j=0;j < (signed)lista_v[i].listaAdjArest.size();j++){
			cout << "->" << lista_v[i].listaAdjArest[j].valor;
		}
			cout << endl;
		}
	}
}

bool Grafo::TADEscola()
{
	if((lista_v[0].EscolaValor.nome != "")&&(lista_v[0].EscolaValor.habilitacoes!=0)){
		return true;
	}
	return false;
}

bool Grafo::TADProfessor()
{
	if((lista_v[0].ProfessorValor.nome != "")&&(lista_v[0].ProfessorValor.habilitacoes!=0)&&(!lista_v[0].ProfessorValor.listaEscola.empty())){
		return true;
	}
	return false;
}

bool Grafo::TADValor()
{
	if(lista_v[0].valor != -1){
		return true;
	}
	return false;
}


bool Grafo::VerificarRequisitos(int habilitacoes,string escola){
	int i=0;

	while((i!=(signed)lista_v.size())&&(lista_v[i].EscolaValor.nome!=escola)){
		i++;
	}
	if(i!=(signed)lista_v.size()){
		if((habilitacoes == lista_v[i].EscolaValor.habilitacoes)&&(lista_v[i].elos!=2)){
			elementoverificado = i;
			lista_v[i].elos++;
			return true;
		}
		elementoverificado = -1;
	}
	return false;
}

void Grafo::Emparelhar(Grafo grafo){
	if((TADProfessor())&&(grafo.TADEscola())){
		for(int i=0;i<(signed)lista_v.size();i++){
			std::vector<string> listaEscolas = lista_v[i].ProfessorValor.listaEscola;
			for(int j=0;j<(signed)listaEscolas.size();j++){
				if(grafo.VerificarRequisitos(lista_v[i].ProfessorValor.habilitacoes,listaEscolas[j])){
					lista_v[i].listaAdjArest.push_back(grafo.lista_v[grafo.elementoverificado]);
				}
			}
		}
	}

}

void Grafo::EmparelhareImprimir(Grafo grafo)
{
	Emparelhar(grafo);
	ImprimirGrafo();
}