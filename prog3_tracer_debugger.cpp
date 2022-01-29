#include <iostream>
#include <random>
#include "prog3_tracer_debugger.h"

using namespace std;

void maFunc(int* a, int b) 
{
	int temp = *a;
	*a = b;
	b = temp;
}

int main()
{
	std::random_device rd;
	std::mt19937 rn(rd());
	// dist1 sert à normaliser le nombre généré entre 1 et 100
	std::uniform_int_distribution<> rng(1, 100);

	int tab[10]{};

	for (int i = 0; i < 10; i++)
	{
		tab[i] = rng(rd);
		cout << tab[i] << " ";
	}
    
	cout << "\n";

	for (int i = 0; i < 10; i++)
	{
		int idx = i;
		for (int j = i; j < 10; j++)
		{
			if (tab[j] < tab[idx]) idx = j;
		}

		maFunc(&tab[i], tab[idx]);
	}

	for (int i = 0; i < 10; i++)
	{
		cout << tab[i] << " ";
	}
}
