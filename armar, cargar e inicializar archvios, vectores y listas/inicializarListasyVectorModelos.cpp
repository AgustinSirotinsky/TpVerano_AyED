#include <iostream>
#include<cstring>
using namespace std;

//vector de modelos:
//para la lista de los componentes
struct infoComponentes{
    int idAccesorio;
    int cantidad;
};
struct nodoComponentes{
    infoComponentes info;
    nodoComponentes* sgte;
};
//para el vector de modelos
struct rModelo{
    int idModelo;
    char descripcion[100+1];
    float precioBase;
    char temporada;
    nodoComponentes* listas; //acceso a la lista de proveedores.
};
//para inicializar las listas
struct listaComp{
    int idModelo;
    int idAccesorio;
    int cantidad;
};

//------------------------------------------------------------------------------------------------------------------------------------
// encabezado funciones
void pushLista(nodoComponentes*& , infoComponentes);
void cargarDatos(rModelo []);
//-------------------------------------------------------------------------------------------------------------------------------------
int main(){
    rModelo vModelos[50]; //hacerlo de 1000
    cargarDatos(vModelos);

    FILE* comp=fopen("ArchivoListaComp.dat","rb");

    //que voy a necesitar:
    listaComp raux;
    infoComponentes aux;
    int idAnterior;

    fread(&raux, sizeof(listaComp), 1, comp);
    while(!feof(comp)){
        idAnterior=raux.idModelo;
        while((!feof(comp))&& (idAnterior==raux.idModelo)){
            //pasar solo los campo de la lista de proveedores
            aux.idAccesorio=raux.idAccesorio;
            aux.cantidad= raux.cantidad;

            pushLista( vModelos[raux.idModelo-1].listas, aux);
            fread(&raux, sizeof(listaComp), 1, comp);
        }
    };
    fclose(comp);

    //solo para saber que esta bien pero en el tp no va
    for (int i=0; i<10; i++){
        cout<<vModelos[i].idModelo<<" "<<vModelos[i].descripcion<<" "<<vModelos[i].precioBase<<" "<<vModelos[i].temporada<<endl;
        cout<<"lista: "<<endl;
        nodoComponentes* aux=vModelos[i].listas;
        while (aux != NULL){
            cout<<"id: "<<aux->info.idAccesorio<<" ";
            cout<<"nombre "<<aux->info.cantidad<<endl;
            aux=aux->sgte;
        };
          cout<<"----------------------------"<<endl;
    };

    return 0;
}
//--------------------------------------------------------------------------------------------------------------------------------
//Funciones
void cargarDatos(rModelo v[]){ //v[i-1000]
    /*struct rModelo{
    int idModelo;
    char descripcion[100+1];
    float precioBase;
    char temporada;
    nodoComponentes* listaComp; //acceso a la lista de proveedores.
};
};
    */
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

    //inicializar los punteros a las listas
    for(int i=0; i<50; i++){
        v[i].listas=NULL;
    };
};

void pushLista(nodoComponentes*& lista,infoComponentes valor){
    nodoComponentes* aux=new nodoComponentes();
    aux->info=valor;
    aux->sgte=lista;
    lista=aux;
};
