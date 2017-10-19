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
		int num_monedas;
		cin >> tam_rejilla;
		maquina.set_filas_columnas(tam_rejilla);
		cout << maquina.num_filas*maquina.num_columnas;
		maquina.get_precios(cin);
		cout << "PRECIOS" << endl;
		for (auto filaprecios : maquina.precios) {

			for (auto precio : filaprecios)
				cout << precio << " ";
			cout << endl;
		}
		cout << endl;

		cin >> seleccion >> num_monedas;
		vector<int> monedas;
		for (int i = 0; i < num_monedas; i++)
		{
			int moneda;
			cin >> moneda;
			maquina.monedas.push_back(moneda);
		}

		maquina.precio = maquina.precio_producto(seleccion);
		cout << "PRECIO DEL PRODUCTO (" << seleccion << ") " << maquina.precio << endl;
		cout << maquina.cambio() << endl;
		if (maquina.cambio() < 0)
			cout << "MISSING " << -maquina.cambio() << endl;
		else
		{
			cout << "CHANGE ";
			for (auto cambio : maquina.devolucion_monedas())
				cout << cambio << " ";
			cout << endl;
		}
	}
}