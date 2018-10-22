#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numero=9;
    int tam=1;
     for(int i = 0; i < tam; i++)
     {
         numero = numero*numero;
         printf("%d", numero);
         printf("lol");
         tam++;
     }
    return 0;
}
