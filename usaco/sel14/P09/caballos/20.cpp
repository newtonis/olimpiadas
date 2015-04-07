#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
using namespace std;
unsigned long long modulo;
int filas,columnas,filaa,columnaa,caminos;
char matriz[1005][1005];
char frase[6];
char temp[4];
ifstream entrada;
ofstream salida;
void buscar(int fi,int co,int fra){
	if (fra!=6){
	if (matriz[fi-2][co-1]==frase[fra]) buscar(fi-2,co-1,fra+1);
	if (matriz[fi-2][co+1]==frase[fra]) buscar(fi-2,co+1,fra+1);
	if (matriz[fi-1][co+2]==frase[fra]) buscar(fi-1,co+2,fra+1);
	if (matriz[fi+1][co+2]==frase[fra]) buscar(fi+1,co+2,fra+1);
	if (matriz[fi+2][co-1]==frase[fra]) buscar(fi+2,co-1,fra+1);
	if (matriz[fi+2][co+1]==frase[fra]) buscar(fi+2,co+1,fra+1);
	if (matriz[fi-1][co-2]==frase[fra]) buscar(fi-1,co-2,fra+1);
	if (matriz[fi+1][co-2]==frase[fra]) buscar(fi+1,co-2,fra+1);
} else caminos++;
}
int main(){
	entrada.open("caballos.in");
	salida.open("caballos.out");
	frase[0]='A';
	frase[1]='B';
	frase[2]='A';
	frase[3]='L';
	frase[4]='L';
	frase[5]='O';
	queue <int>	filac,columnac;
	entrada >> filas >> columnas >> modulo;
	for(int fila=2;fila<filas+2;fila++){
			entrada >> temp;
			for (int columna=2;columna<columnas+2;columna++){
				matriz[fila][columna]=temp[columna-2];
		if (matriz[fila][columna]=='C') {
			filac.push(fila);
			columnac.push(columna);
		}
	}
}
	while (!filac.empty()) {
		filaa=filac.front();
		columnaa=columnac.front();
		filac.pop();
		columnac.pop();
		buscar(filaa,columnaa,0);
	}
	salida << caminos%modulo;
	entrada.close();
	salida.close();
}
		
		
		
		
		
