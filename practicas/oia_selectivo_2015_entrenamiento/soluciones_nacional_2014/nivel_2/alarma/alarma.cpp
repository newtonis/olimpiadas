#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>

#define AHIJOB 0
#define BHIJOA 1
#define DISTINTAS 2

using namespace std;

string palabras[300000];
int C;

int bloqueos[300000];
bool done[300000];

void read();
void solve();
void show();

int comparar( string palabraA, string palabraB );

struct nodo;

bool compare(nodo* a, nodo*b);

struct nodo{
    int x;
    nodo* padre;
    vector <nodo*> hijos;
    nodo(int v){
        x = v;
    }
    void add_hijo( int y ){
        if (hijos.size() == 0){
            nodo* nuevo = new nodo(y);
            nuevo->padre = this;
            hijos.push_back( nuevo );
        }else{
            bool encontro = false;
            for (int a = 0;a < hijos.size();a++){
                char comparacion = comparar(palabras[y], palabras[hijos[a]->x]);
                if (comparacion == AHIJOB){
                    hijos[a]->add_hijo(y);
                    encontro = true;
                    break;
                }else if(comparacion == BHIJOA){
                    nodo* nuevo = new nodo(y);
                    nuevo->padre = this;
                    hijos.push_back( nuevo ); //agrego un nuevo hijo

                    int v = hijos[a]->x; //tomo el actual parcial
                    delete hijos[a]; //elimino no existe mas
                    hijos.erase( hijos.begin() + a ); //lo elimino porque no es mas hijo directo


                    hijos[ hijos.size() - 1 ]->add_hijo( v ); //lo agrego como hijo del nuevo
                    encontro = true;
                    break;
                }
            }
            if (not encontro){
                hijos.push_back(new nodo(y));
            }
        }
    }
    void show(int deep=0){
        cout<<deep<<" "<<palabras[x]<<endl;
        sort(hijos.begin(),hijos.end() , compare);
        for (int x = 0;x < hijos.size();x++){
            hijos[x]->show(deep+1);
        }
    }
};
vector <nodo*> raices;

bool compare(nodo* a, nodo*b){
    return palabras[a->x] < palabras[b->x];
}

int main(){
    read();
    solve();
    cout<<"SOLUCION"<<endl;
    show();
}


void read(){
    freopen("alarma.in","r",stdin);
    cin>>C;
    for (int x = 0;x < C;x++){
        string cc; cin>>cc;
        palabras[x] = cc;
    }
}

void solve(){

    for (int x = 0;x < C;x++){
        bool encontro = false;
        for (int y = 0;y < raices.size();y++){
            cout<<palabras[x]<<" "<<palabras[raices[y]->x]<<endl;
            int resultado_comparacion = comparar ( palabras[x] , palabras[raices[y]->x]);
            cout<<resultado_comparacion<<endl;
            if (resultado_comparacion == AHIJOB){ //si palabras[x] es hijo de palabras[raices]
                raices[y]->add_hijo(x);
                encontro = true;
                break;
            }else if(resultado_comparacion == BHIJOA){
                nodo* nuevo = new nodo(x);
                nuevo->hijos.push_back( raices[y] );
                raices.push_back( nuevo );
                raices.erase(raices.begin() + y);
                encontro = true;
                break;
            }
        }
        if (encontro == false){
            raices.push_back(new nodo(x));
        }
    }
}
void show(){
    sort(raices.begin(),raices.end(),compare);
    for (int a = 0;a < raices.size();a++){
        raices[a]->show();
    }
}
int comparar( string palabraA, string palabraB ){

    for (int x = 0;x < min( palabraA.size() , palabraB.size() );x++){
        if (palabraA[x] != palabraB[x]){
            return DISTINTAS;
        }
    }

    //si se llega hasta aca empiezan igual

    if (palabraA.size() > palabraB.size()){
        return AHIJOB;
    }else{
        return BHIJOA;
    }
}
