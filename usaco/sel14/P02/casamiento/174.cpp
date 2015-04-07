#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <map>

#define forn(i,n) for(int i = 0; i<(int) n; i++)
#define forn1(i,n) for(int i = 1; i<=(int) n; i++)
#define forns(i,n,s) for(int i = s; i<(int) n; i++)
#define dforn(i,n) for(int i = n; i>=0; i--)
#define MAX (1<<30)
#define mp make_pair
#define pb push_back

using namespace std;

int grafo[200000][2];
int voy[200000];
int usado[200000];
int hijo[200000];
int n,m;

pair<bool,int> dfs(int no,int padre)
{
   // cout<<"EMTRE con"<<no<<" "<<padre<<endl;
    if(usado[no] && hijo[no]!=padre) {//cout<<"pase con"<<no<<" "<<padre<<endl;
        return mp(true,0);}
    else
        if(usado[no]) return mp(0,0);
    usado[no]=1;
    pair<bool,int> res =mp(0,1), par = mp(0,1);
    forn(i,voy[no])
       hijo[no]=grafo[no][i],par =dfs(grafo[no][i],no), res.second+=par.second, res.first = res.first ||  par.first;
   // cout<<no<<" "<<res<<endl;
    return res;
}
int a,b;
int main()
{
    freopen("casamiento.in","r",stdin);
	freopen("casamiento.out","w",stdout);
    cin>>n>>m;
    forn(i,m)
    {
         scanf("%i %i",&a,&b);
         grafo[a][voy[a]++]=b;
         grafo[b][voy[b]++]=a;
    }
    /*forn1(i,n)
    {
      forn(j,2)
        cout<<grafo[i][j]<<" ";
        cout<<endl;
    }*/
    int resp=0;
    forn1(i,n)
      if(!usado[i])
      {
        pair<bool,double> res = dfs(i,-1);
       // cout<<res.first<<" "<<res.second<<endl;
        if(res.second!=1)
        {
            res.second = double((res.second/2));
            if(res.first==1) res.second++;
            resp+=res.second;
        }

      }
    cout<<n-resp<<endl;

    return 0;
}
