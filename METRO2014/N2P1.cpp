#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
using namespace std;

/****** 

Por Ariel Nowik, 5EA, ariel.nowik@gmail.com

OIA Certamen Metropolitano, Ejercicio 1, Nivel 2

Puntaje 100/100

*******/
 

//Almaceno las letras segun la tabla del problema
char letras[5][6] = 
{ 
{'a','b','c','d','e',' '},
{'f','g','h','i','j',' '},
{'k','l','m','n','o',' '},
{'p','q','r','s','t',' '},
{'u','v','w','x','y','z'}
};

//Declaro la estructura para guardar cada mensaje y los datos del mismo que tengo en mi poder
struct Mensaje{
	vector <char> letras_finales; //las letras que tengo aseguradas del mensaje (EJ si tengo {A,B,C} guardado aca, mi mensaje termina en ABC si o si)
	vector <char> letra_incial_posibilidades; //las posibles letras que puedo tener como letra anterior a las ultimas que si tengo aseguradas (letra insegura)
	// EJ si tengo como arriba que termina en ABC, y en este vector las letras {G,K,L} , entonces los posibles mensajes que puedo llegar a tener son
	// ****GABC
	// ****KABC
	// ****LABC 
	//Donde **** son letras que no conosco que pueden estar en cualquier cantidad.
};

//VARIABLES GLOBALES

int T; //cantidad de guardias
int N; //cantidad de palabras en diccionario

vector <string> diccionario; //aca almaceno las palabras que me dan al principi
vector < Mensaje > mensajes; //posibles mensajes

void lectura(); //para leer datos
void solucion(); //para resolver el problema
bool compare(string A,string B){ //esta funcion sirve para la funcion sort de c++ y es la condicion tenida en cuenta para ordenar el vector de string
	return A < B; //si fuera A > B por ejemplo, se ordenaria en el sentido contrario
}
bool termina_en(string palabra,Mensaje m); //revisa si X palabra podria ser una de las posibilidades del mensaje

vector <char> posiblidades( int fila_inicial , int columna); 
//diciendo la fila minima donde se encuentra una letra (es decir si se sabe
//que el menor numero de fila es tal valor, mas la columna donde esta, se calcula las diferentes
//letras que pueden llegar a ser.

vector <char> posibilidades2( int columna_incial );
//diciendo el menor valor que puede tener la columna (es el unico dato que se tiene) de una letra
//se calcula todas las posibles letras que pueden llegar a ser

char fletra( int fila , int columna);
//obtenemos una letra por su fila y columna (aca sieimpre hay una sola posibilidad, la fila y 
//columna estan determinadas.

int main(){
	lectura(); //lee ficheroN
	solucion(); //soluciona y muestra en pantalla
}
void solucion(){
	for (int x = 0;x < T;x++){ // por cada guardia (es decir por cada mensaje que un guardia tiene)
		vector <string> palabras_buenas; //aca almaceno las palabaras que estan en el diccionario y podrian 
//ser parte del mensaje
		for (int t = 0;t < N;t++){ //por cada palabra del diccionario
			vector <char> pos = mensajes[x].letra_incial_posibilidades;// linea innescesaria
			if (termina_en(diccionario[t], mensajes[x] )){ // si la palabra T del diccionario podria terminar en el posible mensaje X
				palabras_buenas.push_back(diccionario[t] );//agrego a las posibilidades
			}
		}
		sort( palabras_buenas.begin() , palabras_buenas.end() , compare ); //ordeno tomando en cuenta la funcion compare para decidir el criterio
		cout<<palabras_buenas.size(); //muestro cuantas palabras tengo
		for (int x = 0;x < palabras_buenas.size();x++){
			cout<<" "<<palabras_buenas[x]; //muestro cada palabra
		}
		cout<<endl;
	}
}

