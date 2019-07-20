#include<stdio.h>
#include<stdlib.h>

#define NC 50
#define MC 150

struct materia{
       char nom[NC];
       float calf;
       char ap;
       char op;
       };

struct kardex{
       unsigned int ID;
       char nom[NC];
       unsigned int nm;
       struct materia mt[MC];
       };

int main(void)
{
    FILE *fp;
    struct kardex dt1, dt2;
    int i;
    char op;
    i=0;
    do{
        printf("Ingrese el identificador: ");
        scanf("%u", &dt1.ID);
        printf("Ingrese el nombre: ");
        scanf("%s", &dt1.nom[0]);
        dt1.nm=0;
        do{
            printf("Ingrese la materia: ");
            scanf("%s", &dt1.mt[dt1.nm].nom[0]);
            printf("Ingrese la calificacion: ");
            scanf("%f", &dt1.mt[dt1.nm].calf);
            if(dt1.mt[dt1.nm].calf>=7)
                dt1.mt[dt1.nm].ap=1;
            else
                dt1.mt[dt1.nm].ap=0;
            printf("Ingrese la oportunidad: ");
            scanf("%u", &dt1.mt[dt1.nm].op);
            printf("Desea agregar otra materia[S/N]: ");
            op=getch();
            dt1.nm++;
        }while((op=='s'||op=='S')&&dt1.nm<MC);
        printf("Desea agregar otro alumno[S/N]: ");
        op=getch();
        i++;
    }while(op=='S'||op=='s');
    fp=fopen("Base.dat","wb");
    fwrite(&dt1, sizeof(dt1), 1, fp);  ///Los parámetros son: un puntero a la zona de memoria de donde se
    ///obtendrán los datos a escribir, el tamaño de cada registro, el número de registros a escribir
    ///y un puntero a la estructura FILE del fichero al que se hará la escritura.
    fclose(fp);
    fp=fopen("Base.dat","rb");
    fread(&dt2, sizeof(dt1), 1, fp);
    fclose(fp);
    printf("%u, %s", dt2.ID, dt2.nom);
    system("PAUSE");
    return 0;
}
