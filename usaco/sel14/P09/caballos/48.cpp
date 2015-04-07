#include <iostream>
#include <fstream>
#include <queue>
using namespace std;
unsigned long long ºmodulo=0;
int filas=0,columnas=0,filaa=0,columnaa=0,caminos=0;
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
/*	for(int f1=0;f1<6;f1++) frase[f1]=0;
	for(int f2=0;f2<4;f2++) temp[f2]=0;
	for(int f3=0;f3<1005;f3++){
		for (int f4=0;f4<1005;f4++) matriz[f3][f4]=0;
	}*/
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
}
		
		
		
		
		
