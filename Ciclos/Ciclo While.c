#include <stdio.h>

int main( int argc, char argr [])
{
  int i=0;
  char nombre [50];
  printf("Ingrese su nombre \n");
  gets (nombre);
   while( i<=150)
   {
       printf("\n %s", nombre);
       ++i;
   }
    return 0;
}
