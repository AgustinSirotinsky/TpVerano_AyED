#include <iostream>
#include <cstring>

using namespace std;

// Structs

struct tipoInfo
{
    int idAccesorio;
    int cantidad;
};

struct Nodo
{
    tipoInfo info;
    Nodo *sgte;
};

struct registroModelos
{
    int idModelo;
    char descripcion[100 + 1];
    float precioBase;
    char temporada; // 'v' verano - 'i' invierno o puede ser en mayusculas
    Nodo *listaComp = NULL;
};

// registroModelos vectorModelos[50];

struct tipoInfoProveedores
{
    int idProveedor;
    char nombre[50];
    float valorUnitario;
};

struct NodoProveedores
{
    tipoInfoProveedores info;
    NodoProveedores *sgte ;
};

struct registroComponentes
{
    int idComponente;
    char descripcion[100 + 1];
    NodoProveedores* listaProveedores = NULL;
    int stock;
};

// registroComponentes vectorComponentes[1000];

struct pedido //archivo
{
    int idPedido;
    int idLinea; // Un pedido puede tener varias lineas, cada linea seria un producto distinto.
    int fecha;
    int idModelo; //registroModelos.idModelo
    int cantidad;
    float costo;
};

int main()
{
    cout << "Hello World";
    return 0;
}


