#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main()
{
    int op1=0,op2=0,resultado;
    float resultadoDivision;
    char seguir='s';
    int opcion=0;

    while(seguir=='s')
    {
        printf("\n1- Ingresar 1er operando (A=%d)\n",op1);
        printf("2- Ingresar 2do operando (B=%d)\n",op2);
        printf("3- Calcular la suma (%d+%d)\n",op1,op2);
        printf("4- Calcular la resta (%d-%d)\n",op1,op2);
        printf("5- Calcular la division (%d/%d)\n",op1,op2);
        printf("6- Calcular la multiplicacion (%d*%d)\n",op1,op2);
        printf("7- Calcular el factorial (%d!)\n",op1);
        printf("8- Calcular todas las operacione\n");
        printf("9- Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                printf("Ingrese Numero 1: ");
                scanf("%d",&op1);
                system("cls");
                continue;
            case 2:
                printf("Ingrese Numero 2: ");
                scanf("%d",&op2);
                system("cls");
                continue;
            case 3:
                resultado=suma(op1,op2);
                printf("La Suma es: %d \n",resultado);
                continue;
            case 4:
                resultado=resta(op1,op2);
                printf("La Resta es: %d \n",resultado);
                continue;
            case 5:
                resultadoDivision=division(op1,op2);
                printf("La Division. es: %.2f \n",resultadoDivision);
                continue;
            case 6:
                resultado=multiplicacion(op1,op2);
                printf("La Multiplicacion es: %d \n",resultado);
                continue;
            case 7:
                resultado=factorial(op1);
                printf("Factorial: %d \n",resultado);
                continue;
            case 8:
                resultado=suma(op1,op2);
                printf("La Suma es: %d \n",resultado);
                resultado=resta(op1,op2);
                printf("La Resta es: %d \n",resultado);
                resultado=division(op1,op2);
                printf("La Division es: %d \n",resultado);
                resultado=multiplicacion(op1,op2);
                printf("La Multiplicacion es: %d \n",resultado);
                continue;
            case 9:
                seguir = 'n';
                break;
        }

    }
    return 0;
}
