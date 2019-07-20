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
 printf("\nEl valor del seno es: %f", y);
 printf("\nEl valor del coseno es: %f", coseno(x,n));
 t=(tangente(x, n))/(10);
 printf("\nEl valor de la tangente es: %f", t);
 p=((ctg(x,n)/(10.0)));
 printf("\nEl valor de la cotangente es: %f", p);
 m= ((secante(x, n)/(10.0)));
 printf("\nEl valor de la secante es: %f", m);
 c= ((cosecante(x,n)/(10.0)));
 printf("\nEl valor de la cosecante es: %f", c);
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
      if(n==1)
        return x;
      else{
        return (tangente(x, n-1) + (seno(x, n)/(coseno(x, n))));
      }
  }

//Cotangente
float ctg (float x, int n)
  {
      if(n==1)
        return (1.0)/(x);
      else{
        return (ctg(x, n-1) + (1.0)/(tangente(x, n)));
      }
  }

//secante
float secante (float x, int n)
  {
      if(n==1)
        return 1;
      else{
        return (secante(x, n-1)+ (1.0)/(coseno(x, n)));
      }
  }

float cosecante (float x, int n)
{
    if(n==1)
        return (1.0)/(x);
    else{
        return (cosecante(x, n-1)+ (1.0)/(seno(x, n)));
    }
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
