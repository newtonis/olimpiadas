#include <iostream>
#include <stdio.h>

#define COSTO 10
#define MAX 20
using namespace std;

typedef unsigned int ui;

ui A,M; //A= cantidad agricultores M = cantidad de cajas
ui CC[MAX]; //cantidad de cajas por agricultor
ui VC[MAX][1200]; //valor por caja de cada agricultor

struct chance{
    int sum;
    int cajas;
    ui utilizados[MAX];
    chance(int s,int c,ui u[]){
        sum = s;
        cajas = c;
        for (int x = 0;x < A;x++){
            utilizados[x] = u[x];
        }
    }
};

chance solve(ui restantes,ui utilizados[],int ganancia,bool debug);

int main(){
    freopen("input.in","r",stdin);
    cin>>A>>M;
    for (int a = 0;a < A;a++){
        cin>>CC[a];
        for (ui c = 0;c < CC[a];c++){
            cin>>VC[a][c];
        }
    }
    ui utilizados[MAX];
    for (int v = 0;v < A;v++){
        utilizados[v] = 0;
    }
    chance sol = solve(M-1,utilizados,0,true);
    cout<<sol.sum<<" "<<sol.cajas<<endl;
    for (int x = 0;x < A;x++){
        cout<<sol.utilizados[x]<<" ";
    }
}

chance solve(ui restantes,ui utilizados[],int ganancia,bool debug){
    if (restantes == 0){
        return chance(ganancia,A-restantes,utilizados);
    }
    chance mejor_opcion = chance(ganancia,A-restantes,utilizados);
    for (int x = 0;x < A;x++){  ///por cada agricultor
        if (utilizados[x] == CC[x]){ continue; } ///si no le quedan mas zapallos
        utilizados[x] ++; ///compro al agricultor x un zapallo
        int ganancia_zapallo = - VC[x][ CC[x] - utilizados[x] ] + COSTO;
        if (ganancia_zapallo < 0){ utilizados[x] --; continue; }
        chance pos = solve(restantes - 1,utilizados,ganancia + ganancia_zapallo,false);
        utilizados[x] --;

        if (pos.sum > mejor_opcion.sum){
            mejor_opcion = pos;
        }
    }
    return mejor_opcion;
}
