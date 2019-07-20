// ConsoleApplication12.cpp : Defines the entry point for the console application.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 500

int main(int argc, char* argv[])
{
	int x[N], h[2][N], n, m, i, max, min, moda, cmoda, s1, n1;
	float media;
	srand(time(NULL));
	do{
		printf("Ingrese el valor de n: ");
		scanf("%d", &n);
	} while (n<1||n>N);
	printf("Ingrese el valor de maximo: ");
	scanf("%d", &max);
	printf("Ingrese el valor de minimo: ");
	scanf("%d", &min);
	if (max < min)
	{
		max = max + min;
		min = max - min;
		max = max - min;
	}
	for (i = 0; i < n; i++)
	{
		x[i] = (max - min)*rand() / RAND_MAX + min;
		printf("X[%d] = %d\n", i+1, x[i]);
	}
	m = max - min + 1;
	for (i = 0; i < m; i++)
	{
		h[0][i] = 0;
		h[1][i] = 0;
	}
	for (i = min; i <= max; i++)
		h[0][i - min] = i;
	for (i = 0; i < n; i++)
		h[1][x[i] - min]++;
	moda = h[0][0];
	cmoda = h[1][0];
	for (i = 1; i < m; i++)
		if (h[1][i]>cmoda)
		{
			moda = h[0][i];
			cmoda = h[1][i];
		}
	printf("La moda es %d\n", moda);
	for (i = 0, s1 = 0, n1 = 0; i < m; i++)
	{
		s1 += (h[0][i]*h[1][i]);
		n1 += h[1][i];
	}
	media = (1.0 * s1) / n1;
1	printf("%d\t%d\n", s1, n1);
	printf("La media es %f\n", media);
	return 0;
}

