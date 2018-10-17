#include <stdio.h>
#include <stdlib.h>

int main()
{
    int nro;
    int *ptr;
    nro = 7;
    ptr = &nro;
    printf("nro=%d \n ptr=%d\n\n", nro, *ptr );

    *ptr = 13;
    printf("nro=%d \n ptr=%d\n\n", nro, *ptr );

    return 0;
}
