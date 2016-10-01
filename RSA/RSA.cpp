#include "stdafx.h"
#include <iostream>
#include <conio.h>
#include <ctime>
#include <cstdlib>
#include <iomanip>
using namespace std;
class metods {
public :
	
	int GSB(int a,int b) {
		int c;
		while (b)
		{
			c = a%b;
			a = b;
			b = c;
		}
		return abs(a);
	}

	int Sudarm(int n) {
		int *a = new int[n],k;
		memset(a, 0, sizeof(int)*n);
		for (int i = 1;(i * 3 + 1) < n;i++)
		{
			for (int j = 1;(k = i + j + 2 * i*j) < n && j <= i;j++)
			{
				a[k] = 1;
			}

		}
		for (int i = n - 1;i >= 1;i--)
		{
			if (a[i] == 0)
			{
				return (2 * i + 1);
				break;
			}
		}
		delete[]a;
	}
};


int main()
{
	metods Metod;
	cout << "Key's generated ..." << endl <<endl;
	srand((unsigned)time(NULL));
	int p = rand() % 100;
	int q = rand() % 100;
	int p_simple = Metod.Sudarm(p);
	int q_simple = Metod.Sudarm(q);
	unsigned int n = p_simple*q_simple;
	int d, d_simple = 0;
	while (d_simple != 1)
	{
		d = rand() % 100;
		d_simple = Metod.GSB(d, ((p_simple - 1)*(q_simple - 1)));
	}
	unsigned int e = 0, e_simple = 0;
	while (e_simple != 1)
	{
		e += 1;
		e_simple = (e*d) % ((p_simple - 1)*(q_simple - 1));
	}
	cout << '{' << e << ',' << n << '}' << " - Open key" << endl;
	cout << '{' << d << ',' << n << '}' << " - Secret key" << endl << endl;
	const int MAX = 30;
	char *Text = new char[MAX];
	cout << "Please enter the Text. Use <Enter> button when done." << endl;
	cin.get(Text, MAX);
	unsigned int *CryptoText = new unsigned int[MAX];
	unsigned int *Tdecrypt = new unsigned int[MAX];
	int b = 301;
	int c;
	cout << endl << setw(5) << "Text" << setw(6) << "ASCII"
		<< setw(30) << "CryptoText/Block#" << setw(14)
		<< "ASCIIdecrypt" << setw(14) << "Text decrypt" << endl
		<< "------------------------------------------------------------" << endl;
	for (int j = 0; j < MAX; j++)
	{
		c = 1;
		unsigned int i = 0;
		int ASCIIcode = (static_cast<int>(Text[j])) + b;
		while (i<e)
		{
			c = c*ASCIIcode;
			c = c%n;
			i++;
		}
		CryptoText[j] = c;
		b += 1;
	}
	b = 301;
	int m;

	for (int j = 0; j < MAX; j++)
	{
		m = 1;
		unsigned int i = 0;
		while (i<d)
		{
			m = m*CryptoText[j];
			m = m%n;
			i++;
		}
		m = m - b;
		Tdecrypt[j] = m;
		b += 1;
	}
	for (int j = 0; j < MAX; j++)
	{
		cout << setw(5) << Text[j] << setw(6) << static_cast<int>(Text[j]) << setw(30)
			<< CryptoText[j] << setw(14) << Tdecrypt[j] << setw(14) << static_cast<char>(Tdecrypt[j]) << endl;
	}
	delete[] Text;
	delete[] CryptoText;
	delete[] Tdecrypt;
	system("pause");
	return 0;
}