#include <iostream>
#include <vector>
#include <cstdio>
#include <map>
using namespace std;
#define MAX 20

int N;
int SLEN;

char mapa[MAX][MAX];
map <string,bool> values;
map <string,bool> values2;

int solutions = 0;

int mov[2][2] = {{1,0},{0,1}};

void calcule(string route,int r,int c);

int main() {
    freopen("palpath.in","r",stdin);
    freopen("palpath.out","w+",stdout);

    cin>>N;
    SLEN = N * 2 - 1; //standard len
    for (int r = 0;r < N;r++){
        cin>>mapa[r];
    }

    /*for (int r = 0;r < N;r++){
        for (int c = 0;c < N;c++){
            string route = "";
            calcule(route,r,c);
        }
    }*/
    string route = "";
    calcule(route,0,0);

    cout<<solutions<<endl;
}
bool Palindrome(string value){
    for (int x = 0;x < value.size();x++){
        if (value[x] != value[value.size()-x-1]){
            return false;
        }
    }
    return true;
}
void calcule(string route,int r,int c){
    if (r < 0 or r >= N or c < 0 or c >= N){ return; }
    route.push_back( mapa[r][c] );

    if (r == N-1 and c == N-1) {
        if (values2.find(route) == values2.end()) {
            //if (Palindrome(route)) {
            //cout<<route<<endl;
            solutions++;
            values2[route] = true;
            //}
        }

    }
    if (route.size() == N){
        if (values.find(route) == values.end()){
            values[route] = true;
        }else{
            return;
        }
    }
    for (int m = 0;m < 2;m++){
        if (route.size() >= N) {
            int nr = r + mov[m][0];
            int nc = c + mov[m][1];
            int index  = route.size();
            int indexB = SLEN - index - 1;

            if (mapa[nr][nc] != route[indexB] ){
                continue;
            }
        }

        calcule(route,r + mov[m][0],c + mov[m][1]);
    }
}