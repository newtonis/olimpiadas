#include <iostream>
#include <fstream>
#define forn(a,b) for((a)=0; (a)<(b); ++(a))
#define forr(a,c,b) for((a)=(c); (a)<=(b); ++(a))
using namespace std;
const int maxn = 1001;
const int maxl = 7;
const char *keyword = "CABALLO";

ifstream fin("caballos.in");
ofstream fout("caballos.out");

int W, H, S, M;
int dy[] = {1,2,2,1,-1,-2,-2,-1};
int dx[] = {-2,-1,1,2,2,1,-1,-2};
char T[maxn][maxn];
int DP[maxn][maxn][maxl];

bool placeable(int x, int y){
    if( 0 <= x && x < W )
        if( 0 <= y && y < H)
            return true;
    return false;
}

int encontrar(int x, int y, int level){
    if( level == maxl-1 ) return ( T[x][y] == keyword[level] );
    if( DP[x][y][level] != -1 ) return DP[x][y][level];
    int d, nx, ny, S = 0;

    if( T[x][y] == keyword[level] )
        forn(d, 8){
            nx = x + dx[d];
            ny = y + dy[d];
            if( placeable(nx,ny) )
                S+= encontrar(nx,ny,level+1) % M;
        }
    return DP[x][y][level] = S % M;
}

int main(){
    int i, e, j;

    fin>>H>>W>>M;
    forn(i,H)
        forn(e,W){
            fin>>T[e][i];
            forn(j,maxl)
                DP[e][i][j] = -1;
        }

    forn(i,H)
        forn(e,W)
            S += encontrar(e,i,0) % M;

    fout<<S%M<<endl;

    return 0;
}
