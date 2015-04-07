#include <iostream>
#include <vector>
#include <cstdio>
#define MAX 50
using namespace std;

int moves[8][2] = { {1,1} ,{-1,1}, {1,-1},{-1,-1},{1,0},{-1,0},{0,1},{0,-1} };

char table[MAX][MAX];
int N,M;

int result[26][26];
int best_result = 0;

int search();
void two_equal(char letter,int r,int c,int move);

int main() {
    freopen("moocrypt.in","r",stdin);
    freopen("moocrypt.out","w+",stdout);
    cin>>N>>M;

    /*for (int l = 0;l < 26;l++){
        for (int l2 = 0;l2 < 26;l2++){
            result[l][l2] = 0;
        }
    }*/
    for (int r = 0;r < N;r++){
        cin>>table[r];
    }


    for (int r = 0;r < N;r++){
        for (int c = 0;c < M;c++){
            char value = table[r][c];
            for (int m = 0;m < 8;m++) {
                two_equal(value,r, c, m);
            }
        }
    }
    cout<<best_result<<endl;
}

void two_equal(char lA,int r,int c,int move){
    if (lA == 'M'){ return; }
    r += moves[move][0];
    c += moves[move][1];

    if (r < 0 or r >= N or c < 0 or c >= M){ return; }

    char lB = table[r][c];
    if (lB == lA){ return; }
    if (lB == 'O'){ return; }

    r += moves[move][0];
    c += moves[move][1];

    if (r < 0 or r >= N or c < 0 or c >= M){ return; }

    if (table[r][c] == lB){
        result[lA-65][lB-65] ++;
        best_result = max(best_result,result[lA-65][lB-65]);
    }
}