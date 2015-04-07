#include <iostream>
#include <fstream>
using namespace std;
unsigned long long precio=0,suma=0,total=0;
int cantidad=0,tarifa[50],demora[50],dias=0,mayor,mayorl;
ifstream entrada;
ofstream salida;
int main(){
	entrada.open("ganancia.in");
	salida.open("ganancia.out");
	entrada >> cantidad;
	for(int rep=0;rep<cantidad;rep++){
		entrada >> demora[rep] >> tarifa[rep] >> precio;
		suma+=precio;
   }
   for(int rep2=0;rep2<cantidad;rep2++){
   for(int rep3=0;rep3<cantidad;rep3++){
	   if(tarifa[rep3]>mayor) {
		   mayor=tarifa[rep3];
		   mayorl=rep3;
	   }  
   }
   total+=mayor*dias;
   dias+=demora[mayorl];
   tarifa[mayorl]=0;
   mayor=0;
}
suma-=total;
   salida << suma;
}
