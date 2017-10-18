#pragma once
#include <vector>

class Stall
{
public:
	Stall();
	unsigned min;
	unsigned max;
	void expandir();
private:
	std::vector<unsigned> nodes;
};

