#include <stdio.h>
#include <math.h>

float pot2(float x, int n)
{
    if(n!=1)
        return x*pot2(x,n-1);
    else
        return x;
}
//Funcion de Exponencial 1
float exponencial2(float x, int n) {

    if (n==1)
        return x;
    else {
        return (exponencial2(x, n-1) * x/n);
    }

}

//7
float exponencial (float x, int n)
{
    if(n==1)
        return 1;
    else{
        return (exponencial(x, n-1)+exponencial2(x, n-1));
    }
}

int main(int argc, char* argv[])
{
   int n;
    float  x, e;
     printf("Ingrese el valor de x: ");
        scanf("%f", &x);
    do{
        printf("Ingrese el valor de n: ");
        scanf("%d", &n);
    }
    while (n<1);
    e= exponencial(x,n);
    printf("El exponencial es %f \n", e);
    return 0;
}
