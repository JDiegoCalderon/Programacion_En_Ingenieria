#include <stdio.h>
#include <stdlib.h>

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
       struct materia *mt;  // Materia
       };

int main(void)
{
    FILE *fp;
    struct kardex *kd, *kd2;
    int i, j, na, mc;
    unsigned int aux;
    char op;
    printf("Ingrese el numero de alumnos: ");
    scanf("%d", &na);
    kd = (struct kardex*)calloc(na, sizeof(struct kardex));
    kd2 = (struct kardex*)calloc(na, sizeof(struct kardex));
    for(i=0; i<na; i++)
    {
        printf("Ingrese el NUA: ");
        scanf("%ud", &kd[i].NUA);
        printf("Ingres el nombre: ");
        scanf("%s", &kd[i].nom[0]);
        printf("Ingrese el numero de materias: ");
        scanf("%u", &mc);
        kd[i].mt = (struct materia*)calloc(mc, sizeof(struct materia));
        kd2[i].mt = (struct materia*)calloc(mc, sizeof(struct materia));
        kd[i].nm = mc;
        for(j=0; j<mc; j++)
        {
            printf("Ingrese el nombre de la materia: ");
            scanf("%s", &kd[i].mt[j].nom[0]);
            printf("Ingrese el numero de creditos: ");
            scanf("%u", &aux);
            kd[i].mt[j].cred = aux;
            printf("Ingrese la calficacion: ");
            scanf("%f", &kd[i].mt[j].calf);
            kd[i].pr += kd[i].mt[j].calf;
            printf("Ingrese la oportunidad: ");
            scanf("%u", &aux);
            kd[i].mt[j].op = aux;
            if(kd[i].mt[j].calf>=7)
            {
                kd[i].mt[j].ap = 1;
                kd[i].nma++;
                kd[i].ct += kd[i].mt[j].cred;
            }
            else
                kd[i].mt[j].ap = 0;
        }
        kd[i].pr /= kd[i].nm;
    }
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
