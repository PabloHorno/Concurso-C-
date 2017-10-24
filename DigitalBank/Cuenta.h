#pragma once
#include<iostream>
#include<string>
#include<vector>
#include "NumeroCuenta.h"
using namespace std;

class Cuenta
{
public:
	Cuenta();
	~Cuenta();
	string nombre;
	NumeroCuenta numero_cuenta;
	int balance;
	int limite_operacion;
};

