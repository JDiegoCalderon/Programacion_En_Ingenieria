//
//
// Juan Diego Calderon Mosqueda
//

#include <stdio.h>

int main(int argc, const char * argv[])
{
    int i, n, sg ;
    float ln;
    printf("Ingrese el numero de iteraciones: ");
    scanf("%d", &n);

    for(i=0, ln=0, sg=1; i<n; i++, sg*=(-1))
        ln+= (sg*1.0)/(i+1);
        printf("El Ln (2) es = %f", ln);
    return 0;
}
