#include<iostream>
#include<fstream>
#include<string>
#include "Banco.h"

using namespace std;
bool comparar(Transferencia a, Transferencia b) { return (a.tiempo < b.tiempo); };
void main()
{
	ifstream inputs("inputs/level2/level2-2.txt");
	ofstream outputs("inputs/level2/level2-2-out.txt");
	Banco banco;
	int numero_cuentas_banco, numero_transferencias;

	inputs >> numero_cuentas_banco;
	for (int i = 0; i < numero_cuentas_banco; i++)
	{
		Cuenta nueva_cuenta;
		inputs >> nueva_cuenta.nombre >> nueva_cuenta.numero_cuenta.numero_cuenta_completo >> nueva_cuenta.balance >> nueva_cuenta.limite_operacion;

		if (nueva_cuenta.numero_cuenta.validar() == true)
		{
			banco.cuentas.push_back(nueva_cuenta);
			cout << "BUENA: " << nueva_cuenta.numero_cuenta.numero_cuenta_completo << endl;
			nueva_cuenta.numero_cuenta.validar(true);
			}
	}
	inputs >> numero_transferencias;

	for (int i = 0; i < numero_transferencias; i++)
	{
		Transferencia nueva_transferencia;
		inputs >> nueva_transferencia.cuenta_origen.numero_cuenta.numero_cuenta_completo >> nueva_transferencia.cuenta_destino.numero_cuenta.numero_cuenta_completo >> nueva_transferencia.cantidad >> nueva_transferencia.tiempo;
		if (nueva_transferencia.cuenta_origen.numero_cuenta.validar() && nueva_transferencia.cuenta_destino.numero_cuenta.validar())
			banco.transferencias.push_back(nueva_transferencia);
	}

	sort(banco.transferencias.begin(), banco.transferencias.end(), comparar);

	banco.realizar_transferencias_num_cuenta();


	cout << banco.cuentas.size() << endl;
	for (auto cuenta : banco.cuentas)
	{
		cout << cuenta.nombre << " " << cuenta.balance << endl;
	}

	system("pause");
}