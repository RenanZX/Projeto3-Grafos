#include "dados.hpp"

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>

void InsereRegistros(Grafo *prof, Grafo *Escolas){

  string line, cod, tmp[5];
  int hab;
  ifstream txtFile;
  txtFile.open("dados-trab3.txt");

  // Passa pelas linhas que tem informacoes acerca dos professores
  while(!txtFile.eof() && line != "#InfoEscola"){

    getline(txtFile, line);// Pega a linha do loop.

    if (line != "#InfoEscola"){ // teste para ele não inserir a string #InfoEscola

      istringstream iss(line); // variavel para poder salvar os elementos.

      iss >> cod >> hab >> tmp[0] >> tmp[1] >> tmp[2] >> tmp[3] >> tmp[4]; // pegando da variavel iss e salvando nas variaveis correspondete

      // Teste para debugger.
      
      /*cout << "###cod:"<< cod << " habProf:" << hab 
      << " TMP[0]: "<< tmp[0] 
      << " TMP[1]: "<< tmp[1]
      << " TMP[2]: "<< tmp[2]
      << " TMP[3]: "<< tmp[3]
      << " TMP[4]: "<< tmp[4] << endl;*/

      
      vector<string> v1(tmp,tmp+5);
      prof->InsereVertice((profValor){cod,hab,v1});
    }        
  }

  // Teste para debugger.
  //cout << "\n @@@ OPAAAA" << endl;

  // Passa pelas linhas que tem informacoes acerca das escolas.
  while(!txtFile.eof()){
    getline(txtFile, line); // Pega a linha do loop.

    istringstream iss(line); // variavel para poder salvar os elementos.

    iss >> cod >> hab; // pegando da variavel iss e salvando nas variaveis correspondete
    
    // Teste para debugger
    //cout << "codEsc:"<< cod << " habEsc:" << hab << endl;

    Escolas->InsereVertice((escolaValor){cod,hab,0});
  }
}