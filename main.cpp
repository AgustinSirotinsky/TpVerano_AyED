#include <iostream>
#include <cstring>

using namespace std;

// Structs---------------------------------------------------------------

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
    char nombre[50+1];
    float valorUnitario;
};
struct ArchivoListaProv{
    int idComp; //inicia el 1000
    int idProv;
    char nombre[50+1];
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
//para inicializar las listas
struct listaComp{
    int idModelo;
    int idAccesorio;
    int cantidad;
};


//funciones-----------------------------------------------------------------------------------------------
void cargarVector(pedido vec[], FILE* f, int n);
void burbuja(int v[], int N);
void actualizarPedidos(FILE* ArchivoPedidos);
void leerArchivo (FILE* ArchivoPedidos);
float CalcularComponente(registroModelos vecModelos[], int N, registroComponentes vecComponentes[],	pedido p);
void pushListaComp(NodoProveedores*&, tipoInfoComponentesProveedores);
void cargarDatos(registroComponentes v[]);
void CargarComponente (registroComponentes vComponentes[]);
void pushLista(NodoComponentes*& lista, tipoInfoComponentes valor);
void cargarDatos(registroModelos v[]);
void cargarListaComponentes(registroModelos vModelos[]);
//--------------------------------------------------------------------------------------------------------

int main(){
	FILE* ArchivoPedidos=fopen("Pedidos.dat","rb+");
    registroModelos vecModelos[50];
    cargarListaComponentes(vecModelos);
    
    registroComponentes vecComponentes[1000];
    CargarComponente (vecComponentes);
	pedido p;
	int idPedidoAnt=0;
	float CostoPedido=0;
	
	cout<<"Pedidos: "<<endl;
	cout<<"===================================================================="<<endl;
	
	while (fread(&p, sizeof(pedido), 1, ArchivoPedidos)) {  		
    
		float Componente;
		int N=p.idModelo-1;
		
		if(p.idPedido!=idPedidoAnt &&idPedidoAnt != 0){
			cout<<"Precio Total del pedido: "<< CostoPedido <<endl;
			cout<<"===================================================================="<<endl;
			CostoPedido = 0;//reinicio por las dudas
		}
		
		//imprime los datos del pedido
		if(p.idPedido!=idPedidoAnt)
			cout<<"Id de pedido: "<<p.idPedido<<endl;
		cout<<"Id de linea: "<<p.idLinea<<endl;
		cout<<"Fecha: "<<p.fecha<<endl;
		cout<<"Id de modelo: "<<p.idModelo <<endl;
		cout<<"Cantidad: "<<p.cantidad<<endl;
		
		//por linea
		Componente= CalcularComponente( vecModelos,N, vecComponentes, p);
		p.costo=vecModelos[N].precioBase + p.cantidad*Componente;
		//total
		CostoPedido+=p.costo;
		
		//grabar en el archivo y cout

		fseek(ArchivoPedidos, -sizeof(pedido), SEEK_CUR);
		fwrite(&p,sizeof(pedido),1,ArchivoPedidos);
		fseek(ArchivoPedidos, 0, SEEK_CUR);
	
		cout<<"Costo de linea: "<<p.costo<<endl;
	
		// Actualizar el idPedido actual
  		idPedidoAnt = p.idPedido;

  		
	};
	
	// imprimir el costo total del último pedido después de salir del loop
    if (idPedidoAnt != 0){cout << "Precio Total del pedido: " << CostoPedido << endl;
    cout << "====================================================================" << endl;}

    
    //cerrar archivo
    fclose(ArchivoPedidos);
    return 0;
}

void pushListaComp(NodoProveedores *&lista, tipoInfoComponentesProveedores valor) {
    NodoProveedores *aux = new NodoProveedores();
    aux->info = valor;
    aux->sgte = lista;
    lista = aux;
}

void pushLista(NodoComponentes*& lista, tipoInfoComponentes valor) {
    NodoComponentes* aux = new NodoComponentes();
    aux->info = valor;
    aux->sgte = lista;
    lista = aux;
}


void cargarDatosComp(registroComponentes v[]){ //v[i-1000]
   for (int i = 0; i < 20; i++) {
        v[i].idComponente = 1000 + i;
    }

    strcpy(v[0].descripcion, "Suela_de_goma");
    strcpy(v[1].descripcion, "Plantilla_de_espuma");
    strcpy(v[2].descripcion, "Cordones_de_algodon");
    strcpy(v[3].descripcion, "Cierre_de_velcro");
    strcpy(v[4].descripcion, "Cuero_sintetico");
    strcpy(v[5].descripcion, "Tela_de_malla");
    strcpy(v[6].descripcion, "Espuma_para_talon");
    strcpy(v[7].descripcion, "Ojales_metalicos_plateados");
    strcpy(v[8].descripcion, "Logo bordado");
    strcpy(v[9].descripcion, "Refuerzo de punta");
    strcpy(v[10].descripcion, "Entresuela EVA");
    strcpy(v[11].descripcion, "Talonera");
    strcpy(v[12].descripcion, "Forro textil");
    strcpy(v[13].descripcion, "Etiqueta de marca");
    strcpy(v[14].descripcion, "Espuma de memoria");
    strcpy(v[15].descripcion, "Puntera de goma");
    strcpy(v[16].descripcion, "Adhesivo industrial");
    strcpy(v[17].descripcion, "Ojales_metalicos_dorados");
    strcpy(v[18].descripcion, "Cápsula de aire");
    strcpy(v[19].descripcion, "Ojales_metalicos_bronce");

    for(int i=0; i<20; i++){
        v[i].stock=1000;
    }

    //inicalizar el resto en cero para que no tenga basura
    for(int i=20; i<1000; i++){
        v[i].idComponente=0;
        strcpy(v[i].descripcion, "\0");
    }
};

void CargarComponente (registroComponentes vComponentes[]) {
    //hacerlo de 1000
    cargarDatosComp(vComponentes);

    FILE *prov=fopen("ArchivoListaProv.dat","rb");
    //que voy a necesitar:
    ArchivoListaProv raux;
    tipoInfoComponentesProveedores aux;
    int idAnterior;

    fread(&raux, sizeof(ArchivoListaProv), 1, prov);
    while(!feof(prov)){
        idAnterior=raux.idComp;
        while((!feof(prov))&& (idAnterior==raux.idComp)){
            //pasar solo los campo de la lista de proveedores
            aux.idProveedor=raux.idProv;
            strcpy(aux.nombre, raux.nombre);
            aux.valorUnitario= raux.valorUnitario;
            
            pushListaComp(vComponentes[raux.idComp - 1000].listaProveedores, aux);
            fread(&raux, sizeof(ArchivoListaProv), 1, prov);
        }
    };
    fclose(prov);



}
void cargarDatos(registroModelos v[]){ //v[i-1000]
   
    
    v[0].idModelo = 1;
    strcpy(v[0].descripcion, "Zapatilla_Eco_Friendly");
    v[0].precioBase = 18000.0;
    v[0].temporada = 'v';

    v[1].idModelo = 2;
    strcpy(v[1].descripcion, "Zapatilla_Urbana_Negra");
    v[1].precioBase = 12000.0;
    v[1].temporada = 'v';

    v[2].idModelo = 3;
    strcpy(v[2].descripcion, "Zapatilla_Deportiva_Blanche");
    v[2].precioBase = 15000.0;
    v[2].temporada = 'v';

    v[3].idModelo = 4;
    strcpy(v[3].descripcion, "Zapatilla_Trekking_Resistente");
    v[3].precioBase = 18000.0;
    v[3].temporada = 'i';

    v[4].idModelo = 5;
    strcpy(v[4].descripcion, "Zapatilla_Casual_Azul");
    v[4].precioBase = 13000.0;
    v[4].temporada = 'v';

    v[5].idModelo = 6;
    strcpy(v[5].descripcion, "Zapatilla_High_Top_Roja");
    v[5].precioBase = 17000.0;
    v[5].temporada = 'i';

    v[6].idModelo = 7;
    strcpy(v[6].descripcion, "Zapatilla_Minimalista_Beige");
    v[6].precioBase = 14000.0;
    v[6].temporada = 'v';

    v[7].idModelo = 8;
    strcpy(v[7].descripcion, "Zapatilla_Clásica_Bicolor");
    v[7].precioBase = 12500.0;
    v[7].temporada = 'v';

    v[8].idModelo = 9;
    strcpy(v[8].descripcion, "Zapatilla_Correr_Liviana");
    v[8].precioBase = 16000.0;
    v[8].temporada = 'v';

    v[9].idModelo = 10;
    strcpy(v[9].descripcion, "Zapatilla_Skate_Reforzada");
    v[9].precioBase = 17500.0;
    v[9].temporada = 'i';

    //inicializar el resto de lo modelos en cero
    for (int i=10; i<50; i++){
        v[i].idModelo = 0;
        strcpy(v[i].descripcion, "\0");
        v[i].precioBase =0;
        v[i].temporada = '\0';
    };


};

void cargarListaComponentes(registroModelos vModelos[]) {
    FILE* comp = fopen("ArchivoListaComp.dat", "rb");
    cargarDatos(vModelos);
    listaComp raux;
    tipoInfoComponentes aux;
    fread(&raux, sizeof(listaComp), 1, comp);
    while (!feof(comp)) {
        int idAnterior = raux.idModelo;
        while (!feof(comp) && idAnterior == raux.idModelo) {
            aux.idAccesorio = raux.idAccesorio;
            aux.cantidad = raux.cantidad;
            pushLista(vModelos[raux.idModelo - 1].listaComp, aux);
            fread(&raux, sizeof(listaComp), 1, comp);
        }
    }
    fclose(comp);
}


float CalcularComponente(registroModelos vecModelos[], int N, registroComponentes vecComponentes[],	pedido p){
	NodoComponentes* Aux=vecModelos[N].listaComp;
	tipoInfoComponentesProveedores rAux;
	float ValComponente;
	float ValComponenteTot=0;

	
	while(Aux!=NULL){
		NodoProveedores*	Aux2= vecComponentes[Aux->info.idAccesorio-1000].listaProveedores;
		rAux.idProveedor=0;
		rAux.valorUnitario=0;
		while(Aux2!=NULL){
			if((Aux2->info.valorUnitario)<rAux.valorUnitario ){
				rAux=Aux2->info;
			}
			//Para el primer caso
			if(rAux.idProveedor==0)
				rAux=Aux2->info;
			Aux2=Aux2->sgte;
		}
		ValComponente=rAux.valorUnitario * (Aux->info.cantidad);
		ValComponenteTot+=ValComponente;
		vecComponentes[Aux->info.idAccesorio-1000].stock-=Aux->info.cantidad*p.cantidad;
		Aux=Aux->sgte;	
	
	}	
	
	return ValComponenteTot;
}
