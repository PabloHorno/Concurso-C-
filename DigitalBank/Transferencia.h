#pragma once
#include<string>
#include<vector>
#include "Cuenta.h"

using namespace std;
class Transferencia
{
public:
	Transferencia();
	~Transferencia();
	Cuenta cuenta_origen;
	Cuenta cuenta_destino;

	string persona_origen;
	string persona_destino;
	int cantidad;
	long long int tiempo;
};