void lectura(){
	freopen("TESTN2P1.TXT","r",stdin); //ABRO
	cin>>T; //Leo cantidad de guardias
	cin>>N; //Leo cantidad de palabra de diccionario
	
	for (int x = 0;x < T;x++){
		string mensaje; cin>>mensaje; //leo el mensaje
		
		vector <int> conjuntos; //aca voy a almacenar  la longitud de los conjuntos de puntos
//no vale la pena guardar la longitud de los ___ porque no influye su cantidad

		int m = 0;
		while (mensaje[m] == '*' or mensaje[m] == '_'){ //mientras haya algo
			int valor_conjunto = 0;
			while (mensaje[m] == '*'){
				valor_conjunto ++; //otro * mas
				m ++; //sumo al indice general
			}
			conjuntos.push_back( valor_conjunto ); //agrego valor
			while (mensaje[m] == '_'){
				m ++; //sumo al indice general
			}
		}
		Mensaje nuevo;
		if (conjuntos.size() % 2 == 0){ //si es par la cantidad de conjuntos
//es decir, tengo determinado ademas de letras finales la columa de la letra mas atras, 
//mas la fila minima de tal letra, (minima porque no se como empezo el mensaje)
			int letrainicial_posibles_filas = conjuntos[0];
			int letrainicial_columna        = conjuntos[1];

			nuevo.letra_incial_posibilidades = posiblidades( letrainicial_posibles_filas , letrainicial_columna); //calcula las posiblidades para la letra de mas atas de la que tengo datos
			for (int x = 2;x < conjuntos.size();x+= 2){
				nuevo.letras_finales.push_back (  fletra ( conjuntos[x] , conjuntos[x+1] ) );
//ahora agrego todas las letras que se exactamente cuales son
			}
			
		}else{//si es impar la cntidad de conjuntos, es decir, tengo determinado ademas de letras finales, la columna minima de la letra mas atras (y no tengo ningun dato acerca de su fila) (minima porque no se como empezo el mensaje)
			int letraincial_posibles_columnas = conjuntos[0];
			nuevo.letra_incial_posibilidades = posibilidades2( letraincial_posibles_columnas ); //calculo las posiblidades de letras para la letra de mas atras que tengo datos
			for (int x = 1;x < conjuntos.size();x+= 2){
				nuevo.letras_finales.push_back (  fletra ( conjuntos[x] , conjuntos[x+1] ) );
//ahora almaceno las letras que se exactamente cuales son
			}
			
		}
		mensajes.push_back( nuevo ); //agrego los datos del mensaje
	}
	
	for (int x = 0;x < N;x++){ //ahora almaceno las palabras del diccionario, por cada palabra
		string palabra; cin>>palabra; 
		diccionario.push_back( palabra ); //leo y almaceno
	}
	
}
vector <char> posibilidades2( int columna_incial ){
	columna_incial --; //resto 1, ya que contamos iniciando en 1,2,3 y un array cuenta iniciando de 0,1,2
	vector <char> posible; //aca almacenaremos las posibles letas
	for (int x = 0;x < 5;x++){ //por cada fila (son 5 filas en el mapa de letras)
		int mayor; //este valor lo uso para almacenar la cantidad de columnas de la fila
		if (x != 4){ //si no estoy en la fila 4, (la ultima)
			mayor = 5; //tengo 5 columnas
		}else{
			mayor = 6; //tengo 6 columnas
		}
		for (int y = columna_incial;y < mayor;y++){ //por cada columna, iniciando desde la columna inicial minima que se donde esta la letr
			posible.push_back( letras[x][y] ); //agrego la posible letra
		}
	}
	return posible; //devuelvo las posibilidades
}
vector <char> posiblidades( int fila_inicial , int columna){
	fila_inicial --; //resto uno, ya que contamos de 1,2,3 y un array cuenta iniciando de 0,1,2
	columna --;  //resto uno, ya que contamos de 1,2,3 y un array cuenta iniciando de 0,1,2
	vector <char> resultado; //aca almaceno las posibles letras
	for (int x = fila_inicial;x < 5;x++){ //por cada fila, iniciando desde la fila inicial donde se que esta la letra
		resultado.push_back( letras[x][columna] ); //agregola letra de la fila x, y columna que sabemos exactamente cual es
	}
	return resultado; //devuelvo la solucion
}
char fletra( int fila , int columna){
	fila --; //resto uno ya que contamos de 1,2,3 y array cuenta 0,1,2
	columna --; //lo mismo
	return letras[fila][columna]; //devuelvo la letra de fila fila y columna columna
}
bool termina_en(string palabra,Mensaje m){ //si la palabra tal puede ser una posibilidad de los datos de mensaje m que tengo
	vector <char> final = m.letras_finales; //almaceno las letas finales que se de la palabra
	vector <char> posible_letra = m.letra_incial_posibilidades; //almaceno los datos de las cosas que conosco de la letra mas atras que tengo

	if (final.size() > palabra.size()){ // si sucede que tengo mas posibles letras finales que letras de la palabra, ya se que no es una posibilidad la palabra
		return false;
	}
	
	int j = 0; //quiero recorrer de tal forma que f vaya desde la longitud de final hacia ser 0, y que j vaya de 0 hasta la longitud de final
	for y(int f = final.size() - 1; f > -1; f--){
		if (palabra[palabra.size() - j - 1] != final[f]){ //si no conicide alguna de las letras finales en orden
			return false; //ya entonces el posible mensaje no puede ser parte de la palabra
		}
		j++;
	}
	//ahora reviso si la alguna de las posibilidades de letra anterior a las letras seguras del mensaje (la letra insegura) es la letra correspondiente
	//de la palabra
	for (int x = 0;x < posible_letra.size();x++){ 
		if (posible_letra[x] == palabra[palabra.size() - j - 1]){ //si alguna letra esta justo en la posicion de la palabra anterior a las 
		  //letras que tienen que estar si o si
			return true; //devuelvo que la palabra podria ser una posibilidad de los datos de mensaje
		}
	}
	return false; //no hay ninguna posibildad, la palabra no tiene la letra insegura del mensaje.
	
}
