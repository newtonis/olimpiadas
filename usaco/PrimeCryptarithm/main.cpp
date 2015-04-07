/*
ID: newtonis
LANG: C++
TASK: crypt1
*/
#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

bool allowed[10];
vector <int> ns;
int solutions = 0;

void choose(vector <int> chance,int n);

int main() {
    freopen("crypt1.in","r",stdin);
    freopen("crypt1.out","w+",stdout);

    int N; cin>>N;
    for (int v = 0;v < N;v++){
        int n; cin>>n;
        ns.push_back(n);
        allowed[n] = true;
    }

    vector <int> chance;
    choose(chance , 0);
    cout<<solutions<<endl;
}

void choose(vector <int> chance,int n){
    /* if n == 0 I am selecting the first number */
    /* if n == 1 I am selecting the second number */
    /* if n == 2 I am selecting the third number */
    if (n == 5){
        //debo revisar si los ultimos numeros dan bien

        //if (allowed[chance[4] + chance[5]] )


        int acarreo;

        int d1 = chance[3]%10; acarreo = chance[3] / 10;
        int d2 = (chance[4] + chance[7] + acarreo) % 10 ; acarreo = (chance[4] + chance[7] + acarreo) / 10;
        int d3 = (chance[5] + chance[8] + acarreo) % 10 ; acarreo = (chance[5] + chance[8] + acarreo) / 10;
        int d4 = (chance[9] + acarreo);

        if (d4 >= 10){ return; }
        if (allowed[d1] and allowed[d2] and allowed[d3] and allowed[d4]){
            solutions ++;

        }
        return;
    }
    for (int v = 0;v < ns.size();v++){
        if (n == 3 or n == 4){
            int nA = ( chance[0] * ns[v]);
            int nB = ( chance[1] * ns[v]);
            int nC = ( chance[2] * ns[v]);

            int fA = nA % 10;
            int fB = (nA / 10 + nB) % 10;
            int fC = (nC + (nA / 10 + nB)/10);
            if (fC >= 10){ continue; }
            if ( (not allowed[fA]) or (not allowed[fB]) or (not allowed[fC])) {
                continue;
            }
            chance.push_back(fA);
            chance.push_back(fB);
            chance.push_back(fC);
        }

        chance.push_back(ns[v]);
        choose(chance,n+1);
        chance.erase(chance.begin()+chance.size()-1);

        if (n == 3 or n == 4){
            chance.erase(chance.begin()+chance.size()-1);
            chance.erase(chance.begin()+chance.size()-1);
            chance.erase(chance.begin()+chance.size()-1);
        }
    }
}