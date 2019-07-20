#include <stdio.h>

float ln2 (int n)
{
    int s;
    if (n==1)
        return 1;
    else{
        s= n%2? 1.0:-1.0;
        return (ln2(n-1)+ s/(1.0*n));
    }
}

int main(int argc, char* argv[])
{
    int n;
    float res, rep;
    do
    {
    printf("Ingrese el valor de n: ");
    scanf("%d", &n);
    }
    while (n<1);
    res= ln2(n);
    printf("ln(2)= %f\n", res);
    system("PAUSE");
    return 0;
}

