#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#include "funciones.c"

int main()
{
    char seguir='s';
    int opcion=0;
    float A=0;
    float B=0;
    float resultadoSuma;
    float resultadoResta;
    float resultadoProducto;
    float resultadoDivision;
    float resultadoA;
    float resultadoB;



    while(seguir=='s')
    {


        system("cls");

        printf("1- Ingresar 1er operando (A)= %.2f \n\n", A);
        printf("2- Ingresar 2do operando (B)= %.2f \n\n", B);
        printf("3- Calcular todas las operaciones\n");
        printf(" a) Calcular la suma (A+B)\n");
        printf(" b) Calcular la resta (A-B)\n");
        printf(" c) Calcular la division (A/B)\n");
        printf(" d) Calcular la multiplicacion (A*B)\n");
        printf(" e) Calcular el factorial (A!)\n\n");
        printf("4- Informar los resultados\n");
        printf(" a) Informa la suma (A+B)\n");
        printf(" b) Informa la resta (A-B)\n");
        printf(" c) Informa la division (A/B)\n");
        printf(" d) Informa la multiplicacion (A*B)\n");
        printf(" e) Informa el factorial (A!)\n\n");
        printf("5- Salir\n");

        scanf("%d", &opcion);

        switch(opcion)
        {
            case 1:

                system("cls");
                printf("Ingrese el numero A\n");
                scanf("%f", &A);

                break;

            case 2:

               system("cls");
               printf("Ingrese el numero B\n");
               scanf("%f", &B);

                break;

            case 3:

                system("cls");
                printf("Exito!\n");
                system("pause");
                resultadoSuma = sumar(A,B);
                resultadoResta = resta(A,B);

                if(B != 0)
                {
                  resultadoDivision = division(A,B);
                }

                resultadoProducto = producto(A,B);

                if(A >= 0)
                {

                        resultadoA = factorial(A);
                }

                if(B >= 0)
                {
                        resultadoB = factorial(B);
                }

                break;



            case 4:



                printf("El resultado de la suma es %.2f \n", resultadoSuma);
                printf("El resultado de la resta es %.2f \n", resultadoResta);

                if (B == 0)
                    {
                        printf("No puede dividir por 0 \n");
                    }
                    else
                        {
                            printf("El resultado de la division es %.2f \n", resultadoDivision);
                        }

                printf("El resultado de la multiplicacion es %.2f \n", resultadoProducto);

                if (A < 0)
                    {
                        printf("No puede factorizar por un numero negativo \n");
                    }

                else if (A >= 13)
                    {
                        printf("El numero a factorizar es demasiado grande, por favor use uno mas chico \n");
                    }

                else
                    {
                        printf("El factorial de %.2f es %.2f \n", A, resultadoA);
                    }

                if (B < 0)
                    {
                        printf("No puede factorizar por un numero negativo \n");
                        system("pause");
                        break;
                    }

                else if (B >= 13)
                    {
                        printf("El numero a factorizar es demasiado grande, por favor use uno mas chico \n");
                    }

                    else
                    {
                        printf("El factorial de %.2f es %.2f \n", B, resultadoB);
                    }

                system("pause");
                break;

            case 5:

                seguir = 'n';
                break;

            default:

                system("cls");
                printf("Ingrese una opcion valida de la lista por favor \n"); // Declarado un default en caso de que el User ingrese una opcion no valida
                system("pause");
        }

}
    return 0;

}





