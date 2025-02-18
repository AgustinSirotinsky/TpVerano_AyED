#include <iostream>
#include<cstring>
using namespace std;

//Vector de componentes:
//lista de proveedores
struct infoProveedores{
    int idProv;
    char nombre[50+1];
    float valorUnitario;
};

struct nodoProv{
   infoProveedores info;
   nodoProv* sgte;
};

//para el vector de componentes
struct rComponente{
    int idComp;
    char descripcion[100+1];
    nodoProv* listaProv; //acceso a la lista de proveedores
    int stock;
};
//para cargar la lista
struct listaProv{
    int idComp; //inicia el 1000
    int idProv;
    char nombre[50+1];
    float valorUnitario;
};
//------------------------------------------------------------------------------------------------------------------------------------
// encabezado funciones
void pushLista(nodoProv*& , infoProveedores);
void cargarDatos(rComponente []);
//-------------------------------------------------------------------------------------------------------------------------------------
int main(){
    rComponente vComponentes[1000]; //hacerlo de 1000
    cargarDatos(vComponentes);

    FILE* prov=fopen("ArchivoListaProv.dat","rb");
    //que voy a necesitar:
    listaProv raux;
    infoProveedores aux;
    int idAnterior;

    fread(&raux, sizeof(listaProv), 1, prov);
    while(!feof(prov)){
        idAnterior=raux.idComp;
        while((!feof(prov))&& (idAnterior==raux.idComp)){
            //pasar solo los campo de la lista de proveedores
            aux.idProv=raux.idProv;
            strcpy(aux.nombre, raux.nombre);
            aux.valorUnitario= raux.valorUnitario;

            pushLista( vComponentes[raux.idComp-1000].listaProv, aux);
            fread(&raux, sizeof(listaProv), 1, prov);
        }
    };
    fclose(prov);

    //solo para saber que esta bien pero en el tp no va
    for (int i=0; i<20; i++){
        cout<<vComponentes[i].idComp<<" "<<vComponentes[i].descripcion<<" "<<vComponentes[i].stock<<endl;
        cout<<"lista: "<<endl;
        nodoProv* aux=vComponentes[i].listaProv;
        while (aux != NULL){
            cout<<"id: "<<aux->info.idProv<<" ";
            cout<<"nombre "<<aux->info.nombre<<" ";
            cout<<"valUni "<<aux->info.valorUnitario<<endl;

            aux=aux->sgte;

        };
          cout<<"----------------------------"<<endl;
    }

    return 0;
}
//--------------------------------------------------------------------------------------------------------------------------------
//Funciones
void cargarDatos(rComponente v[]){ //v[i-1000]
    v[0].idComp=1000;
    v[1].idComp=1001;
    v[2].idComp=1002;
    v[3].idComp=1003;
    v[4].idComp=1004;
    v[5].idComp=1005;
    v[6].idComp=1006;
    v[7].idComp=1007;
    v[8].idComp=1008;
    v[9].idComp=1009;
    v[10].idComp=1010;
    v[11].idComp=1011;
    v[12].idComp=1012;
    v[13].idComp=1013;
    v[14].idComp=1014;
    v[15].idComp=1015;
    v[16].idComp=1016;
    v[17].idComp=1017;
    v[18].idComp=1018;
    v[19].idComp=1019;

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
    //inicializar los punteros
    for(int i=0; i<1000; i++){
        v[i].listaProv=NULL;
    };

    //inicalizar el resto en cero para que no tenga basura
    for(int i=20; i<1000; i++){
        v[i].idComp=0;
        strcpy(v[i].descripcion, "\0");
    }
    };
void pushLista(nodoProv*& lista,infoProveedores valor){
    nodoProv* aux=new nodoProv();
    aux->info=valor;
    aux->sgte=lista;
    lista=aux;
};
