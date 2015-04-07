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
vector <int> utilizados;
vector <int> noutilizados;

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

bool permitido(int v){
    for (int x = 0;x < peleas.size();x++){
        for (int y = 0;y < utilizados.size();y++){
            if ( (peleas[x]->A == utilizados[y] and peleas[x]->B == v) or (peleas[x]->B == utilizados[y] and peleas[x]->A == v)){
                return false;
            }
        }
    }
    return true;
}

vector <int> calcularPos(){
    vector <int> info;
    for (int x = 1;x <= N;x++){
        bool mal = false;
        for (int y = 0;y < utilizados.size();y++){
            if (utilizados[y] == x){
                mal = true;
            }
        }
        if (not mal){
            info.push_back(x);
        }
    }
    return info;
}
void solve(){
    vector <int> valores = calcularPos();
    for (int x = 0;x < valores.size();x++){
        bool allowed = permitido(valores[x]);
        if (not allowed){
            continue;
        }

        utilizados.push_back(valores[x]);
        maximo += 1;

        if (maximo > best){
            best = maximo;
        }
        solve();
        maximo -= 1;
        utilizados.erase(utilizados.begin()+utilizados.size()-1);

    }
}

int main(){
    maximo = 0;
    best = 0;
    lectura();
    solve();

    ofstream file ("casamiento.out");
    file << best << endl;
}
