//
// Juan Diego Calderon mosqueda


#include <stdio.h>

int main(int argc, const char * argv[])
{
    int i, n, s;
    float ln, x, nu;

    do
    {
        printf("Ingrese el numero de iteraciones: ");
        scanf("%d", &n);
    }
    while (n<0);
    do
    {
        printf("Ingrese el valor de x: ");
        scanf("%f",&x);
    }
    while ((x<=-1)||(x>=1));
    for(i=0, ln=0, s=1; nu=x, i<=n; i++, s*=(-1) )
        nu*=x;
        ln += s*nu/i+1;
    printf("La operacion ln(1 + %f) es igual a = %f \n",x,ln);
    return 0;
}
