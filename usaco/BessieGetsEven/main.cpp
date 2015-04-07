#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int l[7] = {'B','E','S','I','G','O','M'};
vector <int> chances[7];

int solutions = 0;
void recu(int l,vector <int> actual);

int main() {
    //ios::sync_with_stdio(false);
    freopen("geteven.in","r",stdin);
    freopen("geteven.out","w+",stdout);
    int N; cin>>N;


    for (int x = 0;x < N;x++){
        char var; cin>>var;
        int value; cin>>value;

        if (var == 'B') {
            chances[0].push_back(value);
        }
        if (var == 'E') {
            chances[1].push_back(value);
        }
        if (var == 'S') {
            chances[2].push_back(value);
        }
        if (var == 'I') {
            chances[3].push_back(value);
        }
        if (var == 'G') {
            chances[4].push_back(value);
        }
        if (var == 'O') {
            chances[5].push_back(value);
        }
        if (var == 'M') {
            chances[6].push_back(value);
        }
    }


    int total_pos = chances[0].size() * chances[1].size() * chances[2].size() * chances[3].size() * chances[4].size() * chances[5].size() * chances[6].size();
/*

    vector < vector <int> > pos; //una secuencia de enteros demostrando las elecciones que hicimos. Un valor para cada letra

    for (int v = 0;v < chances[0].size();v++){
        vector <int> ch; ch.push_back( chances[0][v] );
        pos.push_back( ch );
    }

    int solutions = 0;

    vector <vector <int> > npos;

    for (int l = 1;l < 7;l++){ //por cada letra

        for (int p = 0;p < pos.size();p++) { //por cada chance

            for (int c = 0; c < chances[l].size(); c++) {
                vector <int> actual = pos[p];
                actual.push_back(chances[l][c]);
                if (l == 3){
                    int t1 = actual[0] + actual[1]*2 + actual[2]*2 + actual[3];
                    if (t1 % 2 == 0){
                        continue;
                    }
                }
                if (l == 5){
                    int t2 = actual[4] + actual[5] + actual[1] + actual[2];
                    if (t2 % 2 == 0){
                        continue;
                    }
                }
                if (l == 6){
                    int t1 = actual[0] + actual[1]*2 + actual[2]*2 + actual[3];
                    int t2 = actual[4] + actual[5] + actual[1] + actual[2];
                    int t3 = actual[6] + actual[5]*2;
                    if ((t1 * t2 * t3) % 2 != 0) {
                        solutions++;
                    }
                }else {
                    npos.push_back(actual);
                }
            }
        }
        pos = npos;
        npos.clear();
    }
    cout<<total_pos-solutions<<endl;*/
    //recu(0,vector<int>());
    //c/out<<total_pos-solutions<<endl;
}

void recu(int l,vector <int> actual){

    if (l == 4){
        int t1 = actual[0] + actual[1]*2 + actual[2]*2 + actual[3];
        if (t1 % 2 == 0){
            return;
        }
    }
    if (l == 6){
        int t2 = actual[4] + actual[5] + actual[1] + actual[2];
        if (t2 % 2 == 0){
            return;
        }
    }
    if (l == 7){
        //int t1 = actual[0] + actual[1]*2 + actual[2]*2 + actual[3];
        //int t2 = actual[4] + actual[5] + actual[1] + actual[2];
        int t3 = actual[6] + actual[5]*2;
        if (t3 % 2 != 0){
            solutions ++;
        }
        return;
    }
    for (int x = 0;x < chances[l].size();x++){
        actual.push_back(chances[l][x]);
        recu(l+1,actual);
        actual.erase(actual.begin()+actual.size()-1);
    }
}