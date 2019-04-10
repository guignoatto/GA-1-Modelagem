#pragma once
#include "Mapa.h"
#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>
class GameLife: public Mapa{
public:
	
	GameLife();
	~GameLife();
	Mapa aux;
	
	void tamanho(int x1, int y1);
	void teste1();
	void teste2();
	void gerarMapa();
	void carrega_ciclo();
	void testa_vizinhos(int x, int y);
	void geraChao(Chao chao);
	void transfere();
protected:
	int x, y, **matrix, **Nmatrix, vizinhos, rand1;

};

