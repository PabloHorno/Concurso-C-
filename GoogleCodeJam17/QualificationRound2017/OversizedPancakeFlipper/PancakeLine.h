/*
Google Code Jam 17 - Problem A. Oversized Pancake Flipper
Purpose: Calculate the minimun turns needed on a PancakeLine.

@author Pablo Horno
@version 1.0 14/08/17
*/
#pragma once
#include <string>
#include <iostream>
class PancakeLine
{
public:
	/*Constructor*/
	PancakeLine(std::string, unsigned);
	/*Return true it's solved*/
	bool es_solucion();
	/*Find next Pancake to make the turn*/
	size_t next();
	/*Makes the turn of the Pancake given and the next ones*/
	void voltear(size_t pos);
	/*Return the number of turns or if it's impossible to solve*/
	std::string solucion();
private:
	/*Size of the tool tu turn over the pancakes*/
	unsigned tam_voltear;
	/*Actual position of pancakes in queue*/
	std::string linea;
};

