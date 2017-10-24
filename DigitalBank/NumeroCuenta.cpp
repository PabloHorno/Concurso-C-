#include "NumeroCuenta.h"


NumeroCuenta::NumeroCuenta()
{
}

NumeroCuenta::~NumeroCuenta()
{
}

bool NumeroCuenta::validar(bool print)
{
	crear_numero();
	map<char, int> mayus, minus;
	for (auto caracter : id_cuenta)
	{
		if (isupper(caracter))
			mayus[caracter]++;
		else
			minus[caracter]++;
	}
	if (print){
		for (auto may : mayus)
			cout << may.second <<"("<<may.first<<")"<< " != " <<"(" << (char)tolower(may.first) << ")" << minus[tolower(may.first)] << endl;
	}
	for (auto may : mayus)
		if (may.second != minus[tolower(may.first)])
			return false;
	if (mayus.size() != minus.size())
		return false;

	int suma = 0;
	for (auto caracter : id_cuenta)
		suma += (int)caracter;
	suma += 'C' + 'A' + 'T' + '0' + '0';
	int resto = suma % 97;

	return (98 - resto) == checksum;
}

void NumeroCuenta::crear_numero()
{
	codigo_pais = numero_cuenta_completo.substr(0, 3);
	checksum = stoi(numero_cuenta_completo.substr(3, 5));
	id_cuenta = numero_cuenta_completo.substr(5, numero_cuenta_completo.size());
}
