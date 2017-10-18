#include<iostream>
using namespace std;
void main() {
	while (true)
	{
		unsigned n, fibb = 0,fibbAnt = 1;
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			unsigned temp = fibb;
			fibb += fibbAnt;
			fibbAnt = temp;
		}
		cout << fibb << endl;
	}
}