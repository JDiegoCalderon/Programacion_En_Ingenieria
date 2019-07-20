//
//  main.c
//  Examen
//
//  Created by Mario Alberto Ibarra Manzano on 23/03/2015.
//  Copyright (c) 2015 Mario Alberto Ibarra Manzano. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

typedef struct lt{
    int Edad;
    struct lt *s;
}lt;

lt* gen_mem(void)
{
    lt* p;
    p = (lt*)malloc(sizeof(lt));
    return p;
}

lt* enlace(lt* lt1, lt* nv)
{
    lt *lt2, *lt3;
    if(lt1==NULL)
    {
        lt1 = nv;
        lt1->s = NULL;
    }
    else if(lt1->s==NULL)
    {
        if(lt1->Edad<nv->Edad)
        {
            lt1->s = nv;
            nv->s = NULL;
        }
        else
        {
            nv->s = lt1;
            lt1 = nv;
        }
    }
    else
    {
        
        lt2 = lt1;
        while((lt2->Edad<nv->Edad)&&(lt2->s!=NULL))
            lt2=lt2->s;
        if((lt2->s==NULL)&&(lt2->Edad<nv->Edad))
        {
            lt2->s = nv;
            nv->s = NULL;
        }
        else if(lt1==lt2)
        {
            nv->s=lt1;
            lt1=nv;
        }
        else
        {
            nv->s=lt2;
            lt3=lt1;
            while(lt3->s!=lt2)
                lt3=lt3->s;
            lt3->s=nv;
        }
    }
    return lt1;
}

int imprimir(lt *lt1)
{
    if(lt1!=NULL)
    {
        printf("Edad: %d\n", lt1->Edad);
        imprimir(lt1->s);
    }
    return 0;
}

void liberar1(lt *lt1)
{
    lt *lt2;
    lt2 = lt1;
    while(lt2!=NULL)
    {
        lt1 = lt1->s;
        free(lt2);
        lt2 = lt1;
    }
}

int liberar2(lt *lt1)
{
    if(lt1!=NULL)
    {
        liberar2(lt1->s);
        free(lt1);
    }
    return 0;
/*    lt *lt2;
    lt2 = lt1;
    if(lt2!=NULL)
    {
        lt1=lt1->s;
        free(lt2);
        liberar2(lt1);
    }
    return 0;*/
}

int main(void)
{
    int op, n=1;
    lt *lt1, *nv;
    lt1 = NULL;
    nv = NULL;
    do{
        nv = gen_mem();
        printf("Ingrese la edad de la persona %d: ", n++);
        scanf("%d", &(nv->Edad));
        lt1 = enlace(lt1, nv);
        printf("Desea ingresar otra edad: ");
        scanf("%d", &op);
    }while(op);
    imprimir(lt1);
    //liberar1(lt1);
    liberar2(lt1);
    n--;
    return 0;
}
















/*
#include <stdio.h>
#include <stdlib.h>

struct lt{
    float h;
    struct lt *next;
};

struct lt* gen_mem(void)
{
    struct lt *p;
    p = (struct lt*)malloc(sizeof(struct lt));
    return p;
}

int main()
{
    int op, n=1;
    struct lt *lt1, *nv;
    lt1=NULL;
    do{
        nv = gen_mem();
        printf("Ingrese la estatura de la persona %d: ", n++);
        scanf("%f", &(nv->h));
        if(lt1==NULL)
        {
            nv->next = NULL;
            lt1 = nv;
        }
        printf("Desea ingresar otro dato: ");
        scanf("%d", &op);
    }while(op);
    return 0;
}
*/
















/*
#include <stdio.h>

int suma(int n)
{
    if(n)
        return suma(n-1)+n;
    else
        return 0;
}

int producto(int n)
{
    if(n!=1)
        return producto(n-1)*n;
    else
        return 1;
}

int main(int argc, const char * argv[]) {
    int (*funcion)(int n);
    funcion = suma;
    int x=funcion(4);
    printf("%d\n",x);
    return 0;
}
*/
