#pragma once
#include<vector>
#include<iostream>
#include<map>
#include<string>
using namespace std;

class Producto
{
public:
	Producto(int precio = 0, int stock = 0) { this->precio = precio; this->strock = strock; };

	int precio;
	int strock;
};

class SnakVending
{
public:
	SnakVending();
	~SnakVending();
	vector<int> valor_monedas = { 1, 2, 5, 10, 20, 50, 100, 200 };

	int precio;
	int fallo;
	map<string,Producto> productos;
	vector<string>clientes;
	string inicio, llegada;
	vector<int>monedas;
	char letra_maxima;
	int num_columnas = 0;
	int cambio();
	vector<int> devolucion_monedas();
	void set_filas_columnas(string ultima_casilla);
	void get_productos(istream &cin);
	int revenue();
	int tiempo_entre_casillas();
	pair<char, int> code_to_pos(string code);
};

