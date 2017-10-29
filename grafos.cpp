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
	novovertice.EscolaValor.nome = "";
	novovertice.EscolaValor.habilitacoes = 0;
	novovertice.ProfessorValor = professorValor;
	lista_v.push_back(novovertice);
}

void Grafo::InsereVertice(escolaValor escolaValor)
{
	Vertice novovertice;
	novovertice.ProfessorValor.nome = "";
	novovertice.ProfessorValor.habilitacoes = 0;
	novovertice.EscolaValor = escolaValor;
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
			cout << "Professor:" << lista_v[i].ProfessorValor.nome << "\n habilitacoes:" << lista_v[i].ProfessorValor.habilitacoes << "\n";
			for(j=0;j < (signed)lista_v[i].listaAdjArest.size();j++){
				cout << "Escola alocada:" << lista_v[i].listaAdjArest[j].EscolaValor.nome;
			}
			cout << "\n" << endl;
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

void Grafo::Inicializar_valores(){
	if(TADProfessor()){
		for(int i=0;i<(signed)lista_v.size();i++){
			lista_v[i].ProfessorValor.professor_livre = true; /*libera todos os professsores nao alocados a nenhuma escola*/
		}
	}else if(TADEscola()){
		for(int i=0;i<(signed)lista_v.size();i++){
			lista_v[i].EscolaValor.vagas = 2; /*aloca duas vagas para cada professor*/
		}
	}
}

int Grafo::ExisteProfessorLivre(){
	int i =0;

	while((i!=(signed)lista_v.size())&&(lista_v[i].ProfessorValor.professor_livre!=true)){
		i++;
	}

	if(lista_v[i].ProfessorValor.professor_livre == true){
		return i;
	}
	return -1;
}

int Grafo::getValorEscola(string escola){
	int i=0;
	while((i!=(signed)lista_v.size())&&(lista_v[i].EscolaValor.nome != escola)){
		i++;
	}

	if(i==(signed)lista_v.size()){
		return -1;
	}
	return i;
}

int Grafo::PiorProfessor(int index_escola){
	int piorprofessor = 0;
	int piorhabilitacao = 3;
	int i =0;
	bool achou = false;
	std::vector<Vertice>lista_prof = lista_v[index_escola].listaAdjArest;

	for(i=0;i<(signed)lista_prof.size();i++){
		if(piorhabilitacao >= lista_prof[i].ProfessorValor.habilitacoes){
			piorhabilitacao = lista_prof[i].ProfessorValor.habilitacoes;
			piorprofessor = i;
			achou = true;
		}
	}

	int limite = lista_prof.size();

	if((i==limite)&&(!achou)){
		return -1;
	}

	return piorprofessor;
}

void Grafo::LiberarProfessor(const profValor& professor,const escolaValor& escola)
{
	int i=0;

	for(i=0;i<(signed)lista_v.size();i++){
		if(lista_v[i].ProfessorValor == professor){
			lista_v[i].ProfessorValor.professor_livre = true;
			int j =0;
			while((j!=(signed)lista_v[i].listaAdjArest.size())&&(lista_v[i].listaAdjArest[j].EscolaValor!=escola)){
				j++;
			}
			int limite = lista_v[i].listaAdjArest.size();
			if(j!=limite){
				lista_v[i].listaAdjArest.erase(lista_v[i].listaAdjArest.begin()+j);
			}
		}
	}
}

void Grafo::Emparelhar(Grafo grafo){
	if((TADProfessor())&&(grafo.TADEscola())){
		Inicializar_valores();
		grafo.Inicializar_valores();

		int i=0;
		while((i!=-1)&&(!lista_v[i].ProfessorValor.listaEscola.empty())){
			int escola = grafo.getValorEscola(lista_v[i].ProfessorValor.listaEscola.front());
			lista_v[i].ProfessorValor.professor_livre = false;
			grafo.lista_v[escola].listaAdjArest.push_back(lista_v[i]);  /*associa temporiariamente este professor a esta escola*/
			lista_v[i].listaAdjArest.push_back(grafo.lista_v[escola]);
			lista_v[i].ProfessorValor.listaEscola.erase(lista_v[i].ProfessorValor.listaEscola.begin());/*remove esta escola da lista de preferencias do professor*/
			grafo.lista_v[escola].EscolaValor.vagas--;/*diminui uma vaga para esta escola*/

			/*verifica a escola ultrapassou o limite de vagas*/
			if(grafo.lista_v[escola].EscolaValor.vagas < 0){
				int pior = grafo.PiorProfessor(escola); /*pega o indice do pior professor da lista de professores*/
				if(pior != -1){
					LiberarProfessor(grafo.lista_v[escola].listaAdjArest[pior].ProfessorValor,grafo.lista_v[escola].EscolaValor); /*libera este professor*/
					grafo.lista_v[escola].listaAdjArest.erase(grafo.lista_v[escola].listaAdjArest.begin()+pior);/*deleta este professor da lista de prefencia das escolas*/
					grafo.lista_v[escola].EscolaValor.vagas++; /*incrementa uma vaga a esta escola*/
				}else{/*caso contrário libera o último professor da lista de preferencia das escolas*/
					LiberarProfessor(grafo.lista_v[escola].listaAdjArest.back().ProfessorValor,grafo.lista_v[escola].EscolaValor);
					grafo.lista_v[escola].listaAdjArest.pop_back();/*tira o professor da lista de preferencia da escola*/
					grafo.lista_v[escola].EscolaValor.vagas++; /*incrementa o numero de vagas*/
				}
			}

			/*verifica se a escola está cheia*/
			if(grafo.lista_v[escola].EscolaValor.vagas == 0){
				int pior = grafo.PiorProfessor(escola); /*pega o indice do pior professor da lista de professores da escola*/
				if(pior != -1){
					int sucessores = pior+1;/*libera todos os sucessores do pior professor desta escola*/
					for(int k = sucessores;k < (signed)grafo.lista_v[escola].listaAdjArest.size();k++){
						LiberarProfessor(grafo.lista_v[escola].listaAdjArest[k].ProfessorValor,grafo.lista_v[escola].EscolaValor);
					}/*deleta todos os sucessores do pior professor da lista de preferencia das escolas*/
					grafo.lista_v[escola].listaAdjArest.erase(grafo.lista_v[escola].listaAdjArest.begin()+sucessores,grafo.lista_v[escola].listaAdjArest.end());
				}
			}
			i=ExisteProfessorLivre(); /*verifica o proximo*/
		}
	}

}

void Grafo::EmparelhareImprimir(Grafo grafo)
{
	Emparelhar(grafo);
	ImprimirGrafo();
}