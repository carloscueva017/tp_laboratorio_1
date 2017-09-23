#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "funciones.h"


int main()
{
    EPersona datos[20];

    inicializacion(datos);

    char seguir='s';
    int opcion=0;

    while(seguir=='s')
    {
        printf("\n|----------------------------------------|");
        printf("\n|                 MENU                   |");
        printf("\n|----------------------------------------|");
        printf("\n|1- Agregar Persona                      |");
        printf("\n|2- Borrar Persona                       |");
        printf("\n|3- Imprimir Lista Ordenada por Nombre   |");
        printf("\n|4- Imprimir Grafico de Edades           |");
        printf("\n|5- Buscar DNI                           |");
        printf("\n|6- Salir                                |");
        printf("\n|----------------------------------------|\n");
        printf("Elegir Opcion: ");
        scanf("%d",&opcion);


        switch(opcion)
        {
            case 1:
                agregarPersona(datos);
                break;
            case 2:
                borrarPersona(datos);
                break;
            case 3:
                imprimirListaOrdenadaPorNombre(datos);
                break;
            case 4:
                graficar(datos);
                break;
            case 5:
                buscarPorDni(datos);
                break;
            case 6:
                seguir = 'n';
                break;
        }
    }

    return 0;
}
