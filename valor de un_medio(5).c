#include <stdio.h>

int main(int argc, const char * argv[])
{
    int i, n, d;
    float un_medio;

    do
    {
    printf("Ingrese el numero de iteraciones: ");
    scanf("%d", &n);
    }
    while (n<0);
    d=1;
    for(i=0; i<n; i++)
    {
     d*=(2*i+3);
     un_medio+=(1.0/d);

    }
    printf("El Valor de un_medio (1/2) es = %f" ,un_medio);
    return 0;
}
