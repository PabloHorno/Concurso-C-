/*
Google Code Jam 17 - Problem B. Tidy Numbers
Purpose: Solve problem B of Qualification Round. https://code.google.com/codejam/contest/3264486/dashboard#s=p1

@author Pablo Horno
@version 1.0 14/08/17
*/
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

bool is_tidy_number(const string);
string last_tidy_number(string);
int main()
{
	ifstream input("input/B-large-practice.in");
	ofstream output("output/B-large-practice.out");
	unsigned casos, i = 0;
	input >> casos;

	while (!input.eof() && i < casos)
	{
		string numero;
		input >> numero;

		while (!is_tidy_number(numero))
			numero = last_tidy_number(numero);

		output << "Case #" << ++i << ": " << numero << endl;
	}
	cout << "End" << endl;
}
bool is_tidy_number(string num) {
	for (string::iterator it = num.begin(); it+1!=num.end(); ++it)
		if (*it > *(it + 1))
			return false;
	return true;
}
string last_tidy_number(string num)
{
	for (size_t it = 0; it+1 < num.size(); ++it) {
		if (num.at(it) > num.at(it+1))
		{
			num.at(it) = num.at(it) - 1;
			for (size_t it2 = it + 1; it2 < num.size(); ++it2)
				num.at(it2) = '9';
		}
	}
	return to_string(stoull(num));
}