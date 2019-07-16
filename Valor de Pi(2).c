//
// Juan Diego Calderon Mosqueda

#include <stdio.h>

int main(int argc, const char * argv[])
{
    int i, n, d, sg;
    float Pi;
    do
    {
    printf("Ingrese el numero de iteraciones: ");
    scanf("%d", &n);
    }
    while (n<0);
    Pi=0;
    sg=1;
    for(i=0; i<n; i++)
    {
     d=(2*i)+1;
     Pi+=sg*(1.0/d);
     sg*=(-1);
    }
     Pi=(Pi*4);
     printf("El Valor de pi es = %f" ,Pi);
    return 0;
}
