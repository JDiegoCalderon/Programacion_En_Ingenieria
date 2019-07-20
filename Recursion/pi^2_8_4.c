#include <stdio.h>
#include <math.h>

//5
float un_medio (int n)
{
    if(n==0)
        return 0.33333;
    else{
        return (un_medio(n-2)+(1.0/((n+3)*(n+5))));
    }
}

int main(int argc,const char* argv[])
{
    float n;
    float y;
    do
    {
    printf("Ingrese el valor de n: ");
    scanf("%f", &n);
    }
    while (n<1);
    y= un_medio (n);
    printf("El valor de 1/2 es %f\n", y);
    system("PAUSE");
    return 0;
}

