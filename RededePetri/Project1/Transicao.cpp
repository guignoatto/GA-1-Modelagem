#include "Transicao.h"



Transicao::Transicao()
{
}

Transicao::Transicao(int id)
{
	this->id = id;
}


Transicao::~Transicao()
{
}


void Transicao::inserirConexao(Conexao * conn)
{

	
		if (conn->eentrada()) //Testa se a conexao é de entrada
		{
			if (conn->einibidor())  //Testa se conexão é inibidora
				conEntradaInib.push_back(conn);
			else
				conEntrada.push_back(conn);
		}
		else
		{
			conSaida.push_back(conn);
		}
	
}

bool Transicao::estaHabilitado()
{
	if (conEntrada.empty()) //Testa se existem conexoes de entrada
	{
		return false;
	}
	else 
	{ /*saber quantas conexoes de entrada tem
		saber o peso das conexoes de entrada
		saber se os lugares de onde as conexoes vem tem tokens o suficiente para suprir o peso
		se todos os lugares tiverem tokens o suficiente = true
		se não = false*/
	  
			int estaInibindo = 0;
			for (int i = conEntradaInib.size() - 1; i >= 0; i--) { //Testa se tem token dentro do arco inibidor
				if (conEntradaInib[i]->lugar->listaDeTokens.size() > 0) {
					estaInibindo += 1;
				}
			}
			if (estaInibindo == 0) { //Se estaInibindo é igual a zero quer dizer que nenhum arco está inibindo
				int estaAtiva = 0; 
				int i = conEntrada.size() - 1;
				for (i; i >= 0; i--) { //Testa se a quantidade de tokens do lugar é suficiente
					if (conEntrada[i]->lugar->listaDeTokens.size() >= conEntrada[i]->peso) {
						estaAtiva += 1;
					}
				}
				if (estaAtiva == conEntrada.size()) //Se todas os lugares tiverem tokens o suficiente a transicao esta ativa
					return true;
				else
					return false;
			}
			else { //Se estaInibindo é maior que 0, entao esta inibindo essa transicao
				std::cout << "Arco inibidor está inibindo Transicao de id = " << this->id << " de progredir" << std::endl;
				return false;
 			}
		}
		
	
}
