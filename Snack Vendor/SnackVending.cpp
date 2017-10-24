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
		for (int i = valor_monedas.size() - 1; i >= 0; i--)
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
	letra_maxima = *ultima_casilla.substr(0, 1).c_str();
	this->num_columnas = stoi(ultima_casilla.substr(1, ultima_casilla.size()));

	cout << "Filas: " << letra_maxima << " Columnas: " << num_columnas << endl;
}

void SnakVending::get_productos(istream & cin)
{
	for (char letra = 'A'; letra <= letra_maxima; letra++)
	{
		for (int j = 0; j < num_columnas; j++)
		{
			string code;
			code += letra;
			code += to_string(j + 1);
			int precio;
			cin >> precio;
			productos[code] = Producto(precio);
		}
	}
	for (char letra = 'A'; letra <= letra_maxima; letra++)
	{
		for (int j = 0; j < num_columnas; j++)
		{
			string code; int stock;
			code += letra;
			code += to_string(j + 1);
			cin >> stock;
			productos[code].strock = stock;
		}
	}

}

int SnakVending::revenue()
{
	int revenue = 0;
	for (auto cliente : clientes)
	{
		if (productos[cliente].strock > 0) {
			revenue += productos[cliente].precio;
			productos[cliente].strock--;
		}
	}
	return revenue;
}

int SnakVending::tiempo_entre_casillas()
{
	pair<char, int> posicion_actual = code_to_pos(inicio);
	pair<char, int> objetivo = code_to_pos(llegada);
	int dif_col = 0, dif_fil = 0, tiempo = -1;
	do
	{
		if (dif_fil != 0)posicion_actual.first += dif_fil / abs(dif_fil);
		if (dif_col != 0)posicion_actual.second += dif_col / abs(dif_col);

		dif_fil = objetivo.first - posicion_actual.first;
		dif_col = objetivo.second - posicion_actual.second;

		tiempo++;

	} while (dif_col != 0 || dif_fil != 0);
	return tiempo;
}

pair<char, int> SnakVending::code_to_pos(string code)
{
	return pair<char, int>(*code.substr(0, 1).c_str(), stoi(code.substr(1, code.size())));
}


SnakVending::~SnakVending()
{
}
