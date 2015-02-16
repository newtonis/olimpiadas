#include <iostream>
#include <vector>
#include <string>
#include <cstdio>
#include <sstream>
#include <algorithm>
using namespace std;

///////////////////////////////////////////
/// ARIEL NOWIK, CONTRASENIAS CIIC 2014 ///
/// SOLUCION NO OFICIAL                 ///
/// ariel.nowik@gmail.com               ///
///////////////////////////////////////////

struct nodo;

int L; //longitud
int N; //subcadenas
nodo* root; //nodo raiz

string cts(char c){ //cgar to string
    stringstream ss;
    ss << c;
    return ss.str();
}
struct nodo{
    char letra; //mi letra, \0 en caso de ser el nodo root que no tiene letra
    bool endletter; //si soy el final del trie, es decir una palabra prohibida
    nodo* padre; //de donde vengo
    nodo* hijos[26]; //uno por cada letra, todos los nodos tienen un hijo de cada letra de la a a la z, que nunca es NULL al terminar de formar el grafo
    int values[100]; //para la programacion dinamica, aqui guardo para cada cantidad de pasos restantes arrancando desde este nodo cuantas posibilidades de palabras hay
    nodo* sml; //sufijo mas largo de la cadena del nodo en el grafo , sirve para enlazar el nodo para los casos donde una letra no tiene hijo directo. en el root es el mismo nodo y tambien en los nodos que tienen distancia 1 del root tienen root como sufijo mas largo
    //de esta forma, si pongo una letra en esos nodos vuelvo al nodo de inicio al resolver el problema
    nodo(char l,bool el,nodo* p){
        letra = l;
        endletter = el;
        padre = p;
        for (int h = 0;h < 26;h++){ //inizializo en null aunque luego cambiara
            hijos[h] = NULL;
        }
        for (int v = 0;v < 100;v++){ //-1 significa que no hay datos, de esta forma la funcion sabe que debe calcularlo y almacenarlo aqui mas adelante
            values[v] = -1;
        }
    }
    string getLetra(){ //fue utilizado para el debug, su objetivo es mostrar un nodo pero con todos sus nodos padres (y asi mostrar la cadena neta que representa)
        string total = "";
        total += cts(letra);
        nodo* a = padre;
        while (a != NULL){
            total += a->letra;
            a = a->padre;
        }
        reverse(total.begin(),total.end());
        return total;
    }
    void show(){ //tambien para debug, muestra la letra y sus hijos entre {}
        cout<<"Mi letra es "<<getLetra()<<endl;
        cout<<"Mis hijos son {";
        for (int x = 0;x < 26;x++){ //26 letras
            if (hijos[x] != NULL){
                cout<<hijos[x]->getLetra()<<",";
            }
        }
        cout<<"}"<<endl;
    }
    string gCode(){ //mas debug
        if (letra == '\0'){
            return "ROOT";
        }else{
            return "letra " + getLetra();
        }
    }
};
void init(); //inicio el root
void read(); //tomo datos y armo el trie basico
void insertWord(string word); //inserto palabra en el trie
void solve(); //termino de formar el arbol (es decir modifico el trie para armar el arbol con todos los hijos de todos los nodos utilizados)
int getValue(nodo* n,int pasos); //para obtener cuantas posibilidades hay desde un nodo, con tantos pasos
void calcularSufijoMasLargo(nodo* n); //para calcular el sufijo mas largo de un nodo en todo el arbol

