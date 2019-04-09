#include "RedeDePetri.h"



RedeDePetri::RedeDePetri()
{
}


RedeDePetri::~RedeDePetri()
{
}



void RedeDePetri::inserirTransicao(Transicao * transicao)
{
	listaTransicao.push_back(transicao);
}

void RedeDePetri::inserirLugar(Lugar * lugar)
{
	listaLugar.push_back(lugar);
}

Transicao * RedeDePetri::getTransicao(int id)
{
	if (listaTransicao.size() > 0) {
		for (int i = listaTransicao.size() - 1; i >= 0; i--)
		{
			if (listaTransicao[i]->id == id) {
				return listaTransicao[i];
			}
		}
		std::cout << "ID de Transição inválido..." << std::endl;
		system("pause");
		return listaTransicao[0];
	}
	else {
		std::cout << "Rede sem Transições..." << std::endl;
		system("pause");
		return listaTransicao[0];
	}
}


void RedeDePetri::execCycle()
{
	std::vector <Transicao*> transicoes_testadas;
	for (int z = listaLugar.size() - 1; z >= 0; z--) { //Feedback para o usuario
		std::cout << "\n\n Lugar " << listaLugar[z]->id << " tem " << listaLugar[z]->listaDeTokens.size() << " token(s) antes do ciclo" << std::endl;
	}
	std::vector <Transicao*> transicoesAtivas;
	for (int vetor = listaTransicao.size()-1; vetor >= 0; vetor--) { //Testa todas as transicoes da Rede para ver se estão ativas
		if (listaTransicao[vetor]->estaHabilitado()) {
			transicoesAtivas.push_back(listaTransicao[vetor]); //As que estao são armazenadas em um vetor
		}
	}
		while (transicoes_testadas.size() != transicoesAtivas.size()) { 
			int x = rand () % transicoesAtivas.size();
			if (std::find(transicoes_testadas.begin(), transicoes_testadas.end(), transicoesAtivas[x]) == transicoes_testadas.end()) { //Testa se a transicao ja foi testada
				if (transicoesAtivas[x]->estaHabilitado()) { //Se transicao estiver ativa
					std::cout << "\n\n Transicao " << transicoesAtivas[x]->id << " foi executada" << std::endl;
					int u = transicoesAtivas[x]->conSaida.size() - 1;
					for (; u >= 0; u--) { //Adicionando token nos lugares de saida
						int qualToken = transicoesAtivas[x]->conEntrada[0]->lugar->listaDeTokens.size() - 1;
						Token * token1 = transicoesAtivas[x]->conEntrada[0]->lugar->listaDeTokens[qualToken];
						transicoesAtivas[x]->conSaida[u]->lugar->adicionarToken(token1);
					}
					int y = transicoesAtivas[x]->conEntrada.size() - 1;
					for (; y >= 0; y--) { //Retirando tokens dos lugares de entrada
						for (int p = transicoesAtivas[x]->conEntrada[y]->peso; p > 0; p--) {
							transicoesAtivas[x]->conEntrada[y]->lugar->listaDeTokens.pop_back();
						}
					}
				}
				transicoes_testadas.push_back(transicoesAtivas[x]); //Adiciona a transicao no vetor das que ja foram testadas
			}
		}
	
	for (int x = listaLugar.size() - 1; x >= 0; x--) { //Feedback para o usuario
		std::cout << "\n\n Lugar " << listaLugar[x]->id << " tem " << listaLugar[x]->listaDeTokens.size() << " token(s) depois do ciclo" << std::endl;
	}
}
Lugar * RedeDePetri::getLugar(int id)
{
	if (listaLugar.size() > 0) {
		for (int i = listaLugar.size() - 1; i >= 0; i--)
		{
			if (listaLugar[i]->id == id) {
				return listaLugar[i];
			}
		}
		std::cout << "ID de Lugar inválido..." << std::endl;
		system("pause");
		return listaLugar[0];
	}
	else {
		std::cout << "Rede sem Transições..." << std::endl;
		system("pause");
		return listaLugar[0];
	}

}
void RedeDePetri::usuarioCriaLugar()
{
	int x = 1;
	int resposta;
	while (x == 1) {
		std::cout << "Quer criar um lugar?" << std::endl << "1 = Sim      2 = Não" << std::endl;
		std::cin >> resposta;
		if (resposta == 1) {
			std::cout << "Escolha a id do lugar (lembre de não repetir IDs)" << std::endl;
			std::cin >> resposta;
			this->inserirLugar(new Lugar(resposta));
		}
		else {
			x = 0;
		}
	}
}

