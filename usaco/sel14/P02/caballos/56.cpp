#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>

#define forn(i,n) for(int i = 0; i <(int)n ; i++)
#define pb push_back
#define mp make_pair

using namespace std;
int n,m,mod;
vector <string> mapa(1000);
string caballo = "CABALLO";
int dp [1000][1000][7];
int movX[8]={2,-2,2,-2,1,1,-1,-1};
int movY[8]={1,1,-1,-1,2,-2,2,-2};

int metodo(int x, int y,int caract)
{
  //  cout<<"ENTre con"<<x<<" "<<y<<" "<<caballo[caract]<<endl;
    if(caract==7) {return 1;}
    if(dp[x][y][caract]!=-1) return dp[x][y][caract];
    int &r = dp[x][y][caract];
    r=0;
    forn(i,8)
    {
        int a=x+movX[i],b=y+movY[i];
        if(a>=0 && b>=0 && a<n && b<m)
        {
            if(mapa[a][b]==caballo[caract])
            {
             //   cout<<" SII ";
                r+=(metodo(a,b,caract+1)%mod);
            }

        }
    }
    return r;
}

int res()
{
    int dev=0;
    forn(i,n)
      forn(j,m)
         if(mapa[i][j]=='C')
            dev+= (metodo(i,j,1)%mod),dev%=mod;
    return dev;
}


int main()
{
    freopen("caballos.in","r",stdin);
    freopen("caballos.out","w",stdout);
    cin>>n>>m>>mod;
    forn(i,n)
      forn(j,m)
        forn(k,7)
          dp[i][j][k]=-1;
    forn(i,n)
       cin>>mapa[i];

    cout<<res()%mod<<endl;
    return 0;
}
