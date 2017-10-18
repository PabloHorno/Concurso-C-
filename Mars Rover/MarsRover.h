#pragma once
#include <math.h>
#include <vector>
#include "Vector.h"
#define PI 3.14159265359

class MarsRover
{
public:
	MarsRover();
	double calculoRadio(const double distanciaBase, const double anguloDeGiro);
	void posicionNuevaDireccion(double distanciaBase, double distancia, double anguloDeGiro, Vector3D<double> & posicion);
	Vector3D<double> calculaPosicionFinal(double distanciaBase, unsigned numMovimientos, std::vector<std::pair<double,double>> movimientos);
	~MarsRover();
};

