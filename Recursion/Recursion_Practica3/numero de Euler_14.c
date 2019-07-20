//
//  Practica 3
//
//  Created by Juan Diego Calderón Mosqueda, Maria Guadalupe Hernandez Villafuerte, Dulce Maria Frias on 18/03/2016.
//  Copyright (c) 2016 Juan Diego Calderón Mosqueda, Maria Guadalupe Hernandez Villafuerte, Dulce Maria Frias . All rights reserved.


#include <stdio.h>
#define PI 3.141592

 int factorial (int n);
 float mult(int n, float x);
 float serie(int n, int p);

 int main()
 {
   int n,x;
   float en;

   printf("ingrese el valor de n: ");
   scanf("%d", &n);

   printf("ingrese el numero de iteraciones: ");
   scanf("%d", &x);

   //printf("el valor de la multiplicacion es %f",  mult(2*n+2, 2));
   //printf("el valor de factorial es %d", factorial (n));
   //printf("el valor de serie es %f", serie(n,n));

   en= ((mult(2*n+2,2)*factorial(2*n))/mult(2*n+1,PI))*serie(n,n);
   printf("en=%f\n",en);
 }

float serie(int n, int p)
 {
    int signo,num=n*2;

     if(n%2==0)
        signo=-1;
      else
        signo=1;
     if(n==1)
        return 1;
       else
        return serie(n-1,p)+(1/mult(2*p+1,num-1));

 }

  float mult(int n, float x)
  {
   if(n==1)
          return x;
       else
          return mult(n-1,x)*x;
  }

  int factorial (int n)
 {
    int num=n*2;

    if(n==2)
      return 2;
     else
       return factorial (n-1)*n;
 }
