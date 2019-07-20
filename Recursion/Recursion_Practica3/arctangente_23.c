//
//  Practica 3
//
//  Created by Juan Diego Calderón Mosqueda, Maria Guadalupe Hernandez Villafuerte, Dulce Maria Frias on 18/03/2016.
//  Copyright (c) 2016 Juan Diego Calderón Mosqueda, Maria Guadalupe Hernandez Villafuerte, Dulce Maria Frias . All rights reserved.


#include <stdio.h>

 const float PI=3.141592;
 int leern();
 float leerx();
 float valor1(int y,float x);
 float valor2(int y,float x);
 float valor3(int y,float x);
 void comp(float x);

 int main()
{
  comp(leerx());
   return 0;
}

 int leern()
{
 int n;

  printf("\n Introduzca el numero de iteraciones: ");
  scanf("%d",&n);
    return n;
}

 float leerx()
{
  float x;
  printf("\n Introduzca un valor para x: ");
  scanf("%f",&x);
   return x;
}

 void comp(float x)
{
  if((x<1)&&(x>-1))
    valor1(leern(),x);
    if(x>=1)
      valor2(leern(),x);
     if(x<=-1)
       valor3(leern(),x);
}

  float valor1(int y,float x)
{
  int i,s=-1;
  float sum=x,num=x*x,d=3,total=x;

     for(i=0;i<y;i++)
     {
       sum*=num*s;
       total+=(sum/d);
       d+=2;
     }
  printf("\n El valor de tan^-1 (%f) es: %f",x,total);
}

 float valor2(int y,float x)
{
  int i,s=1;
  float sum=1/x,num=x*x,d=3,tot=-(1/x),total=0;
   for(i=0;i<y;i++)
    {
      sum*=(1/num)*s;
      tot+=(sum*(1/d));
      d+=2;
      s*=-1;
    }
 //printf("\n PI/2=%f",PI/2.0);

  total=(PI/2.0)+tot;
 printf("\n El valor de tan^-1 (%f) es: %f",x,total);
}

 float valor3(int y,float x)
{
  int i,s=1;
  float sum=1/x,num=x*x,d=3,tot=-(1/x),total=0;
   for(i=0;i<y;i++)
    {
      sum*=(1/num)*s;
      tot+=(sum*(1/d));
       d+=2;
      s*=-1;
}
  total=-(PI/2.0)+tot;
  printf("\n El valor de tan^-1 (%f) es: %f",x,total);
}
