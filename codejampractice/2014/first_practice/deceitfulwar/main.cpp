#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void solve(int c);
void problemA(vector <double> naomi,vector <double> ken);
void problemB(vector <double> naomi,vector <double> ken);
int kenOption(double value,vector <double> ken);

bool compare(double a,double b){
    return a < b;
}
int main() {
    freopen("D-large-practice.in","r",stdin);
    freopen("output.out","w+",stdout);
    int T; cin>>T;
    for (int c = 1;c <= T;c++){
        solve(c);
    }
}
void solve(int c){
    int N; cin>>N;
    vector <double> naomi;
    vector <double> ken;
    for (int v = 0;v < N;v++){
        double n; cin>>n;
        naomi.push_back(n);
    }
    for (int v = 0;v < N;v++){
        double n; cin>>n;
        ken.push_back(n);
    }
    sort(ken.begin(),ken.end(),compare);
    sort(naomi.begin(),naomi.end(),compare);
    cout<<"Case #"<<c<<": ";
    problemB(naomi,ken);
    problemA(naomi,ken);
    cout<<endl;
}
int kenOption(double value,vector <double> ken){
    for (int x = 0;x < ken.size();x++){
        if (ken[x] > value){
            return x;
        }
    }
    return -1;
}
void problemA(vector <double> naomi,vector <double> ken){
    int score = 0;
    while (not ken.empty()){
        double elected = naomi[0]; naomi.erase(naomi.begin());
        int kenV = kenOption(elected,ken);
        if (kenV == -1){
            score += 1;
            ken.erase(ken.begin());
        }else {
            ken.erase(ken.begin() + kenV);
        }
    }
    cout<<score;
}
void problemB(vector <double> naomi,vector <double> ken){
    int score = 0;
    while (not ken.empty()){
        double elected = ken[0]; ken.erase(ken.begin());
        int naomiV = kenOption(elected,naomi);
        if (naomiV == -1){
            break;
        }else{
            naomi.erase(naomi.begin() + naomiV);
            score ++;
        }
    }
    cout<<score<<" ";
}