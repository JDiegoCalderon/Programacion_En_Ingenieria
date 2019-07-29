//
// Juan Diego Calderon mosqueda


#include <stdio.h>

int main(int argc, const char * argv[])
{
    int i, n ;
    float ln, x, nu, d;
    do
    {
        printf("Ingerse el numero de iteraciones:");
        scanf("%d", &n);
    }
    while(n<1);
    do
    {
        printf("ingrese el valor de x:");
        scanf("%f", &x);
    }
    while(x<=0.5);
    ln=0;
    nu=x-1;
    d=x;
    for(i=1; i<n; i++)
    nu*=x-1;
    d+=x+1;
    ln+=nu/d;
    printf("la operacion ln (%f) es igual a = %f \n",x,ln);
    return 0;
}
