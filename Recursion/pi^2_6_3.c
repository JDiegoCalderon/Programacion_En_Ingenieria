#include <stdio.h>
#include <math.h>
float pot2(float x, int n)
{
    if(n!=1)
        return x*pot2(x,n-1);
    else
        return x;
}

//4
float pi2_8 (int n)
{
    if(n==1)
        return 1;
    else{
        return (pi2_8(n-1)+(1/pot2(n,3)));
    }
}

int main(int argc,const char* argv[])
{
    float n;
    float t;
    do
    {
    printf("Ingrese el valor de n: ");
    scanf("%f", &n);
    }
    while (n<1);
    t= sqrt(pi2_8 (n)*8);
    printf("pi^2/8 es %f\n", t);
    system("PAUSE");
    return 0;
}

