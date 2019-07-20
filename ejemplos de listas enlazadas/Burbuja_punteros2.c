#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(void)
{
    float *pA, max, min, aux;
    int n, i, j;
    do{
        printf("Ingrese el numero de elementos: ");
        scanf("%d", &n);
    }while(n<1);
    printf("Ingrese el maximo: ");
    scanf("%f", &max);
    printf("Ingrese el minimo: ");
    scanf("%f", &min);
    if(min>max)
    {
        min=min+max;
        max=min-max;
        min=min-max;
    }
    srand(time(NULL));
    pA=(float*)malloc(n*sizeof(float));
    printf("Vector desordenado:\n");
    for(i=0; i<n;i++)
    {
        pA[i]=((max-min)*rand())/RAND_MAX+min;
        printf("A[%d] = %f\n", i+1, *(pA+i));
    }
    for(i=0;i<n-1;i++)
        for(j=i+1;j<n;j++)
            if(pA[i]>*(pA+j))
            {
                aux=pA[j];
                pA[j]=pA[i];
                pA[i]=aux;
            }
    printf("Vector ordenado.\n");
    for(i=0;i<n;i++)
        printf("A[%d]=%f\n",i+1,pA[i]);
    system("PAUSE");
    free(pA);
    return 0;
}




