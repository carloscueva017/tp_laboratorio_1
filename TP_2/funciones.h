#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct {

    char nombre[50];
    int edad;
    int estado;
    long int dni;

}EPersona;

/** \brief Inicializacion - inicializa las variables de estado en 0.
*   \param x - valor de iteracion.
*/
int inicializacion(EPersona lista[]);

int agregarPersona(EPersona lista[]);

int borrarPersona(EPersona lista[]);
int imprimirListaOrdenadaPorNombre(EPersona lista[]);
int graficar(EPersona lista[]);

/**
 * Obtiene el primer indice libre del array.
 * @param lista el array se pasa como parametro.
 * @return el primer indice disponible
 */
int obtenerEspacioLibre(EPersona lista[], int pos);

/**
 * Obtiene el indice que coincide con el dni pasado por parametro.
 * @param lista el array se pasa como parametro.
 * @param dni el dni a ser buscado en el array.
 * @return el indice en donde se encuentra el elemento que coincide con el parametro dni
 */
int buscarPorDni(EPersona lista[]);

#endif // FUNCIONES_H_INCLUDED
