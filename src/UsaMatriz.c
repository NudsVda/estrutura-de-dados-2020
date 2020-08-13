#include <stdio.h>
#include "matriz.h"

int main (void)
{
    Matriz* m = matriz_cria(6,6);    

    matriz_atribui(m,2,3,2.0);

    float v = matriz_acessa(m,2,3);    

    printf ("O valor é : %f\n",v);

    matriz_libera(m);

    return 0;
}