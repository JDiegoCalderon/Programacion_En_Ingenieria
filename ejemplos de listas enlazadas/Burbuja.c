#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define N 10000

int main(void)
{
    int A[N];
    int max, min, aux, i, j, ne;
    srand(time(NULL));
    do{
        printf("Ingrese el numero de elementos: ");
        scanf("%d", &ne);
        }while(ne<1||ne>N);
    printf("Ingrese el maximo: ");
    scanf("%d", &max);
    printf("Ingrese el minimo: ");
    scanf("%d", &min);
    if(min>max)
    {
        max=max+min;
        min=max-min;
        max=max-min;
    }
    printf("Vector desordenado.\n");
    for(i=0; i<ne; i++)
    {
        A[i] = (int)(max-min)*((1.0*rand())/RAND_MAX)+min;
        printf("A[%d] = %d\n", i+1, A[i]);
    }
    for(i=0; i<ne-1; i++)
        for(j=i+1; j<ne; j++)
            if(A[i]>A[j])
            {
                aux=A[j];
                A[j]=A[i];
                A[i]=aux;
            }
    printf("Vector Ordenado\n");
    for(i=0;i<ne;i++)
        printf("A[%d]=%d\n",i+1,A[i]);
    system("PAUSE");
    return 0;
}





