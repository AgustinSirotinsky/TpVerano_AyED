#include <iostream>
#include <cstring>

using namespace std;

// Structs

struct tipoInfo // Dentro de vector de struct modelos.
{
    int idAccesorio;
    int cantidad;
};

struct NodoComponentes // Lista de componentes
{
    tipoInfo info;
    NodoComponentes *sgte;
};

struct registroModelos // Struct modelos.
{
    int idModelo; // Secuencial
    char descripcion[100 + 1];
    float precioBase;
    char temporada; // 'v' verano - 'i' invierno o puede ser en mayusculas
    NodoComponentes *listaComp = NULL; // Fijarse si no es Nodo *sgte = NULL en vez de esta linea, o ambos = NULL.
};

// registroModelos vectorModelos[50];

struct tipoInfoProveedores // Struct proveedores
{
    int idProveedor;
    char nombre[50];
    float valorUnitario;
};

struct NodoProveedores // Lista proveedores
{
    tipoInfoProveedores info;
    NodoProveedores *sgte;
};

struct registroComponentes // Struct Componentes -> Va a un vector de 1000. Son las cosas necesarias para armar una zapatilla
{
    int idComponente; // Secuencial, comienza en 1000 (de 1000 a 2000).
    char descripcion[100 + 1];
    NodoProveedores *listaProveedores = NULL;
    int stock;
};

// registroComponentes vectorComponentes[1000];

struct pedido // archivo aprox 8 o 10 pedidos
{
    int idPedido;
    int idLinea; // Un pedido puede tener varias lineas, cada linea seria un producto distinto.
    int fecha;
    int idModelo; // registroModelos.idModelo
    int cantidad;
    float costo;
};

void burbuja(int v[], int N)
{
    int i, j, aux;

    for (i = 1; i < N - 1; i++)
    {
        for (j = 1; j <= N - i; j++)
        {
            if (v[j - 1] > v[j])
            {
                aux = v[j];
                v[j] = v[j - 1];
                v[j - 1] = aux;
            }
        }
    }
}

// Arme este con ayuda de los apuntes y chatgpt porque el que te dan esta mal aparentemente

void leerArchivo (FILE* ArchivoPedidos){ //para usar de prueba borrar cuando ya no lo necesitemos mas
    pedido Pedido;
    fseek(ArchivoPedidos, 0, SEEK_SET);  // Volver al inicio del archivo por si se uso y no se cerro


    while (fread(&Pedido, sizeof(pedido), 1, ArchivoPedidos)) {
        cout << "---------------------" << endl
        << "idPedido: " << Pedido.idPedido << endl
        << "idLinea: " << Pedido.idLinea << endl
        << "fecha: " << Pedido.fecha << endl
        << "idModelo: " << Pedido.idModelo << endl
        << "cantidad: " << Pedido.cantidad << endl
        << "costo: " << Pedido.costo << endl;
    }
}

void actualizarPedidos(FILE* ArchivoPedidos){
    pedido Pedido;
    fseek(ArchivoPedidos, 0, SEEK_SET);  // Volver al inicio del archivo por si se uso y no se cerro

    int idPedidoAnt=0;//no se si se hace falta incicializar :v (dos puntos v)
    int idLineaAnt;

    int i = 0;
    
	while (fread(&Pedido, sizeof(pedido), 1, ArchivoPedidos)){
        cout << i << endl;
    		while(Pedido.idPedido == idPedidoAnt){//esto es para cuando el idPedido se repita. (osea id linea !=)
    			//Acá tendra que ir todo lo  totalLinea y eso
			}
		// idPedidoAnt=Pedido.idPedido;
        i++;
    }
}

int main()
{
    
	FILE* ArchivoPedidos=fopen("Pedidos.dat","rb+");//despues vemos en que orden lo hacemos o si va en una funcion aparte y así
    actualizarPedidos(ArchivoPedidos);
    //Funcion para cout pedidos
    // leerArchivo(ArchivoPedidos);

    //cerrar archivo
    fclose(ArchivoPedidos);
    return 0;
}

// PUNTO 1. :

// - Dicho por Roxana: Hacer un while que lea los pedidos (uno por uno), otro que lea las lineas una por una.
//   Saca el id modelo y lo busca en el vector de modelos con pos unica y predecible (pq esta ordenado).
//   Calcular el totalLinea = PrecioBase (precio del modelos) + Cant de productos * Coponente. Suma el precio base del modelo + el gasto de los componentes.
//   Por cada componente -> Buscarlo en el vector -> Buscar proveedor mas barato (Punto 2).

// -  Sumar los totales de cada linea y multiplicamos por la cantidad para conseguir el total del pedido.

// - Actualizar el archivo? Agregamos el costo del pedido.

// - Disminuir el stock de cada uno de los componentes usados.

// - Mostrar el total.

// - Mostrar archivo de pedidos actualizado.
// - Mostrar el total de todos los pedidos? -> Sumar los costos y mostrar por pantalla.