/*
Google Code Jam 17 - Problem A. Oversized Pancake Flipper
Purpose: Calculate the minimun turns needed on a PancakeLine.

@author Pablo Horno
@version 1.0 14/08/17
*/
#include "PancakeLine.h"

PancakeLine::PancakeLine(std::string str, unsigned num)
{
	linea = str;
	tam_voltear = num;
}

bool PancakeLine::es_solucion()
{
	for (auto c : linea)
		if (c != '+')
			return false;
	return true;
}
size_t PancakeLine::next()
{
	size_t pos = linea.find('-');
	if (pos == std::string::npos)
		return std::string::npos;
	else if (linea.size() - pos < tam_voltear)
		return std::string::npos;
	else
		return pos;
}
void PancakeLine::voltear(size_t pos)
{
	if (pos == std::string::npos)
		return;

	for (unsigned i = 0; i < tam_voltear; i++)
		linea[pos + i] == '+' ? linea[pos + i] = '-' : linea[pos + i] = '+';
}
std::string PancakeLine::solucion() {

	unsigned num = 0;
	while (!es_solucion())
	{
		num++;
		size_t pos = next();
		if (pos != std::string::npos)
			voltear(pos);
		else
			return "IMPOSSIBLE";
	}
	return std::to_string(num);
}