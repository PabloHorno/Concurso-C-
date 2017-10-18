#include "Bathroom.h"



Bathroom::Bathroom(unsigned espacio)
{
	nodes.clear();
	nodes.push_back(Stall(espacio));
}


void Bathroom::expandir()
{
	Stall padre = get_padre();
	Stall derecha, izquierda;
	if (padre.espacio_libre % 2 == 0) {
		derecha.espacio_libre = padre.espacio_libre / 2;
		izquierda.espacio_libre = padre.espacio_libre / 2 - 1;
	}
	else {
		derecha.espacio_libre = padre.espacio_libre / 2;
		izquierda.espacio_libre = padre.espacio_libre / 2;
	}	

}

Stall Bathroom::get_padre()
{
	for (auto padre : nodes) 
		if (padre.visitado == false)
			return padre;
		else
			return Stall();
}

std::pair<unsigned, unsigned> Bathroom::get_min_max()
{
	std::pair<unsigned, unsigned> min_max;
	std::vector<unsigned> espacios;

	for (auto node : nodes)
		if (!node.visitado)
			espacios.push_back(node.espacio_libre);

	min_max.first = *std::max_element(espacios.begin(), espacios.end());
	min_max.first = *std::min_element(espacios.begin(), espacios.end());
	return min_max;
}
