#include <stdio.h>
#include <stdlib.h>
#define CANT 5

int main()
{
    int legajo[CANT];
    int isEmpty[CANT];
    float salario[CANT];
    int i;

    for(i=0; i < CANT; i++)
    {
        isEmpty[i]=1;
    }

    for(i=0; i<CANT; i++)
    {
        if(isEmpty[i]==1)
        {
            printf("legajo");
            scanf("%d",&legajo[i]);
            printf("salario");
            scanf("%d",&salario[i]);
            isEmpty[i]=0;
            break;
        }
    }

    return 0;
}
