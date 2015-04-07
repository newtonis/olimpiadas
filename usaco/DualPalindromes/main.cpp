/*
ID: newtonis
LANG: C++
TASK: dualpal
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
bool checkPalindromic(int number){
    int score = 0;
    for (int b = 2;b <= 10;b++){
        vector <char> n = base(number,b);
        if (Palindrome(n)){
            score ++;
            if (score >= 2){ return true; }
        }
    }
    return false;
}
int main() {
    //show(base(1,10));
    freopen("dualpal.in","r",stdin);
    freopen("dualpal.out","w+",stdout);

    int N,S; cin>>N>>S;


    int numbers = 0;
    int number = S+1;
    while (numbers < N){
        if (checkPalindromic(number)){
            cout<<number<<endl;
            numbers ++;
        }
        number ++;
    }
}