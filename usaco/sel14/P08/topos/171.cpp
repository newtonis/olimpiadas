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
struct hoyo;

vector <hoyo*> hoy;
int index;

struct hoyo{
    string letra;
    vector <hoyo*> amigos;
    int dist;
    hoyo(){}
    hoyo(string l,int value){
        letra = l;
        dist = value;
    }
    string show(hoyo* anterior){

        string data = "";
        if (letra != "-"){
            data += letra;
        }else{

            /*while (getchar() != '\n'){}*/
           for (int x = 0;x < amigos.size();x++){
                for (int y = 0;y < amigos.size();y++){
                    if (amigos[x]->dist > amigos[y]->dist){
                        hoyo* parcial = amigos[x];
                        amigos[x] = amigos[y];
                        amigos[y] = parcial;
                    }
                }
            }

            for (int x = amigos.size()-1;x > -1;x--){
                bool mal = false;
                if (anterior == amigos[x]){
                    mal = true;
                }

                if (not mal){

                    if (amigos[x]->letra == "-"){
                        data += "("+ amigos[x]->show(this) + ")";
                    }else{
                        data += amigos[x]->show(this);
                    }
                }
            }
        }
        return data;
    }
};

vector <hoyo*> hoyos;

void pros(string line,hoyo* actual){
    /*while (cts(line[0]) == "(" and cts(line[line.size()-1]) == ")"){
        line.erase(line.begin());
        line.erase(line.begin()+line.size()-1);
    }*/

    int x_pos = 0;
    while (true){
        if (cts(line[x_pos]) != "("){
            hoyo* nuevo = new hoyo(cts(line[x_pos]),index);
            index++;
            actual->amigos.push_back(nuevo);
            nuevo->amigos.push_back(actual);
            hoyos.push_back(nuevo);
        }else{
            string texttext = "";
            int metido = 1;
            x_pos++;
            while (metido != 0){
                if (cts(line[x_pos]) == "("){
                    metido++;
                }else if(cts(line[x_pos]) == ")"){
                    metido--;
                    if (metido == 0){
                        break;
                    }
                }
                texttext += line[x_pos];
                x_pos++;
            }
            hoyo *nuevo = new hoyo("-",index);
            index++;
            pros(texttext,nuevo);
            actual->amigos.push_back(nuevo);
            nuevo->amigos.push_back(actual);
        }
        x_pos++;
        if (x_pos >= line.size()){
            break;
        }
    }
}

void solve(hoyo* primero){
    hoyo* mio;
    for (int x = 0;x < hoyos.size();x++){
        if (hoyos[x]->letra == "Z"){
            mio = hoyos[x];
        }
    }


    string data = "";

    for (int x = mio->amigos.size();x > -1;x--){
        data += mio->amigos[x]->show(mio);
    }

    /*cout<<data<<endl;*/

    ofstream file ("topos.out");
    data.erase(data.begin());
    file << "Z:("<<data<<")" << endl;
}
int main(){
    index = 0;

    ifstream in ("topos.in");
    string line;
    getline(in,line);

    hoyo *primero = new hoyo(cts(line[0]),index);
    index++;
    line.erase(line.begin());
    line.erase(line.begin());
    pros(line,primero);
    solve(primero);
    /*cout<<primero->amigos[0]->amigos[1]->amigos[0]->amigos[1]->letra<<endl;*/
}
