#include "grafos.hpp"
#include "dados.hpp"

int main(){


  //Grafos grafos;
  Grafo gr;

  /*gr.InsereVertice(113034);
  gr.InsereVertice(113468);
  gr.InsereVertice(113450);
  gr.InsereVertice(113476);
  gr.InsereVertice(116726);


  gr.InsereAresta(113034,113468, 10);
  gr.InsereAresta(113034,113450, 10);


  gr.ImprimirGrafo();*/

  InsereRegistros(&gr);
  gr.ImprimirGrafo();
  gr.ImprimirTopologicamente();
  gr.ImprimirCaminhoCritico();
	return 0;
}
