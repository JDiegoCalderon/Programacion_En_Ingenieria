#include<stdio.h>
#include<stdlib.h>

typedef struct Num{
        float x;
        struct Num *ps;
}Num;

Num* ultimo(Num *lp)
{
     if(lp->ps!=NULL)
          return ultimo(lp->ps);
     else
          return lp;
}

Num* agregar(Num *lp, float x)
{
    Num *lpaux, *lp_u;
    lpaux = (Num*)calloc(1,sizeof(Num));
    lpaux->x=x;
    lpaux->ps=NULL;
    if(lp!=NULL)
    {
        lp_u = ultimo(lp);
        lp_u->ps = lpaux;
        lpaux=lp;
    }
    return lpaux;
}

int imprimir(Num *lp)
{
    if(lp!=NULL)
    {
        printf("%f\n", lp->x);
        imprimir(lp->ps);
    }
}

Num* buscar(Num *lp, float x)
{
    if(lp==NULL)
        return lp;
    else if((lp->x)==x)
        return lp;
    else
        return buscar(lp->ps, x);
}

int liberar(Num *lp)
{
    Num *lpaux;
    if(lp!=NULL)
    {
        lpaux=lp->ps;
        free(lp);
        liberar(lpaux);
    }
}

int posicion(Num *lp, Num *lpb)
{
    int n;
    if(lpb==NULL)
        return 0;
    n=1;
    while(lp!=NULL)
    {
        if(lp==lpb)
            break;
        lp=lp->ps;
        n++;
    }
    return n;
}

int main(void)
{
    Num *lp=NULL;
    int op, n;
    float x;
    do{
        printf("Ingrese un numero: ");
        scanf("%f", &x);
        lp = agregar(lp, x);
        printf("Desea ingresar un dato [S=1,N=0]: ");
        scanf("%d", &op);
        }while(op);
    imprimir(lp);
    printf("Ingrese el valor a buscar: ");
    scanf("%f", &x);
    n = posicion(lp, buscar(lp, x));
    if(n)
        printf("La posicion es %d.\n", n);
    else
        printf("El valor no existe.\n");
    liberar(lp);
    system("PAUSE");
    return 0;
}
