// Comprobación if.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


int main()
{
	int x = 0, y = 0;

	//Si ambas variables se imprimen y son 0, la comprobación se ejecuta de izquierda a derecha y solamente
	//pregunta hasta que encuentra un true. 
	//Si la comprobación no se ejecuta entonces se ejecuta de derecha a izquierda.
	//Si ambas preguntas son realizadas entonces se imprimiran x:1 y:0.
	if (x == y || (++x == y))
		printf_s("X:%d Y:%d", x, y);

	//Si Y se imprime como 1 la operación and realiza todas las preguntas antes de decidir el resultado, 
	//a pesar de que la parte en la izquierda retorne falso.
	if (1 == y && ++y == 2);
	printf_s("\nY:%d", y);

    return 0;
}


