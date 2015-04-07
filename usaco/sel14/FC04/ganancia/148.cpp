#include <iostream>
#include <fstream>
using namespace std;

int cantautos = 0;
int pagardiario = 0;
int totaldias = 0;
int num = 0;
int ganar [100];
int valor = 0;
int aux;
float dias [100];
float pagar [100];
float auxrelacion = 0;
float auxnumero = 0;
float relacion[10][100000];


void ordenar(){
	
	for(int i = 1; i <= cantautos; i++){
		for(int j = 1; j <= cantautos; j++){
			if(relacion[1][i]>relacion[1][j]){
				
				auxrelacion = relacion[1][j];
				auxnumero = relacion[2][j];
				
				relacion[1][j] = relacion[1][i];
				aux = relacion[2][i];
				relacion[2][j] = aux;
				
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
		valor = valor - (pagardiario * dias[num]);
		valor = valor + ganar[num];

	}
	
	fout<<valor<<endl;

	fin.close();
	fout.close();
	return 0;
}

