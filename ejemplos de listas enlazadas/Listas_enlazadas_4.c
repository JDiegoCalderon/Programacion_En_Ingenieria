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

int main(int argc, char *argv[])
{
    paciente *lt, *nv, *aux, **ord;
    int op, i, j, n, fl=0;
    FILE *fp;
    lt=NULL;
    fp=fopen("agenda.bin", "rb");
    if(fp==NULL)
    // Captura de informacion
        do{
            nv = (paciente*)malloc(sizeof(paciente));
            if(nv==NULL)
            {
                printf("Error al crear la memoria.\n");
                while(lt!=NULL)
                {
                    aux=lt;
                    lt=lt->s;
                    free(aux);
                }
                return 1;
            }
            printf("Ingrese el nombre: ");
            scanf("%s", nv->nombre);
            printf("Direccion.\n");
            printf("Ingrese su calle: ");
            scanf("%s", nv->dr.calle);
            printf("Ingrese el numero: ");
            scanf("%d", &(nv->dr.numero));
            printf("Ingrese la colonia: ");
            scanf("%s", nv->dr.colonia);
            printf("Ingrese el codigo postal: ");
            scanf("%d", &(nv->dr.CP));
            printf("Ingrese el peso: ");
            scanf("%f", &(nv->peso));
            printf("Ingrese la estatura: ");
            scanf("%f", &(nv->estatura));
            if(lt==NULL)
            {
                lt=nv;
                lt->s=NULL;
            }
            else
            {
                aux=lt;
                while(aux->s!=NULL)
                    aux=aux->s;
                aux->s=nv;
                nv->s=NULL;
            }
            printf("Deseae ingresar otro paciente[S/N]: ");
            scanf("%d", &op);
        }while(op);
    else
    {
        fread(&n, sizeof(n), 1, fp);
        lt=malloc(n*sizeof(paciente));
        fread(lt, sizeof(paciente), n, fp);
        for(i=0; i<n-1; i++)
            lt[i].s=(lt+i+1);
        lt[i].s=NULL;
        fclose(fp);
        fl=1;
    }
    // Imprimir la lista enlazada
    aux=lt;
    n=tamanio(lt);
    fp=fopen("agenda.bin", "w+b");
    fwrite(&n, sizeof(n), 1, fp);
    printf("Nombre\tPeso\tEstatura\n");
    while(aux!=NULL)
    {
        fwrite(aux, sizeof(paciente), 1, fp);
        printf("%s\t%f\t%f\n", aux->nombre, aux->peso, aux->estatura);
        aux=aux->s;
    }
    fclose(fp);
    // Ordenamiento de la lista enlazada
    printf("Numero de pacientes: %d\n", n);
    ord = (paciente**)malloc(n*sizeof(paciente*));
    if(ord==NULL)
    {
        printf("Error en la creacion de memoria.\n");
        while(lt!=NULL)
        {
            aux=lt;
            lt=lt->s;
            free(aux);
        }
        return 2;
    }
    for(i=0, aux=lt; i<n; i++, aux=aux->s)
        ord[i] = aux;
    for(i=0; i<n-1; i++)
        for(j=i+1; j<n; j++)
            if(ord[i]->peso>ord[j]->peso)
            {
                aux=ord[i];
                ord[i]=ord[j];
                ord[j]=aux;
            }
    // Imprimir la lista enlazada ordenada
    printf("Nombre\tPeso\tEstatura\n");
    for(i=0; i<n; i++)
        printf("%s\t%s %d, CP: %d\t%f\t%f\n", ord[i]->nombre, ord[i]->dr.calle, ord[i]->dr.numero, ord[i]->dr.CP,ord[i]->peso, ord[i]->estatura);
    // Liberar memoria
    free(ord);
    if(fl)
        free(lt);
    else
        while(lt!=NULL)
        {
            aux=lt;
            lt=lt->s;
            free(aux);
        }
    return 0;
}
