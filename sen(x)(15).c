//
//Juan Diego Calderon mosqueda

#include <stdio.h>

int main(int argc, const char * argv[])
{
    int i, n, s;
    float snx, x, num, d, fun;
    do{
        printf("Ingrese el numero de iteraciones: ");
        scanf("%d", &n);
    }while(n<0);
    printf("Ingrese el valor de x: ");
    scanf("%f", &x);
    for(i=0, snx=0, s=1, num=x, d=1; i<n; i++)
    {
        fun = s*num/d;
        snx+=fun;
        s*=(-1);
        num*=(x*x);
        d*=((2*i+2)*(2*i+3));
    }
    printf("sen(%f) = %f\n", x, snx);
    return 0;
}
