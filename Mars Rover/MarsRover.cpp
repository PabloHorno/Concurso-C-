#include "MarsRover.h"



MarsRover::MarsRover()
{
}

double MarsRover::calculoRadio(double distanciaBase, double angulo)
{
	/*if (angulo == 0)
		return 0;*/
	return distanciaBase / sin(angulo * PI / 180);
}

void MarsRover::posicionNuevaDireccion(double distanciaBase, double distancia, double anguloDeGiro, Vector3D<double> & posicion)
{
	bool giroIzquierda = false;
	if (anguloDeGiro < 0) {
		giroIzquierda = true;
		anguloDeGiro = -anguloDeGiro;
	}
	else if (anguloDeGiro == 0)
	{
		posicion.Y = distancia;
	}

	double radio = this->calculoRadio(distanciaBase, anguloDeGiro);
	/*if (radio == 0)
		posicion.Z = 0;
	else*/
	posicion.Z = distancia * 360 / (2 * PI*radio);

	if (giroIzquierda) {
		posicion.X = cos(posicion.Z*PI / 180)*radio - radio;
		posicion.Y = sin(posicion.Z*PI / 180)*radio;
		posicion.Z = 360 - posicion.Z;
	}
	else {
		posicion.X = radio - cos(posicion.Z*PI / 180)*radio;
		posicion.Y = sin(posicion.Z*PI / 180)*radio;
	}
	while (posicion.Z < 0)
		posicion.Z += 360;
}

Vector3D<double> MarsRover::calculaPosicionFinal(double distanciaBase, unsigned numMovimientos, std::vector<std::pair<double, double>> movimientos)
{
	Vector3D<double> posicionFinal(0, 0, 0);
	for (auto movimiento : movimientos) {
		Vector3D<double> posicionNueva;
		double distancia = movimiento.first;
		double anguloDeGiro = movimiento.second;

		this->posicionNuevaDireccion(distanciaBase, distancia, anguloDeGiro, posicionNueva);

		posicionFinal = posicionFinal + posicionNueva.rotacion(posicionFinal.Z);
	}
	if (posicionFinal.Z >= 360)
		posicionFinal.Z = fmod(posicionFinal.Z, 360);
	return posicionFinal;
}


MarsRover::~MarsRover()
{
}
