#include "Lugar.h"



Lugar::Lugar()
{
}

Lugar::Lugar(int id)
{
	this->id = id;
}


Lugar::~Lugar()
{
}

Token * Lugar::getToken(int id)
{
	return listaDeTokens[id];
}

void Lugar::adicionarToken(Token *token)
{
	listaDeTokens.insert(listaDeTokens.begin(), token);
	empty = false;
}

bool Lugar::vazio()
{
	empty = listaDeTokens.empty();
	return empty;
}


