// ConsoleApplication10.cpp : Defines the entry point for the console application.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 100

int cap_n(void)
{
	int m;
	printf("Ingrese el numero de datos: ");
	scanf("%d", &m);
	if (m<1 || m>N)
		m = cap_n();
	return m;
}

void cap_n2(int *n)
{
	printf("Ingrese el numero de datos: ");
	scanf("%d", n);
	if (*n<1 || *n>N)
		cap_n2(n);
}

void validar(float *rmax, float *rmin)
{
	if (*rmin > *rmax)
	{
		*rmin += *rmax;
		*rmax = *rmin - *rmax;
		*rmin -= *rmax;
	}
}

void capturar_x(int n, float *x)
{
	int i;
	printf("Ingrese los datos solicitados.\n");
	for (i = 0; i < n; i++)
	{
		printf("X[%d] = ", i + 1);
		scanf("%f", x + i);
	}
}

void aleatorio(int n, float *x, float rmax, float rmin)
{
	int i;
	for (i = 0; i < n; i++)
		x[i] = ((rmax - rmin)*rand()) / RAND_MAX + rmin;
}

float fmedia(int n, float *x)
{
	int i;
	float media;
	for (i = 1, media = x[0]; i < n; media += x[i++]);
	media /= n;
	return media;
}

int main(int argc, char* argv[])
{
	int i, j, n, op;
	float x[N], media, aux, mediana, rmax, rmin;
	srand(time(NULL));
	//n = cap_n();
	cap_n2(&n);
	printf("Desea ingresar los datos: ");
	scanf("%d", &op);
	if (op)
	{
		capturar_x(n, x);
	}
	else
	{
		printf("Ingrese el valor maximo: ");
		scanf("%f", &rmax);
		printf("Ingrese le valor minimo: ");
		scanf("%f", &rmin);
		validar(&rmax, &rmin);
		printf("max: %f\tmin: %f\n", rmax, rmin);
		aleatorio(n, x, rmax, rmin);
	}
	for (i = 0; i < n; i++)
		printf("X[%d] = %f\n", i+1, x[i]);
	media = fmedia(n, x);
	printf("La media es %f.\n", media);
	for (i = 0; i < n - 2; i++)
		printf("m[%d] =  %f.\n", i+1, fmedia(3, x+i));
	for (i = 0; i < n - 1; i++)
		for (j = i + 1; j < n; j++)
			if (x[i]>x[j])
			{
/*				aux = x[j];
				x[j] = x[i];
				x[i] = aux;*/
				x[i] = x[i] + x[j];
				x[j] = x[i] - x[j];
				x[i] = x[i] - x[j];
			}
	for (i = 0; i < n; i++)
		printf("X[%d] = %f\n", i + 1, x[i]);
	if (n % 2)
		mediana = x[n / 2];
	else
		mediana = (x[n / 2] + x[n / 2 - 1]) / 2;
	printf("La mediana es %f\n", mediana);
	return 0;
}

