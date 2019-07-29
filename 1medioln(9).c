//
// Juan Diego Calderon mosqueda


#include <stdio.h>

int main(int argc, const char * argv[])
{
    int i, n, s, d;
    float ln, x, num;

    do
    {
        printf("Ingrese el numero de iteraciones: ");
        scanf("%d", &n);
    }
    while (n<1);
    do
    {
        printf("Ingrese el valor de x: ");
        scanf("%f",&x);
    }
    while ((x<=-1)||(x>=1));
    ln=0;
    num=x;
    for(i=0, ln=0, num*=x*x; i<n; i++ )
    d= 2i+1;
    ln+=num/d;
    printf("La operacion 1/2*ln(1 + %f/1-%f) es igual a = %f \n",x,x,ln);
    return 0;
}
