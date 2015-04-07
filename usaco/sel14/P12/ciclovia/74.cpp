#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#define forn(a,b) for((a)=0; (a)<(b); ++(a))
#define forr(a,c,b) for((a)=(c); (a)<=(b); ++(a))
using namespace std;
const int maxn = 1005;
const int maxl = 4;
const int INF = (1<<26);

ifstream fin("ciclovia.in");
ofstream fout("ciclovia.out");

struct calle{
    int sentido;
    int riesgo;
};

struct esquina{
    esquina(){}
    esquina(int a, int b, int c) :
        x(a), y(b), d(c) {}
    int x, y, d;
};


int H, W, N;
int D[maxn][maxn];
int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};

calle CH[maxn], CV[maxn];
vector<esquina> Hp;

bool placeable(int x, int y){
    if( 1 <= x && x<= W )
        if( 1 <= y && y <= H )
            return true;
    return false;
}

bool comp(esquina a, esquina b){
    return a.d < b.d;
}

void poner(esquina p){
    Hp.push_back(p);
    push_heap(Hp.begin(),Hp.end(),comp);
}

esquina sacar(){
    esquina f;
    pop_heap(Hp.begin(),Hp.end(),comp);
    f = Hp.back();
    Hp.pop_back();
    return f;
}

int calculo(int x, int y, int d){
    int costo = 0;
    switch( d ){
        case 0:
            costo = CV[x].riesgo + ( CV[x].sentido == 0 ? 0 : 4 );
        break;

        case 1:
            costo = CH[y].riesgo + ( CH[y].sentido == 0 ? 0 : 4 );
        break;

        case 2:
            costo = CV[x].riesgo + ( CV[x].sentido == 0 ? 4 : 0 );
        break;

        case 3:
            costo = CH[y].riesgo + ( CH[y].sentido == 0 ? 4 : 0 );
        break;
    }
    return costo;
}

void solve(int x, int y){
    int d, costo;
    esquina e;

    D[x][y] = 0;
    poner(esquina(x,y,0));

    while( Hp.size() ){
        e = sacar();
        forn(d,4){
            x = e.x + dx[d];
            y = e.y + dy[d];
            if( placeable(x,y) ){
                costo = calculo(x,y,d);
                if( D[x][y] > e.d + costo ){
                    D[x][y] = e.d + costo;
                    poner(esquina(x,y,D[x][y]));
                }
            }
        }
    }
}

int main(){
    int i, e, a, b, c, d;

    fin>>W>>H;

    forr(i,1,W)
        fin>>CV[i].sentido>>CV[i].riesgo;

    forr(i,1,H)
        fin>>CH[i].sentido>>CH[i].riesgo;

    fin>>a>>b;

    forr(i,1,H)
        forr(e,1,W)
            D[e][i] = INF;

    solve(a,b);

    fin>>a>>b;

    fout<<D[a][b]<<endl;

    return 0;
}
