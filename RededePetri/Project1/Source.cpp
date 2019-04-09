#include "RedeDePetri.h"
#include <iostream>
#include <time.h>
using namespace std;

int main() 
{
	srand(time(NULL));
	setlocale(LC_ALL, "Portuguese");

	RedeDePetri rede1;
	rede1.Rede();
	
	
	

	system("pause");

}