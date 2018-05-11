#include <stdio.h>
#include <stdlib.h>
#include "FuncionesUtn.h"
#include "personas.h"
#define CANT 20


int main()
{
    char seguir='s';
    int opcion=0;
    Personas array[CANT];
    int auxId;

    personas_init(array,CANT);


    while(seguir=='s')
    {
        printf("1- Agregar persona\n");
        printf("2- Borrar persona\n");
        printf("3- Imprimir lista ordenada por  nombre\n");
        printf("4- Imprimir grafico de edades\n\n");
        printf("5- Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:

                personas_alta(array,CANT);
                break;
            case 2:
                getValidInt("ingresar id\n","id no valido",&auxId,0,99999999,2);
                personas_baja(array,CANT,auxId);
                break;
            case 3:
                personas_ordenar(array,CANT,1);
                personas_mostrar(array,CANT);
                break;
            case 4:
                personas_mostrarGraficoEdades(array,CANT);
                break;
            case 5:
                seguir = 'n';
                break;
        }
    }

    return 0;
}
