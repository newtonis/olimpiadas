#include <fstream>
#include <iostream>
#include <queue>
#include <vector>
#include <map>

#define forn(i,n) for(int i=0;i<n;i++)

using namespace std;

enum Letras_num {LETRA_C, LETRA_A, LETRA_B, LETRA_L, LETRA_O};

struct Posicion {
	int x, y;
	Posicion(int x, int y){
		this->x = x;
		this->y = y; 
	}
	bool isValid(int limiteC, int limiteF ){
		return this->x >= 0 && this->x < limiteC && this->y >= 0 && this->y < limiteF;
	}
};

char letra[1005][1005];
int llegadas[9][1005][1005];

typedef map<int, vector<Posicion> > PosLetras;

void calc_llegadas(int index_palabra, Letras_num numLetra, PosLetras pos_letras,  int c, int f , int m);

int main(){
	ifstream in ("caballos.in");
	ofstream out ("caballos.out");
	
	int f,c,m;
	int res = 0;
	
	in>>f>>c>>m;
	
	PosLetras pos_letras;
	
	forn(i,f){
		forn(j,c){
			in>>letra[i][j];
			forn (k,8){
				llegadas[k][i][j] = 0;
			}
			switch(letra[i][j]){
				case 'C':
					llegadas[0][i][j] = 1;
					pos_letras[LETRA_C].push_back(Posicion(j, i));
					break;
				case 'A':
					pos_letras[LETRA_A].push_back(Posicion(j, i));
					break;
				case 'B':
					pos_letras[LETRA_B].push_back(Posicion(j, i));
					break;
				case 'L':
					pos_letras[LETRA_L].push_back(Posicion(j, i));
					break;
				case 'O':
					pos_letras[LETRA_O].push_back(Posicion(j, i));
					break;
				default:
					break;
			}
		}
	}
	
	

	calc_llegadas(0, LETRA_C, pos_letras, c, f, m);
	
	calc_llegadas(1, LETRA_A, pos_letras, c, f, m);
	
	calc_llegadas(2, LETRA_B, pos_letras, c, f, m);
	
	calc_llegadas(3, LETRA_A, pos_letras, c, f, m);
	
	calc_llegadas(4, LETRA_L, pos_letras, c, f, m);
	
	calc_llegadas(5, LETRA_L, pos_letras, c, f, m);
	
	
	forn(i, (int) pos_letras[LETRA_O].size()){
		Posicion pos = pos_letras[LETRA_O][i];
		res = (res + llegadas[6][pos.y][pos.x]) % m;
	}
	
	out<<res % m;
}

void calc_llegadas(int index_palabra, Letras_num numLetra, PosLetras pos_letras,  int c, int f , int m){
	string CABALLO = "CABALLO";
	int dx[] = {-1, 1, -1, 1, -2, 2 , -2 , 2};
	int dy[] = { 2,	 2,-2, -2, 1, 1, -1, -1}; //CHEQUEAR!!!!!!!!!!!!!!!!! 
	
	forn(i, (int) pos_letras[numLetra].size()){
		Posicion pos = pos_letras[numLetra][i];

		forn(k, 8){
			Posicion posNueva = Posicion(pos.x + dx[k], pos.y + dy[k]);
			if (posNueva.isValid(c,f)){
				if (letra[posNueva.y][posNueva.x] == CABALLO[index_palabra + 1]){
					llegadas[index_palabra+1][posNueva.y][posNueva.x] = (llegadas[index_palabra+1][posNueva.y][posNueva.x] + llegadas[index_palabra][pos.y][pos.x]) % m;
					/*
					cout<<CABALLO[index_palabra]<<endl;
					cout<<CABALLO[index_palabra + 1]<<endl;
					cout<<pos.x<<" "<<pos.y<<endl;
					cout<<posNueva.x<<" "<<posNueva.y<<endl;
					cout<<"+-----------------"<<endl;*/
				}
			}
 		}
		
	}
}