int main(){
    init();
    read();
    solve();
}
void init(){
    root = new nodo('\0',false,NULL);
}
void read(){
    freopen("input.in","r",stdin);
    cin>>L;
    cin>>N;
    for (int x = 0;x < N;x++){
        string word; cin>>word;
        insertWord(word); //agrego al trie
    }
}
void calcularSufijoMasLargo(nodo* n){
    if (n->letra == '\0'){ //si soy root
        n->sml = n; //mi sufijo mas largo es yo mismo
    }else{
        nodo* current = n->padre; //guardo mi padre porque empiezo analizando si su sml con mi letra existe (y ese seria mi sml)
        while (1){
            if (current == root){ //si llege a la raiz y no encontre sml
                n->sml = current; //el sufijo mas largo es root ya que no encontre ninguno
                break;
            }else if (current->sml->hijos[n->letra-97] != NULL){ //el sufijo de mi padre mas mi letra existe
                n->sml = current->sml->hijos[n->letra-97]; //entonces mi sml es el hijo con mi letra del sml de mi padre (en 1 iteracion), o del sml del sml de mi padre (en 2), o del sml del sml del sml de mi padre (en 3)
                break;
            }else{
                current = current->sml; //el nodo actual es el sml del nodo en cuestion
            }
        }
    }
    for (int x = 0;x < 26;x++){ //por cada hijo calculo sus sml
        if (n->hijos[x] != NULL){
            calcularSufijoMasLargo(n->hijos[x]);
        }
    }
}
void insertWord(string word){ //agrego una palabra al trie inicial, algoritmo clasico para formar tries
    nodo* actual = root;
    for (int x = 0;x < word.size();x++){
        char c = word[x];
        nodo* sub = actual->hijos[c-97]; //como a es 97 y quiero que la a se guarde en la posicion 0, resto 97 al codigo asci
        if (sub != NULL){
            actual = sub;
        }else{
            actual->hijos[c-97] = new nodo(c,(x == word.size()-1),actual);
            actual = actual->hijos[c-97];
        }
    }

}
int getValue(nodo* n,int pasos){
    if (n->endletter){ return 0; } //si el nodo en cuestion es el final del trie (y entonces una palabra prohibida), no hay ninguna palabra permitida
    if (pasos == 0){ return 1;} //si no quedan pasos, hay en total 1 sola posibilidad
    if (n->values[pasos-1] != -1){ return n->values[pasos-1]; } //si ya se calculo anteriormente para el nodo n con tantos pasos devuelvo el valor que se calculo en aquella ocasion (para que hacer el calculo denuevo?)


    int sum = 0;
    for (int x = 0;x < 26;x++){ //sumo el valor de cada una de las posibilidades de letras (mis 26 hijos)
        sum += getValue(n->hijos[x],pasos-1);
        sum %= 1000000000 + 7; //como exige el problema
    }
    n->values[pasos-1] = sum; //guardo el valor para poder ser utilizado en futuras ocasiones donde la funcion sea llamada con mismos parametros

    return sum;
}
void solve(){
    calcularSufijoMasLargo(root); //genero todos los sml

    //aqui voy a transformar el trie basico en un arbol donde todos los nodos que no representen una cadena prohibida (endletter == True),
    //tengan sus 26 hijos ocupados con la posicion donde deberia seguir el recorrido en caso de probar una letra que no sea parte de la cadena
    //y asi en ese caso retomar al nodo alternativo correspondiente del grafo

    vector <nodo*> cola; cola.push_back(root); //para realizar un BFS del trie
    while (not cola.empty()){
        nodo* actual = cola[0]; cola.erase(cola.begin()); //tomo el primero y lo saco
        if (actual->endletter){ continue; } //si la letra representa una cadena prohibida no la tomo

        for (int l = 0;l < 26;l++){
            if (actual->hijos[l] != NULL){ //si el trie tiene ese hijo
                cola.push_back(actual->hijos[l]); //lo agrego para despues seguir el BFS
            }else{ //si devemos calcularlo
                if (actual->padre != NULL){ //si no es root y tiene padre
                    nodo* dec = actual->padre->sml; //ahora voy a recorrer el sml de mi padre, luego el sml del sml de mi padre, hasta encontrar uno que tenga un hijo con la letra y asi poder asignar el nodo alternativo

                    bool cont = true;
                    while (cont){
                        if (dec->hijos[l] != NULL){ //si existe
                            actual->hijos[l] = dec->hijos[l]; //asigno y termino
                            cont = false;
                        }else if (dec == root){ //Si llegue al root y no me tiene de hijo
                            actual->hijos[l] = dec; //entonces el nodo correspondiente sera el root
                            cont = false;
                        }else{ //si debemos continuar con el proceso
                            dec = dec->sml;
                        }
                    }
                }else{ //si es root el nodo como no tiene la letra el hijo con esa letra es el mismo root (ya que no cambia el estado del recorrido si con esa letra ninguna palabra prohibida puede formarse)
                    actual->hijos[l] = actual;
                }
            }
        }
    }
    int solucion = getValue(root,L); //caclulo la solucion arrancando de root con L pasos (ya que las palabras tienen L letras
    cout<<solucion<<endl; //muestro
}
