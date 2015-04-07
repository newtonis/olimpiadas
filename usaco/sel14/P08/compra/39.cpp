#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>
#include <stdlib.h>
#include <stdio.h>
#include <string>

#define INICIO 0
#define DATA 1
#define DATA_B 2

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

struct pos{
    int x;
    int y;
    pos(){}
    vector <pos*> fronteras;
    pos* anterior;
    int distancia;
    bool marcado;
    bool es_casa;
    pos(int px,int py,bool casa){
        x = px;
        y = py;
        distancia = -1;
        marcado = false;
        es_casa = casa;
    }
    void reset(){
        distancia = -1;
        marcado = false;
    }
    void show(){
        cout<<x<<" "<<y<<endl;
    }
};



int V;
int H;
int C;
vector <pos*> casitas;
vector <pos*> nodos;
vector <pos*> chances_ganadora;
int valor_ganador;

void read(){
    ifstream file ("compra.in");
    string line;
    int status = INICIO;
    while (getline(file,line)){
        vector <int> NUMS = lineToInt(line);
        switch (status){
            case INICIO:
                {
                    V = NUMS[0];
                    H = NUMS[1];
                    status = DATA;
                }
            break;
            case DATA:
                {
                    C = NUMS[1];
                    status = DATA_B;
                }
            break;
            case DATA_B:
                {
                    int v_pos = NUMS[0];
                    int h_pos = NUMS[1];
                    casitas.push_back( new pos(v_pos,h_pos,true) );
                }
            break;
        }


    }
}
void show(){
    for (int x = 0;x < casitas.size();x++){
        casitas[x]->show();
    }
}

vector <pos*> obtener_candidatos(pos* actual){
    vector <pos*> candidatos;
    for (int x = 0;x < actual->fronteras.size();x++){
        if (not actual->fronteras[x]->marcado){
            candidatos.push_back(actual->fronteras[x]);
        }
    }
    return candidatos;
}

pos* nueva_eleccion(){
    pos* nueva = NULL;
    for (int x = 0;x < nodos.size();x++){
        if (not nodos[x]->marcado and nodos[x]->distancia != -1){
            if (nueva == NULL){
                nueva = nodos[x];
            }else if (nueva->distancia > nodos[x]->distancia){
                nueva = nodos[x];
            }
        }
    }
    return nueva;
}
void djikstra(pos* testeo){

    for (int x = 0;x < nodos.size();x++){
        nodos[x]->reset();
    }

    pos* actual = testeo;
    actual->distancia = 0;
    bool continuar = true;

    while (continuar){
        actual->marcado = true;
        vector <pos*> candidatos = obtener_candidatos(actual);

        //ETIQUETO
        for (int x = 0;x < candidatos.size();x++){
            if (candidatos[x]->distancia == -1 or candidatos[x]->distancia >= actual->distancia + 1){
                candidatos[x]->distancia = actual->distancia + 1;
                candidatos[x]->anterior = actual;
            }
        }

        //SELECCIONO EL NUEVO
        pos* nuevo = nueva_eleccion();
        if (nuevo == NULL){
            continuar = false;
        }else{
            actual = nuevo;
        }
    }
    int valor = -1;
    for (int x = 0;x < casitas.size();x++){
        if (casitas[x]->distancia > valor or valor == -1){
            valor = casitas[x]->distancia;
        }
        /*cout<<casitas[x]->distancia<<endl;
        cout<<casitas[x]->x<<" "<<casitas[x]->y<<endl;*/
    }

    /*for (int x = 0;x < nodos.size();x++){
        if (nodos[x]->es_casa){

            valor+= nodos[x]->distancia;
            cout<<nodos[x]->distancia<<endl;
            cout<<nodos[x]->x<<" "<<nodos[x]->y<<endl;
        }
    }*/
    /*
    cout<<valor<<endl;*/
    /*while (getchar() != '\n'){}*/

    if (valor_ganador == -1){
        chances_ganadora.push_back(testeo);
        valor_ganador = valor;
    }else if(valor_ganador == valor){
        chances_ganadora.push_back(testeo);
    }else if(valor_ganador > valor){
        chances_ganadora.clear();
        chances_ganadora.push_back(testeo);
        valor_ganador = valor;
    }
}

pos* existe(pos position){
    for (int x = 0;x < casitas.size();x++){
        if (casitas[x]->x == position.x and casitas[x]->y == position.y){
            return casitas[x];
        }
    }
    return NULL;
}
void calcular_nodos(){
    for (int x = 0;x < V;x++){
        for (int y = 0;y < H;y++){
            pos* casa = existe(pos(x,y,true));
            if (casa == NULL){
                nodos.push_back(new pos(x,y,false));
            }else{
                nodos.push_back(casa);
            }
        }
    }
}
pos* get_pos_by_pos(int x,int y){
    for (int a = 0;a < nodos.size();a++){
        if (nodos[a]->x == x and nodos[a]->y == y){
            return nodos[a];
        }
    }
    return NULL;
}
void add_frontera(pos* mia,int x,int y){
    if (x < 0 or y < 0 or x >= V or y >= H){ return; }

    mia->fronteras.push_back( get_pos_by_pos(x,y) );

}
void calcular_fronteras(){
    for (int x = 0;x < nodos.size();x++){
        add_frontera(nodos[x],nodos[x]->x+1,nodos[x]->y);
        add_frontera(nodos[x],nodos[x]->x-1,nodos[x]->y);
        add_frontera(nodos[x],nodos[x]->x  ,nodos[x]->y+1);
        add_frontera(nodos[x],nodos[x]->x  ,nodos[x]->y-1);
    }
}
void solve(){
    djikstra(get_pos_by_pos(0,0));
}

void order(){
    for (int x = 0;x < chances_ganadora.size();x++){
        for (int y = 0;y < chances_ganadora.size();y++){
            if (x != y){
                if (chances_ganadora[x]->x < chances_ganadora[y]->x or (chances_ganadora[x]->x == chances_ganadora[y]->x and chances_ganadora[x]->y < chances_ganadora[y]->y)){
                    pos* parcial = chances_ganadora[x];
                    chances_ganadora[x] = chances_ganadora[y];
                    chances_ganadora[y] = parcial;
                }
            }
        }
    }
}
int main(){
    valor_ganador = -1;
    read();
    calcular_nodos();
    calcular_fronteras();
    for (int x = 0;x < V;x++){
        for (int y = 0;y < H;y++){
            djikstra(get_pos_by_pos(x,y));
        }
    }
/*    chances_ganadora.push_back(new pos(3,2,false));
    chances_ganadora.push_back(new pos(5,5,false));
    chances_ganadora.push_back(new pos(4,2,false));
    chances_ganadora.push_back(new pos(4,5,false));
    chances_ganadora.push_back(new pos(4,6,false));
    chances_ganadora.push_back(new pos(4,8,false));
    chances_ganadora.push_back(new pos(7,4,false));
*/
    order();
    ofstream file2 ("compra.out");

    for (int x = 0;x < chances_ganadora.size();x++){
        file2<<chances_ganadora[x]->x<<" "<<chances_ganadora[x]->y;
        if (x != chances_ganadora.size()-1){
            file2<<endl;
        }
    }

    /*for (int x = 0;x < nodos.size();x++){
        cout<<nodos[x]->x<<" "<<nodos[x]->y<<" "<<nodos[x]->fronteras.size()<<endl;
    }*/
}
