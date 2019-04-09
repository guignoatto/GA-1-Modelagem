#pragma once
#include <iostream>
class Token
{
public:
	Token();
	~Token();

	Token(int id);
	void printID();
	int id;
};