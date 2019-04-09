#pragma once
#include <vector>
#include "Token.h"
class Lugar
{
public:
	Lugar();
	Lugar(int id);
	~Lugar();

	bool empty;
	std::vector<Token*> listaDeTokens;

	Token * getToken(int id);
	void adicionarToken(Token *token);
	bool vazio();

	int id;

};

