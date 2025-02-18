#include <iostream>
#include <cstring>

using namespace std;

// Structs

struct tipoInfoComponentes // Dentro de vector de struct modelos.
{
    int idAccesorio;
    int cantidad;
};

struct NodoComponentes // Lista de componentes
{
    tipoInfoComponentes info;
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

struct tipoInfoComponentesProveedores // Struct proveedores
{
    int idProveedor;
    char nombre[50];
    float valorUnitario;
};

struct NodoProveedores // Lista proveedores
{
    tipoInfoComponentesProveedores info;
    NodoProveedores *sgte;
};

struct registroComponentes // Struct Componentes -> Va a un vector de 1000. Son las cosas necesarias para armar una zapatilla
{
    int idComponente; // Secuencial, comienza en 1000 (de 1000 a 2000).
    char descripcion[100 + 1];
    NodoProveedores *listaProveedores = NULL;
    int stock;
};

struct pedido // archivo aprox 8 o 10 pedidos
{
    int idPedido;
    int idLinea; // Un pedido puede tener varias lineas, cada linea seria un producto distinto.
    int fecha;
    int idModelo; // registroModelos.idModelo
    int cantidad;
    float costo;
};

// nodo para la colardix
// struct NodoPedido {
//     pedido info;
//     NodoPedido* sgte;
// };

//funciones
void cargarVector(pedido vec[], FILE* f, int n);
void burbuja(int v[], int N);
void actualizarPedidos(FILE* ArchivoPedidos);
void leerArchivo (FILE* ArchivoPedidos);
// void queue(NodoPedido*& frente, NodoPedido*& fin, pedido x);
// pedido unqueue(NodoPedido*& frente, NodoPedido*& fin);
int main()
{
	FILE* ArchivoPedidos=fopen("Pedidos.dat","rb+");//despues vemos en que orden lo hacemos o si va en una funcion aparte y así
    registroModelos vecModelos[50] = {
        {1000, "Zapatilla_Eco_Friendly", 18000.0, 'v', NULL},
        {1001, "Zapatilla_Urbana_Negra", 12000.0, 'v', NULL},
        {1002, "Zapatilla_Deportiva_Blanque", 15000.0, 'v', NULL},
        {1003, "Zapatilla_Trekking_Resistente", 18000.0, 'i', NULL},
        {1004, "Zapatilla_Casual_Azul", 13000.0, 'v', NULL},
        {1005, "Zapatilla_High_Top_Roja", 17000.0, 'i', NULL},
        {1006, "Zapatilla_Minimalista_Beige", 14000.0, 'v', NULL},
        {1007, "Zapatilla_Clásica_Bicolor", 12500.0, 'v', NULL},
        {1008, "Zapatilla_Correr_Liviana", 16000.0, 'v', NULL},
        {1009, "Zapatilla_Skate_Reforzada", 17500.0, 'i', NULL},
        {1010, "Zapatilla_Deportiva_Negro", 15500.0, 'v', NULL},
        {1011, "Zapatilla_Hiking_Agarre_Max", 18500.0, 'i', NULL},
        {1012, "Zapatilla_Basket_Ajuste_Pro", 19500.0, 'i', NULL},
        {1013, "Zapatilla_Casual_Tela_Suave", 13500.0, 'v', NULL},
        {1014, "Zapatilla_Outdoor_Impermeable", 21000.0, 'i', NULL},
        {1015, "Zapatilla_Deportiva_Elástica", 14500.0, 'v', NULL},
        {1016, "Zapatilla_Con_Plataforma", 16000.0, 'v', NULL},
        {1017, "Zapatilla_Trail_Grip_Fuerte", 20000.0, 'i', NULL},
        {1018, "Zapatilla_Tenis_Profesional", 22000.0, 'v', NULL},
        {1019, "Zapatilla_Deportivo_Confort", 16500.0, 'v', NULL},
        {1020, "Zapatilla_Streetwear_Exclusiva", 19000.0, 'i', NULL},
        {1021, "Zapatilla_Running_Aireado", 17500.0, 'v', NULL},
        {1022, "Zapatilla_Basket_Amortiguada", 19500.0, 'i', NULL},
        {1023, "Zapatilla_Casual_Diseño_Moderno", 14000.0, 'v', NULL},
        {1024, "Zapatilla_Deportiva_Ultra_Light", 15500.0, 'v', NULL},
        {1025, "Zapatilla_Montaña_Termica", 23000.0, 'i', NULL},
        {1026, "Zapatilla_Velcro_Comoda", 12500.0, 'v', NULL},
        {1027, "Zapatilla_Sintética_Multicolor", 13500.0, 'v', NULL},
        {1028, "Zapatilla_Básica_Económica", 11000.0, 'v', NULL},
        {1029, "Zapatilla_Deportiva_Malla", 14500.0, 'v', NULL},
        {1030, "Zapatilla_Alta_Confort", 17500.0, 'i', NULL},
        {1031, "Zapatilla_Gym_Premium", 20000.0, 'v', NULL},
        {1032, "Zapatilla_Fitness_Antideslizante", 18500.0, 'v', NULL},
        {1033, "Zapatilla_Deportiva_Suela_Ancha", 19000.0, 'v', NULL},
        {1034, "Zapatilla_Basket_Liviana", 19500.0, 'i', NULL},
        {1035, "Zapatilla_Deportiva_Suela_Gel", 21000.0, 'v', NULL},
        {1036, "Zapatilla_Premium_Casual", 22000.0, 'i', NULL},
        {1037, "Zapatilla_Trekking_Alta_Gama", 25000.0, 'i', NULL},
        {1038, "Zapatilla_Outdoor_Adventure", 23000.0, 'i', NULL},
        {1039, "Zapatilla_Techno_Streetwear", 20000.0, 'v', NULL},
        {1040, "Zapatilla_Retro_Deportiva", 17000.0, 'v', NULL},
        {1041, "Zapatilla_Edición_Limitada", 30000.0, 'i', NULL},
        {1042, "Zapatilla_Clásica_Reinventada", 15000.0, 'v', NULL},
        {1043, "Zapatilla_Gamer_Especial", 19500.0, 'v', NULL},
        {1044, "Zapatilla_Futbol_Sintética", 24000.0, 'v', NULL},
        {1045, "Zapatilla_Trail_Todo_Terreno", 22000.0, 'i', NULL},
        {1046, "Zapatilla_Deportivo_Aerodinámico", 20000.0, 'v', NULL},
        {1047, "Zapatilla_Ultra_Resistente", 27000.0, 'i', NULL},
        {1048, "Zapatilla_Casual_Básica", 12000.0, 'v', NULL},
        {1049, "Zapatilla_Lujo_Exclusiva", 35000.0, 'i', NULL}
    };
    registroComponentes vecComponentes[1000] = {
        {1000, "Cordones_Negros", NULL, 50},
        {1001, "Plantillas_de_gel", NULL, 30},
        {1002, "Suela_de_Goma", NULL, 20},
        {1003, "Tela", NULL, 40},
        {1004, "Cierre_Lateral", NULL, 25},
        {1005, "Ojales_Metalicos", NULL, 100},
        {1006, "Plantillas_Ortopedicas", NULL, 35},
        {1007, "Suela_Antideslizante", NULL, 25},
        {1008, "Tela_Impermeable", NULL, 30},
        {1009, "Cordones_Blancos", NULL, 45},
        {1010, "Espuma_Acolchonada", NULL, 50},
        {1011, "Refuerzo_Puntera", NULL, 20},
        {1012, "Cuero_Sintetico", NULL, 15},
        {1013, "Costuras_Reforzadas", NULL, 80},
        {1014, "Tela_Transpirable", NULL, 40},
        {1015, "Entresuela_EVA", NULL, 35},
        {1016, "Talonera", NULL, 25},
        {1017, "Velcro_Ajustable", NULL, 30},
        {1018, "Ojales_Plasticos", NULL, 90},
        {1019, "Forro_Interior", NULL, 50},
        {1020, "Refuerzo_Talon", NULL, 20},
        {1021, "Plantilla_Extraible", NULL, 30},
        {1022, "Malla_Ligera", NULL, 40},
        {1023, "Suela_Transparente", NULL, 15},
        {1024, "Cordones_Elasticos", NULL, 35},
        {1025, "Suela_Bicolor", NULL, 25},
        {1026, "Borde_Acolchonado", NULL, 30},
        {1027, "Logo_Bordado", NULL, 45},
        {1028, "Tela_Reflectante", NULL, 20},
        {1029, "Cordones_Multicolor", NULL, 45}
    };


    fseek(ArchivoPedidos, 0, SEEK_END);
    int n = ftell(ArchivoPedidos) / sizeof(pedido);  // Cantidad de registros
    fseek(ArchivoPedidos, 0, SEEK_SET);

    //Funcion para cout pedidos
    // leerArchivo(ArchivoPedidos);
    
    pedido vecDePedidos[n];
    cargarVector(vecDePedidos,ArchivoPedidos,n);
    int idModeloActual;
    for (int i=0;i<n;i++){
        idModeloActual=vecDePedidos[i].idModelo;
        cout << idModeloActual - 1000 << ": ";
        cout << vecModelos[idModeloActual-1000].descripcion << endl;
    }

    //cerrar archivo
    fclose(ArchivoPedidos);
    return 0;
}

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

void cargarVector(pedido vec[], FILE* f, int n){
    for (int i=0;i<n;i++){
        fread(&vec[i],sizeof(pedido),1,f);
    }
}

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

void actualizarPedidos(FILE* ArchivoPedidos, pedido* colaPedidoFrente){
    pedido Pedido;
    fseek(ArchivoPedidos, 0, SEEK_SET);  // Volver al inicio del archivo por si se uso y no se cerro

    int idPedidoAnt=0;//no se si se hace falta incicializar :v (dos puntos v)
    int idLineaAnt;

    int i = 0;
    
	while (colaPedidoFrente!=NULL){
        cout << i << endl;
    		while(Pedido.idPedido == idPedidoAnt){//esto es para cuando el idPedido se repita. (osea id linea !=)
    			//Acá tendra que ir todo lo totalLinea y eso
			}
		// idPedidoAnt=Pedido.idPedido;
        i++;
    }
}

// void queue(NodoPedido*& frente, NodoPedido*& fin, pedido x){ 
//     NodoPedido* p =new NodoPedido;
//     p->info = x;
//     p->sgte=NULL; // como el nodo p va a tener la direccion del ultimo, el siguiente a este necesita ser NULL
//     // si la cola esta vacia ahora el frente apunta al nuevo nodo
//     if (frente==NULL){
//         frente = p;
//     }
//     // si la cola NO esta vacia el nuevo nodo se debe enlazar despues del ultimo
//     else {
//         fin->sgte=p; // el siguiente del ultimo es el nuevo que acabamos de crear
//     }

//     fin=p; // el puntero al final siempre debe apuntar al nodo que acabamos de crear
// }

// pedido unqueue(NodoPedido*& frente, NodoPedido*& fin){
//     // en el caso de una cola el puntero que siempre se modifica es el del frente, el puntero del final permanece sin modificaciones hasta que saquemos el ultimo
//     // porque cuando sacamos el ultimo la cola queda vacia y el puntero tiene que apuntar a NULL
//     NodoPedido* p = frente; // a un puntero auxilar p, le asignamos la direccion de memoria del primer nodo de la cola
//     pedido x = p->info; // en el entero guardamos la info del primer nodo
//     frente=p->sgte; // hacemos avanzar al puntero frente al proximo nodo porque vamos a eliminar al que estaba primero
//     // este control es lo unico que cambia en el procedimiento de la pila, porque si el frente vale NULL el fin tambien
//     if (frente==NULL){
//         fin==NULL; // cola vacia
//     }
//     delete p; // eliminamos el nodo que era primero antes
//     return x; // retornamos info del primer nodo
// }

// PUNTO 1. :

// - Dicho por Roxana: Hacer un while que lea los pedidos (uno por uno), otro que lea las lineas una por una.
//   Saca el id modelo y lo busca en el vector de modelos con pos unica y predecible (pq esta ordenado).
//   Calcular el totalLinea = PrecioBase (precio del modelos) + Cant de productos * Componente. Suma el precio base del modelo + el gasto de los componentes.
//   Por cada componente -> Buscarlo en el vector -> Buscar proveedor mas barato (Punto 2).

// -  Sumar los totales de cada linea y multiplicamos por la cantidad para conseguir el total del pedido.

// - Actualizar el archivo? Agregamos el costo del pedido.

// - Disminuir el stock de cada uno de los componentes usados.

// - Mostrar el total.

// - Mostrar archivo de pedidos actualizado.
// - Mostrar el total de todos los pedidos? -> Sumar los costos y mostrar por pantalla.