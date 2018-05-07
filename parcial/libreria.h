#ifndef LIBRERIA_H_INCLUDED
#define LIBRERIA_H_INCLUDED
typedef struct
{
    char nombre[20];
    int id;
    int tipo;
    char calle[20];
    int altura;
    float precio;
    int ocupado;

}ePantalla;
typedef struct
{
    int cuit;

}eCliente;
typedef struct
{
 int idPan;
 int cuit;
 int cantidad;
 char nombre[20];
 int estado;
}ePublicacion;
void iniciaPan(ePantalla [],int);
int menu();
void alta(ePantalla vec[],int  tam);
int buscarLugar(ePantalla vec[], int tam);
void iniciaPub(ePublicacion vec[],int tam);
void mostrarPanta(ePantalla vec[],int indice);
void modificar(ePantalla vec[],int tam);
int buscarId(ePantalla vec[],int tam,int id);
void listarPantallas(ePantalla vec[],int tam);
void bajaPantalla(ePantalla vec[],int tam);
void contratarPublicidad(ePantalla vec[],int tam,ePublicacion pub[],int tamP,eCliente cli[],int tamC);
int buscarLugarPublicidad(ePublicacion vec[], int tam);
void iniciaCli(eCliente vec[],int tam);
int buscarCuit(eCliente vec[],int tam,int cuit,int indice);
void ModificarPublicacion(ePantalla pan[],int tam,ePublicacion pub[],int tamP ,eCliente cli[],int tamC);
void coincidencia2(ePantalla pan[],int tam,ePublicacion pub[],int tamP ,eCliente cli[],int tamC,int cuit);
int coincidencia(ePublicacion pub[],int tamP,int cuit);
int  buscarIdPub(ePublicacion vec[],int tam,int id);
void cancelarPublicacion(ePantalla pan[],int tam,ePublicacion pub[],int tamP ,eCliente cli[],int tamC);
void consultaFacturacion(ePantalla pan[],int tam,ePublicacion pub[],int tamP ,eCliente cli[],int tamC);
void sumar(ePantalla pan[],int tam,ePublicacion pub[],int tamP ,eCliente cli[],int tamC,int cuit);
void ListarContraciones (ePantalla pan[],int tam,ePublicacion pub[],int tamP ,eCliente cli[],int tamC);
void Listar (ePantalla pan[],int tam,ePublicacion pub[],int tamP,int cuit);
void informar(ePantalla pan[],int tam,ePublicacion pub[],int tamP ,eCliente cli[],int tamC);


#endif // LIBRERIA_H_INCLUDED
