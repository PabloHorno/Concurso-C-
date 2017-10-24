#pragma once
#include<iostream>
#include<vector>
#include<algorithm>
#include"Cuenta.h"
#include"Transferencia.h"
using namespace std;
class Banco
{
public:
	Banco();
	~Banco();
	vector<Cuenta> cuentas;
	vector<Transferencia> transferencias;
	void realizar_transferencia_persona(Transferencia transferencia);
	void realizar_transferencia_num_cuenta(Transferencia transferencia);
	void realizar_transferencias_num_cuenta();
};

