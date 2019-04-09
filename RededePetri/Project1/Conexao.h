#pragma once
#include "Lugar.h"

class Conexao
{
public:
	Conexao();
	Conexao(Lugar *lugar, int peso, bool ehEntrada, bool ehArcoInib);
	~Conexao();


	bool eentrada();
	bool einibidor();

	bool entrada;
	bool inibidor;
	int peso;
	Lugar *lugar;
};

