#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "funciones.h"
#define CANT 19

int inicializacion(EPersona lista[])
{
    int x;
    for (x=0;x<CANT;x++)
    {
        lista[x].estado=0;
    }
}

int agregarPersona(EPersona lista[])
{
    EPersona est;
    int z;

    for(z=0;z<20;z++)
    {
        if(lista[z].estado==0)
        {
            printf("Nombre: ");
            setbuf(stdin,NULL);
            scanf("%[^\n]",lista[z].nombre);

            printf("Edad: ");
            scanf("%d",&lista[z].edad);

            printf("D.N.I: ");
            scanf("%ld",&lista[z].dni);

            lista[z].estado=1;
            break;
            }

    }

    if(est.estado==0)
        {
            printf("ESPACIO INSUFICIENTE\n");
        }else{
            printf("DATOS CARGADOS\n");
        }
}

int borrarPersona(EPersona lista[])
{
    int y;
    int dni;
    printf("Ingrese DNI de Persona a Eliminar:\n");
    scanf("%d",&dni);

    for(y=0;y<CANT;y++)
    {
        if(dni == lista[y].dni)
        {
            lista[y].estado=0;
            printf("La Persona fue Eliminada Correctamente.\n");
            return;

        }
    }

    printf("No Se encontro DNI.\n");
}

int obtenerEspacioLibre(EPersona lista[],int pos)
{
    for (pos=0;pos<CANT;pos++)
    {
        if(lista[pos].estado == 0)
        {
            break;
        }
    }
    return pos;
}

int imprimirListaOrdenadaPorNombre(EPersona lista[])
{
    EPersona aux;

    int p1, p2;
    for (p1=0;p1<CANT-1;p1++)
    {
        for (p2=1;p2<CANT;p2++)
        {
            if (strcasecmp(lista[p1].nombre, lista[p2].nombre) < 0)
            {
                aux = lista[p1];
                lista[p1] = lista[p2];
                lista[p2] = aux;
            }

        }
    }

    for (p1=0;p1<CANT;p1++)
    {
        if (lista[p1].estado == 1)
        {
            printf("\t--------------------------------------------------------------------------\n");
            printf("\t\tNombre: %s   \nDNI: %ld    \tEdad: %d\n|",lista[p1].nombre,lista[p1].dni,lista[p1].edad);
            printf("\t-------------------------------------------------------------------------\n");
        }
    }

}

int graficar(EPersona lista[])
{
    int i, mayor=0,busqueda=0, menorEdad=0,de19a35=0, mayorDe35=0, flag=0;

    while(busqueda<CANT)
    {
        if (lista[busqueda].edad<19 && lista[busqueda].estado == 1)
        {
            menorEdad++;
        }
        else if (lista[busqueda].edad>18 && lista[busqueda].edad<36 && lista[busqueda].estado == 1)
        {
            de19a35++;
        }
        else if (lista[busqueda].edad>35 && lista[busqueda].estado == 1)
        {
            mayorDe35++;
        }
        busqueda++;
    }

    if(menorEdad>=de19a35 && menorEdad>=mayorDe35)
    {
        mayor = menorEdad;
    }
    else
    {
        if(de19a35>=menorEdad && de19a35>=mayorDe35)
        {
            mayor = de19a35;
        }
        else
        {
            mayor = mayorDe35;
        }
    }

    for(i=mayor; i>0; i--)
    {
        if(i<10)
        {
            printf("%02d|",i);
        }
        else
            printf("%02d|",i);

        if(i<=menorEdad)
        {
            printf("*");
        }
        if(i<=de19a35)
        {
            flag=1;
            printf("\t*");
        }
        if(i<= mayorDe35)
        {
            if(flag==0)
                printf("\t\t*");
            if(flag==1)
                printf("\t*");
        }
        //Bajo una linea luego de cada iteracion
        printf("\n");
    }
    printf("--+-----------------");
    printf("\n  |<18\t19-35\t>35");
    printf("\n   %d\t%d\t%d",menorEdad,de19a35,mayorDe35);
}

buscarPorDni(EPersona lista[])
{
    int x;
    int dni;

    printf("Buscar DNI:\n");
    scanf("%d",&dni);

    for(x=0;x<CANT;x++)
    {
        if(dni == lista[x].dni)
        {
            printf("Nombre: %s \nDNI: %ld \nEdad: %d\n",lista[x].nombre,lista[x].dni,lista[x].edad);
            return;
        }
    }

    printf("No Se encontro DNI.\n");
}
