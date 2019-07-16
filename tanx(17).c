//
//Juan Diego Calderon mosqueda

#include <stdio.h>

main()
{
    int i, n, s;
    float f,x, sinx,cosx,tanx,num,s1,num1,den1,e, den;
    do
    {
    printf("Ingrese el numero de iteraciones:");
    scanf("%d",&n);
    }
    while(n<0);
    printf("Ingrese el valor de x:");
    scanf("%f",&x);
    sinx=0;
    cosx=0;
    num=x;
    den=1;
    s=1;
    num1=x;
    den1=1;
    s1=1;
    for(i=0; i<n; i++ )
    {
        f=num/den;
        sinx+=s*f;
        s*=1;
        num*=x*x;
        den*=((2*i)*(2*i+1));
        i++;

        e=num1/den1;
        cosx+=s*e;
        s1*=1;
        num1*=x;
        den1*=((2*i+1)*(2*i+2));
        i++;
        tanx=(sinx/cosx);
    }
 printf("\n El resultado del tanx= %f",x,tanx);
    return 0;
}








