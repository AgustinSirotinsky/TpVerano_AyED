#include<iostream>
#include<cstring>
using namespace std;

struct pedidos{
    int idPedido;
    int idLinea;
    int fecha;
    int idModelo;
    int cantidad;
    float costo;
};

int main(){
//datos del archivo
pedidos vec[]; //modificiar la dimensión alg agregar una linea de pedido
vec[0].idPedido=;
vec[0].idLinea=;
vec[0].fecha=;
vec[0].idModelo=;
vec[0].cantidad=;
vec[0].costo=;



//==============================================================================
//grabar en el archivo
FILE* p=fopen("ArchivoPedidos.dat","wb");

pedidos raux;

for (int i=0; i<7; i++){
    raux= vec[i];
    fwrite(&raux, sizeof(pedidos),1,p);
};
fclose(p);

FILE* f=fopen("ArchivoPedidos.dat","rb");

while (fread(&raux,sizeof(pedidos),1,f)){
    cout<<raux.idPedido<<" "<<raux.idLinea<<" "<<raux.fecha<<" "<<raux.idModelo<<" "<<raux.cantidad<<" "<<raux.costo<<endl;
}
fclose(f);
return 0;
}
