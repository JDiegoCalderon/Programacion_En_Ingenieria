#include <stdio.h>
#include <math.h>
float pot2(float x, int n)
{
    if(n!=1)
        return x*pot2(x,n-1);
    else
        return x;
}

//3
float pi2_6 (int n)
{
    if(n==1)
        return 1;
    else{
        return (pi2_6(n-1)+(1.0/pot2(n,2)));
    }
}

int main(int argc, char* argv[])
{
    int n;
    float w;
    do
    {
    printf("Ingrese el valor de n: ");
    scanf("%d", &n);
    }
    while (n<1);
    w= sqrt(pi2_6 (n)*6);
    printf("pi^2/6 es %f\n", w);
    system("PAUSE");
    return 0;
}

