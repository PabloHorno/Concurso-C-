#include "SnackVending.h"



SnakVending::SnakVending()
{
}

int SnakVending::cambio()
{
	int suma = 0;
	for (auto moneda : monedas)
		suma += moneda;
	return suma - precio;
}

vector<int> SnakVending::devolucion_monedas()
{
	vector<int> cambio(8, 0);
	int devolucion = this->cambio();
	while (devolucion != 0)
	{
		for (int i = valor_monedas.size()-1; i >=0; i--)
		{
			if (valor_monedas.at(i) <= devolucion)
			{
				devolucion -= valor_monedas.at(i);
				cambio.at(i)++;
				break;
			}
		}
	}
	return cambio;
}

void SnakVending::set_filas_columnas(string ultima_casilla)
{
	auto pos = code_to_pos(ultima_casilla);
	this->num_filas = pos.first;
	this->num_columnas = pos.second;
	cout << "Filas: " << num_filas << " Columnas: " << num_columnas<< endl;
}

int SnakVending::precio_producto(string code)
{
	auto pos = code_to_pos(code);
	return precios[pos.first-1][pos.second-1];
}

pair<int, int> SnakVending::code_to_pos(string code)
{
	pair<int, int> posicion;
	posicion.first = ((int)code[0] - (int)(char)'A' + 1);
	code.erase(0, 1);
	posicion.second = stoi(code);
	return posicion;
}

void SnakVending::get_precios(istream & cin)
{
	for (int i = 0; i < num_filas; i++)
	{
		precios.push_back(vector<int>());
		for (int j = 0; j < num_columnas; j++)
		{
			int precio;
			cin >> precio;
			precios[i].push_back(precio);
		}
	}
}


SnakVending::~SnakVending()
{
}
