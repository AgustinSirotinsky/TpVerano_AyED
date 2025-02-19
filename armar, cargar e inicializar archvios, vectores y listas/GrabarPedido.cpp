//Archivo

#include <iostream>

using namespace std;

struct ArchivoDePedido{
	int IdPedido;
	int Idlinea;
	int Fecha;//AAAAMMDD
	int IdModelo;
	int Cant;
	float Costo;
};

int main(){
	ArchivoDePedido Pedido[10]={
	{5226,1,20250126,2,25,0},
	{5226,2,20250126,9,32,0},
	{5227,1,20250126,2,3,0},
	{5227,2,20250127,3,15,0},
	{5228,1,20250128,7,40,0},
	{5228,2,20250128,4,18,0},
	{5229,1,20250129,9,50,0},
	{5230,1,20250130,6,28,0},
	{5231,1,20250131,8,12,0},
	{5232,1,20250201,10,22,0}
	};
	
	FILE *Pedidos= fopen("Pedidos.dat","wb");
	
	fwrite(&Pedido, sizeof(ArchivoDePedido), 10, Pedidos);

    
	fclose(Pedidos);
	return 0;
}