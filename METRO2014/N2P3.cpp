#include <iostream>
#include <vector>
#include <cstdio>
#include <string>
#include <algorithm>
#include <sstream>
using namespace std;

/****** 

Por Ariel Nowik, 5EA, ariel.nowik@gmail.com

OIA Certamen Metropolitano, Ejercicio 3, Nivel 2

Puntaje 100/100

*******/

/*** NOTA: Se utilizo mucho en vez de string, vector <char> para guardar palabras. vector <char> es un conjunto de caracteres ***/
/*** NOTA: Yo tampoco se que es "lexicograficamente" , pero, si comparas dos strings utilizando el operador >, podes saber que palabra
 es mayor en ese orden 
***/

//globales

int N; //cantidad de palabras
vector < vector <char> > palabras;  //aca almaceno las N palabras, uso en vez de string vector <char> que es mas manejable
vector < bool > utilizadas; //este vector siempre tiene longitud N (es decir un lugar para cada palabra), marco con True en el lugar n, si ya use la palabra en la posicion n de palabras
vector < vector < string > > soluciones; //aca almaceno los grupos de palabras soluciones. es un vector de vectores de palabras, los grupos tiene cada uno 1 o mas palabras

void lectura(); //leer fichero
void solucion(); //solucionar
void ordenar(); //ordenar
void mostrar(); //mostrar en pantalla

bool compare(string a, string b ){ //esta funcion se utiliza para ordenar los strings "lexicograficamente", usando.
	return a < b; //si fuera b < a por ejemplo, se ordenaria al reves
}
bool compareb( vector <string> a,vector <string> b){ //funcion para ordenar vectores de string segun su longitud
	return a.size() < b.size(); //si fuera por ejemplo a.size() > b.size() se ordenaria al reves
}
vector <vector <char> > generar_corridas( vector <char> palabra); //genero a partir de una palabra, todas las posibles otras palabras que pueden llegar a estar en la ruleta con esas letras, en ambos sentidos

/**EJ

uso la funcion con ARBOL, obtengo

ARBOL y LOBRA
RBOLA y ALOBR
BOLAR y RALOB
OLARB y BRALO
LARBO y OBRAL

**/

bool comparar_vchar( vector <char> a,vector <char> b); //comparo si dos palabras guardades en vector <char> son iguales , ya que vector <char> no es como string que ya trae una funcion para comprar
string vchar_to_st( vector <char> a); // para transformar una palabra almacenada en vector <char> a una palabra almacenada en un string. Se utilizo para poder usar el operador < de los strings, que me permite ordenar "lexicograficamente"
string cts(char c); //transformo un char, a un string de longitud 1

int main(){
	lectura();	 //leo
	solucion();	//resuelvo
	ordenar();      //ordeno la solucion
	mostrar();     //muestro en pantalla
}
void mostrar(){
	for (int x = 0;x < soluciones.size();x++){ //por cada grupo
		for (int y = 0;y < soluciones[x].size();y++){ //por cada palabra del grupo
			cout<<soluciones[x][y]<<" "; //la muestro
		}
		cout<<endl; //dejo un espacio para el proximo grupo
	}
}
void ordenar(){
	for (int x = 0;x < soluciones.size();x++){ //por cada grupo
		//ORDENO
		sort( soluciones[x].begin() , soluciones[x].end() , compare); //ordeno sus palabras internas, utilizando como criterio la funcion compare, que hace que se ordene "lexicograficamente"
	}
	sort( soluciones.begin() , soluciones.end() , compareb ); //ordeno los grupos, segun la funcion compareb, que las compara segun longitud, y por lo tanto,se ordenan los grupos por longitud
}
void solucion(){
	for (int x = 0;x < N;x++){ //por cada palabra
		if (utilizadas[x]){ continue; } //si sucede que la palabra ya la utilize porque, en la iteracion de alguna palabra anterior ya la meti en el grupo correspondiente (sino, se me crearia un grupo paralelo)
		
		utilizadas[x] = true; //marco que la use
		vector <string> grupo; //inicio un nuevo grupo
		grupo.push_back(vchar_to_st(palabras[x])); //agrego la palabra pasada de vector char a string
		
		vector <vector <char> > an = generar_corridas( palabras[x] ); //genero todas las palabras que podria formar en la ruleta con la palabra actual
		
		for (int y = x+1;y < N;y++){ //por cada palabra, arrancando de x+1 ya que las palabras anteriores nunca van a ser agregadas al grupo porque sino, en su iteracion anterior del primer for hubieran agregado a la palabra actual, y entonces no estariamos llamando esto porque utilizadas de esta palabra seria true
			if (palabras[y].size() != palabras[x].size() ){  //si no coincide la longitud no puede pertenecer a la misma ruleta, es lo que el enunciado da a entender
				continue; //entonces la salteo
			}
			for (int z = 0;z < an.size();z++){ //por cada posible palabra de la ruleta
				if ( comparar_vchar( an[z] , palabras[y] ) ){ //si la palabra que encontre esta en una de las posibles palabras de la ruleta de la primera palabra
					utilizadas[y] = true; //marco que ya la use porque la voy a agregar al grupo
					
					//////*** NO ESTOY SEGURO Si estas lineas eran necesarias, pero como la solucion saco 100 puntos, dejo como estaba ***//////
					string st = vchar_to_st( an[z] );  //genero un string del anagrama actual
					bool noagregar = false;  
					for (int x = 0;x < grupo.size();x++){  //recorro el grupo actual
						if (grupo[x] == st){ //si estaba la palabra
							noagregar = true; //seteo para que no la agrege, sino, se va a repetir
							break;
						}
					}
					//////*** NO ESTOY SEGURO Si estas lineas eran necesarias, pero como la solucion saco 100 puntos, dejo como estaba ***//////
					
					if (noagregar == false){ //si la palabra no estaba en el grupo
						grupo.push_back(vchar_to_st(an[z])); //agrego el anagrama al grupo, an[z] es igual a palabras[y] por lo que podria tambien escribir vchar_to_st(palabras[y]);
					}
				}
			}
		}
		
		soluciones.push_back( grupo ); //agrego el grupo al conjunto de grupos (vector de grupos = vector de vectores)
	}
}

