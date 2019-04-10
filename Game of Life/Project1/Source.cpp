#include "Caverna.h"
#include "Chao.h"
#include "GameLife.h"
#include "Mapa.h"
#include <iostream>
#include <ctime>


void main() {
	

	int xM, yM, decisao;

	GameLife teste;
	std::cout << "Defina o x da sua matriz: ";
	std::cin >> xM;
	std::cout << "\nAgora defina o y da sua matriz: ";
	std::cin >> yM;
	std::cout << "\nA sua matriz ficou: \n";
	teste.tamanho(xM, yM);
	teste.teste1();
	std::cout << "\nE o proximo ciclo ficou: \n";
	teste.gerarMapa();
	std::cout << "\nDeseja gerar um próximo ciclo? (1.sim 2.nao)\n";
	std::cin >> decisao;
	while (decisao == 1) {
		teste.gerarMapa();
		std::cout << "\nDeseja gerar um próximo ciclo? (1.sim 2.nao)\n";
		std::cin >> decisao;
	
	}
	std::cout << "\nMuito obrigado, e volte sempre ;) \n";
		
	system("pause");
}