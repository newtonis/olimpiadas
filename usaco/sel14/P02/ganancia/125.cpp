#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>

#define forn(i,n) for(int i = 0; i<(int) n; i++)
#define forn1(i,n) for(int i = 1; i<=(int) n; i++)
#define forns(i,n,s) for(int i = s; i<(int) n; i++)
#define MAX 2000000000
#define mp make_pair
#define pb push_back

using namespace std;
int n;
struct est
{
    int dias,precio,gana;
}root,autos [50];

bool comp(est a, est es)
{
    if(a.precio > es.precio) return true;
    if(a.precio< es.precio) return false;
    if(a.dias < es.dias) return true;
    if(a.dias >es.dias) return false;
    return false;
}
long long g=0;
int usado[50], ma[50][50];
long long dp(int no,int pos,int dias)
{
    if(pos==n-1) return 0;
    if(usado[no])return MAX;
    //if(ma[no][pos]!=MAX) return ma[no][pos];
    long long aux=MAX;
    usado[no]=1;
    long long usandote=0;
            forn(j,n)
              if(!usado[j])
                usandote+=(dias*autos[j].precio);

    for(int i  = 0; i <n; i++)
        if(!usado[i])
        {
            aux = min (aux,dp(i,pos+1,autos[i].dias)+usandote);
        }
    usado[no]=0;
    return ma[no][pos]=aux;
}

int main()
{
    freopen("ganancia.in","r",stdin);
	freopen("ganancia.out","w",stdout);
    cin>>n;
    forn(i,n)
        scanf("%i %i %i",&root.dias,&root.precio,&root.gana),autos[i]=root,g+=root.gana;
    forn(i,50)
      forn(j,50)
       ma[i][j]=MAX;
  //  sort(autos,autos+n,comp);
    forn(i,n)
      cout<<autos[i].precio<<" "<<autos[i].dias<<" "<<autos[i].gana<<endl;
    long long res = MAX;
    forn(i,n)
        res = min (res,dp(i,0,autos[i].dias));
    cout<<g-res<<endl;
   /* int diastrans = autos[0].dias;
    forn1(i,n-1)
      g-=(autos[i].precio*diastrans),diastrans+=autos[i].dias;
    cout<<g<<endl;*/
    return 0;
}
