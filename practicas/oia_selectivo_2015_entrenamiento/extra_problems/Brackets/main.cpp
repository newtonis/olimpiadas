#include <iostream>
#include <ios>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

typedef unsigned int ui;

#define MAX 65537 //2^16, enough space to handle 30000 nodes in the base of the segtree (a total of 65536 nodes with root node as 1, and 32768 nodes space in the base)

char word[30000]; //our word with max len 30000
ui close[MAX]; //how many close brackets has a node that need to be opened in their left nodes (NOT the total closing brackets! only the ones are not auto-cancelled in the node)
ui open[MAX]; //how many open brackets has a node that need to be closed in their right nodes (NOT the total open brackets! only the ones are not auto-cancelled in the node)

void Create(ui N,ui S,ui E); //create a segtree starting in node N that covers range of word indexes S to E including both
void Query(ui N,ui S,ui E,ui V); //query change in the node with node N as root
//void Debug(ui values);

int main(){
    ios::sync_with_stdio(false);
    ui casos = 10;

    #ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
    casos = 1;
    #endif


    for (ui t = 0;t < casos;t++){
        cout<<"Test "<<t+1<<":"<<endl;
        ui len; cin>>len;
        cin>>word;

        Create(1,0,len-1);
        ui mod; cin>>mod;
        while (mod --){
            ui vv; cin>>vv;
            if (vv == 0){
                if (open[1] == 0 and close[1] == 0){
                    cout<<"YES"<<endl;
                }else{
                    cout<<"NO"<<endl;
                }
            }else{
                Query(1,0,len-1,vv-1);
            }
        }
    }
}

void Create(ui N,ui S,ui E){ //nodo , start , end
    if (S == E){
        if (word[S] == '('){
            open[N] = 1;
            close[N] = 0;
        }else if(word[S] == ')'){
            open[N] = 0;
            close[N] = 1;
        }
        return;
    }

    Create(N*2  , S , (S+E)/2 );
    Create(N*2+1, (S+E)/2 + 1, E);


    int mid_value =  open[N*2] - close[N*2+1];

    ui add_w_right;
    ui add_w_left;
    if (mid_value > 0){
        add_w_right = abs(mid_value);
        add_w_left = 0;
    }else if (mid_value < 0){
        add_w_left = abs(mid_value);
        add_w_right = 0;
    }else{
        add_w_left = 0;
        add_w_right = 0;
    }

    close[N] = close[N*2] + add_w_left;
    open[N] = open[N*2+1] + add_w_right;

}

void Query(ui N,ui S,ui E,ui V){
    if (S == E && V == S){
        if (word[S] == '('){
            word[S] = ')';
            close[N] = 1;
            open[N] = 0;
        }else if(word[S] == ')'){
            word[S] = '(';
            close[N] = 0;
            open[N] = 1;
        }
        return;
    }
    if(V <= (S+E)/2){
        Query(N*2,S,(S+E)/2,V);
    }else{
        Query(N*2+1,(S+E)/2+1,E,V);
    }

    int mid_value =  open[N*2] - close[N*2+1];

    ui add_w_right;
    ui add_w_left;
    if (mid_value > 0){
        add_w_right = abs(mid_value);
        add_w_left = 0;
    }else if (mid_value < 0){
        add_w_left = abs(-mid_value);
        add_w_right = 0;
    }else{
        add_w_left = 0;
        add_w_right = 0;
    }

    close[N] = close[N*2] + add_w_left;
    open[N] = open[N*2+1] + add_w_right;

}

/*void Debug(ui values){
    for (int x = 0;x < values*2;x++){
        cout<<x<<":"<<cierra[x]<<" "<<abre[x]<<endl;
    }
}*/
