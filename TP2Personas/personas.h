#ifndef personas_H_INCLUDED
#define personas_H_INCLUDED
typedef struct
{
    char nombre[50];
    int edad;
    int dni;

    int idPersonas;
    int estado;
}Personas;
#endif // personas_H_INCLUDED


int personas_init(Personas* array,int limite);
int personas_mostrar(Personas* array,int limite);
int personas_alta(Personas* array,int limite);
int personas_baja(Personas* array,int limite, int id);
int personas_ordenar(Personas* array,int limite, int orden);
int personas_buscarPorId(Personas* array,int limite, int id);
int personas_mostrarGraficoEdades(Personas* array,int limite);




