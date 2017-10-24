#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#include <ctype.h>
#include <string.h>
#define ESC 27

int cargarArchivos(EMovie *movie)
{
	int flag = 0;
	FILE *ptr;

	if((ptr = fopen("binPeliculas.dat","rb+"))==NULL)
	{
		ptr = fopen("binPeliculas.dat","wb+");
		if(ptr == NULL)
		{
			return 1;
		}
		flag=1;
	}

	if(flag ==0)
	{
	fread(movie, sizeof(EMovie),1,ptr);
    }

	fclose(ptr);
	return 0;
}
int inicializar(EMovie *movie, int estad)
{
    int x;

    for(x=0;x<estad;x++)
    {
        (movie + x)->estado=0;
    }

    if(cargarArchivos(movie))
    {
        printf("No se pudo abrir el fichero");
    }
    else
    {
        printf("Se cargaron las estructuras con exito\n");
    }
}
int posicionLibre(EMovie *movie,int tam)
{
  int posic;
  for (posic=0;posic<tam;posic++)
  {
    if (movie[posic].estado == 0)
    {
      break;
    }
  }
	return posic;
}
int generarCodigo(EMovie *movie, int tam)
{
    int codigo,x;
    int index = -2;

  printf("Codigo de la pelicula.\n");
  scanf("%d", &codigo);

  for (x = 0 ;x<tam;x++)
  {
    if (codigo == movie[x].codigoPelicula)
    {
      index = x;
    }
  }
  return index;

}
void peliculaNombre(EMovie *movie, int x)
{
    printf("Titulo: ");
    setbuf(stdin,NULL);
    scanf("%[^\n]",movie[x].titulo);
}
void peliculaGenero(EMovie *movie, int x)
{
    int validar;
    printf("Genero: ");
    setbuf(stdin,NULL);
    scanf("%[^\n]",movie[x].genero);

    validar=strlen(movie[x].genero);

    if(validar > 0)
    {
        if(!validarLetras(movie[x].genero))
        {
            printf("ERROR: Debe Escribir Solo Letras\n");

        }
    }
}
void peliculaDuracion(EMovie *movie, int x)
{
    printf("Duracion en Minutos: ");
    scanf("%d",&movie[x].duracion);
}
void peliculaDescripcion(EMovie *movie, int x)
{
    printf("Descripcion: ");
    setbuf(stdin,NULL);
    scanf("%[^\n]",movie[x].descripcion);
}
void peliculaPuntaje(EMovie *movie, int x)
{
    printf("Puntaje: ");
    scanf("%f",&movie[x].puntaje);
}
void peliculaLinkImagen(EMovie *movie, int x)
{
    printf("Link Imagen: ");
    setbuf(stdin,NULL);
    scanf("%[^\n]",movie[x].linkImagen);

}
void toString(EMovie *movie)
{
    printf("\n----------");
    printf("\n DATOS");
    printf("\n----------");
	printf("\nCod: %d",movie->codigoPelicula);
    printf("\nTitulo: %s",movie->titulo);
    printf("\nGenero: %s",movie->genero);
    printf("\nDuracion en Minutos: %d",movie->duracion);
    printf("\nDescripcion: %s",movie->descripcion);
    printf("\nPuntaje: %.2f",movie->puntaje);
	printf("\nLink Imagen",movie->linkImagen);
}
int validarLetras(char str[])
{
    int i = 0;
    while(str[i] != '\0')
    {
        if((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z'))
            return 0;
        i++;
    }
    return 1;
}




int agregarPelicula(EMovie *movie,int tam)
{
    int posicion;
    EMovie estado;
    int x;

    FILE  *bin;
    int cant;

    if ((bin = fopen("binPeliculas.dat","rb+"))==NULL)
    {
        if ((bin = fopen("binPeliculas.dat","wb+"))==NULL)
        {
            printf("No se pudo abrir el archivo");
            exit(1);
        }
    }

    posicion = posicionLibre(movie,tam);
    peliculaNombre(movie,posicion);
    peliculaGenero(movie,posicion);
    peliculaDuracion(movie,posicion);
    peliculaDescripcion(movie,posicion);
    peliculaPuntaje(movie,posicion);
    peliculaLinkImagen(movie,posicion);
    (movie + posicion)->codigoPelicula = posicion + 1;
    (movie + posicion)->estado = 1;

     if(estado.estado==0)
     {
         printf("ESPACIO INSUFICIENTE\n");
    }
    else
    {
        printf("\t\n|------------------|");
        printf("\t\n|  DATOS CARGADOS  |");
        printf("\t\n|------------------|\n");
    }


    fflush(stdin);
    fseek(bin, 0L, SEEK_END);
    fwrite(movie, (10*(sizeof(EMovie)),1, bin);

    rewind(bin);
    while(!feof(bin))
    {
        cant = fread(10*(sizeof(EMovie)),1,bin);
        if(cant!=1)
        {
            if(feof(bin))
            {
                break;
            }
            else
            {
                printf("No leyo el ultimo registro");
                break;
            }
        }


    }

   fclose(bin);
   getch();

}

int borrarPelicula(EMovie *movie)
{
    int x;
    int flag;
    int codigo;
    char opcion;

    printf("CodiGO a Eliminar: ");
    scanf("%d",&codigo);


    for(x=0;CANTIDAD;x++)
    {
        if(codigo == movie[x].codigoPelicula)
        {
            printf("Datos a Eliminar:\n");

            toString((movie+x));

            printf("\nCODIGO encontrado. Seguro Desea Eliminar Pelicula? [Y = SI] \n");
            opcion=getche();

            if(opcion=='Y')
            {
                (movie + x)->estado = 0;
                printf("\nRegistro eliminado!!");
            }
            else
            {
                printf("\nEl registro no fue eliminado!");
            }
            flag=1;
			break;
        }

    }

    if(flag==0)
	{
		printf("Codigo de Pelicula inexistente");
		getch();
	}
}

void modificarPelicula(EMovie *movie, int tam)
 {
    int posicion;

    posicion = generarCodigo(movie, tam);
    if(posicion != -2)
    {
        peliculaNombre(movie,posicion);
        peliculaGenero(movie,posicion);
        peliculaDuracion(movie,posicion);
        peliculaDescripcion(movie,posicion);
        peliculaPuntaje(movie,posicion);
        peliculaLinkImagen(movie,posicion);
        printf("Modificacion Realizada\n");
    }
    else
    {
      printf("No se encontró una pelicula con el ID ingresado.\n");
    }
 }

void listaPelicula(EMovie *movie)
{
int i,j;
	EMovie auxPelicula;

	for(i=0; i<CANTIDAD-1;i++)
	{
		for(j=i+1; j<CANTIDAD; j++)
		{
			if(strcmp(movie[i].titulo,movie[j].titulo)>0)
			{
				auxPelicula=movie[i];
				movie[i]=movie[j];
				movie[j]=auxPelicula;
			}
		}
	}

	for(i=0; i<CANTIDAD; i++)
	{
		if(movie[i].estado!=0)
		   toString((movie + i));
		   printf("\n");

	}

}

void generarPagina(EMovie *movie)
{
     int x;
     FILE *pf;

     if((pf=fopen("Lista_de_Pelicul.html", "w+")) != NULL)
     {
         fprintf(pf,"<!DOCTYPE html>");
         fprintf(pf,"<!-- Template by Quackit.com -->");
         fprintf(pf,"<html lang='en'>");
         fprintf(pf,"<head> <meta charset='utf-8'>");
         fprintf(pf,"<meta http-equiv='X-UA-Compatible' content='IE=edge'>");
         fprintf(pf,"<meta name='viewport' content='width=device-width, initial-scale=1'>");
         fprintf(pf,"<!-- The above 3 meta tags *must* come first in the head; any other head content must come *after* these tags -->");
         fprintf(pf,"<title>Lista peliculas</title>");
         fprintf(pf,"<!-- Bootstrap Core CSS -->");
         fprintf(pf,"<link href='css/bootstrap.min.css' rel='stylesheet'>");
         fprintf(pf,"<!-- Custom CSS: You can use this stylesheet to override any Bootstrap styles and/or apply your own styles -->");
         fprintf(pf,"<link href='css/custom.css' rel='stylesheet'>");
         fprintf(pf,"<!-- HTML5 Shim and Respond.js IE8 support of HTML5 elements and media queries -->");
         fprintf(pf,"<!-- WARNING: Respond.js doesn't work if you view the page via file:// -->");
         fprintf(pf,"<!--[if lt IE 9]>");
         fprintf(pf,"<script src='https://oss.maxcdn.com/libs/html5shiv/3.7.0/html5shiv.js'></script>");
         fprintf(pf,"<script src='https://oss.maxcdn.com/libs/respond.js/1.4.2/respond.min.js'></script>");
         fprintf(pf,"<![endif]--> </head>");
         fprintf(pf,"<body style='background-color:yellow;'>");
         fprintf(pf,"<div class='container'>");
         fprintf(pf,"<br><div class='row'>\n");


         for(x=0; x<CANTIDAD; x++)
         {
             if(movie[x].estado == 1)
             {
                 fprintf(pf,"<center><!-- Repetir esto para cada pelicula -->");
                 fprintf(pf,"<article class='col-md-4 article-intro'>");
                 fprintf(pf,"<a href='#'>");
                 fprintf(pf,"<img class='img-responsive img-rounded' src='%s' alt=''>",movie[x].linkImagen);
                 fprintf(pf,"</a>");
                 fprintf(pf,"<h3>");
                 fprintf(pf,"<a href='#'>%s</a>",movie[x].titulo);
                 fprintf(pf,"</h3>");
				 fprintf(pf,"<ul>");
					fprintf(pf,"<li>Genero:%s</li>",movie[x].genero);
					fprintf(pf,"<li>Puntaje:%.2f</li>",movie[x].puntaje);
					fprintf(pf,"<li>Duracion:%d</li>",movie[x].duracion);
				 fprintf(pf,"</ul>");
                 fprintf(pf,"<p>%s</p>",movie[x].descripcion);
                 fprintf(pf,"</article>");
                 fprintf(pf,"<!-- Repetir esto para cada pelicula --><br><br>");
                 fprintf(pf,"\n");

             }
         }


         fprintf(pf,"</div>");
         fprintf(pf,"<!-- /.row -->");
         fprintf(pf,"</div>");
         fprintf(pf,"<!-- /.container -->");
         fprintf(pf,"<!-- jQuery -->");
         fprintf(pf,"<script src='js/jquery-1.11.3.min.js'></script>");
         fprintf(pf,"<!-- Bootstrap Core JavaScript -->");
         fprintf(pf,"<script src='js/bootstrap.min.js'></script>");
         fprintf(pf,"<!-- IE10 viewport bug workaround -->");
         fprintf(pf,"<script src='js/ie10-viewport-bug-workaround.js'></script>");
         fprintf(pf,"<!-- Placeholder Images -->");
         fprintf(pf,"<script src='js/holder.min.js'></script>");
         fprintf(pf,"</body>");
         fprintf(pf,"</html>");

         fclose(pf);


     }
     else
     {

         printf("No se pudo abrir el archivo\n");

      }


      printf("HTML creado con exito\n");
      system("pause");
}





