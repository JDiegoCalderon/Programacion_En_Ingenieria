//
//  Proyecto "KARDEX"
//
//  Created by Juan Diego Calderón Mosqueda, Maria Guadalupe Hernandez Villafuerte, Dulce Maria Frias on 03/06/2016.
//  Copyright (c) 2016 Juan Diego Calderón Mosqueda, Maria Guadalupe Hernandez Villafuerte, Dulce Maria Frias . All rights reserved.

#include <stdio.h>
#include <stdlib.h>
#define NO 300

int nnn;
int nperiodo;
FILE *doc;

typedef struct materia{
       int nua;
       int nper;
       char nom[NO];       // Nombre de materia
       float calf;          // Calificacion
       unsigned char op;    // Oportunidad
       unsigned char cred;  // Creditos
       unsigned char ap;    // Aprobada
       struct materia *ps;
       }materia;

typedef struct periodo{
        int nper;
        unsigned int nua;          //periodo
        struct periodo *ps; //puntero siguiente
        }periodo;


typedef struct kardex{
       unsigned int nua;     // NUA
       char nom[NO];        // Nombre del alumno
       unsigned char nm;     // Numero de materias
       unsigned char nma;    // Numero de materias aprobadas
       unsigned int ct;      // Creditos
       struct kardex *ps;    // Puntero siguiente
       }kardex;

void imp_k(struct kardex *ppt)
   {
     fprintf(doc,"\n\n");
     printf("Nua: %d\n",ppt->nua);
     printf("Alumno: %s\n",ppt->nom);
     fprintf(doc, "Nua: %d\n",ppt->nua);
     fprintf(doc, "Alumno: %s\n",ppt->nom);
    }

void imp_p(struct periodo *ppt)
{
     printf("periodo: %d\n",ppt->nper);
     fprintf(doc, "periodo: %d\n",ppt->nper);
}
void imp_m(struct materia *ppt)
{
     printf("Materia: %s\n",ppt->nom);
     printf("Calificacion: %f\n",ppt->calf);
     fprintf(doc, "Materia: %s\n",ppt->nom);
     fprintf(doc, "Calificacion: %f\n",ppt->calf);
}

struct kardex * nuevo_k(kardex *ppk)
{
    kardex *aux;
    aux=ppk;
    if(aux==NULL)
    {
        aux=(kardex*)malloc(1*sizeof(kardex));
        printf("Ingrese el nombre: ");
        scanf("%s", &(aux->nom));
        printf("Ingrese el NUA: ");
        scanf("%d", &(aux->nua));
        nnn=aux->nua;
        aux->ps=NULL;
        return aux;
    }
    else
    {

        if(aux->ps!=NULL)
            do{
                aux=aux->ps;
            }while(aux->ps!=NULL);
            aux->ps=(kardex*)calloc(1, sizeof(kardex));
            aux=aux->ps;
            aux->ps=NULL;

    }
        printf("Ingrese el nombre: ");
         scanf("%s", &(aux->nom));
         printf("Ingrese el NUA: ");
         scanf("%d", &(aux->nua));
         nnn=aux->nua;
         return ppk;
}

struct periodo * nuevo_p(struct periodo *ppp)
{
    periodo *aux;
    aux=ppp;
    if(aux==NULL)
       {
        aux=(periodo*)calloc(1,sizeof(periodo));
        printf("Ingrese el numero de periodo: ");
        scanf("%d", &(aux->nper));
        nperiodo=aux->nper;
        aux->nua=nnn;
        aux->ps=NULL;
        return aux;
       }
       else
       {
           if(aux->ps!=NULL)
            do
            {
                aux=aux->ps;
            }while(aux->ps!=NULL);
            aux->ps=(periodo*)calloc(1, sizeof(periodo));
            aux=aux->ps;
            aux->ps=NULL;
       }
        printf("Ingrese el numero de periodo: ");
        scanf("%d", &(aux->nper));
        aux->nua=nnn;
        nperiodo=aux->nper;
        return ppp;

}

struct materia * nuevo_m(struct materia *ppm)
{
    materia *aux;
    aux=ppm;
    if(aux==NULL)
       {
        aux=(materia*)calloc(1,sizeof(materia));
        printf("Ingrese el nombre de la materia: ");
        scanf("%s", &(aux->nom));
        printf("Ingrese la calificacion: ");
        scanf("%f", &(aux->calf));
        aux->nua=nnn;
        aux->nper=nperiodo;
        aux->ps=NULL;
        return aux;
       }
       else
       {
           if(aux->ps!=NULL)
            do
            {
                aux=aux->ps;
            }while(aux->ps!=NULL);
            aux->ps=(materia*)calloc(1, sizeof(materia));
            aux=aux->ps;
            aux->ps=NULL;
       }
          printf("Ingrese el nombre de la materia: ");
          scanf("%s", &(aux->nom));
          printf("Ingrese la calificacion: ");
         scanf("%f", &(aux->calf));
         aux->nua=nnn;
         aux->nper=nperiodo;
         return ppm;
}

