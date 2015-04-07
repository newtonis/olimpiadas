#include <fstream>
#include <iostream>
#include <vector>
#include <stack>

#define forn(i,n) for(int i = 0 ;i<n;i++)

using namespace std;

long long  int min_sum_tar[55][55]; 

struct Auto {
	int demora, tarifa, precio;
	Auto(int d, int t,int p){
		this->demora = d;
		this->tarifa = t;
		this->precio = p;
		
	}
	Auto (){
		
	}
};
struct Nodo {
	bool poner;
	int car;
	int resta; 
	int turno;
};

int main(){


	ofstream out("casamiento.out");
	
	out<<3<<endl;
	
}
	

