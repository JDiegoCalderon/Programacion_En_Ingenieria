//
//  Practica 3
//
//  Created by Juan Diego Calderón Mosqueda, Maria Guadalupe Hernandez Villafuerte, Dulce Maria Frias on 18/03/2016.
//  Copyright (c) 2016 Juan Diego Calderón Mosqueda, Maria Guadalupe Hernandez Villafuerte, Dulce Maria Frias . All rights reserved.


#include<stdio.h>
#define b (x-1)/(x+1)
#define b_11 (x-1)/(x)

//Potencia
float pot(float x, int n){

    if (n) //equivalente a if (n!=0)
    {
        if (n<0)
            return pot(x,n+1)*(1/x);
        else
            return pot(x,n-1)*x;
        }
    return 1;
}



//Funcion de Exponencial 1
float exponencial2(float x, int n) {

    if (n==1)
        return x;
    else {
        return (exponencial2(x, n-1) * x/n);
    }

}


//11
float ln_11 (float x, int n)
{
        if(x>=0.5){
        if(n==1)
            return b_11;
            else{
                return (ln_11 (x, n-1)+pot(b_11, n)/n);
            }
    }
            return (printf("El valor de x es incorrecto\n"));

}

//12
float Exponencial12(float a,float x,int n) {

    if (n==1)
        return 1;
    else {
        return (Exponencial12(a, x, n-1) + exponencial2(x*ln_11(a, n), n-1));
    }
}

int main(int argc, char* argv[])
{
   int n;
    float x, w, a;
    printf("Ingrese el valor de x: ");
        scanf("%f", &x);
    do{
        printf("Ingrese el valor de n: ");
        scanf("%d", &n);
    }
    while (n<1);
    a= ln_11 (x, n);
    printf("El Ln(%f) es igual a %f\n\n",x, a);
    w= Exponencial12(a,x,n);
    printf("El expnencial de e^xlna es %f\n\n", w);
    return 0;
}






