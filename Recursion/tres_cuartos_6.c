#include <stdio.h>
#include <math.h>

//6
float tres_cuartos (int n)
{
    if(n==0)
        return 0;
    else{
        return (tres_cuartos(n-1)+(1.0/((n)*(n+2))));
    }
}

int main(int argc,const char* argv[])
{
    float n;
    float u;
    do
    {
    printf("Ingrese el valor de n: ");
    scanf("%f", &n);
    }
    while (n<1);
    u= tres_cuartos (n);
    printf("El valor de 3/4 es %f\n", u);
    system("PAUSE");
    return 0;
}

