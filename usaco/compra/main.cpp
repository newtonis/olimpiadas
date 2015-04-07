#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#define MAX_CASAS 400000
using namespace std;

typedef unsigned int ui;

string its(int v){
    stringstream ss;
    ss << v;
    return ss.str();
}
struct pnt{
    int x;
    int y;
    pnt(int px,int py){
        x = px;
        y = py;
    }
    pnt();
    string show(){
        return "x="+its(x)+" y="+its(y) + " A=" + its(x+y) + " B=" + its(y-x) + "   ";
    }
};
bool compare(pnt a,pnt b){
    if (a.x > b.x){
        return false;
    }else if(a.x < b.x){
        return true;
    }else{
        return (a.y < b.y);
    }
}
int main() {
    freopen("input.in","r",stdin);

    ui V,H,C; cin>>V>>H>>C; //vertical , horizontal , casas

    int xs[MAX_CASAS];
    int ys[MAX_CASAS];

    const int INF = 1000000000;
    int maxcA  = -INF , mincA =  INF , maxcB  = -INF, mincB  = INF;

    for (int c = 0;c < C;c++){
        cin>>xs[c]>>ys[c];

        int a = (xs[c] + ys[c]);
        int b = (ys[c] - xs[c]);

        maxcA = max(a,maxcA);
        maxcB = max(b,maxcB);
        mincA = min(a,mincA);
        mincB = min(b,mincB);
    }

    int sizeA = maxcA - mincA;
    int sizeB = maxcB - mincB;

    int rectD = (max(sizeA,sizeB) + 1) / 2;

    int minA = maxcA - rectD;
    int minB = maxcB - rectD;
    int maxA = mincA + rectD;
    int maxB = mincB + rectD;

    if (minA == maxA and minB == maxB and minA + minB % 2 == 0){
        minA --;
        maxA ++;
        minB --;
        maxB ++;
    }

    vector <pnt> solution;

    for (int lA = minA;lA <= maxA;lA ++){
        for (int lB = minB;lB <= maxB;lB ++){
            if ((lA + lB) % 2 == 0){
                int x = ( lA - lB ) / 2;
                int y = lB + x;

                solution.push_back(pnt(x,y));
            }
        }
    }
    sort(solution.begin(),solution.end(),compare);

    for (int v = 0;v < solution.size();v++){
        cout<<solution[v].x<<" "<<solution[v].y<<endl;
    }
}
