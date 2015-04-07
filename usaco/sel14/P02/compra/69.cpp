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
int M,N,vecinos;
int maxX, minX,minY,maxY;
pair<int,int> casas[400000];

int probar (int x,int y)
{
   int resp = 0;
   forn(i,vecinos)
        resp=max(resp,abs( casas[i].first-x)+abs( casas[i].second-y));
    return resp;
}

int main()
{
    freopen("compra.in","r",stdin);
    freopen("compra.out","w",stdout);
    cin>>N>>M>>vecinos;
    forn(i,vecinos)
    {
        scanf("%i %i",&casas[i].first, &casas[i].second);
        maxX=max(maxX,casas[i].first);
        minX=min(minX,casas[i].first);
        maxY=max(maxY,casas[i].second);
        minY=min(minY,casas[i].second);
    }
    int difX=maxX-minX,difY=maxY-minY;
    int dx = difX/2;
    int dy = difY/2;
    vector <int> res;
    res.pb(probar(dx-1,dy-1));  //
    res.pb(probar(dx-1,dy));  //
    res.pb(probar(dx-1,dy+1)); //
    res.pb(probar(dx,dy-1)); //
    res.pb(probar(dx,dy)); //
    res.pb(probar(dx,dy+1)); //
    res.pb(probar(dx+1,dy-1)); //
    res.pb(probar(dx+1,dy)); //
    res.pb(probar(dx+1,dy+1)); //
    int minimo = MAX;
    forn(i,res.size())
     minimo=min(minimo,res[i]);
    forn(i,res.size())
        if(res[i]==minimo)
        {
            switch (i)
            {
            case 0:
            cout<<dx-1+minX<<" "<<dy-1+minY<<endl;
                break;
            case 1:
                cout<<dx-1+minX<<" "<<dy+minY<<endl;
                break;
            case 2:
                cout<<dx-1+minX<<" "<<dy+1+minY<<endl;
                break;
            case 3:
                cout<<dx+minX<<" "<<dy-1+minY<<endl;
                break;
            case 4:
                cout<<dx+minX<<" "<<dy+minY<<endl;
                break;
            case 5:
                cout<<dx+minX<<" "<<dy+1+minY<<endl;
                break;
            case 6:
                cout<<dx+1+minX<<" "<<dy-1+minY<<endl;
                break;
            case 7:
                cout<<dx+1+minX<<" "<<dy+minY<<endl;
                break;
            case 8:
                cout<<dx+1+minX<<" "<<dy+1+minY<<endl;
                break;
            }
        }
    return 0;
}
