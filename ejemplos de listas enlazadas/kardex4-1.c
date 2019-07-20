

#include <stdio.h>
#include <stdlib.h>

#define MXC 20

typedef struct materia{
       char nom[MXC];       // Nombre de materia
       float calf;          // Calificacion
       unsigned char op;    // Oportunidad
       unsigned char cred;  // Creditos
       unsigned char ap;    // Aprobada
       }materia;

typedef struct kardex{
       unsigned int NUA;    // NUA
       char nom[MXC];       // Nombre del alumno
       float pr;            // Promedio
       unsigned char nm;    // Numero de materias
       unsigned char nma;   // Numero de materias aprobadas
       unsigned int ct;     // Creditos
       materia *mt;         // Materia
       struct kardex *ps;          // Puntero siguiente
       }kardex;

int main(void)
{
    FILE *fp;
    kardex *kd, *kd2;
    int i, j, na, mc;
    unsigned int aux;
    char op;
    kd2 = NULL;
    do{
        if(kd2==NULL)
        {
            kd2 = (kardex*)calloc(1,sizeof(kardex));
            if(kd2==NULL)
            {
                printf("Memoria insuficiente.\n");
                return 1;
            }
            kd = kd2;
            kd->ps = NULL;
        }
        else
        {
            kd->ps = (kardex*)calloc(1,sizeof(kardex));
            if(kd->ps == NULL)
            {
                do{
                    kd = kd2->ps;
                    free(kd2);
                    kd2 = kd;
                    }while(kd!=NULL);
            }
            kd = kd->ps;
            kd->ps = NULL;
        }
         printf("Ingrese el nombre: ");
         scanf("%s", &(kd->nom));
         printf("Ingrese el NUA: ");
         scanf("%d", &(kd->NUA));
         printf("Ingrese el promedio: ");
         scanf("%f", &(kd->pr));
         printf("Ingresar un nuevo usuario: ");
         op=getch();
         printf("%c\n", op);
    }while(op=='s'||op=='S');
    kd = kd2;
    do{
        printf("%d\t%s\t%f\n",kd->NUA, kd->nom, kd->pr);
        kd=kd->ps;
    }while(kd!=NULL);
    system("PAUSE");
    return 0;
}
