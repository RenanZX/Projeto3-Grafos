#include "grafos.hpp"
#include "dados.hpp"

int main(){


  //Grafos grafos;
  //teste pra verificar a saida
  Grafo prof;
  Grafo Escolas;
  
  /*string tmp1[] = {"E10", "E20", "E1", "E27", "E3"};
  std::vector<string> v1(tmp1,tmp1+5);
  prof.InsereVertice((profValor){"P1",3,v1});

  string tmp2[] = {"E10", "E20", "E2", "E27", "E5"};
  std::vector<string> v2(tmp2,tmp2+5);
  prof.InsereVertice((profValor){"P2",2,v2});

  string tmp3[] = {"E10", "E20", "E3", "E27", "E7"};
  std::vector<string> v3(tmp3,tmp3+5);
  prof.InsereVertice((profValor){"P3",2,v3});

  Escolas.InsereVertice((escolaValor){"E10",1,0});
  Escolas.InsereVertice((escolaValor){"E20",3,0});
  Escolas.InsereVertice((escolaValor){"E1",1,0});
  Escolas.InsereVertice((escolaValor){"E27",2,0});
  Escolas.InsereVertice((escolaValor){"E2",1,0});
  Escolas.InsereVertice((escolaValor){"E3",1,0});
  Escolas.InsereVertice((escolaValor){"E7",1,0});
  Escolas.InsereVertice((escolaValor){"E5",1,0});

  prof.EmparelhareImprimir(Escolas);
	return 0;*/

  InsereRegistros(&prof, &Escolas);
  prof.EmparelhareImprimir(Escolas);
}
