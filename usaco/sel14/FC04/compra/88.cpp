#include <iostream>
#include <fstream>
#include <queue>
#define MAX_CASAS 1000000
#define INFINITO 1000000
using namespace std;

typedef struct{
	int v;
	int h;
}casa;

queue <casa> cola;
/*
cola.push();
cola.front();
cola.empty();
cola.pop();
*/

int norsur;//Largo
int estoest;//Ancho
int cantcasas;//Cantidad de casas
casa casamaxv;
casa casamaxh;
casa casaminv;
casa casaminh;
casa casas[MAX_CASAS];//Donde estan almacenadas las casa
int distmax = 0;
int multiplicadorv = 1;
int multiplicadorh = 1;

void maxdistancia (){
	if(casamaxv.h-casaminv.h<0){
		multiplicadorv=-1;
	}
	if(casamaxh.v-casaminh.v<0){
		multiplicadorh=-1;
	}
	
	if((casamaxv.v-casaminv.v)+((casamaxh.v-casaminh.v)*multiplicadorv)>(casamaxh.h-casaminh.h)+((casamaxv.h-casaminv.h)*multiplicadorh)){
		distmax=(casamaxv.v-casaminv.v)+((casamaxh.v-casaminh.v)*multiplicadorv);
	}else{
		distmax=(casamaxv.v-casaminv.v)+((casamaxh.v-casaminh.v)*multiplicadorv);
	}
	cout<<distmax;
}




int main (){
	
	casamaxv.v = 0;
	casamaxh.h = 0;
	casaminv.v = INFINITO;
	casaminh.h = INFINITO;
	
	
	ifstream fin("compra.in");
	ofstream fout("compra.out");
	
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
	
	for(int i = 0; i <cantcasas; i++){
		
		cout<<casas[i].v<<" ";
		cout<<casas[i].h<<endl;
	}
	
	
	
	cout<<"MAXH= "<<casamaxh.v<<" "<<casamaxh.h<<endl;
	cout<<"MAXV= "<<casamaxv.v<<" "<<casamaxv.h<<endl;
	cout<<"MINH= "<<casaminh.v<<" "<<casaminh.h<<endl;
	cout<<"MINV= "<<casaminv.v<<" "<<casaminv.h<<endl;

	maxdistancia();
	
	fin.close();
	fout.close();
	return 0;
}
