#include "red.h"
#include "string.h"

#include <time.h>
#include <map>
#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

struct persona;

void Delay(int e){
    if (e == 0){ return; }
    for (int x = 0;x < 10;x ++){ Delay(e-1); }
}
typedef map <string,persona>::iterator ite;

string cts(char *s){
    stringstream ss;
    ss << s;
    return ss.str();
}

struct persona{
    vector <string> amigos;
    int max_nivel;
    bool visitado;
    bool solucion;
    persona(){ visitado = false; }
    void AddAmigo(string amigo){
        amigos.push_back(amigo);
        max_nivel = 0;
        solucion = false;
    }
};
bool compare(string a,string b){
    return a < b;
}
int grado(int P, char pares[60000][2][12], int * nl, char lejanos[3000][12]) {
    // Aqui debe programar la solucion al problema.
    //strcpy(lejanos[0], pares[0][0]); // Para asignar a lejanos[0] el valor pares[0][0]
    //strcpy(lejanos[1], pares[0][1]); // Para asignar a lejanos[0] el valor pares[0][1]
    clock_t tStart = clock();

    map <string , persona > personas;
    for (int p = 0;p < P;p++){
        string nombreA = cts(pares[p][0]);
        string nombreB = cts(pares[p][1]);

        map <string , persona>::iterator itA = personas.find(nombreA);
        map <string , persona>::iterator itB = personas.find(nombreB);

        if (itA == personas.end()) {
            personas[nombreA] = persona();
        }
        personas[nombreA].AddAmigo(nombreB);
        if (itB == personas.end()){
            personas[nombreB] = persona();
        }
        personas[nombreB].AddAmigo(nombreA);

    }
    /*
    for (ite i=personas.begin();i != personas.end();++i){
        cout<<"---------------------------"<<endl;
        cout<<"[Persona = "<<i->first<<"]"<<endl;
        cout<<"---------------------------"<<endl;
        cout<<"[Amigos = "<<i->second.amigos.size()<<"]"<<endl;
        for (int a = 0;a < i->second.amigos.size();a++){
            cout<<"[A"<<a+1<<" = "<<i->second.amigos[a]<<"]"<<endl;
        }
    }*/
    vector <string> solucion;

    int max_level = 0;
    bool signo = true;
    for (ite i = personas.begin();i != personas.end();++i){
        Delay(8);
        vector <string> cola[3]; cola[1].push_back(i->first);

        int level = 0;
        while (not cola[1].empty()) {
            cola[0] = cola[1];
            cola[2] = cola[1];
            cola[1].clear();
            while (not cola[0].empty()) {
                string actual = cola[0][0];
                cola[0].erase(cola[0].begin());
                personas[actual].visitado = signo;
                for (int h = 0; h < personas[actual].amigos.size(); h++) {
                    if (personas[personas[actual].amigos[h]].visitado == signo){ continue; }
                    personas[personas[actual].amigos[h]].visitado = signo;
                    cola[1].push_back(personas[actual].amigos[h]);
                }
            }
            if (cola[1].empty()){
                if (level > max_level){
                    max_level = level;
                    for (int x = 0;x < solucion.size();x++){
                        personas[solucion[x]].solucion = false;
                    }
                    solucion.clear();
                    if (not personas[i->first].solucion) {
                        solucion.push_back(i->first);
                        personas[i->first].solucion = true;
                    }
                    for (int x = 0;x < cola[2].size();x++){
                        if (not personas[cola[2][x]].solucion) {
                            solucion.push_back(cola[2][x]);
                            personas[cola[2][x]].solucion = true;
                        }
                    }
                }else if(level == max_level){
                    if (not personas[i->first].solucion) {
                        personas[i->first].solucion = true;
                        solucion.push_back(i->first);
                    }
                    for (int x = 0;x < cola[2].size();x++){
                        if (not personas[cola[2][x]].solucion) {
                            solucion.push_back(cola[2][x]);
                            personas[cola[2][x]].solucion = true;
                        }
                    }
                }
            }
            level ++;
        }
        signo = not signo;
    }
    sort(solucion.begin(),solucion.end(),compare);
    for (int x = 0;x < solucion.size();x++){
        strcpy(lejanos[x],solucion[x].c_str());
    }
    *nl = solucion.size(); // Para devolver que nl = 2

    printf("Time taken: %.3fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);

    return max_level;
}

