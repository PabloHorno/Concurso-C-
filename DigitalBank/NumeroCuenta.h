#pragma once
#include<map>
#include<string>
#include <iostream>

using namespace std;

class NumeroCuenta
{
public:
	NumeroCuenta();
	~NumeroCuenta();
	string codigo_pais;
	int checksum;
	string id_cuenta;
	string numero_cuenta_completo;
	bool validar(bool = false);
	void crear_numero();
};

