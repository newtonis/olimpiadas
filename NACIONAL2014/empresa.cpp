#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
using namespace std;

### PUNTAJE 45 / 100 ###
struct conexion{
    string A;
    string B;
    conexion(string a,string b){
        A = a;
        B = b;
    }
};

struct persona{
    string nombre;
    vector <int> conexiones;
    persona(string n){
        nombre = n;
    }
};

int P;
int max_grado;
vector <int> titulares;

vector <conexion> conexiones;
vector <persona> personas;
vector <bool> analizados;

bool compare(int a,int b){
    return personas[a].nombre < personas[b].nombre;
}

void read();
void solve();
int search(string nombre);
void reset();

int main(){
    read();
    solve();
}

void read(){
    freopen("empresa.in","r",stdin);
    freopen("empresa.out","w",stdout);

    cin>>P;
    for (int x = 0;x < P;x++){
        string nombreA; cin>>nombreA;
        string nombreB; cin>>nombreB;
        //cout<<nombreA<<" "<<nombreB<<endl;
        int numeroA = search(nombreA);
        int numeroB = search(nombreB);

        if (numeroA == -1){
            personas.push_back(persona(nombreA));
            numeroA = personas.size()-1;
            analizados.push_back(false);
        }
        if (numeroB == -1){
            personas.push_back(persona(nombreB));
            numeroB = personas.size()-1;
            analizados.push_back(false);
        }
        personas[numeroA].conexiones.push_back(numeroB);
        personas[numeroB].conexiones.push_back(numeroA);
    }
}
int search(string nombre){
    for (int x = 0;x < personas.size();x++){
        if (personas[x].nombre == nombre){
            return x;
        }
    }
    return -1;
}
void solve(){
    max_grado = -1;
    /*for (int x = 0;x < personas.size();x++){
        cout<<personas[x].nombre<<endl;
    }*/

    for (int x = 0;x < personas.size();x++){

        reset();
        analizados[x] = true;
        int profundidad = 0;

        vector <int> cola; cola.push_back(x);
        vector <int> proxima_cola;

        int start = x;

        while (1){
            if (cola.empty()){
                if (proxima_cola.empty()){
                    break;
                }
                cola   = proxima_cola;
                proxima_cola.clear();
                profundidad++;
            }

            int actual = cola[0]; cola.erase(cola.begin());

            analizados[actual] = true;
            for (int a = 0;a < personas[actual].conexiones.size();a++){
                if (analizados[personas[actual].conexiones[a]]){ continue; }
                proxima_cola.push_back( personas[actual].conexiones[a] );
                analizados[personas[actual].conexiones[a]] = true;
            }
            //cout<<proxima_cola.size()<<endl;

        }
        if (profundidad > max_grado or max_grado == -1){
            max_grado = profundidad;
            titulares.clear();
            titulares.push_back ( start );
        }else if(profundidad == max_grado){
            //cout<<profundidad<<endl;
            titulares.push_back ( start );
        }
    }
    sort(titulares.begin(),titulares.end(),compare);
    cout<<max_grado<<endl;
    for (int x = 0;x < titulares.size();x++){
        cout<<personas[titulares[x]].nombre<<endl;
    }/*
    sort(solution.begin(),solution.end(),compare);
    cout<<max_grado<<endl;
    for (int x = 0;x < solution.size();x++){
        cout<<personas[solution[x]].nombre<<endl;
    }*/
}
void reset(){
    for (int x = 0;x < personas.size();x++){
        analizados[x] = false;
    }
}
