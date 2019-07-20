//
//  Practica 3
//
//  Created by Juan Diego Calderón Mosqueda, Maria Guadalupe Hernandez Villafuerte, Dulce Maria Frias on 18/03/2016.
//  Copyright (c) 2016 Juan Diego Calderón Mosqueda, Maria Guadalupe Hernandez Villafuerte, Dulce Maria Frias . All rights reserved.


#include <stdio.h>

 int leern();
 float leerx();
 void esen(int y,float x);

 int main()
{
    esen(leern(),leerx());
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
    printf("\n Introduzca el valor de x que se encuentre en el intervalo [-1,1]: ");
    scanf("%f",&x);

    return x;
}

 void esen(int y,float x)
{
    int i;
    float sum=(1+x),num=x*x,d=2,total=(1+x),ex=2,s=1;

    for(i=0;i<y;i++)
    {
        if((i+2)%2)//falso
        {
            s*=-1;
            num*=x;
        }
        else
        {
            ex++;
        }
        //printf("\n signo=%f",s);
        ex++;
        sum+=((num*s)/d);
        d=ex*(i+2);
        num*=x;
    }
    printf("\nEl resultado de e^sen x es= %f",sum);
}
