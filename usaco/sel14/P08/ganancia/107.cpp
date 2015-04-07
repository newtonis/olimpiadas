#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#define INICIO 0
#define LECTURA 1

using namespace std;

int cantidad;
int solucion;
bool alguna;

struct Auto{
    int demora;
    int tarifa;
    int arreglo;
    bool usado;
    Auto(int d,int t,int a){
        demora  = d;
        tarifa  = t;
        arreglo = a;
        usado = false;
    }
};

vector <Auto*> autos;

string cts(char c){
    stringstream ss;
    ss << c;
    return ss.str();
}
vector <string> lineString(string line){
    vector <string> info;
    info.push_back("");
    for (int x = 0;x < line.size();x++){
        if (cts(line[x]) != " "){
            info[info.size()-1] += cts(line[x]);
        }else{
            info.push_back("");
        }
    }
    return info;
}
vector <int> lineInt(string line){
    vector <string> info = lineString(line);
    vector <int> fin;
    for (int x = 0;x < info.size();x++){
        fin.push_back(atoi(info[x].c_str()));
    }
    return fin;
}
void lectura(){
    int estado = INICIO;
    ifstream file ("ganancia.in");
    string line;

    while (getline(file,line)){
        vector <int> data = lineInt(line);
        switch (estado){
            case INICIO:
                {
                    cantidad = data[0];
                    estado = LECTURA;
                }
            break;
            case LECTURA:
                {
                    int demora = data[0];
                    int tarifa = data[1];
                    int arreglo = data[2];
                    autos.push_back(new Auto(demora,tarifa,arreglo));
                }
            break;
        }
    }
}

int ganancia;

vector <Auto*> obtener_excepto(){
    vector <Auto*> data;
    for (int x = 0;x < autos.size();x++){
        if (autos[x]->usado == false){
            data.push_back(autos[x]);
        }
    }
    return data;
}
bool todos_usados(){
    for (int x = 0;x < autos.size();x++){
        if (autos[x]->usado == false){
            return false;
        }
    }
    return true;
}
void solve(){
    for (int x = 0;x < autos.size();x++){
        if (autos[x]->usado == false){
            autos[x]->usado = true;

            int parcial = 0;
            vector <Auto*> almacenados = obtener_excepto();
            for (int y = 0;y < almacenados.size();y++){
                parcial -= almacenados[y]->tarifa * autos[x]->demora;
            }
            parcial += autos[x]->arreglo;

            ganancia += parcial;

            if (todos_usados()){
                if (not(alguna) or ganancia > solucion){
                    solucion = ganancia;
                    alguna = true;
                }
            }else{
                solve();
            }
            ganancia -= parcial;

            autos[x]->usado = false;
        }
    }
}


int main(){
   ganancia = 0;
   solucion = 0;
   alguna = false;
   lectura();
   solve();
   /*for (int x = 0;x < autos.size();x++){
        cout<<autos[x].arreglo<<endl;
   }*/


    ofstream file ("ganancia.out");

    file << solucion << endl;
}
