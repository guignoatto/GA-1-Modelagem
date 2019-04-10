#include "GameLife.h"



GameLife::GameLife()
{
	srand(time(0));
}

GameLife::~GameLife()
{
}

void GameLife::tamanho(int x1, int y1)
{
	//cria a matriz
	matrix = new int*[x1 + 2] ;
	for (int i = 0; i < x1 + 2; ++i) {
		
			matrix[i] = new int[y1 + 2];		
			
	}

	Nmatrix = new int*[x1 + 2];
	for (int i = 0; i < x1 + 2; ++i) {

		Nmatrix[i] = new int[y1 + 2];

	}

	x = x1 + 1;
	y = y1 + 1;
	


}

void GameLife::teste1()
{for (int i = 0; x + 1 > i; i++)//carrega o "pixel" (x)
	{
		for (int j = 0; y + 1 > j; j++)//(y)
		{//randomiza a matriz
			rand1 = rand() % 100;
			if (i == 0 || j == 0 || i == x  || j == y ) {
				*(*(matrix + i) + j) = 0;
				*(*(Nmatrix + i) + j) = 0;
			}
			else if (rand1  > 45) {
				*(*(matrix + i) + j) = 2;
				*(*(Nmatrix + i) + j) = 2;
			}
			else{
				*(*(matrix + i) + j) = 1;
				*(*(Nmatrix + i) + j) = 1;
			}
			std::cout << *(*(matrix + i) + j);
		}
		std::cout << "\n";
	}
}

void GameLife::teste2()
{
	for (int i = 0; x > i; i++)//carrega o "pixel" (x)
	{
		for (int j = 0; y > j; j++)//(y)
		{
			std::cout << *(*(matrix + i) + j);
		}
		std::cout << "\n";
	}
}

void GameLife::gerarMapa()
{
	carrega_ciclo();
	transfere();
	for (int i = 0; x + 1 > i; i++)//carrega o "pixel" (x)
	{
		for (int j = 0; y + 1 > j; j++)//(y)
		{
			std::cout << *(*(matrix + i) + j);

		}
		std::cout <<"\n";
	}

}

void GameLife::carrega_ciclo()
{
	for (int i = 1; x > i; i++)//carrega o "pixel" (x)
	{
		for (int j = 1; y  > j; j++)//(y)
		{
			vizinhos = 0;

			for (int xi = -1; xi < 2; xi++) {//testa os vizinhos
				for (int yi = -1; yi < 2; yi++) {
					//Regra
					if (xi == 0 && yi == 0) {//caso vá contar o próprio número 

					}


						else if (*(*(matrix + i + xi) + j + yi) > 0) {// Se for > 0, significa que há vizinho, e se for 1, esse vizinho será contabilizado 
							if (*(*(matrix + i + xi) + j + yi) == 1) {

								vizinhos++;
								testa_vizinhos(i, j);
							}
						}

						

						else if (xi == - 1 && yi == 0) {//CIMA
							if (*(*(matrix + x - 1) + j + yi) == 1) {
							vizinhos++;
							testa_vizinhos(i, j);
							}
						}
						else if (xi == 0 && yi == 1) {//DIREITA
							if (*(*(matrix + i + xi) + y - j) == 1) {
							vizinhos++;
							testa_vizinhos(i, j);
							}
						}
						else if (xi == -1 && yi == 0) {//BAIXO
							if (*(*(matrix + x - i) + j + yi) == 1) {
							vizinhos++;
							testa_vizinhos(i, j);
							}
						}
						else if (xi == 0 && yi == -1) {//ESQUERDA
							if (*(*(matrix + i + xi) + y - 1) == 1) {
							vizinhos++;
							testa_vizinhos(i, j);
							}
						}
	
						else if (xi == -1 && yi == -1) {//SUPERIOR ESQUERDA

						
							if (*(*(matrix + x - 1) + j + yi) > 0) {
								if (*(*(matrix + x - 1) + j + yi) == 1) {
									vizinhos++;
									testa_vizinhos(i, j);
								}
							}
							else if (*(*(matrix + i + xi) + y - 1) > 0) {
								if (*(*(matrix + i + xi) + y - 1) == 1) {
									vizinhos++;
									testa_vizinhos(i, j);
								}
							}
							else {
								if (*(*(matrix + x - 1) + y - 1) == 1) 
								{
									vizinhos++;
									testa_vizinhos(i, j);
								}
							}
						
						}
						else if (xi == -1 && yi == 1) {//SUPERIOR DIREITA
									
							if (*(*(matrix + x - 1) + j + yi) > 0) {
								if (*(*(matrix + x - 1) + j + yi) == 1) {
									vizinhos++;
									testa_vizinhos(i, j);
								}
							}

							else if (*(*(matrix + i + xi) + y - j) > 0) {
								if (*(*(matrix + i + xi) + y - j) == 1) {
									vizinhos++;
									testa_vizinhos(i, j);
								}
								else {
									if (*(*(matrix + x - 1) + y - j) == 1) {
										vizinhos++;
										testa_vizinhos(i, j);
									}
								}
							}
						}
					

						else if (xi == 1 && yi == 1) {//INFERIOR DIREITA


							if (*(*(matrix + x - i) + j + yi) > 0) {
								if (*(*(matrix + x - i) + j + yi) == 1) {
									vizinhos++;
									testa_vizinhos(i, j);
								}
							}
							else if (*(*(matrix + i + xi) + y - j) > 0) {
								if (*(*(matrix + i + xi) + y - j) == 1) {
									vizinhos++;
									testa_vizinhos(i, j);
								}
							}
							else {
								if (*(*(matrix + x - i) + y - j) == 1) {
									vizinhos++;
									testa_vizinhos(i, j);
								}
							}
						}
				


						else if (xi == 1 && yi == -1) {//INFERIOR ESQUERDA
	
						
							if (*(*(matrix + x - i) + j + yi) > 0) {
								if (*(*(matrix + x - i) + j + yi) == 1) {
									vizinhos++;
									testa_vizinhos(i, j);
								}
							}
							else if (*(*(matrix + i + xi) + y - 1) > 0) {
								if (*(*(matrix + i + xi) + y - 1) == 1) {
									vizinhos++;
									testa_vizinhos(i, j);
								}
							}
							else {
								if (*(*(matrix + x - i) + y - 1) == 1) {
									vizinhos++;
									testa_vizinhos(i, j);
								}
							}
						
						}
					

				}
			}

		}
	}
}

void GameLife::testa_vizinhos(int x, int y)
{
	if (vizinhos < 3 && *(*(matrix + x) + y) == 1) {
		*(*(Nmatrix + x) + y) = 2;
	}
	else if (vizinhos > 4 && *(*(matrix + x) + y) == 2) {
		*(*(Nmatrix + x) + y) = 1;
	}

}

void GameLife::geraChao(Chao chao)
{

}

void GameLife::transfere()
{
	for (int i = 0; x + 1 > i; i++)//carrega o "pixel" (x)
	{
		for (int j = 0; y + 1 > j; j++)//(y)
		{
			*(*(matrix + i) + j) = *(*(Nmatrix + i) + j);

		}
		std::cout << "\n";
	}

}
