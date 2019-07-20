//
//  Practica 3
//
//  Created by Juan Diego Calderón Mosqueda, Maria Guadalupe Hernandez Villafuerte, Dulce Maria Frias on 18/03/2016.
//  Copyright (c) 2016 Juan Diego Calderón Mosqueda, Maria Guadalupe Hernandez Villafuerte, Dulce Maria Frias . All rights reserved.


#include<stdio.h>
#define pi 3.13159265
#define pi2 3.14159265


float serie(float c,float n);
float pot(float b,float x);
float suma(int x);
float cos(float X, int c);
int main()
{
	int res,b;
	float c,res1,a,X, res2;
	printf("\t\t\tCalculo del valor del arcseno\n");
	do{
	printf("Ingrese el valor X:");
	scanf("%f",&X);
    }while(X>1||X<-1);
	printf("ingrese el numero de interacciones de n:");
	scanf("%f",&c);
	//res1=serie(c,X);
	//printf("\n%f ",res1);
	res2= ((pi2)/(2))-(serie(c,X));
	printf("el arcocoseno es %f", res2);
	return 0;
}

//pot calcula las potencias de la potencia de X

float pot(float a,float x)
{
	if(a==0)
	return 1;
	else
	return pot(a-1,x)*x;
}


//calcula la mutiplicacion de 1/2, 1/2*3/4 etc.
float suma(int x){
	if(x-1==1){
		return 1;
}else{if(x%2)
{
return suma(x-1)*1.0*(x-2)/(x-1);
}else return suma(x-1);
}
}


//calcula la sumatoria.
float serie(float c,float n)
{
	float x;
	float y;
	if(c==1){
	return n;
	}else if((int)c%2){//este es solo para que no sume los numeros pares en las elevaciones
          x=pot(c,n)/c;//x^n/n
          y=suma(c);//1/2, 1/2*3/4 etc.
          	//printf("\n%f \n",x);
	return (serie(c-1,n)+x*y);//1/2*x^3/3 +1/2*3/4*x^5/5 etc.
}
return serie(c-1,n);
}

float cos(float X, int c)
{
    float n;
    if(c==1)
        return 1;
    else{
        return (cos(X, c-1)+ (serie(c,n)));
    }
}


