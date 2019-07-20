//
//  Practica 3
//
//  Created by Juan Diego Calderón Mosqueda, Maria Guadalupe Hernandez Villafuerte, Dulce Maria Frias on 18/03/2016.
//  Copyright (c) 2016 Juan Diego Calderón Mosqueda, Maria Guadalupe Hernandez Villafuerte, Dulce Maria Frias . All rights reserved.


#include <stdio.h>

float seno(float x, int n);
float coseno(float x, int n);
float tangente(float x, int n);
float ctg (float x, int n);
float secante (float x, int n);
float cosecante (float x, int n);
int fact(int x);
float pot(float x, int n);

int main()
{
 int n;
 float x,y, t, u, p, m, c;
 printf("\t\t\tFunciones Trigonometricas\n");
 printf("introduzca el valor de x: ");
 scanf("%f", &x);
 do{
 printf("introduzca el valor de n: ");
 scanf("%d", &n);
 }
 while(n<1);
 y= seno(x, n);
 printf("\nEl valor del seno es: %f\n\n", y);
 printf("El valor del coseno es: %f\n\n", coseno(x,n));
 t=(tangente(x, n))/(10);
 printf("El valor de la tangente es: %f\n\n", t);
 p=((ctg(x,n)/(10.0)));
 printf("El valor de la cotangente es: %f\n\n", p);
 m= ((secante(x, n)/(10.0)));
 printf("El valor de la secante es: %f\n\n", m);
 c= ((cosecante(x,n)/(10.0)));
 printf("El valor de la cosecante es: %f\n", c);
 return 0;
 }

//seno
float seno(float x, int n)
  {
      int s, num=n*2;

      if(n==1)
        return x;
        else{
            s = n%2? 1.0:-1.0;
            return seno(x, n-1)+(s*(pot(x,num-1)/fact(num-1)));
  }
  }

//coseno
float coseno(float x, int n)
  {
      int s, num=n*2;

      if(n==1)
          return 1;
      else{
          s = n%2? 1.0:-1.0;
          return coseno(x, n-1)+(s*(pot(x,num-2)/fact(num-2)));
  }
  }

//Tangente
float tangente (float x, int n)
  {
      if(x>-1.57&&x<1.57){
      if(n==1)
        return x;
      else{
        return (tangente(x, n-1) + (seno(x, n)/(coseno(x, n))));
      }
  }
      return (printf("El valor de x es incorrecto\n"));
  }


//Cotangente
float ctg (float x, int n)
  {
      if(x>-1&&x<=1){
      if(n==1)
        return (1.0)/(x);
      else{
        return (ctg(x, n-1) + (1.0)/(tangente(x, n)));
      }
      }
      return (printf("El valor de x es incorrecto\n"));
  }

//secante
float secante (float x, int n)
  {
      if(x>-1.57&&x<1.57){
      if(n==1)
        return 1;
      else{
        return (secante(x, n-1)+ (1.0)/(coseno(x, n)));
      }
  }
        return (printf("El valor de x es incorrecto\n"));
  }


float cosecante (float x, int n)
{
   if(x>0&&x<1.57){
    if(n==1)
        return (1.0)/(x);
    else{
        return (cosecante(x, n-1)+ (1.0)/(seno(x, n)));
    }
}
      return (printf("El valor de x es incorrecto\n"));
}
int fact(int x)
  {
        if(x==0|| x==1)
              return 1;
        else
            return fact(x-1)*x;
  }

  float pot(float x, int n)
  {
        if(n==1)
              return x;
        else
            return pot(x, n-1)*x;
  }
