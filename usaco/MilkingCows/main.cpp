/*
ID: newtonis
LANG: C++
TASK: milk2
*/
#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

struct p{
    int a;
    int b;
    p(int pa,int pb){
        a = pa;
        b = pb;
    }
};

int main() {
    freopen("milk2.in","r",stdin);
    freopen("milk2.out","w+",stdout);
    int N; cin>>N;

    int times[1000000];

    int end = 0;
    int start = 10000000;
    vector <p> cases;
    for (int x = 0;x < N;x++){
        int a,b; cin>>a>>b; //start, end
        start = min(start,a);
        end = max(end,b);
        cases.push_back(p(a,b));
    }
    for (int x = start;x <= end;x++){
        times[x] = 0;
    }

    for (int c = 0;c < N;c++){
        for (int v = cases[c].a;v < cases[c].b;v++){
            times[v] = 1;
        }
    }

    int status  = 0;
    int max_yes = 0;
    int max_no  = 0;

    int current_yes = 0;
    int current_no  = 0;
    for (int x = start;x < end;x++){
        //cout<<times[x];
        if (status == 0){
            if (times[x]){
                status = 1;
                current_yes = 1;
                max_yes = max(current_yes,max_yes);
            }else{
                status = 0;
                current_no ++;
                max_no = max(current_no,max_no);
            }
        }else if (status == 1){
            if (times[x]){
                status = 1;
                current_yes ++;
                max_yes = max(current_yes,max_yes);
            }else{
                status = 0;
                current_no = 1;
                max_no = max(current_no,max_no);
            }
        }
    }
    //cout<<endl;
    cout<<max_yes<<" "<<max_no<<endl;
}