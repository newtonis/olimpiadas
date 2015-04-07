#include <iostream>
#include <fstream>
#define INF 10000

using namespace std;

typedef struct{
	int id;
	int enemigos;
	}invitados;


int cantinvitados;
int cantenemigos;
int pos;
int contador;
int total;
invitados amigos[100000];
int main(){
	
	ifstream fin("casamiento.in");
	ofstream fout("casamiento.out");
	
	fin>>cantinvitados;
	fin>>cantenemigos;
	
	for(int i = 0; i<cantenemigos; i++){
		amigos[i].id=-1;
		amigos[i].enemigos=-1;
	}

	
	for(int i = 0; i<cantenemigos; i++){
		fin>>pos;
		fin>>amigos[pos].enemigos;
		fin>>amigos[pos].id;
	}
	
	contador=cantenemigos;
	
	for(int i = 0; i<cantenemigos; i++){
	
		if(amigos[i].enemigos != -1){
			contador--;
		}
	
	}
	
	total = cantinvitados - contador;
	
	fout<<total;
	
	return 0;
}
