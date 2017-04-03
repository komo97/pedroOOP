// pedroOOP.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

#define print(i) (std::cout<<i<<std::endl)

int main()
{
	//el punto de estos dos loops es demostrar si se hace el incremento hasta el final del loop.
	//si x regresa 9 en post y en su primera ejecución en mid regresa 1 entonces el incremento se hace al inicio, 
	//si regresa 10 y su primer ciclo es 0 se hace hasta el final.
	int x = 0;
	for (; x < 10; ++x)
	{
		print(x << " mid");
	}
	print(x << " post");
	//El resultado es 0 en la primera ejecución de mid y 10 en la de post. Por lo tanto se hace hasta el final.
}

