/*
ID: newtonis
LANG: C++
TASK: beads
*/
#include <iostream>
#include <cstdio>

#define MAX 350

using namespace std;

int main() {
    freopen("beads.in","r",stdin);
    freopen("beads.out","w+",stdout);

    int N; cin>>N;
    char beds[MAX]; cin>>beds;

    /*int a = N-1;

    for (int b = 0;b < N;b++){
        if (beds[b] == 'w'){
            beds[b] = beds[a]; //if it is white, set the last color
        }
        a = b;
    }*/

    int a = N-1;
    int sol = 0;

    for (int b = 0;b < N;b++){
        if (beds[a] != beds[b]){
            int ca = beds[a]; //color a
            int cb = beds[b]; //color b
            int ia = a;
            int ib = b;
            int l = 0; //longitud
            while ((beds[ia] == ca or beds[ia] == 'w' or ca == 'w') and l < N){
                if (ca == 'w'){ ca = beds[ia]; }
                l ++;
                ia --; if (ia < 0){ ia = N-1; }
            }

            while ((beds[ib] == cb or beds[ib] == 'w' or cb == 'w') and l < N){
                if (cb == 'w'){ cb = beds[ib]; }
                l ++;
                ib ++; if (ib > N-1){ ib = 0; }
            }

            sol = max(sol,l);
        }
        a = b;
    }
    if (sol == 0){
        sol = N;
    }
    cout<<sol<<endl;
}