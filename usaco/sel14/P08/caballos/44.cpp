#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>
#include <stdlib.h>
#include <stdio.h>
#include <string>

#define INICIO 0
#define DATA 1

using namespace std;

string cts(char c){
    stringstream ss;
    ss << c;
    return ss.str();
}
vector <string> lineToString(string line){
    vector <string> valores;
    valores.push_back( "" );
    for (int x = 0;x < line.size();x++){
        if (cts(line[x]) != " "){
            valores[ valores.size() - 1] += cts(line[x]);
        }else{
            valores.push_back("");
        }
    }
    return valores;
}
vector <int> lineToInt(string line){
    vector <string> data = lineToString(line);
    vector <int> info;
    for (int x = 0;x < data.size();x++){
        info.push_back(atoi(data[x].c_str()));
    }
    return info;
}

int f;
int c;
int m;
vector < vector <string> > mapa;
vector <string> palabra;
int soluciones;

void leer(){
    ifstream file ("caballos.in");
    int status = INICIO;
    string line;
    while (getline(file,line)){
        switch (status){
            case INICIO:
                {
                    vector <int> info = lineToInt(line);
                    f = info[0];
                    c = info[1];
                    m = info[2];
                    status = DATA;
                }
            break;
            case DATA:
                {
                    vector <string> fila;
                    for (int x = 0;x < line.size();x++){
                        fila.push_back( cts(line[x] ));
                    }
                    mapa.push_back(fila);
                }
            break;
        }
    }
}
void show(){

    for (int x = 0;x < f;x++){
        for (int y = 0;y < c;y++){
            cout<<mapa[x][y];
        }
        cout<<endl;
    }
}
void armar(){
    palabra.push_back("C");
    palabra.push_back("A");
    palabra.push_back("B");
    palabra.push_back("A");
    palabra.push_back("L");
    palabra.push_back("L");
    palabra.push_back("O");
}

struct pos{
    int x;
    int y;
    pos(){}
    pos(int px,int py){
        x = px;
        y = py;
    }
};

bool disponible(pos lugar){
    if (lugar.x < 0 or lugar.y < 0 or lugar.x >= f or lugar.y >= c){
        return false;
    }
    return true;
}
vector <pos> puede_llegar(pos caballo){
    vector <pos> data;

    data.push_back(  pos( caballo.x + 2 , caballo.y + 1) );
    data.push_back(  pos( caballo.x + 1 , caballo.y + 2) );
    data.push_back(  pos( caballo.x + 2 , caballo.y - 1) );
    data.push_back(  pos( caballo.x + 1 , caballo.y - 2) );
    data.push_back(  pos( caballo.x - 2 , caballo.y + 1) );
    data.push_back(  pos( caballo.x - 1 , caballo.y + 2) );
    data.push_back(  pos( caballo.x - 2 , caballo.y - 1) );
    data.push_back(  pos( caballo.x - 1 , caballo.y - 2) );

    for (int x = data.size()-1;x > -1;x--){
        if (not disponible(data[x])){
            data.erase(data.begin()+x);
        }
    }
    return data;
}

void solve(pos position_actual,vector <pos> actualidad,int letra_actual){
    vector <pos> lugares_disponibles = puede_llegar(position_actual);
    for (int x = 0;x < lugares_disponibles.size();x++){

        if (mapa[lugares_disponibles[x].x][lugares_disponibles[x].y] == palabra[letra_actual]){
            letra_actual++;
            if (letra_actual == palabra.size()){
                soluciones ++;
            }else{

                actualidad.push_back(lugares_disponibles[x]);
                solve(lugares_disponibles[x],actualidad,letra_actual);
                actualidad.erase(actualidad.begin()+actualidad.size()-1);
            }
            letra_actual --;
        }
    }
}
int main(){
    leer();
    armar();
    for (int x = 0;x < f;x++){
        for (int y = 0;y < c;y++){
            if (mapa[x][y] == "C"){
                solve(pos(x,y),vector<pos>(),1);
            }
        }
    }
    ofstream file ("caballos.out");
    file<< soluciones % m <<endl;
}


