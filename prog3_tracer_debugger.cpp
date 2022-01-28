#pragma once
#include <iostream>
#include <random>
using namespace std;

/// <summary>
/// 
/// </summary>
/// <param name="tab"></param>
/// <param name="len"></param>
/// <param name="i"></param>
void coutTab(int* tab, int len, int i = 0) {
	for (i = 0; i < len; i++)
	{
		cout << tab[i] << " ";
	}
	cout << "\n";
}

/// <summary>
/// 
/// </summary>
/// <param name="a"></param>
/// <param name="b"></param>
void permuteAB(int* a, int* b)
{
	int temptInt{ *a };
	*a = *b;
	*b = temptInt;
}

/// <summary>
/// 
/// </summary>
/// <param name="len"></param>
/// <param name="min"></param>
/// <param name="max"></param>
/// <returns></returns>
int* rndNormalisedIntArr(int len, int min, int max) {

	std::random_device rd;
	std::mt19937 rn(rd());
	// dist1 sert à normaliser le nombre généré entre 1 et 100
	std::uniform_int_distribution<> rng(min, max);


	int* tab{ new int[len] {} };

	for (int i = 0; i < len; i++)
	{
		tab[i] = rng(rd);
	}

	return tab;
}

/// <summary>
/// 
/// </summary>
/// <param name="len"></param>
/// <param name="tab"></param>
void ascendingSort(int len, int* tab) {
	for (int i = 0; i < len; i++)
	{
		int idx = i;
		for (int j = i; j < len; j++)
		{
			if (tab[j] < tab[idx]) idx = j;
		}
		permuteAB(&tab[i], &tab[idx]);
	}
}

int main()
{
	int len = 10;
	int* tab = rndNormalisedIntArr(len, 1, 100);
	coutTab(tab, len);
	ascendingSort(len, tab);
	coutTab(tab, len);
	delete[] tab;
}
