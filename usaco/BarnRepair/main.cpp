/*
ID: newtonis
LANG: C++
TASK: barn1
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;

#define MAX 200
#define MAX_TABLES 50

struct space{
    int s,e,size; //start , end
    space(int ps,int pe){
        s = ps;
        e = pe;
        size = pe - ps;
    }
};
bool compare(int a,int b){
    return a < b; //de menor a mayor
}
bool compareB(space a,space b){
    return a.size > b.size; //de mayor a menor
}
int main(){
    freopen("barn1.in","r",stdin);
    freopen("barn1.out","w+",stdout);

    //freopen("barn1.out","w+",stdout);
    int M,S,C; cin>>M>>S>>C; //M= maximo boards S=stalls totales //C=numero de vacas en stalls

    vector <int> ocupied;
    bool stalls[MAX]; //si hay establo o no en la posicion
    for (int v = 0;v < S;v++){
        stalls[v] = 0;
    }
    for (int c = 0;c < C;c++){
        int o; cin>>o; //ocupied
        ocupied.push_back(o);
        stalls[o] = 1;
    }
    //minimizar la longitud total de las tablas que compra, es decir utilizar la mayor cantidad de tablas
    sort(ocupied.begin(),ocupied.end(),compare);

    int status = 0;
    vector <space> spaces;  //espacios

    int solution = ocupied[ocupied.size()-1] - ocupied[0] + 1;

    for (int s = ocupied[0]+1;s <= ocupied[ocupied.size()-1]-1;s++){
        if (stalls[s]){ continue; }

        int start = s;
        while (not stalls[s]){ s ++; };
        int end = s;
        spaces.push_back( space(start,end) );
    }

    sort(spaces.begin(),spaces.end(),compareB); //de mayor a menor


    for (int t = 2;t <= M;t++){
        //ahora voy a usar t tablas
        //debo encontrar el espacio vacio mas grande y a que tabla le pertenece
        if (spaces.size() == 0){ //no puedo mejorar mas el espacio
            //fin
            break;
        }
        space elected = spaces[0]; spaces.erase(spaces.begin()); //tomo el espacio mas grande
        //resto a la solucion
        solution -= elected.size;
    }
    cout<<solution<<endl;
}