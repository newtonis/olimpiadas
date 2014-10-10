#include <iostream>
#include <vector>
#include <cstdio>
#include <queue>
#include <algorithm>

int mov[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

using namespace std;

#define INFINITO -1

int best_level       = INFINITO;
int best_level_value = INFINITO;

struct zona{
    char letra;
    int peso[120];
    int x_anterior[120];
    int y_anterior[120];
    bool anterior_level_down[120];
    zona(char l,int p){
        letra   = l;
        for (int x = 0;x <= p;x++){
            peso[x]                = INFINITO;
            anterior_level_down[x] = false;
        }
    }
    zona(){}
};
struct pos{
    int x;
    int y;
    int peso;
    pos(int px,int py,int p){
        x    = px;
        y    = py;
        peso = p;
    };
    pos(){}
};
struct compare{
    bool operator()(pos A,pos B){
        return A.peso > B.peso;
    }
};
//GLOBALES
int M;
int N;
int F;
zona mapa[120][120];
pos referencia_final;

void read();
void show();
void solve();
void djikstra(int level, int start_x, int start_y);
void show_level(int level);

int main(){
    //cout<<getValue()<<"KB = "<<float(getValue())/1024.0<<"MB"<<endl;
    read();
    solve();

    //show_level(0);
    //show_level(1);
    //show_level(2);
}

void read(){
    freopen("tesoro.in","r",stdin);
    cin>>M;
    cin>>N;
    cin>>F;
    for (int f = 0;f < M;f++){
        string line; cin>>line;
        for (int c = 0;c < N;c++){
            mapa[f][c] = zona( line[c] , F);
        }
    }
}
void show(){
    for (int f = 0;f < M;f++){
        for (int c = 0;c < N;c++){
            cout<<mapa[f][c].letra<<" ";
        }
        cout<<endl;
    }

}
void show_level(int level){
    for (int f = 0;f < M;f++){
        for (int c = 0;c < N;c++){
            /*if (mapa[f][c].peso[level] == INFINITO){
                cout<<"II";
            }else if(mapa[f][c].peso[level] < 10){
                cout<<"0"<<mapa[f][c].anterior_level_down[level];
            }else{*/
                cout<<mapa[f][c].anterior_level_down[level];
            //}
        }
        cout<<endl;
    }
}
void solve(){
    mapa[0][0].peso[0] = 1;
    djikstra(0,0,0);
    /*show_level(0);
    cout<<endl;
    show_level(1);*/
    //cout<<endl;
    if (best_level == INFINITO){
        cout<<"imposible"<<endl;
    }else{
        cout<<best_level_value<<endl;

        pos actual = referencia_final;
        vector <pos> solucion;
        while (1){
            solucion.push_back(pos (actual.x , actual.y , 0 ) );
            int x_anterior = mapa[actual.y][actual.x].x_anterior[best_level];
            int y_anterior = mapa[actual.y][actual.x].y_anterior[best_level];
            if (mapa[actual.y][actual.x].anterior_level_down[best_level]){
                best_level --;
            }
            if (actual.x == 0 and actual.y == 0){
                break;
            }
            actual = pos(x_anterior,y_anterior,0);
        }
        reverse(solucion.begin(),solucion.end());
        for (int x = 0;x < solucion.size();x++){
            cout<<"("<<solucion[x].y<<","<<solucion[x].x<<")"<<endl;
        }
    }
}
void djikstra(int level, int start_x, int start_y){
    //cout<<"djikstra "<<level<<" "<<start_x<<" "<<start_y<<endl;
    priority_queue < pos , vector <pos> , compare> cola;

    cola.push( pos(start_x,start_y,mapa[start_y][start_x].peso[level]) );

    while (not cola.empty()){
        pos actual = cola.top(); cola.pop();
        if (mapa[actual.y][actual.x].letra == 'T'){
            referencia_final = pos(actual.x,actual.y,0);
            int value = mapa[actual.y][actual.x].peso[level];
            if (value < best_level_value or best_level_value == INFINITO){
                best_level_value = value;
                best_level = level;
            }
            break;
        }
        for (int x = 0;x < 4;x++){
            int nx = actual.x + mov[x][0];
            int ny = actual.y + mov[x][1];
            if (nx < 0 or ny < 0 or nx >= N or ny >= M){
                continue;
            }
            if (mapa[ny][nx].letra == 'P'){
                continue;
            }else if(mapa[ny][nx].letra == 'W'){
                if (level >= F){ //SI ESTOY EN EL NIVEL MAXIMO (es decir me quede sin flechas)
                    continue;
                } ///SALTO AL NIVEL SUPERIOR
                if (mapa[ny][nx].peso[level+1] > mapa[actual.y][actual.x].peso[level] + 1 or mapa[ny][nx].peso[level+1] == INFINITO ){
                    mapa[ny][nx].peso[level+1] = mapa[actual.y][actual.x].peso[level] + 1;
                    mapa[ny][nx].x_anterior[level+1] = actual.x;
                    mapa[ny][nx].y_anterior[level+1] = actual.y;
                    mapa[ny][nx].anterior_level_down[level+1] = true;
                    djikstra( level + 1 , nx , ny );
                }
            }else{ //CONTINUO EL DJIKSTRA EN EL NIVEL ACTUAL
                if (mapa[ny][nx].peso[level] > mapa[actual.y][actual.x].peso[level] + 1 or mapa[ny][nx].peso[level] == INFINITO){
                    mapa[ny][nx].peso[level] = mapa[actual.y][actual.x].peso[level] + 1;
                    mapa[ny][nx].x_anterior[level] = actual.x;
                    mapa[ny][nx].y_anterior[level] = actual.y;
                    cola.push( pos(nx,ny,mapa[ny][nx].peso[level]));
                }
            }
        }
    }
}
