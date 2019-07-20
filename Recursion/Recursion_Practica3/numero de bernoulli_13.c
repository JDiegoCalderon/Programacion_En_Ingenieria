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

 int main ()
 {
  int n,x;
  float bn;
  printf("ingrese el valor de n: ");
  scanf("%d", &n);

  printf("ingrese el numero de iteraciones: ");
  scanf("%d", &x);
   //printf("el valor de factorial es %d", factorial (n));
  //printf("el valor de la multiplicacion es %f",  mult(2*n-1, 2));
  //printf("el valor de serie es %f", serie(n,n));

  bn=(factorial(2*n)/(mult(2*n-1, 2)* mult (2*n,PI)))*serie(2*n,n);
  printf("bn=%f\n", bn);

  return 0;

 }

 float serie(int n, int p)
 {
     if(n==1)
        return 1;
       else
        return serie(n-1,p)+(1/mult(2*p,n));
 }

 int factorial (int n)
 {
    int num=n*2;

    if(n==2)
      return 2;
     else
       return factorial (n-1)*n;
 }

 float mult(int n, float x)
 {

      if(n==1)
          return x;
       else
          return mult(n-1,x)*x;
 }




