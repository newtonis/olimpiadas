#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 1000

using namespace std;

void solve(int x);

int main() {
    freopen("input.in","r",stdin);
    int T; cin>>T;
    for (int x = 1;x <= T;x++){
        solve(x);
    }
}
struct bl{
    double value;
    int position;
    bl(double v,int p){
        value    = v;
        position = p;
    }
};
bool compare(double a,double b){
    return a < b;
}
void solve(int x){
    int N; cin>>N;

    vector <double> naomi;
    vector <double> ken;
    for (int x = 0;x < N;x++){
        double v; cin>>v; naomi.push_back(v);
    }
    for (int x = 0;x < N;x++){
        double v; cin>>v; ken.push_back(v);
    }
    sort(naomi.begin(),naomi.end(),compare);
    sort(ken.begin(),ken.end(),compare);

    int points = 0;

    for (int x = 0;x < N;x++){
        bool bad = false;
        for (int y = 0;y < ken.size();y++){
            if (ken[y] > naomi[x]){
                bad = true;
                ken.erase(ken.begin()+y);
                break;
            }
        }
        if (not bad){
            ken.erase(ken.begin()); //elimino primer valor de ken
            points ++;
        }
    }
    cout<<points<<endl;
}