#include "Token.h"



Token::Token()
{
}


Token::~Token()
{
}

Token::Token(int id)
{
	this->id = id;
}

void Token::printID()
{
	std::cout << "id: " << id << std::endl;
}
