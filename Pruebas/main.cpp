#include <iostream>
#include <map>
#include <string>
#include <vector>
#include<algorithm>
using namespace std;
void main()
{
	char letra = 'A';
	for (int i = 0; i < 10; i++){
		for (int j = 0; j < 7; j++)
		{
			string code;
			code += letra;
			code += to_string(j);
			cout << code;
		}
	cout << endl;
		letra++;
	}
system("pause");
}