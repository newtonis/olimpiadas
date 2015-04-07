#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#define forn(a,b) for((a)=0; (a)<(b); ++(a))
#define forr(a,c,b) for((a)=(c); (a)<=(b); ++(a))
using namespace std;
const int maxc = 400010;
const int maxv = 100010;

ifstream fin("compra.in");
ofstream fout("compra.out");

struct casa{
    casa(){}
    casa(int a, int b) : x(a), y(b) {}
    int x, y;
};

int W, H, C, D = (1<<26);
casa A[maxc];
vector<casa> R;

int distancia(casa a, casa b){
    int x = b.x - a.x;
    if( x < 0 ) x = -x;
    int y = b.y - a.y;
    if( y < 0 ) y = -y;
    return x+y;
}

int main(){
    int i, e, j;

    fin>>H>>W>>C;
    forn(i, C)
        fin>>A[i].x>>A[i].y;

    forn(i, W)
        forn(e, H){
            int S = 0;
            forn(j, C)
                S = max ( S,  distancia(casa(i,e), A[j]) );
            if( S < D ){
                D = S;
                R.clear();
                R.push_back(casa(i,e));
            }else if( S == D ) R.push_back(casa(i,e));
        }

    forn(i, R.size())
        cout<<R[i].x<<' '<<R[i].y<<endl;

    return 0;
}
