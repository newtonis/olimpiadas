#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

### PUNTAJE 100 / 100 ###
struct conexion{
    int a;
    int b;
    conexion(int pa,int pb){
        a = pa;
        b = pb;
    }
};
struct letra{
    char l;
    int pos;
    letra(char let,int p){
        l   = let;
        pos = p;
    }
};

int P;
vector <letra> letras;
vector <conexion> conexiones;

void read();
void solve();

int main(){
    read();
    solve();
}

void read(){
    freopen("leds.in","r",stdin);
    freopen("leds.out","w",stdout);
    cin>>P;
    string line; cin>>line;
    for (int x = 0;x < P;x++){
        letras.push_back(letra(line[x],x+1));

    }
}

void solve(){
    bool continuar = true;
    int correccion = 0;
    while (continuar){
        bool hice_algo = false;
        for (int x = 0;x < letras.size();x++){
            int actual = x;
            int proximo;
            if (x == letras.size()-1){
                proximo = 0;
            }else{
                proximo = x + 1;
            }
            if (letras[actual].l == 'C' and letras[proximo].l == 'L'){
                conexiones.push_back( conexion(letras[actual].pos,letras[proximo].pos) );
                if (proximo != 0){
                    letras.erase(letras.begin() + proximo);
                }
                letras.erase(letras.begin() + actual);
                if (proximo == 0){
                    letras.erase(letras.begin()+proximo);
                }
                hice_algo = true;
                break;
            }
        }
        if (not hice_algo){
            continuar = false;
        }
    }

    cout<<conexiones.size()<<endl;
    for (int x = 0;x < conexiones.size();x++){
        cout<<conexiones[x].a<<" "<<conexiones[x].b<<endl;
    }
}
