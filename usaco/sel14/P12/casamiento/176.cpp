#include<iostream>
#include<fstream>
#include<vector>
#define forn(a,b) for((a)=0; (a)<(b); ++(a))
using namespace std;
const int maxn = 100010;

ifstream fin("casamiento.in");
ofstream fout("casamiento.out");

struct nodo{
    bool visited;
};

struct par{
    par(){}
    par(int a, bool b) : largo(a), esciclo(b) {}
    bool esciclo;
    int largo;
};

int N, E, R;
vector<int> G[maxn];
nodo V[maxn];

par DFS(int v, int padre){
    int i, w, suma = 1;
    bool hayciclo = false;
    par m;

    V[v].visited = true;

    //cout<<v+1<<" es visitado"<<endl;

    forn(i, G[v].size() ){
        w = G[v][i];
        if( w != padre ){
           if( V[w].visited ){
                //es ciclo
                hayciclo = true;
           }else{
                m = DFS(w, v);
                if( m.esciclo ){
                    suma += m.largo;
                    hayciclo = true;
                }
                else suma += m.largo;
           }
        }
    }
    return par(suma,hayciclo);
}

int main(){
    int i, a, b;
    par m;

    fin>>N>>E;
    forn(i,E){
        fin>>a>>b;
        a--; b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    forn(i, N)
        if( !V[i].visited ){
            m = DFS( i, -1 );
            //cout<<"m vale "<<m.largo<<" y es ciclo?: "<<m.esciclo<<endl;
            if( m.largo == 1 ) R++;
            else if( m.esciclo ){
                R += m.largo / 2;
            }else{
                R += ( m.largo / 2 ) + bool(m.largo%2) ;
            }
        }

    fout<<R<<endl;

    return 0;
}
