#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numero1;
    int numero2;
    int resultado;

    printf("Ingrese 2 numeros a sumar:\n");
    scanf("%d", &numero1);
    fflush(stdin);
    scanf("%d", &numero2);

    resultado= numero1+numero2;
    printf("El resultado es:%d", resultado);
    return 0;
}
