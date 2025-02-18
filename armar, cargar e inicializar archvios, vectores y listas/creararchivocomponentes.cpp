#include<iostream>
#include<cstring>
using namespace std;
//para dsp cargar el vector de componentes y la lista de proveedores

struct listaProv{
    int idComp; //inicia el 1000 vec[i+1000]
    int idProv;
    char nombre[50+1];
    float valorUnitario;
};
//===========================================================
//el vector de modelos tiene 1000 componentes
//queresmos crear el archivo para que se creen las listas
int main(){
    //vector a pasar al archivo con 6 componentes y algunos poroveedores por componente
    listaProv v[40];

    v[0].idComp = 1000;
    v[0].idProv = 157;
    strcpy(v[0].nombre, "Proveedor1");
    v[0].valorUnitario = 15.50;

    v[1].idComp = 1000;
    v[1].idProv = 119;
    strcpy(v[1].nombre, "Proveedor2");
    v[1].valorUnitario = 12.30;

    v[2].idComp = 1001;
    v[2].idProv = 132;
    strcpy(v[2].nombre, "Proveedor3");
    v[2].valorUnitario = 8.75;

    v[3].idComp = 1001;
    v[3].idProv = 180;
    strcpy(v[3].nombre, "Proveedor4");
    v[3].valorUnitario = 9.40;

    v[4].idComp = 1002;
    v[4].idProv = 101;
    strcpy(v[4].nombre, "Proveedor5");
    v[4].valorUnitario = 2.20;

    v[5].idComp = 1002;
    v[5].idProv = 165;
    strcpy(v[5].nombre, "Proveedor 6");
    v[5].valorUnitario = 2.50;

    v[6].idComp = 1003;
    v[6].idProv = 191;
    strcpy(v[6].nombre, "Proveedor7");
    v[6].valorUnitario = 5.80;

    v[7].idComp = 1003;
    v[7].idProv = 144;
    strcpy(v[7].nombre, "Proveedor 8");
    v[7].valorUnitario = 6.10;

    v[8].idComp = 1004;
    v[8].idProv = 125;
    strcpy(v[8].nombre, "Proveedor9");
    v[8].valorUnitario = 22.00;

    v[9].idComp = 1004;
    v[9].idProv = 176;
    strcpy(v[9].nombre, "Proveedor10");
    v[9].valorUnitario = 24.50;

    v[10].idComp = 1005;
    v[10].idProv = 133;
    strcpy(v[10].nombre, "Proveedor11");
    v[10].valorUnitario = 14.60;

    v[11].idComp = 1005;
    v[11].idProv = 162;
    strcpy(v[11].nombre, "Proveedor12");
    v[11].valorUnitario = 13.90;

    v[12].idComp = 1006;
    v[12].idProv = 148;
    strcpy(v[12].nombre, "Proveedor13");
    v[12].valorUnitario = 8.0;

    v[13].idComp = 1006;
    v[13].idProv = 153;
    strcpy(v[13].nombre, "Proveedor14");
    v[13].valorUnitario = 7.90;

    v[14].idComp = 1007;
    v[14].idProv = 117;
    strcpy(v[14].nombre, "Proveedor15");
    v[14].valorUnitario = 4.30;

    v[15].idComp = 1007;
    v[15].idProv = 195;
    strcpy(v[15].nombre, "Proveedor16");
    v[15].valorUnitario = 3.60;

    v[16].idComp = 1008;
    v[16].idProv = 122;
    strcpy(v[16].nombre, "Proveedor17");
    v[16].valorUnitario = 10.50;

    v[17].idComp = 1008;
    v[17].idProv = 184;
    strcpy(v[17].nombre, "Proveedor18");
    v[17].valorUnitario = 18.0;

    v[18].idComp = 1009;
    v[18].idProv = 129;
    strcpy(v[18].nombre, "Proveedor19");
    v[18].valorUnitario = 11.5;

    v[19].idComp = 1009;
    v[19].idProv = 199;
    strcpy(v[19].nombre, "Proveedor20");
    v[19].valorUnitario = 12.0;

    v[20].idComp = 1010;
    v[20].idProv = 159;
    strcpy(v[20].nombre, "Proveedor21");
    v[20].valorUnitario = 14.00;

    v[21].idComp = 1010;
    v[21].idProv = 140;
    strcpy(v[21].nombre, "Proveedor22");
    v[21].valorUnitario = 9.85;

    v[22].idComp = 1011;
    v[22].idProv = 137;
    strcpy(v[22].nombre, "Proveedor23");
    v[22].valorUnitario = 5.95;

    v[23].idComp = 1011;
    v[23].idProv = 178;
    strcpy(v[23].nombre, "Proveedor24");
    v[23].valorUnitario = 6.75;

    v[24].idComp = 1012;
    v[24].idProv = 111;
    strcpy(v[24].nombre, "Proveedor25");
    v[24].valorUnitario = 15.10;

    v[25].idComp = 1012;
    v[25].idProv = 193;
    strcpy(v[25].nombre, "Proveedor26");
    v[25].valorUnitario = 17.0;

    v[26].idComp = 1013;
    v[26].idProv = 123;
    strcpy(v[26].nombre, "Proveedor27");
    v[26].valorUnitario = 8.90;

    v[27].idComp = 1013;
    v[27].idProv = 175;
    strcpy(v[27].nombre, "Proveedor28");
    v[27].valorUnitario = 10.0;

    v[28].idComp = 1014;
    v[28].idProv = 155;
    strcpy(v[28].nombre, "Proveedor29");
    v[28].valorUnitario = 12.70;

    v[29].idComp = 1014;
    v[29].idProv = 145;
    strcpy(v[29].nombre, "Proveedor30");
    v[29].valorUnitario = 13.0;

    v[30].idComp = 1015;
    v[30].idProv = 179;
    strcpy(v[30].nombre, "Proveedor31");
    v[30].valorUnitario = 9.30;

    v[31].idComp = 1015;
    v[31].idProv = 142;
    strcpy(v[31].nombre, "Proveedor32");
    v[31].valorUnitario = 10.25;

    v[32].idComp = 1016;
    v[32].idProv = 127;
    strcpy(v[32].nombre, "Proveedor33");
    v[32].valorUnitario = 6.70;

    v[33].idComp = 1016;
    v[33].idProv = 186;
    strcpy(v[33].nombre, "Proveedor34");
    v[33].valorUnitario = 7.0;

    v[34].idComp = 1017;
    v[34].idProv = 135;
    strcpy(v[34].nombre, "Proveedor35");
    v[34].valorUnitario = 11.40;

    v[35].idComp = 1017;
    v[35].idProv = 150;
    strcpy(v[35].nombre, "Proveedor36");
    v[35].valorUnitario = 12.90;

    v[36].idComp = 1018;
    v[36].idProv = 170;
    strcpy(v[36].nombre, "Proveedor37");
    v[36].valorUnitario = 6.0;

    v[37].idComp = 1018;
    v[37].idProv = 104;
    strcpy(v[37].nombre, "Proveedor38");
    v[37].valorUnitario = 5.25;

    v[38].idComp = 1019;
    v[38].idProv = 138;
    strcpy(v[38].nombre, "Proveedor39");
    v[38].valorUnitario = 19.75;

    v[39].idComp = 1019;
    v[39].idProv = 160;
    strcpy(v[39].nombre, "Proveedor40");
    v[39].valorUnitario = 18.0;
    //==============================================================================
    //grabar en el archivo
    FILE* p=fopen("ArchivoListaProv.dat","wb");

    listaProv raux;
    for (int i=0; i<40; i++){
        raux= v[i];
        fwrite(&raux, sizeof(listaProv),1,p);
    };
    fclose(p);

    //-------------------------------------------------------------------------------------------------
    //mostrar en pantalla lo del archivo
    FILE* f=fopen("ArchivoListaProv.dat","rb");
    cout<<"IdComponente: "<<"IdProveedor: "<<"Nombre: "<<"ValorUnitario: "<<endl;
    while (fread(&raux,sizeof(listaProv),1,f)){
        cout<<raux.idComp<<" "<<" "<<raux.idProv<<" "<<raux.nombre<<" "<<raux.valorUnitario<<endl;
        cout<<"---------------------------------------------------------------------------------"<<endl;
    }
    fclose(f);

    return 0;
}






