#include <stdio.h>
#include <stdlib.h>

int main()
{
    int flag=0;
    int numero=0;
    int total=0;
    float promedio=0;

    printf("Ingrese 5 numeros:\n");

    while(flag < 5)
    {
        flag++;
        scanf("%d",&numero);
        fflush(stdin);
        total = numero+total;
    }
    promedio = (float)=total/flag;
    printf("el promedio es %f",promedio);

    return 0;
}