void buscar(int nnua,struct kardex *iniciokdx,struct periodo *inicioper,struct materia *iniciomt)
{
 	kardex *auxk;
   int cont2, cont;
   periodo *auxp;
   materia *auxm;
   auxk=iniciokdx;
   auxp=inicioper;
   auxm=iniciomt;
 	if(auxk==NULL)
    {
        printf("LISTA VACIA\n");
        fprintf(doc, "LISTA VACIA\n");
    }
 	else
 	{
     	do
     	{
        	if(auxk->nua==nnua)
           imp_k(auxk);
        	else
           auxk=auxk->ps;
      }while((auxk!=NULL) && (auxk->nua!=nnua));
     	if(auxk==NULL)
            {
                printf("NO ENCONTRADO\n");
                fprintf(doc, "NO ENCONTRADO\n");
            }
      else
      {
         if(auxk->nua==nnua){
            cont2 =0;
         if(auxp==NULL)
         {
           	printf("NO HAY PERIODOS\n");
           	fprintf(doc, "NO HAY PERIODOS\n");
         }
         else
         {
            do{
               if(auxp->nua==nnua)
               {
                  cont2 ++;
                  imp_p(auxp);
                  nperiodo=auxp->nper;
               }
               if(auxm==NULL)
                  {
                  printf("NO TIENE MATERIAS\n");
                  fprintf(doc, "NO TIENE MATERIAS\n");
                  }
               else
               {
                  do
                  {
                     if((auxm->nua==nnua)&&(auxm->nper==nperiodo))
                    	{
                        imp_m(auxm);
                        cont ++;
                     }
                     auxm=auxm->ps;
                  }while(auxm!=NULL);
                  auxm=iniciomt;
                  if(cont==0)
                     //printf("SIN MATERIAS\n");
                  cont=0;
               }
               auxp=auxp->ps;
            }while(auxp!=NULL);
            nperiodo=0;
            if(cont2==0)
              	{
              	    printf("NO TIENE PERIODOS\n");
              	    fprintf(doc, "NO TIENE PERIODOS\n");
              	}
            }
         }
      }
   }
}


void imprimir_todos(struct kardex *iniciokdx,struct periodo *inicioper,struct materia *iniciomt)
{
 	if(iniciokdx==NULL)
 	{
 	    printf("LA LISTA ESTA VACIA\n");
        fprintf(doc, "LA LISTA ESTA VACIA\n");
 	}
 else
    {
     	do{
        	buscar(iniciokdx->nua,iniciokdx,inicioper,iniciomt);
        	iniciokdx=iniciokdx->ps;
     	}while(iniciokdx!=NULL);

     }
}
int main()
{
    doc = fopen("Tarea 3.txt", "w");
    kardex *iniciok,*auxkk;
    periodo *iniciop,*auxpp;
    materia *iniciom, *auxmm;
    iniciok=NULL;
    iniciom=NULL;
    iniciop=NULL;
    auxkk=NULL;
    auxpp=NULL;
    auxmm=NULL;
    int opcion,cont2,cont1,nnua;
    char op,opp;


    do{
      printf("1. Agregar un nuevo estudiante al Kardex\n");
      printf("2. Mostrar kardex\n");
      printf("3. Mostrar todos los estudiantes del kardex\n");
      printf("\nEliga una opcion:");
      scanf("%d", &opcion);
      switch(opcion)
      {
         case 1:
              do{
                    iniciok=nuevo_k (iniciok);


                      do{
                            iniciop=nuevo_p(iniciop);

                              do{
                                    iniciom=nuevo_m(iniciom);
                                    printf("Desea ingresar un nuevo Materia[S][N]: ");
                                    op=getch();
                                    printf("%c\n", op);

                                }while(op=='s'||op=='S');

                            printf("Desea ingresar un nuevo Periodo[S][N]: ");
                            op=getch();
                            printf("%c\n", op);

                        }while(op=='s'||op=='S');

                    printf("Desea ingresar un nuevo usuario[S][N]: ");
                    op=getch();
                    printf("%c\n", op);
                }while(op=='s'||op=='S');
                printf("Volver a mostrar menu?[S][N]\n");
                opp=getch();
                break;

         case 2:
            printf("Dame una nua\n");
            scanf("%d",& (nnua));
            buscar(nnua,iniciok,iniciop,iniciom);

            printf("Volver a mostrar menu?[S][N]\n");
            opp=getch();
            break;
         case 3:
            imprimir_todos(iniciok,iniciop,iniciom);
            printf("Volver a mostrar menu?[S][N]\n");
            opp=getch();
            break;
         default:
            printf("No valido\n");
            printf("Volver a mostrar menu?[S][N]\n");
            opp=getch();

    }
    }while(opp=='s'||opp=='S');
    fprintf(doc, "\n\n\tFIN!");
    fclose(doc);
   return 0;

}
