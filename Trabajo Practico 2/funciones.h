#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct {

    char nombre[50];
    int edad;
    int estado;
    int dni;

}EPersona;

/** \brief Inicializacion - inicializa las variables de estado en 0.
*   \param x - valor de iteracion.
*/
int inicializacion(EPersona lista[]);


/** \brief la funcion agrega los datos de una persona a la estructura
 *
 * \param agrega el nombre,dni,edad de una persona
 * \return si los datos estan cargados
 *
 */
int agregarPersona(EPersona lista[]);

/** \brief esta funcion elimina los datos de una persona
 *
 * \param elimina nombre,edad,dni
 * \return si los datos fueron eliminados
 *
 */
int borrarPersona(EPersona lista[]);

/** \brief Esta funcion Ordena por nombre alfabeticamente A-Z
 *
 * \param P1 compara el valor con el segundo objeto
 * \param P2 compara el valor con el primer objeto
 * \return muestra en orden los datos
 *
 */
int imprimirListaOrdenadaPorNombre(EPersona lista[]);

/** \brief Esta funcion genera un grafico de barras para mostrar la cantidad de personas por edades
 *
 *  \param flag la iniciamos en 0
 *  \param menorEdad es un contador y al mismo tiempo lo usamos para graficar.
 *  \param de19a35 es un contador y al mismo tiempo lo usamos para graficar.
 *  \param meyorDe35 es un contador y al mismo tiempo lo usamos para graficar.
 *
 */
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
