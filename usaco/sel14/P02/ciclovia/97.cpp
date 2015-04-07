#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <set>
#include <fstream>
#define forn(i,n) for(int i = 0; i <(int)n ; i++)
#define forn1(i,n) for(int i = 1; i <=(int)n ; i++)
#define pb push_back
#define mp make_pair
#define MAX 1000000

using namespace std;

pair <int,int> columna [1005],fila[1005];
int distancia [1005][1005];
pair <int,int> padre[1005][1005];
int C,F;
pair<int,int> inicio,fin;
int movX[4]={1,-1,0,0};
int movY[4]={0,0,1,-1};

void metodo()
{
    distancia[inicio.first][inicio.second]=0;
    set <pair<int,pair<int,int> > > conj;
    conj.insert(mp(0,inicio));
    padre[inicio.first][inicio.second]=inicio;
    while(!conj.empty())
    {
        pair<int,int> no = (*conj.begin()).second;
        conj.erase(conj.begin());
       // cout<<no.first<<" "<<no.second<<" "<<distancia[no.first][no.second]<<endl;
        pair<int,int> vecino;
        forn(i,4)
        {
            vecino = mp(no.first+movX[i], no.second+movY[i]);
            if(vecino.first >0 && vecino.second >0 && vecino.first<=F && vecino.second<=C)
            {
                int mov=0;
                bool comp=false;
                if(i<2)
                {
                    if(vecino.second != padre[no.first][no.second].second)comp=true;
                    if(columna[vecino.second].first==0 && i==1) mov++;
                    else
                        if(columna[vecino.second].first==1 && i==0) mov++;
                    if(mov==1 && comp) mov=4;
                    mov+=columna[vecino.second].second;
                }
                else
                {
                    if(vecino.first != padre[no.first][no.second].first) comp=true;
                    if(fila[vecino.first].first==0 && i == 3) mov++;
                    else
                        if(fila[vecino.first].first==1 && i == 2) mov++;
                    if(mov==1 && comp) mov=4;
                    mov+=fila[vecino.first].second;
                }
                if(distancia[vecino.first][vecino.second]>distancia[no.first][no.second]+mov)
                {
                    if(padre[vecino.first][vecino.second]!=mp(-1,-1))
                        conj.erase(mp(distancia[vecino.first][vecino.second],vecino));
                    distancia[vecino.first][vecino.second]=distancia[no.first][no.second]+mov;
                    padre[vecino.first][vecino.second]=no;
                    conj.insert(mp(distancia[vecino.first][vecino.second],vecino));
                }
            }
        }
    }
}

int main()
{
    freopen("ciclovia.in","r",stdin);
    freopen("ciclovia.out","w",stdout);

    cin>>F>>C;
    forn1(i,F)
      forn1(j,C)
      {
         distancia[i][j]=MAX;
         padre[i][j]=mp(-1,-1);
      }

    forn1(i,F)
        scanf("%i %i",&fila[i].first,&fila[i].second);
    forn1(i,C)
        scanf("%i %i",&columna[i].first,&columna[i].second);
    scanf("%i %i",&inicio.first,&inicio.second);
    scanf("%i %i",&fin.first,&fin.second);
    metodo();
    cout<<distancia[fin.first][fin.second]<<endl;
    return 0;
}

