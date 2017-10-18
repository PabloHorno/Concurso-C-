/*
Google Code Jam 17 - Problem A. Oversized Pancake Flipper
Purpose: Calculate the minimun turns needed on a PancakeLine.

@author Pablo Horno
@version 1.0 14/08/17
*/

#include <iostream>
#include <fstream>
#include <string>
#include "PancakeLine.h"
#include "main.h"
using namespace std;
int main()
{

	ifstream input("input/A-large-practice.in");
	ofstream output("output/A-large-practice.out");
	unsigned casos, i = 0, tam_pan;
	input >> casos;

	while (!input.eof() && i < casos)
	{
		string s;
		input >> s >> tam_pan;
		PancakeLine pancake(s, tam_pan);
		output << "Case #" << ++i << ": " << pancake.solucion() << endl;
	}
	cout << "Fin" << endl;
}
