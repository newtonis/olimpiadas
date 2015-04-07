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

int N;
int M;

struct duo{
    int A;
    int B;
    duo(int a,int b){
        A = a;
        B = b;
    }
    duo(){}
};

struct peleado{
    int numero;
    vector <int> peleas;
    peleado(int n){
        numero = n;
    }
};


vector <duo*> peleas;
vector <int> solucion;
vector <peleado*> peleados;

int maximo;
int best;

void lectura(){
    ifstream file ("casamiento.in");
    string line;
    int estado = INICIO;
    while (getline(file,line)){
        vector <int> nums = lineInt(line);
        switch (estado){
            case INICIO:
                {
                    N = nums[0];
                    M = nums[1];
                    estado = LECTURA;
                }
            break;
            case LECTURA:
                {
                    int A = nums[0];
                    int B = nums[1];

                    peleas.push_back(new duo(A,B));
                }
            break;
        }
    }
}




void p(){
    for (int x = 0;x < N;x++){
        peleados.push_back(new peleado(x+1));
    }
    for (int x = 0;x < peleas.size();x++){
        peleados[peleas[x]->A-1]->peleas.push_back(peleas[x]->B+1);
        peleados[peleas[x]->B-1]->peleas.push_back(peleas[x]->A+1);
    }

}
int longitud;
int scaned;

void solve(){
    vector <peleado*> posibilidad;
    for (int x = 0;x < peleados.size();x++){
        if (peleados[x]->peleas.size() == longitud){
            scaned++;
            posibilidad.push_back(peleados[x]);
        }
    }

    for (int x = posibilidad.size()-1;x > -1;x--){
        bool mal = false;
        for (int y = 0;y < posibilidad[x]->peleas.size();y++){
            for (int z = 0;z < solucion.size();z++){
                if (solucion[z] == posibilidad[x]->peleas[y]){
                    mal = true;
                }
            }
        }
        if (mal == false){
            solucion.push_back(posibilidad[x]->numero);
        }
    }

    longitud += 1;
    if (scaned == peleados.size()){
        return;
    }
    solve();
}
/*
void solve(){
    for (int x = 0;x < peleas.size();x++){
        int cant = 0;
        for (int y = 0;y < lugares.size();y++){
            if (peleas[x]->A == lugares[y] or peleas[x]->B == lugares[y]){
                cant ++;
            }
        }

        if (cant == 0){
            maximo --;
        }else if(cant == 1){

        }else if(cant == 2){
            maximo --;

        }

        agregar(peleas[x]->A);
        agregar(peleas[x]->B);
    }

}
*/
int main(){
    scaned = 0;

    lectura();
    p();
    longitud = 0;
    solve();


    ofstream file ("casamiento.out");
    file << solucion.size() << endl;
    /*cout<< solucion.size() <<endl;
    for (int x = 0;x < solucion.size();x++){
        cout<<solucion[x]<<endl;
    }*/
}

