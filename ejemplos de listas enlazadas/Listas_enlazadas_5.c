//
//  main.c
//  Ejemplo1
//
//  Created by Mario Alberto Ibarra Manzano on 02/02/2016.
//  Copyright (c) 2016 Mario Alberto Ibarra Manzano. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct dir{
    char calle[30];
    int numero;
    char colonia[30];
    int CP;
}dir;

typedef struct paciente{
    char nombre[30];
    dir dr;
    float peso;
    float estatura;
    struct paciente *s;
}paciente;

int tamanio(paciente *lt)
{
    if(lt==NULL)
        return 0;
    else
        return tamanio(lt->s)+1;
}

paciente *ingresar(paciente *p1)
{
    paciente *nv, *aux;
    nv=(paciente*)malloc(sizeof(paciente));
    printf("Nombre: ");
    scanf("%s", nv->nombre);
    printf("Direccion.\nCalle: ");
    scanf("%s", nv->dr.calle);
    printf("Numero: ");
    scanf("%d", &(nv->dr.numero));
    printf("Colonia: ");
    scanf("%s", nv->dr.colonia);
    printf("Codigo Postal: ");
    scanf("%d", &(nv->dr.CP));
    printf("Peso: ");
    scanf("%f", &(nv->peso));
    printf("Estatura: ");
    scanf("%f", &(nv->estatura));
    nv->s=NULL;
    if(p1==NULL)
        p1=nv;
    else
    {
        aux=p1;
        while(aux->s!=NULL)
            aux=aux->s;
        aux->s=nv;
    }
    return p1;
}

void mostrar(paciente *p1)
{
    int i=1;
    printf("Nombre\tDireccion\tPeso\tEstatura\n");
    while(p1!=NULL)
    {
        printf("%d. %s\t%s %d, %s, CP: %d\t%f\t%f\n", i++, p1->nombre, p1->dr.calle, p1->dr.numero, p1->dr.colonia, p1->dr.CP, p1->peso, p1->estatura);
        p1=p1->s;
    }
}

int liberar(paciente *p1)
{
    paciente *aux;
    if(p1!=NULL)
    {
        aux=p1;
        p1=p1->s;
        free(aux);
        return liberar(p1);
    }
    else
        return 0;
}

paciente *eliminar(paciente *p1)
{
    int sel, n, i=1;
    paciente *aux1, *aux2;
    mostrar(p1);
    printf("Selecciona el registro a eliminar: ");
    scanf("%d", &sel);
    n=tamanio(p1);
    if(sel>0&&sel<=n)
    {
        aux2=p1;
        aux1=p1;
        for(; sel>1; sel--)
        {
            aux1=aux2;
            aux2=aux2->s;
        }
        if(aux1!=aux2)
            aux1->s=aux2->s;
        else
            p1=p1->s;
        free(aux2);
    }
    return p1;
}

void guardar(paciente *p1)
{
    int n, i;
    FILE *fp;
    n=tamanio(p1);
    fp=fopen("agenda.bin", "wb");
    fwrite(&n, sizeof(int), 1, fp);
    for(i=0; i<n; i++, p1=p1->s)
        fwrite(p1, sizeof(paciente), 1, fp);
    fclose(fp);
}

paciente *leer(paciente *p1)
{
    int m, n, i, op;
    FILE *fp;
    paciente *nv, *aux;
    m=tamanio(p1);
    fp=fopen("agenda.bin", "rb");
    printf("Desea sobre escribir: ");
    scanf("%d", &op);
    fread(&n, sizeof(int), 1, fp);
    if(op)
    {
        liberar(p1);
        for(i=0; i<n; i++)
        {
            nv=malloc(sizeof(paciente));
            if(i==0)
            {
                p1=nv;
                aux=nv;
            }
            fread(nv, sizeof(paciente), 1, fp);
            aux->s=nv;
            aux=nv;
        }
        aux->s=NULL;
    }
    else
    {
        for(i=0; i<n; i++)
        {
            nv=malloc(sizeof(paciente));
            if(i==0)
            {
                aux=p1;
                while(aux->s!=NULL)
                    aux=aux->s;
            }
            fread(nv, sizeof(paciente), 1, fp);
            aux->s=nv;
            aux=nv;
        }
        aux->s=NULL;
    }
    fclose(fp);
    return p1;
}

int main(int argc, char *argv[])
{
    paciente *p1=NULL;
    int op;
    do{
        printf("MENU:\n");
        printf("1. Ingresar un paciente.\n");
        printf("2. Mostrar pacientes.\n");
        printf("3. Buscar.\n");
        printf("4. Eliminar registro.\n");
        printf("5. Editar registro.\n");
        printf("6. Guardar registros.\n");
        printf("7. Cargar registros.\n");
        printf("8. Salir\n");
        printf("Opción: ");
        scanf("%d", &op);
        switch(op)
        {
            case 1:
                p1=ingresar(p1);
                break;
            case 2:
                mostrar(p1);
                break;
            case 3:
                break;
            case 4:
                p1=eliminar(p1);
                break;
            case 5:
                break;
            case 6:
                guardar(p1);
                break;
            case 7:
                p1=leer(p1);
                break;
            case 8:
                liberar(p1);
                printf("Saliendo...");
                break;
            default:
                printf("Opcion no valida.\n");
        }
    }while(op!=8);
    printf("\n");
    return 0;
}
