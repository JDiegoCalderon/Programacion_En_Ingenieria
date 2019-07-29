//
//Juan Diego Calderon mosqueda

#include <stdio.h>

main()
{
    int i, n, s;
    float f,x, cosx,secx, num, den;
    do
    {
    printf("Ingrese el numero de iteraciones:");
    scanf("%d",&n);
    }
    while(n<0);
    printf("Ingrese el valor de x:");
    scanf("%f",&x);
    cosx=0;
    num=x;
    den=1;
    s=1;
    for(i=0; i<n; i++ )
    {
        f=num/den;
        cosx+=s*f;
        s*=-1;
        num*=x;
        den*=(2*i+1)*(2*i+2);
        secx=(1/cosx);
    }
   printf("\n El resultado del secx= %f",x, secx);
    return 0;
}





