#include <iostream>
#include <fstream>
#include <queue>
#define MAX 10000
using namespace std;

typedef struct{
	int numletra;
	int x;
	int y;
}caballos;

queue <caballos> cola;

char mapa[MAX][MAX];
char letras[8];
int cantdirs = 8; 
int filas;
int columnas;
int dir[10][10];
long long modulo;
long long contador = 0;

void definir(){
	
	dir[1][1]=-1;
	dir[1][2]=-2;
	dir[2][1]=1;
	dir[2][2]=-2;
	dir[3][1]=2;
	dir[3][2]=-1;
	dir[4][1]=2;
	dir[4][2]=1;
	dir[5][1]=1;
	dir[5][2]=2;
	dir[6][1]=-1;
	dir[6][2]=2;
	dir[7][1]=-2;
	dir[7][2]=1;
	dir[8][1]=-2;
	dir[8][2]=-1;
	
	letras[1] = 'C';
	letras[2] = 'A';
	letras[3] = 'B';
	letras[4] = 'A';
	letras[5] = 'L';
	letras[6] = 'L';
	letras[7] = 'O';
	letras[8] = ' ';
	
}

void buscar(){
	
	while(cola.empty()==false){

		caballos a = cola.front();
		cola.pop();
		
		for(int i = 1; i<=cantdirs;i++){
			
			caballos nuevocaballo = a;
			nuevocaballo.x += dir[i][1];
			nuevocaballo.y += dir[i][2];
			
			if(nuevocaballo.x>0 && nuevocaballo.y>0 && nuevocaballo.x<=filas && nuevocaballo.y<=columnas){
				
				if(mapa[nuevocaballo.x][nuevocaballo.y]==letras[nuevocaballo.numletra+1]){
					
					nuevocaballo.numletra+=1;
					
					if(nuevocaballo.numletra==7){
						
						if(contador==(modulo-1)){
							
							contador=0;
							
						}else{
							
							contador++;
							
						}
					}else{
						
						cola.push(nuevocaballo);
						
					}
				}
			}
		}
	}
}



int main (){
	
	ifstream fin("caballos.in");
	ofstream fout("caballos.out");
	
	definir();
	fin>>filas;
	fin>>columnas;
	fin>>modulo;
	
	for(int i = 1; i <=filas; i++){
		
		for(int j = 1; j <=columnas; j++){
			
			fin>>mapa[i][j];
			
			if(mapa[i][j]=='C'){
				
				caballos entrada;
				entrada.x=i;
				entrada.y=j;
				entrada.numletra=1;
				cola.push(entrada);
				
			}
		}
	}
	buscar();
	
	fout<<contador<<endl;
	
	fin.close();
	fout.close();
	return 0;
}
