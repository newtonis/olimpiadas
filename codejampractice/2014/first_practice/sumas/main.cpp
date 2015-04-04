#include <iostream>
#include <cstdio>
#include <map>
#include <cmath>
using namespace std;

int M; //numeros
int N; //digitos

unsigned int values[1000];
unsigned int sumatorias[1000];
unsigned int target;


unsigned int ss(unsigned int a,unsigned int b){
    unsigned int solution = 0;

    for (int d = 0;d < N;d++){
        unsigned int powerA = pow(double(10),double(d+1));
        unsigned int powerB = pow(double(10),double(d));
        int D1 = (a % powerA - a % powerB) / powerB;
        int D2 = (b % powerA - b % powerB) / powerB;
        solution += (D1 + D2)%10*powerB;
    }
    return solution;
}
unsigned int inversa(unsigned int a){
    unsigned int solution = 0;
    for (int d = 0;d < N;d++){
        unsigned int powerA = pow(double(10),double(d+1));
        unsigned int powerB = pow(double(10),double(d));
        int D = (a % powerA - a % powerB) / powerB;
        solution += (10-D)*powerB;
    }
    return solution;
}

int main(){
    freopen("input.in","r",stdin);
    cin>>M; cin>>N;
    for (int x = 0;x < M;x++){
        cin>>values[x];
    }
    cin>>target;

    int sumatoria = 0;
    int sol = 0;
    unsigned int invert = inversa(target);

    for (int i = 0;i < M;i++){
        sumatoria = ss(sumatoria,values[i]);
        sumatorias[i] = sumatoria;

        for (int j = 0;j < i;j++){
            if (ss(sumatorias[i],invert) == sumatorias[j]){
                sol++;
            }
        }
    }
    cout<<sol<<endl;

}
