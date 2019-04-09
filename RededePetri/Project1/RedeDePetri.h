#pragma once
#include "Lugar.h"
#include "Transicao.h"
class RedeDePetri
{
public:


	std::vector<Lugar*> listaLugar;
	std::vector<Transicao*> listaTransicao;

	RedeDePetri();
	~RedeDePetri();

	void usuarioCriaLugar();
	void usuarioCriaTransicao();
	void usuarioCriaConexaoDeEntrada();

	void Rede();
	void inserirTransicao(Transicao* transicao);
	void inserirLugar(Lugar* lugar);
	Transicao* getTransicao(int id);
	Lugar* getLugar(int id);
	void execCycle();

};