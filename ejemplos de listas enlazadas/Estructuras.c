// ConsoleApplication13.cpp : Defines the entry point for the console application.
//

#include <stdio.h>

struct Z{
	float a;
	float b;
};

union A
{
	char a;
	int b;
};

struct B{
	char a;
	int b;
};

int main(int argc, char* argv[])
{
	struct Z X, Y, W;
	union A T1;
	struct B T2;
	printf("Ingrese el numero real: ");
	scanf("%f", &X.a);
	printf("Ingrese el numero imaginario: ");
	scanf("%f", &X.b);
	printf("Ingrese el numero real: ");
	scanf("%f", &Y.a);
	printf("Ingrese el numero imaginario: ");
	scanf("%f", &Y.b);
	W.a = X.a + Y.a;
	W.b = X.b + Y.b;
	printf("(%f%+fi)+(%f%+fi)=%f%+fi\n", X.a, X.b, Y.a, Y.b, W.a, W.b);
	W.a = X.a - Y.a;
	W.b = X.b - Y.b;
	printf("(%f%+fi)-(%f%+fi)=%f%+fi\n", X.a, X.b, Y.a, Y.b, W.a, W.b);
	W.a = X.a * Y.a - X.b * Y.b;
	W.b = X.a * Y.b + X.b * Y.a;
	printf("(%f%+fi)*(%f%+fi)=%f%+fi\n", X.a, X.b, Y.a, Y.b, W.a, W.b);
	W.a = (X.a * Y.a + X.b * Y.b) / (Y.a * Y.a + Y.b * Y.b);
	W.b = (Y.a * X.b - X.a * Y.b) / (Y.a * Y.a + Y.b * Y.b);
	printf("(%f%+fi)/(%f%+fi)=%f%+fi\n", X.a, X.b, Y.a, Y.b, W.a, W.b);
	printf("float -> %d\n", sizeof(X.a));
	printf("struct Z -> %d\n", sizeof(X));
	printf("union A -> %d\n", sizeof(T1));
	printf("struct B -> %d\n", sizeof(T2));
	printf("Ingrese un entero: ");
	scanf_s("%d", &T1.b);
	printf("%d\t%d\n", T1.b, T1.a);
	return 0;
}

