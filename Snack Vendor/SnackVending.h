#pragma once
#include<vector>
#include<iostream>
#include<string>
using namespace std;
class SnakVending
{
public:
	SnakVending();
	~SnakVending();
	vector<int> valor_monedas = { 1, 2, 5, 10, 20, 50, 100, 200 };

	int precio;
	vector<vector<int>> precios;
	vector<int>monedas;
	int num_filas = 0, num_columnas = 0;
	int cambio();
	vector<int> devolucion_monedas();
	void set_filas_columnas(string ultima_casilla);
	int precio_producto(string code);
	pair<int, int> code_to_pos(string code);
	void get_precios(istream &cin);
};

