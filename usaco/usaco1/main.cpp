/*
ID:newtonis
LANG: C++
TASK: ride
*/
#include <iostream>
#include <cstdio>
using namespace std;

int main() {
    freopen("ride.in","r",stdin);
    freopen("ride.out","w+",stdout);
    string c; cin>>c;
    string g; cin>>g;

    int nc = 1,ng = 1;
    for (int x = 0;x < c.size();x++){
        nc *= c[x] - 64;
    }
    for (int x = 0;x < g.size();x++){
        ng *= g[x] - 64;
    }
    if (nc % 47 == ng % 47){
        cout<<"GO"<<endl;
    }else{
        cout<<"STAY"<<endl;
    }
    return 0;
}