#include<iostream>
#include<cstring>
using namespace std;

//vector de modelos:
//para la lista de los componentes
struct listaComp{
    int idModelo;
    int idAccesorio;
    int cantidad;
};

int main(){
    listaComp v[21];

    v[0].idModelo = 1;
    v[0].idAccesorio = 1000;
    v[0].cantidad = 2;

    v[1].idModelo = 1;
    v[1].idAccesorio = 1007;
    v[1].cantidad = 8;

    v[2].idModelo = 2;
    v[2].idAccesorio = 1001;
    v[2].cantidad = 2;

    v[3].idModelo = 2;
    v[3].idAccesorio = 1002;
    v[3].cantidad = 2;

    v[4].idModelo = 3;
    v[4].idAccesorio = 1004;
    v[4].cantidad = 2;

    v[5].idModelo = 3;
    v[5].idAccesorio = 1005;
    v[5].cantidad = 4;

    v[6].idModelo = 4;
    v[6].idAccesorio = 1017;
    v[6].cantidad = 8;

    v[7].idModelo = 4;
    v[7].idAccesorio = 1006;
    v[7].cantidad = 2;

    v[8].idModelo = 5;
    v[8].idAccesorio = 1008;
    v[8].cantidad = 2;

    v[9].idModelo = 5;
    v[9].idAccesorio = 1009;
    v[9].cantidad = 2;

    v[10].idModelo = 6;
    v[10].idAccesorio = 1010;
    v[10].cantidad = 2;

    v[11].idModelo = 6;
    v[11].idAccesorio = 1019;
    v[11].cantidad = 8;

    v[12].idModelo = 7;
    v[12].idAccesorio = 1012;
    v[12].cantidad = 4;

    v[13].idModelo = 7;
    v[13].idAccesorio = 1013;
    v[13].cantidad = 2;

    v[14].idModelo = 8;
    v[14].idAccesorio = 1014;
    v[14].cantidad = 2;

    v[15].idModelo = 8;
    v[15].idAccesorio = 1011;
    v[15].cantidad = 2;

    v[16].idModelo = 9;
    v[16].idAccesorio = 1016;
    v[16].cantidad = 1;

    v[17].idModelo = 9;
    v[17].idAccesorio = 1015;
    v[17].cantidad = 2;

    v[18].idModelo = 10;
    v[18].idAccesorio = 1018;
    v[18].cantidad = 2;

    v[19].idModelo = 10;
    v[19].idAccesorio = 1019;
    v[19].cantidad = 8;

    v[20].idModelo = 10;
    v[20].idAccesorio = 1003;
    v[20].cantidad = 2;

    //==============================================================================
    //grabar en el archivo
    FILE* p=fopen("ArchivoListaComp.dat","wb");

    listaComp raux;

    for (int i=0; i<21; i++){
        raux= v[i];
        fwrite(&raux, sizeof(listaComp),1,p);
    };
    fclose(p);

    FILE* f=fopen("ArchivoListaComp.dat","rb");

    while (fread(&raux,sizeof(listaComp),1,f)){
        cout<<raux.idModelo<<" "<<raux.idAccesorio<<" "<<raux.cantidad<<endl;
    }
    fclose(f);
    return 0;
}

/*

{1, "Zapatilla_Eco_Friendly", 18000.0, 'v', NULL},
        {2, "Zapatilla_Urbana_Negra", 12000.0, 'v', NULL},
        {3, "Zapatilla_Deportiva_Blanque", 15000.0, 'v', NULL},
        {4, "Zapatilla_Trekking_Resistente", 18000.0, 'i', NULL},
        {5, "Zapatilla_Casual_Azul", 13000.0, 'v', NULL},
        {6, "Zapatilla_High_Top_Roja", 17000.0, 'i', NULL},
        {7, "Zapatilla_Minimalista_Beige", 14000.0, 'v', NULL},
        {8, "Zapatilla_Clásica_Bicolor", 12500.0, 'v', NULL},
        {9, "Zapatilla_Correr_Liviana", 16000.0, 'v', NULL},
        {10, "Zapatilla_Skate_Reforzada", 17500.0, 'i', NULL},
*/
