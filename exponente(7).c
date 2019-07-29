
#include <stdio.h>

int main(int argc, const char * argv[])
{
    int i, n, num;
    float x, exp, d;
    do
    {
    printf("Ingrese el numero de iteraciones: ");
    scanf("%d", &n);
    }
    while (n<1);
    printf("ingrese el valor de x: ");
    scanf("%f", &x);
    for(i=0, d=1, exp=0; i<n; i++, d*=x/i )
    {
     exp+=d;
    }
     printf("El exp de %f es = %f\n" ,x, exp);
    return 0;
}
