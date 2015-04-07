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
int n,m,a,b;
int rival [100000][2];
int voy[100000];
int dp[100000];
int lista[100000];
int llamar(int no)
{
    if(lista[no]==1) return 0;
   // if(dp[no]!=0) return dp[no];
    int resp = -1;
    forns(i,n+1,no+1)
    {
      //  if(i==5)
       //  cout<<endl;
        forn(j,2)
          if(rival[i][j]!=0)
             lista[rival[i][j]]=1;
        resp = max(resp,llamar(i)+1);
        forn(j,2)
          if(rival[i][j]!=0)
             lista[rival[i][j]]=0;
    }
    return dp[no]=resp;
}
int main()
{
    freopen("casamiento.in","r",stdin);
	freopen("casamiento.out","w",stdout);
    cin>>n>>m;

    forn(i,m)
    {
        scanf("%i %i",&a,&b);
        rival[a][voy[a]++]=b;
        rival[b][voy[b]++]=a;

    }
    int resp=0;
    /*
    forn(i,n)
       if(voy[i]==0)
            resp++;
    */
    forn1(i,n)
    {
       forn(j,2)
          if(rival[i][j]!=0)
            lista[rival[i][j]]=1;
        resp = max ( resp, llamar(i));
       forn(j,2)
          if(rival[i][j]!=0)
            lista[rival[i][j]]=0;
    }
    cout<<resp<<endl;
    return 0;
}
/*
    forn1(i,n)
    {
        cout<<i<<" ";
        forn(j,2)
            if(rival[i][j]!=0)
                cout<<rival[i][j];
        cout<<endl;
    }
    */
