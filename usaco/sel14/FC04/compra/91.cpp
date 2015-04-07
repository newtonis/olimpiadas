#include <iostream>
#include <fstream>
#define MAX_CASAS 1000000
#define INFINITO 1000000
using namespace std;

	
ifstream fin("compra.in");
ofstream fout("compra.out");
	


typedef struct{
	int v;
	int h;
}casa;


int norsur;//Largo
int estoest;//Ancho
int cantcasas;//Cantidad de casas
casa casamaxv;
casa casamaxh;
casa casaminv;
casa casaminh;
casa casas[MAX_CASAS];//Donde estan almacenadas las casa
int distmaxv = 0;
int distmaxh = 0;
int multiplicadorv = 1;
int multiplicadorh = 1;

void maxdistancia (){
	if(casamaxv.h-casaminv.h<0){
		multiplicadorv=-1;
	}
	if(casamaxh.v-casaminh.v<0){
		multiplicadorh=-1;
	}
	
	distmaxh=(casamaxv.v-casaminv.v)+((casamaxh.v-casaminh.v)*multiplicadorv);
	
	distmaxv=(casamaxh.h-casaminh.h)+((casamaxv.h-casaminv.h)*multiplicadorh);
	
	fout<<distmaxh/3<<" ";
	fout<<distmaxv/3<<endl;
}




int main (){
	
	casamaxv.v = 0;
	casamaxh.h = 0;
	casaminv.v = INFINITO;
	casaminh.h = INFINITO;
	
	fin>>norsur;
	fin>>estoest;
	fin>>cantcasas;
	
	for(int i = 0; i <cantcasas; i++){
		
		fin>>casas[i].v;
		fin>>casas[i].h;
		
		if(casas[i].v>casamaxv.v){
			casamaxv.v = casas[i].v;
			casamaxv.h = casas[i].h;
			
		}else if(casas[i].v<casaminv.v){
			casaminv.v = casas[i].v;
			casaminv.h = casas[i].h;
		}
		if(casas[i].h>casamaxh.h){
			casamaxh.v = casas[i].v;
			casamaxh.h = casas[i].h;
		}else if(casas[i].h<casaminh.h){
			casaminh.v = casas[i].v;
			casaminh.h = casas[i].h;
		}
		
	}

	maxdistancia();
	
	fin.close();
	fout.close();
	return 0;
}
