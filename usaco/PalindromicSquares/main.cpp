/*
ID: newtonis
LANG: C++
TASK: palsquare
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdio>
using namespace std;

int codes[20] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F','G','H','I','J'};



vector <char> base(int n,int b){
    vector <char> result;

    int max_power = 0;
    while (n > pow(b,max_power)){
        max_power ++;
    }
    max_power --;
    max_power = max(0,max_power);

    while (max_power >= 0){
        int value =  pow(b,max_power);
        int digit = n / value;
        n = n % value;

        result.push_back(codes[digit]);
        max_power --;
    }

    return result;
}
bool Palindrome(vector <char> n){
    for (int x = 0;x < n.size();x++){
        if (n[x] != n[n.size()-x-1]){
            return false;
        }
    }
    return true;
}
void show(vector <char> n){
    for (int x = 0;x < n.size();x++){
        cout<<n[x];
    }
}
int main() {
    //show(base(1,10));
    freopen("palsquare.in","r",stdin);
    freopen("palsquare.out","w+",stdout);

    int B; cin>>B;


    for (int n = 1;n <= 300;n++){
        int n2 = n * n;

        vector <char> a = base(n,B);
        vector <char> b = base(n2,B);

        if (Palindrome(b)){
            show(a);
            cout<<" ";
            show(b);
            cout<<endl;
        }
    }
}