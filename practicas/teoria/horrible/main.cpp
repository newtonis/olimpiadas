#include <stdio.h>
#include <iostream>
#include<string.h>

using namespace std;

#define MAX 100000

int elements[MAX];
int arr[MAX];
int lazy[MAX];

void BuildTree(int node,int a,int b);
void UpdateTree(int node,int a,int b,int i,int j,int value);
int QueryTree(int node,int a,int b,int i,int j);

int main(){
    freopen("input.in","r",stdin);
    int t; scanf("%i",&t);
    while (t--){
        int N,C; scanf("%i%i",&N,&C);
        BuildTree(1,0,N-1);
        memset(lazy, 0, sizeof lazy);
        while (C--){
            int t; scanf("%i",&t);
            if (t == 0){
                int p,q,v; scanf("%i%i%i",&p,&q,&v); p--; q--;
                UpdateTree(1,0,N-1,p,q,v);
            }else if (t == 1){
                int p,q; scanf("%i%i",&p,&q); p--; q--;
                int rta = QueryTree(1,0,N-1,p,q);
                printf("%i\n",rta);
            }
        }
    }
}

void BuildTree(int node,int a,int b){
    if (a > b){ return; }
    if (a == b){
        elements[a] = arr[a];
        return;
    }
    BuildTree(node*2  ,a,(a+b)/2);
    BuildTree(node*2+1,(a+b)/2+1,b);

    elements[node] = elements[node*2] + elements[node*2+1];
}

void UpdateTree(int node,int a,int b,int i,int j,int value){
    if (lazy[node] != 0){
        elements[node] += lazy[node];
        if (a != b){
            elements[node*2]   += lazy[node];
            elements[node*2+1] += lazy[node];
        }
        lazy[node] = 0;
    }
    if (a > b or a > j or b < i){
        return;
    }
    if (a >= i and b <= j){
        elements[node] = value;
        if (a != b){
            lazy[node*2]  += value;
            lazy[node*2+1] += value;
        }
        return;
    }
    UpdateTree(node*2,a,(a+b)/2,i,j,value);
    UpdateTree(node*2+1,(a+b)/2+1,b,i,j,value);
    elements[node] = elements[node*2] + elements[node*2+1];
}

int QueryTree(int node,int a,int b,int i,int j){
    if (a > b or a > j or b < i){
        return 0;
    }
    if (lazy[node] != 0){
        elements[node] += lazy[node];
        if (a != b){
            lazy[node*2]  += lazy[node];
            lazy[node*2+1] += lazy[node];
        }
        lazy[node] = 0;
    }

    if (a >= i and b <= j){
        return elements[node];
    }

    int r1 = QueryTree(node*2,a,(a+b)/2,i,j);
    int r2 = QueryTree(node*2+1,(a+b)/2+1,b,i,j);
    return r1+r2;
}

