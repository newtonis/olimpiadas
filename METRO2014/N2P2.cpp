#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

/****** 

Por Ariel Nowik, 5EA, ariel.nowik@gmail.com

OIA Certamen Metropolitano, Ejercicio 2, Nivel 2

Puntaje 100/100

*******/

///GLOBALES
int N; //cantidad parentesis
int Q; //cantidad de modificaciones
vector <char> original; //lugar donde almaceno los parentesis en forma de un vector de char
int neto_parentesis; //variable no utilizada


void lectura(); //leo el fichero y almaceno los datos de la cadena
bool cumple(); //para revisar si actualmente los parentesis cumplen las reglas

int main(){
	neto_parentesis = 0; //variable que al final no use
	lectura(); //en este problema al final termine haciendo todo en la funcion lectura, ya que era muy simple. Lectura, solucion y mostrar solucion estan en la misma funcion
}

bool cumple(){
	int neto_p = 0; //en cuanto estoy metido en parentesis (en que "mundo" estoy) mundo0(mundo1(mundo2)))
	for (int x = 0;x < N;x++){ //por cada parentesis
		if (original[x] == '('){ //si abre parentesis
			neto_p ++; //entro a un mundo mas adentro
		}else if(original[x] == ')'){ //si cierra parentesis
 			neto_p --; //salgo del mundo actual, vuelvo al anterior
		}
		if (neto_p < 0){ //no hay mundos negativos, si sucede, no se cumplen las reglas
			return false;
		}
	}
	if (neto_p == 0){ //si se cerraron todos los parentesis, es decir, como inicie en el mundo 0, termine en el mundo 0
		return true;
 	}
 	//si no, no se cumplen las reglas
	return false;
}
void lectura(){
	freopen("TESTN2P2.TXT","r",stdin); //leo fichero
	cin>>N; //cargo la longitud del parentesis
	
	string valor; cin>>valor; //leo el valor
	for (int x = 0;x < N;x++){ //lo itero y almaceno en un vector de char cada item individual del string (un vector de char es mas manipulable
	  //que un string
		original.push_back( valor[x] );
	}
	cin>>Q; //leo la cantidad de modificaciones que seguiran
	if (cumple()){ //si "original" cumple las reglas de parentesis
		cout<<"V"<<endl;
	}else{ //sino
		cout<<"I"<<endl;
	}
	for (int x = 0;x < Q;x++){ //por cada modificacion que se enlista
		int id; cin>>id; id --; //leo que numero de parentesis cambia por su contrario ( resto 1, porque se enumeran de 1,2,3, y los vectores se enumeran de 0,1,2)
		if (original[id] == '('){ //si abro
			original[id] = ')'; //cambio por cierro
		}else if(original[id] == ')'){ //si cierro
			original[id] = '('; //cambio por abro
		}
		if (cumple()){ //si con la modificacion actual a original se cumplen las reglas
			cout<<"V"<<endl;
		}else{ //sino
			cout<<"I"<<endl;
		}
	}
	
}