void lectura(){
	freopen("TESTN2P3.TXT","r",stdin); //abro fichero
	cin>>N; //leo cantidad de palabars
	for (int x = 0;x < N;x++){ //por cada palabra
		string palabra; cin>>palabra;
		vector <char> pc; //creo un vector char para almacenar la palabra
		for (int y = 0;y < palabra.size();y++){ //por cada letra 
			pc.push_back( palabra[y] ); //la agrego al vector char
		}
		palabras.push_back(pc); //agrego el vector char = palabra al vector de palabras
		utilizadas.push_back( false ); //agrego un item de utilizadas, de esta forma voy a tener un valor True/False en utilizadas por cada palabra
	}
}

vector <vector <char> > generar_corridas( vector <char> palabra){  //genero a partir de una palabra, todas las posibles palabras que podrian estar en la ruleta
	vector <vector <char> > solucion;  //donde pongo la solucion de las palabras que pueden ser
	
	for (int x = 0;x < palabra.size();x++){ //por cada letra de la palabra
		solucion.push_back( palabra ); //agrego la palabra actual
		vector <char> inv = palabra; 
		reverse( inv.begin() , inv.end() ); //genero el inverso de la palabra
		solucion.push_back( inv );  //agrego el inverso de la palabra actual
		char pout = palabra[ palabra.size() - 1]; //tomo el ultimo caracter de la palabra
		for (int x = palabra.size() - 1;x > -1; x--){ //recorro la palabra de adelante hacia atras
			palabra[x] = palabra[x - 1];	 //hago que cada caracter sea igual a su anterior, a excepcion del caracter 0, que que queda como esta, ya que no hay caracter -1
		}
		palabra[0] = pout; //y hago que el caracter 0, sea igual al ultimo caracter que tenia la palabra, pout
		
		//ejecutando este for de 0 a la longitud de palabra, voy a terminar formando todo el corrimiento de la palabra
	}
	return solucion; //devuelvo las palabras que forme
}
bool comparar_vchar( vector <char> a,vector <char> b){ //comprao si son iguales dos vchar
  //tambien podria combertir los dos vector char = vchar a string, y compararlos, pero hice esto que por ahi es levemente mas veloz
	for (int x = 0;x < a.size();x++){ //por cada letra de a
		if (a[x] != b[x]){ //si no coincide la letra de a con la de b
			return false; //chau, no pueden ser iguales
		}
	} 
	return true; //si coiciden entonces todas
}
string vchar_to_st( vector <char> a){ //transformo un vchar a string
	string sol = "";  //aca almaceno los datos del string final
	for (int x = 0;x < a.size();x++){ //por cada dato del vchar
		sol += cts(a[x]); //hago que sol se le sume la version string del item del vchar a[x]
	}
	return sol; //devuelvo entonces el string
}
string cts(char c){ //char to string
	stringstream ss; 
	ss << c;
	return ss.str();
}
