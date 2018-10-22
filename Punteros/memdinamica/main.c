#include <stdio.h>
#include <stdlib.h>

int main()
{
    int* p;
    p=(int*)malloc(sizeof(int));

    if(p == NULL)
    {
        printf("ERROR 404");
        exit(1);
    }
    *p=33;
    printf("%d", *p);
    free(p);

    return 0;
}
