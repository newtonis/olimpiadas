#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>

using namespace std;

### PUNTAJE 51 / 100 ###
struct contrasenia{
    string data;
    int conflictos;
    contrasenia(string d,int c){
        data = d;
        conflictos = c;
    }
};

bool compare(contrasenia A,contrasenia B){
    return A.data.size() > B.data.size();
}
bool compare2(contrasenia A,contrasenia B){
    return A.data < B.data;
}

int C;
vector <contrasenia> contrasenias;
void read();
void solve();
bool check_equal(string a,string b);

int main(){
    read();
    solve();
}

void read(){
    freopen("alarma.in","r",stdin);
    freopen("alarma.out","w",stdout);
    cin>>C;
    for (int x = 0;x < C;x++){
        string contra; cin>>contra;
        contrasenias.push_back(contrasenia(contra,0));
    }
}
void solve(){
    sort(contrasenias.begin(),contrasenias.end(),compare);
    for (int x = 0;x < C;x++){
        for (int y = x+1;y < C;y++){
            if (check_equal(contrasenias[y].data,contrasenias[x].data)){
                contrasenias[x].conflictos++;
            }
        }
    }
    sort(contrasenias.begin(),contrasenias.end(),compare2);
    for (int x = 0;x < C;x++){
        cout<<contrasenias[x].conflictos<<" "<<contrasenias[x].data<<endl;
    }
}
bool check_equal(string a,string b){
    if (a.size() > b.size()){
        return false;
    }
    for (int x = 0;x < a.size();x++){
        if (a[x] != b[x]){
            return false;
        }
    }
    return true;
}
