#include <iostream>
#include <vector>
#include <climits>
#include <queue>

#define MAX_NODES 101
#define INF INT_MAX

using namespace std;

typedef unsigned int ui;

void solve(ui c);
void AddArista(ui s,ui e,ui p , vector <int> *daristas, vector <int> *paristas,ui *m);
bool BellmanFord(ui s,ui n,ui m,vector <int> *daristas,vector <int> *paristas,int *distancias);
void Dijkstra(ui s,ui n,ui m,vector <int> *daristas, vector <int> *paristas, int *anteriores,int *distancias,int *items);
int CalcularDistancia(ui s,ui e,vector <int> *daristas, vector <int> *paristas, int *anteriores,int *items,int *distancias);

struct node{
    int d;
    int n;
    node(ui pn,ui pd){
        n = pn;
        d = pd;
    }
    node(){}
};

class compare{
    public:
        bool operator()(node a,node b){
            return a.d > b.d;
        }
};

int main() {
    ios::sync_with_stdio(false);
    #ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
    #endif

    ui t; cin>>t;
    for (ui c = 1;c <= t;c++) {
        solve(c);
    }
}

void solve(ui c) {
    cout << "graph " << c << " ";

    ui n, m;
    cin >> n >> m; //n = nodos, m = vertices

    vector<int> daristas[MAX_NODES]; //destino aristas
    vector<int> paristas[MAX_NODES]; //peso aristas
    int distancias[MAX_NODES];

    for (ui e = 0; e < m; e++) {
        ui u, v, w;
        cin >> u >> v >> w;
        u--;
        v--; //u=inicio, v=fin, w=peso
        AddArista(u, v, w, daristas, paristas, &m);
    }


    //Add the node Q
    for (ui a = 0;a < n;a++) {
        AddArista(n,a,0,daristas,paristas,&m);
    }
    n++;

    bool rta = BellmanFord(n-1,n,m,daristas,paristas,distancias);

    if (not rta){
        cout<<"no"<<endl;
        cout<<endl;
        return;
    }else{
        cout<<"yes"<<endl;
        cout<<endl;
    }

    ///Ahora actualizar pesos
    for (ui nodo = 0;nodo < n;nodo++){
        for (ui arista = 0;arista < daristas[nodo].size();arista++){
        //    //w(u,v) = w(u,v) + h(u) - h(v)
            paristas[ nodo ][ arista ] = paristas[ nodo ][ arista ] + distancias[ nodo ] - distancias[ daristas[nodo][arista] ];
        }
    }

    for (ui nodo = 0;nodo < n;nodo++) {
        cout<<distancias[nodo]<<" ";
    }
    cout<<endl;
    //Ahora el djikstra final


    for (ui nodo = 0;nodo < n-1;nodo++){
        int final[MAX_NODES] , anteriores[MAX_NODES] , items[MAX_NODES];

        Dijkstra(nodo,n,m,daristas,paristas,anteriores,final,items);

        for (ui s = 0;s < n-1;s++) {
            if (final[s] == -1) {
                cout << "# ";
            } else {
                cout << CalcularDistancia(nodo , s , daristas, paristas , anteriores , items ,distancias) << " ";
            }
        }
    }
    cout<<endl<<endl;


}
void AddArista(ui s,ui e,ui p , vector <int> *daristas, vector <int> *paristas , ui *m){
    daristas[s].push_back(e);
    paristas[s].push_back(p);
    *m++;
}
bool BellmanFord(ui s,ui n,ui m,vector <int> *daristas,vector <int> *paristas,int *distancias){
    //cout<<"Iniciando bellman ford con Start="<<s<<" Cantidad de nodos="<<n<<endl;

    for (ui actual = 0;actual < n;actual++){
        distancias[actual] = INF;
    }
    distancias[s] = 0;

    for (ui rep = 0;rep < n-1;rep ++){ //por cada repeticion
        for (ui actual = 0;actual < n;actual++) { //por cada vertice
            if (distancias[actual] == INF) {
                continue;
            }
            for (ui v = 0; v < daristas[actual].size(); v++) { //por cada arista de el vertice *actual*
                if (distancias[actual] + paristas[actual][v] < distancias[daristas[actual][v]]) {
                    distancias[daristas[actual][v]] = distancias[actual] + paristas[actual][v];
                }
            }
        }
    }

    //ciclos negativos
    for (ui nodo = 0;nodo < n;nodo++){ //por cada nodo
        for (ui vertice = 0;vertice < daristas[nodo].size();vertice++){ //por cada vertice del nodo
            if (distancias[nodo] == INF){ continue; }

            if (distancias[ daristas[nodo][vertice] ] > distancias[nodo] + paristas[nodo][vertice] ){
                return false;
            }
        }
    }
    return true;
}
void Dijkstra(ui s,ui n,ui m,vector <int> *daristas,vector <int> *paristas,int* anteriores,int *distancias,int *items){
    for (ui nn = 0;nn < n;nn++){
        distancias[nn] = -1;
    }

    distancias[s] = 0;

    priority_queue < node , vector <node> , compare> cola; cola.push( node(s,distancias[s])  );

    while (not cola.empty()){
        ui actual = cola.top().n; cola.pop();
        //cout<<actual+1<<endl;

        for (ui h = 0;h < daristas[actual].size();h++){
            if (distancias[ daristas[actual][h] ] > distancias[actual] + paristas[actual][h] || distancias[ daristas[actual][h] ] == -1){
                distancias[ daristas[actual][h] ] = distancias[actual] + paristas[actual][h];
                anteriores[ daristas[actual][h] ] = actual;
                items[ daristas[actual][h] ] = h;
                //cout<< daristas[actual][h] <<":"<< distancias[ daristas[actual][h] ]<<endl;
                cola.push( node( daristas[actual][h] , distancias[ daristas[actual][h] ] ) );
            }
        }
    }
    cout<<endl;

}
int CalcularDistancia(ui s,ui e,vector <int> *daristas, vector <int> *paristas, int *anteriores,int *items,int *distancias){
    int rta = 0;
    ui actual = e;
    while (actual != s){

        rta += paristas[ anteriores[actual] ][ items[actual] ] - distancias[ anteriores[actual] ] + distancias[ actual ];
        actual = anteriores[actual];
    }
    return rta;
}