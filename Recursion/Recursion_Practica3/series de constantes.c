//
//  Practica 3
//
//  Created by Juan Diego Calderón Mosqueda, Maria Guadalupe Hernandez Villafuerte, Dulce Maria Frias on 18/03/2016.
//  Copyright (c) 2016 Juan Diego Calderón Mosqueda, Maria Guadalupe Hernandez Villafuerte, Dulce Maria Frias . All rights reserved.


#include <stdio.h>
#include <math.h>

float pot2(float x, int n)
{
    if(n!=1)
        return x*pot2(x,n-1);
    else
        return x;
}
//1
float ln2 (int n)
{
    int s;
    if (n==1)
        return 1;
    else{
        s= n%2? 1.0:-1.0;
        return (ln2(n-1)+ s/(1.0*n));
    }
}

//2
float pi_4 (int n)
{
    float s;
    if(n==1)
        return 1;
    else{
        s= n%2? 1.0:-1.0;
        return (pi_4(n-1)+s/(1.0*(n+(n-1))));
    }
}

//3
float pi2_6 (int n)
{
    if(n==1)
        return 1;
    else{
        return (pi2_6(n-1)+(1.0/pot2(n,2)));
    }
}

//4
float pi2_8 (int n)
{
    if(n==1)
        return 1;
    else{
        return (pi2_8(n-1)+(1.0/pot2(n,3)));
    }
}

//5
float un_medio (int n)
{
    if(n==1)
        return 0.3333;
    else{
        return (un_medio(n-1)+(1.0/((2*n+1)*(2*n-1))));
    }
}

//6
float tres_cuartos (int n)
{
    if(n==0)
        return 0;
    else{
        return (tres_cuartos(n-1)+(1.0/((n)*(n+2))));
    }
}

int main(int argc, char* argv[])
{
    int n;
    float res, rep, w, t, y, u;
    printf("\t\tSeries de constantes....\n");
    do
    {
    printf("Ingrese el valor de n: ");
    scanf("%d", &n);
    }
    while (n<1);
    res= ln2(n);
    printf("ln(2)= %f\n\n", res);
    rep= (pi_4 (n)*4);
    printf("pi/4 es %f\n\n", rep);
    w= sqrt(pi2_6 (n)*6);
    printf("pi^2/6 es %f\n\n", w);
    t= sqrt(pi2_8 (n)*8);
    printf("pi^2/8 es %f\n\n", t);
    y= un_medio (n);
    printf("El valor de 1/2 es %f\n\n", y);
    u= tres_cuartos (n);
    printf("El valor de 3/4 es %f\n\n", u);
    system ("PAUSE");
    return 0;
}
