// Calendario.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

int main()
{
	time_t y,m,d,h,mi,s;
	std::cin >> y >> m >> d >> s;
	mi = s / 60;
	s %= 60;
	h = mi / 60;
	mi %= 60;
	d += h / 24;
	h %= 24;
	while (((m % 12) <= 6 && !(m % 2) && d > 30) || /*Meses non primera mitad del año, 31 dias*/
		((m % 12) > 6 && (m % 2) && d > 30) || /*Meses par segunda mitad del año, 31 dias*/
		((m % 12) == 1 && d > 28) || /*Feberero no bisiesto.*/
		((m % 12) == 1 && (y % 4) && d > 27) || /*Febrero bisiesto.*/
		d > 29) /*más de 30 dias en cualquier otro caso.*/
	{
		if (((m % 12) <= 6 && !(m % 2)) || ((m % 12) > 6 && (m % 2)))
		{
			d -= 31;
			m += 1;
		}
		else if ((m % 12) == 1)
		{
			d -= 29;
			m += 1;
		}
		else if ((m % 12) == 1 && (y % 4))
		{
			d -= 28;
			m += 1;
		}
		else
		{
			d -= 30;
			m += 1;
		}
		y += m / 12;
		m = m % 12;
	}
	y += m / 12;
	m = m % 12;
	std::cout << "Año: " << y << " Mes: " << m + 1 << " Dia: " << d << " Hora: " << h << " Minuto: " << mi << " Segundo: " << s << std::endl;
	system("pause");
    return 0;
}

