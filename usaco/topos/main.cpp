#include <iostream>
#include <vector>
#include <string>

#define MAX 600000

using namespace std;

char hoyos[MAX];
vector <int> hijos[MAX];
int amount;
int zz;

void analisis(int hoyo , string line , int *index);
void AddHoyo(char letra);
void ShowHoyo(int numero);
void ShowPower(int padre,int numero);

int main() {
    freopen("input.in","r",stdin);

    amount = 0;

    string line; cin>>line;
    AddHoyo(line[0]);

    int index = 2;

    analisis(0 , line , &index);

    //for (int x = 0;x < amount;x++){
     //   ShowHoyo(x);
    //}
    //cout<<"---"<<endl;
    cout<<"Z:(";
    ShowPower(zz,hijos[zz][0]);
    cout<<")";

    //while (0);
    cout<<endl;
}

void analisis(int hoyo, string line , int *index){

    bool continuar = true;
    while (continuar and (*index) < line.size()) {
        if (line[*index] != '(' and line[*index] != ')') {
            AddHoyo(line[*index]);
            hijos[hoyo].push_back(amount - 1);
            hijos[amount-1].push_back(hoyo);
        } else if (line[*index] == ')') {
            continuar = false;
        } else if (line[*index] == '('){
            AddHoyo('-');
            hijos[hoyo].push_back(amount - 1);
            hijos[amount-1].push_back(hoyo);

            (*index)++;
            analisis(amount - 1, line, index);
            (*index)--;
        }
        (*index)++;
    }

}

void AddHoyo(char letra){
    //cout<<amount<<":"<<letra<<endl;
    if (letra == 'Z'){
        zz = amount;
    }
    hoyos[amount] = letra;
    amount ++;
}
void ShowHoyo(int numero){
    cout<<numero<<": ";
    for (int h = 0;h < hijos[numero].size();h++){
        cout<<hijos[numero][h]<<" ";
    }
    cout<<endl;
}
void ShowPower(int padre, int numero){
    //cout<<padre<<":"<<numero<<endl;
    int h = 0;
    while (hijos[numero][h] != padre){ h ++; }
    h ++;
    if (h >= hijos[numero].size()){
        h = 0;
    }
    while (not (hijos[numero][h] == padre)){
        if (hoyos[hijos[numero][h]] == '-') {
            //cout<<"N "<<numero<<" ("<<h<<") hijo "<<hijos[numero][h]<<" es linea "<<endl;
            cout<<"(";
            ShowPower(numero,hijos[numero][h]);
            cout<<")";
        }else{
            cout<<hoyos[hijos[numero][h]];
            //cout<<"N "<<numero<<" ("<<h<<") hijo: "<<hijos[numero][h]<<endl;
        }

        h ++;
        if (h >= hijos[numero].size()){
            h = 0;
        }
    }
}