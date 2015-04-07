#include <fstream>
#include <queue>
#define MAX_VH 1000

using namespace std;

struct Vertex{
    int h,v;
};

struct Calle{
    bool sentido;
    short riesgo;
};

Calle CV[MAX_VH];
Calle CH[MAX_VH];

struct Esquina{
    int r;
    char type;
};

int V,H,v1,h1,v2,h2;
Esquina matrix[MAX_VH][MAX_VH];
queue<Vertex> toVisit;



void readInput(const char* fileName);
void algorithm();
void visit(int h, int v, Vertex&);
void writeOutput(const char* fileName);

int main (){
    readInput("ciclovia.in");
    algorithm();
    writeOutput("ciclovia.out");
}

void readInput(const char* fileName){
    ifstream file(fileName);
    file>>V>>H;
    for (int i = 0; i<V; i++){
        file>>CV[i].sentido>>CV[i].riesgo;
        if (CV[i].sentido == 0)
            CV[i].sentido = 1;
    }
    for (int i = 0; i<H; i++)
        file>>CH[i].sentido>>CH[i].riesgo;

    for (int i = 0; i<V; i++)
        for(int j =0; j<H; j++)
            matrix[j][i].r=-1;

    file>>v1>>h1;
    file>>v2>>h2;
    file.close();
}

void algorithm(){
    Vertex ini = {h1-1,v1-1};
    toVisit.push(ini);
    matrix[h1-1][v1-1].r = 0;
    matrix[h1-1][v1-1].type = 0;
    while(!toVisit.empty()){
        Vertex vertex = toVisit.front();
        visit(vertex.h,vertex.v+1,vertex);
        visit(vertex.h,vertex.v-1,vertex);
        visit(vertex.h+1,vertex.v,vertex);
        visit(vertex.h-1,vertex.v,vertex);
        toVisit.pop();
    }
}

void visit(int h, int v,Vertex &from){
    if (h < 0 || v < 0 || h>=H || v>=V) return;
    int riesgo = matrix[from.h][from.v].r;
    char type = matrix[from.h][from.v].type;


    if (from.h < h){
        if (CV[from.v].sentido == 1) riesgo += CV[from.v].riesgo;
        else riesgo += CV[from.v].riesgo + 1;
        if (type == 'H')
            if (CV[from.v].sentido == 0) riesgo += 3;
        type = 'V';
    }
    else  if (from.h > h){
        if (CV[from.v].sentido == 0) riesgo += CV[from.v].riesgo;
        else riesgo += CV[from.v].riesgo + 1;
        if (type == 'H')
            if (CV[from.v].sentido == 1) riesgo += 3;
        type = 'V';
    }else  if (from.v < v){
        if (CH[from.h].sentido == 0) riesgo += CH[from.h].riesgo;
        else riesgo += CH[from.h].riesgo + 1;
        if (type =='V')
            if (CH[from.h].sentido == 1) riesgo += 3;
        type = 'H';
    }else  if (from.v > v){
        if (CH[from.h].sentido == 1) riesgo += CH[from.h].riesgo;
        else riesgo += CH[from.h].riesgo + 1;
        if (type == 'V')
            if (CH[from.h].sentido == 0) riesgo += 3;
        type = 'H';
    }

    if (riesgo < matrix[h][v].r || matrix[h][v].r==-1){
        matrix[h][v].r = riesgo;
        matrix[h][v].type = type;
        Vertex aux = {h,v};
        toVisit.push(aux);
    }
    
}

void writeOutput(const char* fileName){
    ofstream file(fileName);
    file<<matrix[h2-1][v2-1].r<<endl;
    file.close();
}
