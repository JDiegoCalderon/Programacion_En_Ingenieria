// ConsoleApplication14.cpp : Defines the entry point for the console application.
//

#include <stdio.h>

struct Materia{
	char Nombre[20];
	float Calif;
};

struct Alumno{
	char Nombre[20];
	int NUA;
	int Carrera;
	char Insc;
	int Nmaterias;
	struct Materia UDA[50];
	float Promedio;
};

int main(int argc, char* argv[])
{
	struct Alumno Juan;
	printf("Ingrese su nombre: ");
	scanf("%s", Juan.Nombre);
	printf("Ingrese su NUA: ");
	scanf("%d", &Juan.NUA);
	return 0;
}

