/*
ID: newtonis
LANG: C++
TASK: gift1
*/
#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
using namespace std;

int main() {
    freopen("gift1.in","r",stdin);
    freopen("gift1.out","w+",stdout);

    map <string , int > money;
    vector <string> opeople; //people order
    int NP; cin>>NP;
    for (int x = 0;x < NP;x++){
        string person; cin>>person;
        money[person] = 0;
        opeople.push_back(person);
    }
    for (int x = 0;x < NP;x++){
        string person; cin>>person;
        int m,ap; cin>>m>>ap; //money, amount persons
        if (ap == 0){ continue; }
        money[person] -= m ;
        money[person] += m % ap;

        int mpp = m / ap; //money per person

        for (int y = 0;y < ap;y++){
            string rec; cin>>rec; //receipient of gift

            money[rec] += mpp;
        }
    }
    for (int x = 0;x < NP;x++){
        cout<<opeople[x]<<" "<<money[opeople[x]]<<endl;
    }
}