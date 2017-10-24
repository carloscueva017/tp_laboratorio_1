#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"



int main()
{
    EMovie peliculas[CANTIDAD];
    inicializar(peliculas,10);


    char seguir='s';
    int opcion=0;

    while(seguir=='s')
    {
        printf("\n");
        printf("|-------------------------|\n");
        printf("|----------MENU-----------|\n");
        printf("|-------------------------|\n");
        printf("| 1- Agregar pelicula     |\n");
        printf("| 2- Borrar pelicula      |\n");
        printf("| 3- Modificar Pelicula   |\n");
        printf("| 4- Generar pagina web   |\n");
        printf("| 5- Lista de Peliculas   |\n");
        printf("| 6- Salir                |\n");
        printf("|-------------------------|\n");

        printf("Ingrese Opcion: ");
        scanf("%d",&opcion);

        if(opcion<0 || opcion>7)
        {
            printf("Opcion No Valida");
            break;
        }

        switch(opcion)
        {
            case 1:
                system("cls");
                agregarPelicula(peliculas,10);
                break;
            case 2:
                system("cls");
                borrarPelicula(peliculas);
                break;
            case 3:
                system("cls");
                modificarPelicula(peliculas,CANTIDAD);
               break;
            case 4:
                system("cls");
                generarPagina(peliculas);
                break;
            case 5:
                system("cls");
                listaPelicula(peliculas);
                break;
            case 6:
                seguir = 'n';
                break;
        }
    }

    return 0;
}
