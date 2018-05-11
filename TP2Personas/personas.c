#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "personas.h"
#include "FuncionesUtn.h"

#define DEFINE_DEL_ARCHIVO  "hola"

//Funciones privadas
static int proximoId(void);
static int buscarLugarLibre(Personas* array,int limite);

//__________________



/** \brief modifica el valor del estado
 * \param array Personas* corresponde al array ingresado por el usuario
 * \param limite int corresponde a la cantidad de elementos del array
 * \return si el retorno es correcto[0] o erroneo[-1]
 *
 */
int personas_init(Personas* array,int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && array != NULL)
    {
        retorno = 0;
        for(i=0;i<limite;i++)
        {
            array[i].estado=1;
        }
    }
    return retorno;
}


/** \brief muestra las personas ingresadas
 * \param array Personas* corresponde al array ingresado por el usuario
 * \param limite int corresponde a la cantidad de elementos del array
 * \return si el retorno es correcto[0] o erroneo[-1]
 *
 */
int personas_mostrar(Personas* array,int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && array != NULL)
    {
        retorno = 0;
        printf("Nombre - Edad -   DNI     - Estado\n");
        for(i=0;i<limite;i++)
        {
            if(!array[i].estado)
                printf("%s  - %d  -  %d   -  %d\n",array[i].nombre,array[i].edad,array[i].dni,array[i].estado);
        }
    }
    return retorno;
}
/** \brief se ingresa el alta de una persona
 * \param array Personas* corresponde al array ingresado por el usuario
 * \param limite int corresponde a la cantidad de elementos del array
 * \return si el retorno es correcto[0] o erroneo[-1]
 *
 */
int personas_alta(Personas* array,int limite)
{
    int retorno = -1;
    int i;
    char nombre[50];
    int edad;
    int dni;
    if(limite > 0 && array != NULL)
    {
        i = buscarLugarLibre(array,limite);
        if(i >= 0)
        {
            if(!getValidString("ingrese Nombre\n","\nEso no es un nombre\n","\nEl maximo es 40",nombre,40,2))
            {
                if(!getValidInt("Ingrese edad\n","\nNo es una edad valida\n",&edad,0,120,2))
                {
                    if(!getValidInt("Ingrese dni\n","\n Eso no es un dni\n",&dni,0,999999999,2))
                    {
                        retorno = 0;
                        strcpy(array[i].nombre,nombre);
                        array[i].edad = edad;
                        array[i].dni = dni;
                        //------------------------------
                        //------------------------------
                        array[i].idPersonas=proximoId();
                        array[i].estado = 0;
                    }
                }

            }
            else
            {
                retorno = -3;
            }
        }
        else
        {
            retorno = -2;
        }

    }
    return retorno;
}


/** \brief se ingresa la baja de una persona
 *
 * \param array Personas* corresponde al array ingresado por el usuario
 * \param limite int corresponde a la cantidad de elementos del array
 * \param id int corresponde al numero con el que se identifica a la persona
 * \return int si el retorno es correcto[0] o erroneo[-1]
 *
 */
int personas_baja(Personas* array,int limite, int id)
{
    int indiceAEliminar;
    int retorno=-1;
    indiceAEliminar = personas_buscarPorId(array,limite,id);
    if(indiceAEliminar>=0)
    {
        array[indiceAEliminar].estado=1;
        retorno=0;
    }
    return retorno;
}



/** \brief se ordena el listado de personas
 *
 * \param array Personas* corresponde al array ingresado por el usuario
 * \param limite int corresponde a la cantidad de elementos del array
 * \param orden int corresponde a la forma en que lo quiera ordenar el usuario
 * \return int si el retorno es correcto[0] o erroneo[-1]
 *
 */
int personas_ordenar(Personas* array,int limite, int orden)
{
    int retorno = -1;
    int i;
    int flagSwap;
    Personas auxiliarEstructura;

    if(limite > 0 && array != NULL)
    {
        do
        {
            flagSwap = 0;
            for(i=0;i<limite-1;i++)
            {
                if(!array[i].estado && !array[i+1].estado)
                {
                    if((strcmp(array[i].nombre,array[i+1].nombre) > 0 && orden) || (strcmp(array[i].nombre,array[i+1].nombre) < 0 && !orden))
                    {
                        auxiliarEstructura = array[i];
                        array[i] = array[i+1];
                        array[i+1] = auxiliarEstructura;
                        flagSwap = 1;
                    }
                }
            }
        }while(flagSwap);
    }
    return retorno;
}



/** \brief calcula el proximo identificador de persona
 *
 * \param void
 * \return int retorna el identificador nuevo
 *
 */
static int proximoId(void)
{
    static int proximoId = -1;
    proximoId++;
    return proximoId;
}


/** \brief busca por identificador a la persona
 *
 * \param array Personas* corresponde al array ingresado por el usuario
 * \param limite int corresponde a la cantidad de elementos del array
 * \param id int corresponde al numero de identificador que ingresa el usuario
 * \return int retorna el identificador a buscar
 *
 */
int personas_buscarPorId(Personas* array,int limite, int id)
//static int buscarPorId(Personas* array,int limite, int id)
{
    int retorno = -1;
    int i;
    if(limite > 0 && array != NULL)
    {
        retorno = -2;
        for(i=0;i<limite;i++)
        {
            if(!array[i].estado && array[i].idPersonas==id)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}

/** \brief busca un lugar de estado que no este ocupado
 *
 * \param array Personas* corresponde al array ingresado por el usuario
 * \param limite int corresponde a la cantidad de elementos del array
 * \return int retorna el estado libre
 *
 */
static int buscarLugarLibre(Personas* array,int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && array != NULL)
    {
        for(i=0;i<limite;i++)
        {
            if(array[i].estado==1)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}


/** \brief muestra un grafico de asteriscos por edades
 *
 * \param array Personas* corresponde al array ingresado por el usuario
 * \param limite int corresponde a la cantidad de elementos del array
 * \return int si el retorno es correcto[0] o erroneo[-1]
 *
 */
int personas_mostrarGraficoEdades(Personas* array,int limite)
{

    int retorno = -1;
    int i;
    int j;
    int menores=0;
    int adultos=0;
    int mayores=0;
    int maximo=0;
    char posicion[3];

    if(limite > 0 && array != NULL)
    {
        retorno = 0;

        for(i=0;i<limite;i++)
        {
            if(!array[i].estado)
            {
                if(array[i].edad>0 && array[i].edad<18)
                {
                  menores++;

                }

                else if(array[i].edad>=18 && array[i].edad<=35)
                {
                    adultos++;
                }

                else if(array[i].edad>35)
                {
                    mayores++;
                }

            }


        }
        posicion[0]=menores;
        posicion[1]=adultos;
        posicion[2]=mayores;

        for(i=0;i<3;i++)
        {
            if(posicion[i]>maximo)
            {
                maximo=posicion[i];
            }
        }
        for (i=maximo;i>0;i--)
        {
            retorno=0;
            for(j=0;j<3;j++)
            {

                if(j>0)
                {
                    printf("   ");
                }

                if (posicion[j]>=i)
                {
                    printf(" * ");
                }
                else
                {
                    printf("   ");
                }
            }
            printf("\n");
        }
        printf("<18  18-35  >35\n");
    }
    return retorno;

}
