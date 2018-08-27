#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numero=0;
    int total=0;
    float promedio=0;
    int contador=0;
    char flag='s';

    while(flag=='s')
    {
        contador++;
        system("cls");
        fflush(stdin);
        printf("Ingrese un numero:");
        scanf("%d", &numero);
        total= numero+total;
        fflush(stdin);
        printf("Desea agregar otro numero? s->si,n->no : ");
        scanf("%c", &flag);
    }

    promedio= (float) total/contador;

    printf("El promedio de los numeros ingresados es: %.2f", promedio);
    return 0;
}
