#include <iostream>
#include <queue>
#include <vector>
#include <ios>
#include <stdio.h>
#define MAX 10000

using namespace std;

typedef unsigned int ui;

int distancias[MAX];
vector <ui> hijos[MAX];
vector <ui> dhijos[MAX];

ui S,E; //start end

struct compare{
    bool operator()(ui A,ui B){
        return distancias[A] > distancias[B];
    }
};

void initGraph(ui V);
void solve();

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
    #endif
    ios::sync_with_stdio(false);

    ui C; cin>>C;
    while (C--){
        ui V,K; cin>>V>>K;
        initGraph(V);
        while (K--){
            ui A,B,C; cin>>A>>B>>C; A--; B--;
            hijos[A].push_back(B);
            dhijos[A].push_back(C);
        }
        cin>>S>>E; S--; E--;
        solve();
    }
}

void initGraph(ui V){
    for (int x = 0;x < V;x++){
        distancias[x] = -1;
        hijos[x] = vector<ui>();
        dhijos[x] = vector<ui>();
    }
}
void solve(){
    distancias[S] = 0;
    priority_queue < ui, vector <ui> , compare > cola;
    cola.push(S);
    while (not cola.empty()){
        ui actual = cola.top(); cola.pop();
        if (actual == E){
            cout<<distancias[actual]<<endl;
            return;
        }
        for (ui h = 0;h < hijos[actual].size();h++){
            ui hijo = hijos[actual][h]; ui dist = dhijos[actual][h];
            if (distancias[hijo] == -1 or distancias[actual] + dist < distancias[hijo]){
                distancias[hijo] = distancias[actual] + dist;
                cola.push(hijo);
            }
        }
    }
    cout<<"NO"<<endl;
}
