#include <iostream>
#include <vector>
#include <cmath>
#include <cstdio>
#include <iostream>
using namespace std;


struct Node{
    int sumatory;
    Node* left;
    Node* right;

    int min_index;
    int max_index;
    int lazy;
    Node(int a,int b){
        lazy = 0;
        min_index = a;
        max_index = b;
        if (a > b){ return; }
        if (a == b){
            sumatory = 0;
        }else{
            left  = new Node(Start() ,Half());
            right = new Node(Half()+1, End());
            left->sumatory + right->sumatory;
        }
    }
    int Start(){
        return min_index;
    }
    int Half(){
        return (min_index+max_index)/2;
    }
    int End(){
        return max_index;
    }
    bool Root(){
        return (min_index == max_index);
    }
    void SetValues(int Min,int Max,int v){
        if (lazy != 0){
            sumatory += lazy;
            if (not Root()){
                left->lazy += lazy;
                right->lazy += lazy;
            }
            lazy = 0;
        }


        if (max_index < min_index or max_index < Min or min_index > Max){ //out of range
            return;
        }

        /*if (Root()){
            sumatory += v;
            return;
        }*/
        if (min_index >= Min and max_index <= Max){
            sumatory += v;
            if (not Root()){
                left->lazy  += v;
                right->lazy += v;
            }
            return;
        }
        left->SetValues(Min,Max,v);
        right->SetValues(Min,Max,v);

        sumatory = left->sumatory + right->sumatory;
    }
    int GetValues(int Min,int Max){
        if (max_index < min_index or max_index < Min or min_index > Max){
            return 0;
        }
        if (lazy != 0){
            sumatory += lazy;
            if (not Root()){
                left->lazy += lazy;
                right->lazy += lazy;
            }
            lazy = 0;
        }

        if (min_index >= Min and max_index <= Max){ //enters completely
            return sumatory;
        }
        int v1 = left->GetValues(Min,Max);
        int v2 = right->GetValues(Min,Max);

        return v;
    }
    void show(){

        if (not Root()){
            left->show();
            right->show();
        }else{
            //cout<<"["<<min_index<<":"<<max_index<<"] = "<<sumatory<<endl;
        }

    }
};

Node* CreateTree(int elements){
    return new Node(0,elements*2-1);
}
void SetValues(int min_index,int max_index,long long int v,Node* root){
    root->SetValues(min_index,max_index,v);
}
void GetValues(int min_index,int max_index,Node* root){
    cout<<root->GetValues(min_index,max_index)<<endl;
}
int main(){
    freopen("input.in","r",stdin);
    int T; cin>>T;
    while (T--){
        int N,C; cin>>N>>C;
        Node* tree = CreateTree(N);
        while (C--){
            int c; cin>>c;
            if (c == 0){
                long long int p,q,v; cin>>p>>q>>v;
                SetValues(p,q,v,tree);
            }else if(c == 1){
                long long int p,q; cin>>p>>q;
                GetValues(p,q,tree);
            }
            cout<<"---------------------"<<endl;
            tree->show();
            cout<<"---------------------"<<endl;
        }
    }
}
