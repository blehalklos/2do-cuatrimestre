#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numero1=0;
    int numero2=0;

    scanf("Ingrese el primer numero: %d \n", &numero1);
    fflush(stdin);
    scanf("Ingrese el segundo numero: %d \n", &numero2);

    int producto = numero1*numero2;
    int cuadrado=numero1*numero1;

    printf("producto: %d \n", producto);
    printf ("cuadrado: %d \n", cuadrado);

    return 0;
}
