/*
ID: newtonis
LANG: C++
TASK: namenum
*/
#include <iostream>
#include <vector>
#include <fstream>
#include <map>
using namespace std;


int letters[8][3] = {
        {'A','B','C'},
        {'D','E','F'},
        {'G','H','I'},
        {'J','K','L'},
        {'M','N','O'},
        {'P','R','S'},
        {'T','U','V'},
        {'W','X','Y'}
};

int main() {
    freopen("namenum.in","r",stdin);
    freopen("namenum.out","w+",stdout);
    ifstream file;
    file.open("dict.txt");

    string option;
    map <string,bool> dict;
    while (file>>option){
        dict[option] = true;
    }
    string name;
    cin>>name;

    vector < string > chances;
    vector < string > lchances;
    string current;

    for (int n = 0;n < name.size();n++){
        char letter = name[n];
        int value = atoi(&letter) - 2;

        for (int x = 0;x < lchances.size();x++) {
            for (int l = 0; l < 3; l++) {
                current = lchances[x];
                current += letters[value][l];
                if (n != name.size()-1) {
                    chances.push_back(current);
                }else{
                    if (dict.find(current) != dict.end()){
                        chances.push_back(current);
                    }
                }
            }
        }
        if (lchances.size() == 0){
            for (int l = 0;l < 3;l++){
                current = "";
                current += letters[value][l];
                chances.push_back(current);
            }
        }

        lchances = chances;
        chances.clear();
    }

    for (int x = 0;x < lchances.size();x++){
        cout<<lchances[x]<<endl;
    }
    if (lchances.size() == 0){
        cout<<"NONE"<<endl;
    }
}