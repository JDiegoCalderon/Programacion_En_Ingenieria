#include <stdio.h>
#include <stdlib.h>

float media_m(float *pV, int p)
{
    if(p==1)
        return pV[0];
    else
        return (pV[0]+media_m(pV+1,p-1));
}

int main(int argc, char *argv[])
{
    int n, m, i, j, p;
    float **ppX, *pX, **ppY, *pY;
    FILE *fp;
    if(argc<3)
    {
        printf("Error: falta el nombre del archivo.\n");
        system("PAUSE");
        return 1;
    }
    fp = fopen(argv[1], "rt");
    p=atoi(argv[2]);
    if(fp==NULL)
    {
        printf("Error: fallo la lectura del archivo %s.\n",argv[1]);
        system("PAUSE");
        return 2;
    }
    fscanf(fp, "%d", &n);
    fscanf(fp, "%d", &m);
    pX=(float*)malloc(n*m*sizeof(float));
    if(pX==NULL)
    {
        printf("Error: asignamiento de memoria.\n");
        system("PAUSE");
        fclose(fp);
        return 3;
    }
    ppX=(float**)malloc(m*sizeof(float*));
    if(ppX==NULL)
    {
        printf("Error: asignamiento de memoria.\n");
        system("PAUSE");
        fclose(fp);
        free(pX);
        return 4;
    }
    for(i=0; i<m; i++)
        ppX[i]=pX+i*n;
    for(i=0; i<n; i++)
        for(j=0; j<m; j++)
            fscanf(fp, "%f", &ppX[j][i]);
    fclose(fp);
    printf("Numero de datos: %d\n", n);
    printf("Numero de vectores: %d\n", m);
    printf("Numero de elementos: %d\n", p);
    printf("Matriz original:\n");
    for(i=0; i<n; i++)
    {
        for(j=0; j<m; j++)
            printf("%f\t",ppX[j][i]);
        printf("\n");
    }
    pY=(float*)malloc(m*(n-p+1)*sizeof(float));
    if(pY==NULL)
    {
        printf("Error: asignamiento de memoria.");
        system("PAUSE");
        free(pX);
        free(ppX);
        return 5;
    }
    ppY=(float**)malloc(m*sizeof(float*));
    if(ppY==NULL)
    {
        printf("Error: asignamiento de memoria.");
        system("PAUSE");
        free(pX);
        free(ppX);
        free(pY);
        return 6;
    }
    for(i=0;i<m;i++)
        ppY[i]=pY+i*(n-p+1);
    for(i=0;i<m;i++)
        for(j=0;j<(n-p+1);j++)
            ppY[i][j]=media_m(ppX[i]+j,p)/p;
    printf("Matriz filtrada:\n");
    for(i=0; i<(n-p+1); i++)
    {
        for(j=0; j<m; j++)
            printf("%f\t",ppY[j][i]);
        printf("\n");
    }
    free(ppY);
    free(pY);
    free(ppX);
    free(pX);
    system("PAUSE");
    return 0;
}
