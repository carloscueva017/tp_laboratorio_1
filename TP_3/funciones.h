#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#define CANTIDAD 10


typedef struct{
    int codigoPelicula;
    char titulo[20];
    char genero[20];
    int duracion;
    char descripcion[150];
    float puntaje;
    char linkImagen[150];
    int estado;
}EMovie;


/** \brief carga el archivo binario
 *
 * \param  *movie - puntero
 * \return void
 *
 */
int cargarArchivos(EMovie *movie);


int posicionLibre (EMovie *movie, int tam);
/** \brief Busca un codigo de una pelicula.
 *
 * \param pelicula Emovie* - Lista de peliculas.
 * \param tam  - Tamaño de array de las peliculas.
 * \return index - Devuelve el codigo de la pelicula
 *
 */
int generarCodigo(EMovie *movie, int tam);

/** \brief Inicializa el estado en 0.
 *
 * \param *movie - puntero.
 * \param estad - Tamaño del array.
 * \return void
 *
 */
int inicializar(EMovie *movie,int estad);

/** \brief Carga el nombre de la película.
 *
 * \param *movie - Puntero.
 * \param x - Tamaño del array.
 * \return void
 *
 */
void peliculaNombre(EMovie *movie, int x);

/** \brief Carga el Genero de la película.
 *
 * \param *movie - Puntero.
 * \param x - Tamaño del array.
 * \return void
 *
 */
void peliculaGenero(EMovie *movie, int x);
/** \brief Carga la Duracion de la película.
 *
 * \param *movie - Puntero.
 * \param x - Tamaño del array.
 * \return void
 *
 */
void peliculaDuracion(EMovie *movie, int x);

/** \brief Carga la Descripcion de la película.
 *
 * \param *movie - Puntero.
 * \param x - Tamaño del array.
 * \return void
 *
 */
void peliculaDescripcion(EMovie *movie, int x);

/** \brief Carga el Puntaje de la película.
 *
 * \param *movie - Puntero.
 * \param x - Tamaño del array.
 * \return void
 *
 */
void peliculaPuntaje(EMovie *movie, int x);

/** \brief Carga la Imagen de la película.
 *
 * \param *movie - Puntero.
 * \param x - Tamaño del array.
 * \return void
 *
 */
void peliculaLinkImagen(EMovie *movie, int x);

/** \brief Cadena de TEXTO con todos los datos ingresados.
 *
 * \param *movie - Puntero.
 * \return void
 *
 */
void toString(EMovie *movie);

/** \brief valida las cadenasd de texto
 *
 * \param str - array
 * \return void
 *
 */
int validarLetras(char str[]);


/**
 *  Agrega una pelicula al archivo binario
 *  @param movie la estructura a ser agregada al archivo
 *  @return retorna 1 o 0 de acuerdo a si pudo agregar la pelicula o no
 */
int agregarPelicula(EMovie *movie,int tam);

/**
 *  Borra una pelicula del archivo binario
 *  @param movie la estructura a ser eliminada al archivo
 *  @return retorna 1 o 0 de acuerdo a si pudo eliminar la pelicula o no
 */
 int borrarPelicula(EMovie *movie);

/**
 *  Modificar una pelicula al archivo binario
 *  @param movie la estructura a ser modificada al archivo
 *  @return retorna 1 o 0 de acuerdo a si pudo agregar la pelicula o no
 */
void modificarPelicula(EMovie *movie, int tam);


/**
 *  Lista todas pelicula del archivo binario por nombre
 *  @param movie la estructura a ser listada al archivo
 *  @return retorna 1 o 0 de acuerdo a si pudo agregar la pelicula o no
 */
void listaPelicula(EMovie *movie);

/**
 *  Genera un archivo html a partir de las peliculas cargadas en el archivo binario.
 *  @param lista la lista de peliculas a ser agregadas en el archivo.
 *  @param nombre el nombre para el archivo.
 */
 void generarPagina(EMovie *movie);


#endif // FUNCIONES_H_INCLUDED
