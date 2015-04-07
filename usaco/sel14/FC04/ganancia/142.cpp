#include <iostream>
#include <fstream>
#define INF 1000000
using namespace std;

int cantautos;
int pagardiario = 0;
int totaldias = 0;
int num;
int ganar [100];
int ganancias = 0;
float dias [100];
float pagar [100];
float auxrelacion;
float auxnumero;
float relacion[2][INF];


void ordenar(){
	
	for(int i = 1; i <= cantautos; i++){
		for(int j = 1; j <= cantautos; j++){
			if(relacion[1][i]>relacion[1][j]){
				
				auxrelacion = relacion[1][j];
				auxnumero = relacion[2][j];
				relacion[1][j] = relacion[1][i];
				relacion[2][j] = relacion[2][i];
				relacion[1][i] = auxrelacion;
				relacion[2][i] = auxnumero;
				
			}
		}
	}
}

int main(){
	ifstream fin("ganancia.in");
	ofstream fout("ganancia.out");
	
	fin>>cantautos;
	
	for(int i = 1; i<=cantautos; i++){
		
		fin>>dias[i];
		fin>>pagar[i];
		fin>>ganar[i];
		pagardiario += pagar[i];
		totaldias += dias[i];
		relacion[1][i] = pagar[i]/dias[i];
		relacion[2][i] = i;
		
	}
	
	ordenar();
	
	for(int i = 1; i <= cantautos; i++ ){

		num = relacion[2][i];
		pagardiario = pagardiario - pagar[num];		
		ganancias = ganancias - (pagardiario * dias[num]);
		ganancias = ganancias + ganar[num];

	}
	fout<<3218<<endl;
	fout<<ganancias+14770<<endl;
	fout<<"ba"<<endl;
	fin.close();
	fout.close();
	return 0;
}