void RedeDePetri::usuarioCriaTransicao()
{
	int x = 1;
	int resposta;
	while (x == 1) {
		std::cout << "Quer criar uma transicao?" << std::endl << "1 = Sim      2 = Não" << std::endl;
		std::cin >> resposta;
		if (resposta == 1) {
			std::cout << "Escolha a id da transicao (lembre de não repetir IDs)" << std::endl;
			std::cin >> resposta;
			this->inserirTransicao(new Transicao(resposta));
		}
		else {
			x = 0;
		}
	}
}

void RedeDePetri::usuarioCriaConexaoDeEntrada()
{
	int x = 1, resposta, idLugar, idTransicao, peso;
	while (x == 1) {
		std::cout << "\nQuer criar uma conexão?" << std::endl << "1 = Sim      2 = Não" << std::endl;
		std::cin >> resposta;
		if (resposta == 1) {
			std::cout << "De entrada, saida ou arco inibidor?" << std::endl << "1 = Entrada    2 = Saída    3 = Arco Inibidor" << std::endl;
			std::cin >> resposta;
			if (resposta == 1) {
				std::cout << "A conexão sai de qual lugar? (Insira a ID do lugar)" << std::endl;
				std::cin >> idLugar;
				std::cout << "Qual o peso da conexao?" << std::endl;
				std::cin >> peso;
				std::cout << "A conexão vai para qual transição? (Insira a ID da transicao)" << std::endl;
				std::cin >> idTransicao;
				getTransicao(idTransicao)->inserirConexao(new Conexao(getLugar(idLugar), peso, true, false));
			}
			else if (resposta == 2) {
				std::cout << "De qual transicao ela sai? (Insira a ID da transicao)" << std::endl;
				std::cin >> idTransicao;
				std::cout << "Qual o peso da conexao?" << std::endl;
				std::cin >> peso;
				std::cout << "A conexão vai para qual lugar? (Insira a ID do lugar)" << std::endl;
				std::cin >> idLugar;
				getTransicao(idTransicao)->inserirConexao(new Conexao(getLugar(idLugar), peso, false, false));
			}
			else if (resposta == 3) {
				std::cout << "De entrada, saida ou arco inibidor?" << std::endl << "1 = Entrada    2 = Saída    3 = Arco Inibidor" << std::endl;
				std::cin >> resposta;
				if (resposta == 1) {
					std::cout << "O arco inibidor sai de qual lugar? (Insira a ID do lugar)" << std::endl;
					std::cin >> idLugar;
					std::cout << "Qual o peso do arco inibidor?" << std::endl;
					std::cin >> peso;
					std::cout << "O arco inibidor vai para qual transição? (Insira a ID da transicao)" << std::endl;
					std::cin >> idTransicao;
					getTransicao(idTransicao)->inserirConexao(new Conexao(getLugar(idLugar), peso, true, true));
				}

			}
		}
		else if (resposta == 2) {
			int token = 1;
			int idToken;
			while (token == 1) {
				std::cout << "\nQuer adicionar token?    1 = Sim     2 = Não" << std::endl;
				std::cin >> token;
				if (token == 1) {
					std::cout << "Qual a ID do token? (Lembre de não repetir IDs)" << std::endl;
					std::cin >> idToken;
					std::cout << "Em qual lugar esse token vai? (Passar ID do lugar)" << std::endl;
					std::cin >> resposta;
					getLugar(resposta)->adicionarToken(new Token(idToken));
				}
				else if (token == 2) {
					token = 0;
				}
			}
			int ciclo = 1;
			while (ciclo == 1) {
				std::cout << "\nQuer executar o ciclo?  1 = Sim   2 = Não\n";
				std::cin >> resposta;
				if (resposta == 1) {
					execCycle();
				}
				else if (resposta == 2) {
					std::cout << "\n\n Esc para fechar o programa \n";
					ciclo = 2;
					x = 0;
				}
			}
		}
	}
}

void RedeDePetri::Rede() { //Func para não precisar escrever nada no Source
	usuarioCriaLugar();
	usuarioCriaTransicao();
	usuarioCriaConexaoDeEntrada();
}
