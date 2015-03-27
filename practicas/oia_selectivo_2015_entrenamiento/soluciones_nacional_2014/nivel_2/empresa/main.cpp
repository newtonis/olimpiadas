#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

/// PUNTAJE 45 / 100 ///

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
    vector <string> conexiones;
    bool visitado;
    persona(string n){
        nombre = n;
        visitado = false;
    }
    persona(){}
};

int P;
int max_grado;
vector <string> titulares;

vector <conexion> conexiones;
vector <persona> personas;
map <string , persona> pers;

vector <bool> analizados;

typedef map <string,persona>::iterator ite;

bool compare(string a,string b){
    return a < b;
}

void read();
void solve();
int search(string nombre);
void reset();

int main(){
    clock_t tStart = clock();
    read();
    solve();
    printf("Time taken: %.4fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
}

void read(){
    freopen("input.in","r",stdin);
    //freopen("empresa.out","w",stdout);

    cin>>P;
    for (int x = 0;x < P;x++){
        string nombreA; cin>>nombreA;
        string nombreB; cin>>nombreB;
        //cout<<nombreA<<" "<<nombreB<<endl;
        ite numeroA = pers.find(nombreA);
        ite numeroB = pers.find(nombreB);

        if (numeroA == pers.end()){
            pers[nombreA] = persona(nombreA);
        }
        if (numeroB == pers.end()){
            pers[nombreB] = persona(nombreB);
        }
        pers[nombreA].conexiones.push_back(nombreB);
        pers[nombreB].conexiones.push_back(nombreA);
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
    for (int x = 0;x < personas.size();x++){
        cout<<personas[x].nombre<<endl;
    }

    for (ite x = pers.begin();x != pers.end();++x){

        reset();
        pers[x->first].visitado = true;
        int profundidad = 0;

        vector <string> cola; cola.push_back(x->first);
        vector <string> proxima_cola;

        string start = x->first;

        while (1){
            if (cola.empty()){
                if (proxima_cola.empty()){
                    break;
                }
                cola   = proxima_cola;
                proxima_cola.clear();
                profundidad++;
            }

            string actual = cola[0]; cola.erase(cola.begin());

            pers[actual].visitado = true;
            for (int a = 0;a < pers[actual].conexiones.size();a++){
                if (pers[pers[actual].conexiones[a]].visitado){ continue; }
                proxima_cola.push_back( pers[actual].conexiones[a] );
                pers[pers[actual].conexiones[a]].visitado = true;
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
        cout<<pers[titulares[x]].nombre<<endl;
    }
    /*sort(solution.begin(),solution.end(),compare);
    cout<<max_grado<<endl;
    for (int x = 0;x < solution.size();x++){
        cout<<personas[solution[x]].nombre<<endl;
    }*/
}
void reset(){
    for (ite x = pers.begin();x != pers.end();++x){
        pers[x->first].visitado = false;
    }
}