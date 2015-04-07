#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>
#include <stdlib.h>
#include <stdio.h>
#include <string>

#define INICIO 0
#define DATA 1

#define NORTESUR 0
#define SURNORTE 1

#define OESTEESTE 0
#define ESTEOESTE 1

#define HORIZONTAL 0
#define VERTICAL 1

#define INICIO 0
#define DATA_A 1
#define DATA_B 2
#define DATA_C 3
#define DATA_D 4

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

int riesgo(int puntos,int sentido){

}
//Prototipo
struct pos;

struct calle{
    int riesgo;
    int sentido;
    bool inclinacion;
    pos* A;
    pos* B;
    calle(int sen,int rta,bool inc){
        riesgo = rta;
        sentido = sen;
        inclinacion = inc;
    }
    calle(){}
    pos* notYo(pos* V){
        if (V == A){return B;}
        if (V == B){return A;}
    }
};
struct pos{
    int x;
    int y;
    bool marcado;
    int faltas;
    vector <calle*> fronteras;
    calle* anterior;
    pos(int px,int py){
        x = px;
        y = py;
        marcado = false;
        faltas = -1;
        anterior = NULL;
    }
    pos(){}
};

int V;
int H;

int H1;
int V1;
int V2;
int H2;

vector <pos*> lugares;

vector <calle*> horizontal;
vector <calle*> vertical;

vector <calle*> calles;

void read(){
    ifstream file ("ciclovia.in");
    string line;
    int estado = INICIO;
    while (getline(file,line)){
        vector <int> nums = lineToInt(line);
        switch (estado){
            case INICIO:
                {
                    V = nums[0];
                    H = nums[1];
                    estado = DATA_A;
                }
            break;
            case DATA_A:
                {
                    int sentido = nums[0];
                    int riesgo = nums[1];
                    vertical.push_back(new calle(sentido,riesgo,VERTICAL));
                    if (vertical.size() == H){
                        estado = DATA_B;
                    }
                }
            break;
            case DATA_B:
                {
                    int sentido = nums[0];
                    int riesgo = nums[1];
                    horizontal.push_back(new calle(sentido,riesgo,HORIZONTAL));
                    if (horizontal.size() == V){
                        estado = DATA_C;
                    }
                }
            break;
            case DATA_C:
                {
                    V1 = nums[0];
                    H1 = nums[1];
                    estado = DATA_D;

                }
            break;
            case DATA_D:
                {
                    V2 = nums[0];
                    H2 = nums[1];
                }
            break;
        }
    }
}
pos* get_lugar_by_pos(int x,int y){
    for (int a = 0;a < lugares.size();a++){
        if (lugares[a]->x == x and lugares[a]->y == y){
            return lugares[a];
        }
    }
    return NULL;
}

void makeLugares(){
    for (int x = 0;x <= V;x++){
        for (int y = 0;y <= H;y++){
            lugares.push_back( new pos(x+1,y+1) );
        }
    }

    for (int x = 0;x < vertical.size();x++){
        for (int y = 0;y < H;y++){
            calle* nueva = new calle(vertical[x]->sentido,vertical[x]->riesgo,vertical[x]->inclinacion);
            nueva->A = get_lugar_by_pos(x+1,y+1);
            nueva->B = get_lugar_by_pos(x+1,y+2);
            get_lugar_by_pos(x+1,y+1)->fronteras.push_back(nueva);
            get_lugar_by_pos(x+1,y+2)->fronteras.push_back(nueva);
            calles.push_back(nueva);
        }
    }

    for (int y = 0;y< horizontal.size();y++){
        for (int x = 0;x < V;x++){
            calle* nueva = new calle(horizontal[x]->sentido,horizontal[x]->riesgo,horizontal[x]->inclinacion);
            nueva->A = get_lugar_by_pos(x+1,y+1);
            nueva->B = get_lugar_by_pos(x+2,y+1);
            get_lugar_by_pos(x+1,y+1)->fronteras.push_back(nueva);
            get_lugar_by_pos(x+2,y+1)->fronteras.push_back(nueva);
            calles.push_back(nueva);
        }
    }


}

vector <calle*> obtener_candidatos(pos* actual){
    vector <calle*> cands = actual->fronteras;
    for (int x = cands.size()-1;x > -1;x--){
        if (cands[x]->notYo(actual)->marcado){
            cands.erase(cands.begin()+x);
        }
    }
    return cands;
}
pos* siguente_calle(){
    pos* best = NULL;
    for (int x = 0;x < lugares.size();x++){
        if (not lugares[x]->marcado and lugares[x]->faltas != -1){
            if (best == NULL or lugares[x]->faltas < best->faltas){
                best = lugares[x];
            }
        }
    }
    return best;
}

void dijikstra(pos* nodo){
    pos* actual = nodo;
    bool continuar = true;

    actual->faltas = 1;
    while (continuar){

        actual->marcado = true;
        vector <calle*> candidatos = obtener_candidatos(actual);

        for (int x = 0;x < candidatos.size();x++){
            int faltas = candidatos[x]->riesgo + actual->faltas;
            if (actual->anterior != NULL){
                if (actual->anterior->inclinacion != candidatos[x]->inclinacion){
                    faltas += 3;
                }
            }
            if (candidatos[x]->inclinacion == VERTICAL){
                if (candidatos[x]->sentido == NORTESUR){
                    if (actual->y > candidatos[x]->notYo(actual)->y){
                        faltas += 1;
                    }
                }else{
                    if (actual->y < candidatos[x]->notYo(actual)->y){
                        faltas += 1;
                    }
                }
            }else{
                if (candidatos[x]->sentido == OESTEESTE){
                    if (actual->x > candidatos[x]->notYo(actual)->x){
                        faltas += 1;
                    }
                }else{
                    if (actual->x < candidatos[x]->notYo(actual)->x){
                        faltas += 1;
                    }
                }
            }

            if (candidatos[x]->notYo(actual)->faltas == -1 or candidatos[x]->notYo(actual)->faltas > faltas){
                candidatos[x]->notYo(actual)->faltas = faltas;
                candidatos[x]->notYo(actual)->anterior = candidatos[x];
            }
        }
        pos* nuevo = siguente_calle();
        actual = nuevo;
        if (actual == NULL){
            continuar = false;
        }

    }


}


void solve(){
    pos* inicio = get_lugar_by_pos(V1,H1);
    pos* fin = get_lugar_by_pos(V2,H2);
    dijikstra(inicio);

    ofstream file ("ciclovia.out");

    file<<fin->faltas<<endl;
}

/*void show(){
    for (int x = 0;x < lugares.size();x++){
        cout<<lugares[x]->fronteras.size()<<endl;
    }
}*/
int main(){
    read();
    makeLugares();
    /*show();*/

    solve();
}
