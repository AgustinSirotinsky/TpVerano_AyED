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
//Ordenar x burbuja
void OrdxBur(int Vec[],int N){
int aux;
    int ord = 0;

    for (int k = 0; k < N - 1 && ord == 0; k++) {
        ord = 1;
        for (int l = 0; l < N - k - 1; l++) {
            if (Vec[l] > Vec[l + 1]) {
                aux = Vec[l];
                Vec[l] = Vec[l + 1];
                Vec[l + 1] = aux;
                ord = 0; 
            }
        }
    }
}
//Arme este con ayuda de los apuntes y chatgpt porque el que te dan esta mal aparentemente

int main()
{
    cout << "Hello World";
    return 0;
}


