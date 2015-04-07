#include<iostream>
#include<fstream>
#define forn(a,b) for((a)=0; (a)<(b); ++(a))
using namespace std;
const int maxn = 60;

ifstream fin("ganancia.in");
ofstream fout("ganancia.out");

struct taller{
    int d, t, p;
    bool usado;
};

int N, S = (1<<30), T;
int R[maxn];
taller A[maxn];

void calcular(){
    int i, e, C = 0;
    forn(i, N){
        for(e = i+1; e < N; ++e)
            C += A[ R[i] ].d * A[ R[e] ].t;
    }
    S = min(S, C);
}

void dfs(int nivel){
    if( nivel == N ){
        calcular();
        return;
    }
    int i;
    forn(i, N)
        if( !A[i].usado ){
            A[i].usado = true;
            R[nivel] = i;
            dfs(nivel+1);
            A[i].usado = false;
        }
}


int main(){
    int i, e;

    fin>>N;
    forn(i, N){
        fin>>A[i].d>>A[i].t>>A[i].p;
        T += A[i].p;
    }


    dfs(0);

    fout<<T-S<<endl;
    return 0;
}
