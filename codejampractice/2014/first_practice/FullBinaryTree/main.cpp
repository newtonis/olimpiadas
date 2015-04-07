#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef vector < vector <int> > amatrix;

void solve(int c);

int main() {
    //freopen("input.in","r",stdin);
    freopen("B-large-practice.in","r",stdin);
    //freopen("output.out","w+",stdout);
    int T; cin>>T;
    for (int c = 1;c <= T;c++){
        solve(c);
    }
}
struct arista{
    int x;
    int y;
    arista(int px,int py){
        x = px;
        y = py;
    }
    arista(){}
};
void Count(int padre,int nodo ,int *count ,amatrix hijos);
int Cost(int p,int n , amatrix hijos);
struct item{
    int a;
    int b;
    item(int pa,int pb){
        a = pa;
        b = pb;
    }
};

bool compare(int a,int b) {
    return a > b;
}

void solve(int c){
    cout<<"Case #"<<c<<": ";
    int N; cin>>N; //nodos
    vector <arista> aristas;
    amatrix hijos; hijos.assign(N,vector <int>());

    for (int a = 0;a < N-1;a++){
        int X,Y; cin>>X>>Y; X--; Y--;
        aristas.push_back(arista(X,Y));
        hijos[X].push_back(Y);
        hijos[Y].push_back(X);
    }
    int min_deleted = 10000000;

    for (int x = 0;x < N;x++){
        //pruebo x como raiz
        //cout<<x<<endl;
        int del = Cost(-1,x,hijos);
        min_deleted = min(del,min_deleted);
    }
    cout<<min_deleted<<endl;
}
int Cost(int padre,int nodo,amatrix hijos){
    int hs = hijos[nodo].size();
    if (padre != -1){ hs--; } //si no es raiz, entonces uno de mis hijos no son realmente hijos
    if (hs == 0){
        return 0; //si no tengo hijos entonces el costo sera 0
    }
    vector <int> chances;
    vector <int> hc;

    int totalcost = 0;


    for (int h = 0;h < hijos[nodo].size();h++){
        int hijo = hijos[nodo][h];
        if (hijo == padre){ continue; }
        if (hs == 1){ //si tengo un solo hijo, voy a necesitar eliminarlo
            int val = 0;
            Count(nodo,hijo,&val,hijos); //cuento al hijo y sus descendientes
            return val; //devuelvo el valor de nodos a eliminar, ya que para usar el nodo, voy a necesitar eliminar el hijo
        }else if(hs >= 2){ //si tengo dos hijos o mas, debo analizar el costo que seria eliminar cada uno de ellos
            int val = 0;
            Count(nodo,hijo,&val,hijos);
            int fv = val - Cost(nodo,hijo,hijos);

            if (chances.size() == 0){
                chances.push_back(fv);
            }else if(chances.size() == 1){
                if (fv > chances[0]){
                    chances.push_back(chances[0]);
                    chances[0] = fv;
                }else{
                    chances.push_back(fv);
                }
            }else if(chances.size() == 2){
                if (fv > chances[0]){
                    chances[1] = chances[0];
                    chances[0] = fv;
                }else if(fv > chances[1]){
                    chances[1] = fv;
                }
            }
            //chances.push_back( val - Cost(nodo,hijo,hijos) );

            hc.push_back(hijo);
            totalcost += val;
        }
    }
    /*vector <int> ganancia;
    for (int c = 0;c < chances.size();c++){
        ganancia.push_back( chances[c] - Cost( nodo , hc[c] , hijos) );
    }*/

    return totalcost - chances[0] - chances[1]; //devuelvo los dos hijos con menor costo de nodos a eliminar, el costo neto es su sumatoria
}
void Count(int padre,int nodo ,int *count ,amatrix hijos){
    (*count) += 1;

    for (int x = 0;x < hijos[nodo].size();x++){
        if (hijos[nodo][x] != padre) {
            Count(nodo,hijos[nodo][x],count,hijos);
        }
    }
}