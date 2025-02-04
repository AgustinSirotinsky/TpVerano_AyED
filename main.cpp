#include <iostream>
#include <cstring>

using namespace std;

//Structs

struct Modelos{
    int id;
    char descripcion[100+1];
    int precioBase;
    int temporada; // 0-verano 1-invierno (preguntar a la profe si deberia ser un char[])
    //ptr a la lista de componentes ???
};

struct Componentes{
    int id;
    char descripcion[100+1];
    ListaDeProovedores listaDeProovedores[10];
    int stock;
};

struct ListaDeProovedores{
    int id;
    char nombre[50+1];
    int valorUnitario;
};

struct Pedidos{
    int idPedido;
    int idLinea;
    int fecha;
    int idModelo;
    int cantidad;
    int costo;
};

int main() {
	cout<<"Hello World";
    return 0;
}
