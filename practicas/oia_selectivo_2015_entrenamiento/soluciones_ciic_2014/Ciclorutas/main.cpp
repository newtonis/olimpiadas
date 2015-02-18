#include <iostream>
#include <cstdio>
#define INF -1
using namespace std;

///////////////////////////////////////////
/// ARIEL NOWIK, Ciclorutas CIIC 2014   ///
/// SOLUCION NO OFICIAL                 ///
/// ariel.nowik@gmail.com               ///
///////////////////////////////////////////

unsigned int N; //numero de ciudades / nodos
unsigned int M; //numero de carreteras / intersecciones

long int distancias[400][400]; //almaceno las distancias de ciudad y ciudad. 400x400 es el maximo tamanio que puede haber en el caso de tener
//400 ciudades y una distancia de cada ciudad hacia cada otra ciudad

void read();
void solve();

int main(){
    read();
    solve();
}

void read(){
    freopen("input.in","r",stdin);
    cin>>N;
    cin>>M;
    //por defecto la distancia entre ciudad y ciudad es infinito, es decir no hay camino de la ciudad y a la ciudad x
    for (int y = 0;y < N;y++){
        for (int x = 0;x < N;x++){
            distancias[y][x] = INF;
        }
    }
    for (int a = 0;a < M;a++){ //por cada camino M
        unsigned int Y; cin>>Y; Y--; //resto uno ya que la entrada del problema se da arrancando desde 1
        unsigned int X; cin>>X; X--;
        unsigned long int D; cin>>D;
        distancias[Y][X] = D; //almaceno la distancia correspondiente desde la ciudad X a la ciudad Y, remplazando el defecto de INFINITO
    }
}
void solve(){
    int solution = 0;
    //procederemos a realizar un floyd warshall - http://es.wikipedia.org/wiki/Algoritmo_de_Floyd-Warshall
    for (int k = 0;k < N;k++){ //por cada interacion K del algoritmo
        for (int y = 0;y < N;y++){ //por cada fila Y en la tabla K
            for (int x = 0;x < N;x++){ //por cada columna X en la fila Y
                long int DAC = distancias[y][x]; //DISTANCIA ACTUAL
                long int DAL; //DISTANCIA ALTERNATIVA
                if (distancias[y][k] == INF or distancias[k][x] == INF){
                //si el camino y-k o el camino k-x es infinito entonces el camino alternativo que queremos proponer es infinito
                    DAL = INF;
                }else{ //de lo contrario ese camino alternativo es la sumatoria de los dos caminos que remplazarian al camino central
                    DAL = distancias[y][k] + distancias[k][x];
                }
                //si el camino alternativo es de menor o igual disntancia que el camino original podemos convertir el camino original en cicloruta
                if (( (DAC != INF and DAL != INF and DAC >= DAL)) and y != k and k != x){
                    //si hay una ruta de x a y menor pasando por k, entonces la ruta de x a y puede ser anulada
                    distancias[y][x] = DAL; //guardamos la nueva distancia
                    solution++; //agregamos una cicloruta
                }
            }
        }
    }
    //mostramos la solucion
    cout<<solution<<endl;
}
