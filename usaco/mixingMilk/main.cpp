/*
ID: newtonis
LANG: C++
TASK: milk
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

struct fm{
    int p,a;
    fm(int pp,int aa){
        p = pp;
        a = aa;
    };
    fm();
};
bool compare(fm a,fm b){
    return a.p < b.p; //MENOR A MAYOR
}
int main() {
    freopen("milk.in","r",stdin);
    freopen("milk.out","w+",stdout);

    int N,M; cin>>N>>M; //milk,farmers

    vector <fm> farmers;

    for (int m = 0;m < M;m++){
        int p,a; cin>>p>>a; //price , amount milk
        farmers.push_back( fm(p,a) );
    }

    sort(farmers.begin(),farmers.end(),compare);

    int paid = 0;

    for (int x = 0;x < farmers.size();x++){
        if (N <= farmers[x].a){
            paid += N * farmers[x].p;
            break;
        }else{
            paid += farmers[x].a * farmers[x].p;
            N -= farmers[x].a;
        }
    }
    cout<<paid<<endl;

}