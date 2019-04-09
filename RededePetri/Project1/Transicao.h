#pragma once
#include "Lugar.h"
#include "Conexao.h"
class Transicao
{
public:
	Transicao();
	Transicao(int id);
	~Transicao();


	bool enabled;
	std::vector<Conexao*> conEntrada;
	std::vector<Conexao*> conEntradaInib;
	std::vector<Conexao*> conSaida;

	void inserirConexao(Conexao* conn);
	bool estaHabilitado();//completar

	int id;
};

