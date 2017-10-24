#include <iostream>
#include <iomanip>
#include <math.h>
#include <vector>
#include <algorithm>
#include <string>
#include "SnackVending.h"
using namespace std;

void main()
{

	while (true)
	{
		SnakVending maquina;
		string tam_rejilla,seleccion;
		int num_monedas, num_clientes;
		cin >> tam_rejilla;
		maquina.set_filas_columnas(tam_rejilla);

		cin >> maquina.inicio >> maquina.llegada;
		cout << "Tiempo entre casillas " << maquina.inicio << " " << maquina.llegada << " es de " << maquina.tiempo_entre_casillas() << endl;

		//maquina.get_productos(cin);
		
		/*cin >> num_clientes;
		for (int i = 0; i < num_clientes; i++)
		{
			string code;
			cin >> code;
			maquina.clientes.push_back(code);
		}

		cout << maquina.revenue();
		/*
		cout << maquina.cambio() << endl;
		if (maquina.cambio() < 0)
			cout << "MISSING " << -maquina.cambio() << endl;
		else
		{
			cout << "CHANGE ";
			for (auto cambio : maquina.devolucion_monedas())
				cout << cambio << " ";
			cout << endl;
		}*/
	}
}