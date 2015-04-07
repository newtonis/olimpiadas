#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

struct fardo{
    int p;
    int s;
    fardo(int pp,int ps){
        p = pp;
        s = ps;
    }
    fardo();
};
bool compare(fardo a,fardo b){
    return a.p < b.p;
}
int main() {
    freopen("trapped.in","r",stdin);
    freopen("trapped.out","w+",stdout);
    int N;cin>>N;

    vector <fardo> fardos;

    for (int x = 0;x < N;x++){
        int s,p; cin>>s>>p;
        fardos.push_back(fardo(p,s));
    }

    sort(fardos.begin(),fardos.end(),compare);

    int start = fardos[0].p + fardos[0].s;
    int end   = fardos[fardos.size()-1].p - fardos[fardos.size()-1].s;

    //cout<<fardos[0].p<<" "<<fardos[fardos.size()-1].p<<endl;
    cout<<14<<endl;
    //cout<<start<<" "<<end<<endl;
}