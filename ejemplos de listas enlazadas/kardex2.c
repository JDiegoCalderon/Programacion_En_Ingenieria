#include <stdio.h>
#include <stdlib.h>

#define MC 150
#define NA 20
#define MXC 20

struct materia{
       char nom[MXC];       // Nombre de materia
       float calf;          // Calificacion
       unsigned char op;    // Oportunidad
       unsigned char cred;  // Creditos
       unsigned char ap;    // Aprobada
       };

struct kardex{
       unsigned int NUA;    // NUA
       char nom[MXC];       // Nombre del alumno
       float pr;            // Promedio
       unsigned char nm;    // Numero de materias
       unsigned char nma;   // Numero de materias aprobadas
       unsigned int ct;     // Creditos
       struct materia mt[MC]; // Materia
       };

int main(void)
{
    FILE *fp;
    struct kardex kd[NA], kd2[NA];
    int i, j;
    unsigned int aux;
    char op;
    i=0;
    do{
        printf("Ingrese el NUA: ");
        scanf("%ud", &kd[i].NUA);
        printf("Ingrese el nombre: ");
        scanf("%s", &kd[i].nom[0]);
        kd[i].nm=0;
        kd[i].nma=0;
        kd[i].ct=0;
        do{
            printf("Ingrese el nombre de la materia: ");
            scanf("%s", &kd[i].mt[kd[i].nm].nom[0]);
            printf("Ingrese el numero de creditos: ");
            scanf("%u", &aux);
            kd[i].mt[kd[i].nm].cred = aux;
            printf("Ingrese la calficacion: ");
            scanf("%f", &kd[i].mt[kd[i].nm].calf);
            printf("Ingrese la oportunidad: ");
            scanf("%u", &aux);
            kd[i].mt[kd[i].nm].op = aux;
            if(kd[i].mt[kd[i].nm].calf>=7)
            {
                kd[i].mt[kd[i].nm].ap = 1;
                kd[i].nma++;
                kd[i].ct += kd[i].mt[kd[i].nm].cred;
            }
            else
                kd[i].mt[kd[i].nm].ap = 0;
            kd[i].nm++;
            printf("Ingresar otra materia [S/N]: ");
            op = getch();
            printf("%c\n", op);
        }while((op=='s'||op=='S')&&kd[i].nm<MC);
        for(j=0, kd[i].pr=0; j<kd[i].nm; j++)
            kd[i].pr += kd[i].mt[j].calf;
        kd[i].pr /= kd[i].nm;
        printf("Ingresar otro alumno [S/N]: ");
        op = getch();
        printf("%c\n", op);
        i++;
        }while((op=='s'||op=='S')&&i<NA);
    fp = fopen("base.bin", "wb");
    if(fp==NULL)
    {
        printf("Error al crear el archivo.\n");
        return 1;
    }
    fwrite(kd, sizeof(struct kardex), i, fp);
    fclose(fp);
    fp = fopen("base.bin", "rb");
    if(fp==NULL)
    {
        printf("Error al abrir el archivo.\n");
        return 2;
    }
    fread(kd2, sizeof(struct kardex), i, fp);
    fclose(fp);
    for(j=0; j<i; j++)
    {
        printf("%10s\t%u\t%u\t%f\n", kd2[j].nom, kd2[j].nm, kd2[j].ct, kd2[j].pr);
    }
    system("PAUSE");
    return 0;
}
