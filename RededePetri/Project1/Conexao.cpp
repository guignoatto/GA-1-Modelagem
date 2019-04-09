#include "Conexao.h"



Conexao::Conexao()
{
}

Conexao::Conexao(Lugar *lugar, int peso, bool ehEntrada, bool ehArcoInib)
{
	this->lugar = lugar;
	this->entrada = ehEntrada;
	this->inibidor = ehArcoInib;
	this->peso = peso;
}

Conexao::~Conexao()
{
}


bool Conexao::eentrada() 
{
	return entrada;
}

bool Conexao::einibidor()
{
	return inibidor;
}
