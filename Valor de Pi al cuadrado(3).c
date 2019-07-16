//
// Juan Diego Calderon Mosqueda

#include <stdio.h>
#include <math.h>

int main(int argc, const char * argv[])
{
    int i, n, d;
    float Pi;
    do
    {
    printf("Ingrese el numero de iteraciones: ");
    scanf("%d", &n);
    }
    while (n<0);
    Pi=0;
    for(i=0; i<n; i++)
    {
     d=(i+1)*(i+1);
     Pi+=(1.0/d);
    }
     Pi=sqrt(Pi*6);
     printf("El Valor de pi es = %f" ,Pi);
    return 0;
}
