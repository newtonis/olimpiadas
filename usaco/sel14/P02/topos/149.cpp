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
string a;
int vec [600000];
int abierto[600000];
int contador=0;
int vecino[600000][4];
int voy[600000];
char corresponde[600000];
int visitado[600000];
int ubic;
string res="";
void dfs(int no,int padre)
{
    if(visitado[no]) return ;
    visitado[no]=1;
    res+=corresponde[no];
    if(res[res.size()-1]>='A' && res[res.size()-1]<='Z' && res[res.size()-2]>='A' && res[res.size()-2]<='Z')
      swap(res[res.size()-1],res[res.size()-2]);
    if(no==ubic)res+=":";
    dforn(i,voy[no]-1)
        dfs(vecino[no][i],no);
    if(voy[no]==1 && padre == vecino[no][voy[no]-1]);
    else
        if(no!=ubic)
        res+=")";
}

int main()
{
    freopen("topos.in","r",stdin);
    freopen("topos.out","w",stdout);
    cin>>a;
    abierto[0]=1;
    int ay=1, no=1;

    forn(i,a.size())
    {
         if(a[i]!=')' && a[i]!=':')
            vec[i]=no++,corresponde[no-1]=a[i];
        if(a[i]=='Z')ubic = vec[i];
         if(i>=2)
         {
             if(a[i]=='(')
                 abierto[ay++]=vec[i];
            else
            {
                if(a[i]==')')
                {
                    vecino[ abierto[ay-1] ] [voy [ abierto[ay-1] ] ++] = abierto[ay-2];
                    vecino[  abierto[ay-2] ] [voy [ abierto[ay-2] ] ++] = abierto[ay-1];
                    ay--;
                }
                else
                {
                    vecino[ abierto[ay-1] ] [ voy[abierto[ay-1]]++ ] = vec[i];
                    vecino[vec[i]] [voy[vec[i]]++] = abierto[ay-1];
                }
            }
         }
    }
    dfs(ubic,-1), cout<<res<<endl;
    /*forn1(i,no+1)
    {
        //cout<<a[i]<<" ";
        forn(j,3)
           cout<<vecino[i][j]<<" ";
        cout<<endl;
    }*/


    return 0;
}
