#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define MAX 1000

using namespace std;

void AddHijo(int s, int e,int w, vector <int> *hijos,vector <int>* pesos,int *entrante);

void TopologicalSort(int n,int e,vector <int> *hijos,vector <int> *pesos,int *entrante);
void Prim(int n,int e,vector <int> *hijos,vector <int> *pesos,int *apeso,int *goA,int *goB,vector <int> *ahijo,int min_arista);
void FloydWarshall(int n,int e,vector <int> *hijos,vector <int> *pesos,int *apeso,int *goA,int *goB,vector <int> *ahijo);

int main() {
    ios::sync_with_stdio(false);
    #ifndef ONLINE_JUDGE
    freopen("input.in", "r", stdin);
    #endif

    vector <int> hijo[MAX];
    vector <int> peso[MAX];
    vector <int> ahijo[MAX];

    int entrante[MAX];
    int apeso[MAX];
    int goA[MAX];
    int goB[MAX];

    int d; cin>>d;
    int n,e; cin>>n>>e; //c nodos, c aristas

    int min_arista , min_value_arista = 10000000;

    for (int nm = 0;nm < n;nm++){
        entrante[nm] = 0;
    }
    for (int a = 0;a < e;a++){
        int o,t,w; cin>>o>>t>>w; o--; t--; //source , target , weight
        apeso[a] = w;
        goA[a] = o;
        goB[a] = t;

        AddHijo(o,t,w,hijo,peso,entrante);
        ahijo[o].push_back(a);
        if (d == 0){
            AddHijo(t,o,w,hijo,peso,entrante);
            ahijo[t].push_back(a);
        }
        if (w < min_value_arista){
            min_arista        = a;
            min_value_arista = w;
        }
    }
    char letter; cin>>letter;
    if (letter == 'g'){
        TopologicalSort(n,e,hijo,peso,entrante);
    }else if (letter == 'h'){
        Prim(n,e,hijo,peso,apeso,goA,goB,ahijo,min_arista);
    }else if(letter == 'i'){
        FloydWarshall(n,e,hijo,peso,apeso,goA,goB,ahijo);
    }
}
void AddHijo(int s, int e,int w, vector <int> *hijos,vector <int>* peso,int* entrante){
    hijos[s].push_back(e);
    peso[s] .push_back(w);
    entrante[e] ++;
}
void TopologicalSort(int n,int e,vector <int> *hijos, vector <int> *pesos,int* entrante){
    vector <int> result;

    vector <int> cola;
    for (int mn = 0;mn < n;mn++){
        if (entrante[mn] == 0){
            cola.push_back(mn);
        }
    }
    while (not cola.empty()){
        int mn = cola[0]; cola.erase(cola.begin());

        result.push_back(mn);

        while (not hijos[mn].empty()){
            //elimino arista
            int hijo = hijos[mn][0]; hijos[mn].erase(hijos[mn].begin());

            entrante[ hijo ] --;

            if (entrante[hijo] == 0){
                cola.push_back( hijo );
            }
        }
    }

    for (int x = 0;x < result.size();x++){
        cout<<result[x]+1<<" ";
    }
    cout<<endl;
}
struct ec{
    int ma;
    int distancia;
    ec(int pmn,int pd){
        ma = pmn;
        distancia = pd;
    }
    ec(){}
};
struct compare{
    bool operator()(ec A,ec B){
        return A.distancia > B.distancia;
    }
};
bool compareB(ec A,ec B){
    return A.distancia < B.distancia;
};


void Prim(int n,int e,vector <int> *hijos,vector <int> *pesos,int *apeso,int *goA,int *goB,vector <int> *ahijo,int min_arista){
    priority_queue < ec , vector <ec> , compare > cola;
    cola.push( ec(min_arista , apeso[min_arista]));

    int elegidas[MAX];
    int nodos_dentro[MAX];
    vector <ec> solution; //solution.push_back(ec(min_arista,apeso[min_arista]));

    for (int ne = 0;ne < e;ne++){
        elegidas[ne] = false;
    }
    for (int nm = 0;nm < n;nm++){
        nodos_dentro[nm] = false;
    }
    int nodos = 0;
    int sumatoria = 0;

    while (nodos < n){
        ec value = cola.top(); cola.pop();
        int na = value.ma;
        sumatoria += apeso[na];
        solution.push_back(ec(na,apeso[na]));

        elegidas[na] = true;
        if (not nodos_dentro[goA[na]]){
            nodos_dentro[goA[na]] = true;
            for (int nv = 0;nv < ahijo[goA[na]].size();nv++) {
                int arista = ahijo[goA[na]][nv];
                if (elegidas[arista]) {continue;}
                elegidas[arista] = true;
                cola.push(ec(arista, apeso[arista]));
            }
            nodos ++;
        }
        if (not nodos_dentro[goB[na]]){
            nodos_dentro[goB[na]] = true;
            for (int nv = 0;nv < ahijo[goB[na]].size();nv++){
                int arista = ahijo[goB[na]][nv];
                if (elegidas[arista]){ continue; }
                elegidas[arista] = true;
                cola.push( ec(arista , apeso[arista]));
            }
            nodos ++;
        }
    }
    cout<<sumatoria<<endl;
    sort(solution.begin(),solution.end(),compareB);

    for (int a = 0;a < solution.size();a++){
        cout<<goA[solution[a].ma]+1<<"-"<<goB[solution[a].ma]+1<<" ";
    }
    cout<<endl;
}
void FloydWarshall(int n,int e,vector <int> *hijos,vector <int> *pesos,int *apeso,int *goA,int *goB,vector <int> *ahijo){
    int matrix[MAX][MAX];
    for (int nm = 0;nm < n;nm++){
        for (int nmb = 0;nmb < n;nmb++){
            if (nm == nmb){
                matrix[nm][nmb] = 0;
            }else {
                matrix[nm][nmb] = -1;
            }
        }
    }

    for (int a = 0;a < e;a++){
        matrix[goA[a]][goB[a]] = apeso[a];
    }

    for (int mn = 0;mn < n;mn++){
        for (int na = 0;na < n;na++){
            for (int nb = 0;nb < n;nb++){
                int a = matrix[na][mn];
                int b = matrix[mn][nb];
                int c = matrix[na][nb]; //current

                if (a != -1 and b != -1 and (a + b < c or c == -1)){
                    matrix[na][nb] = a + b;
                }
            }
        }
    }

    for (int a = 0;a < n;a++){
        for (int b = 0;b < n;b++){
            cout<<matrix[a][b]<<" ";
        }
        cout<<endl;
    }
}












