#include "Echange.h"

void echange(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
