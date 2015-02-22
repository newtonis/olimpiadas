#include <iostream>
#include <cstdio>
#include <ios>

/// http://www.spoj.com/problems/HORRIBLE/ ///

#define MAX 262145 //2^18, because the max amount is 262145 nodes with 100000 nodes in the base of the segtree
using namespace std;

typedef unsigned long ul;
typedef unsigned long long ull;

ull node[MAX]; //node real values array
ull lazy[MAX]; //node values not executed yet

void Create(ul id,ul a,ul b);
void Whiten(ul id,ul A,ul B);
void Update(ul L,ul a,ul b,ul tA,ul tB,ull v);
ull Query(ul id,ul A,ul B,ul tA,ul tB);
void Debug(ul a,ul b);

int main(){
    ios::sync_with_stdio(false); //to make cin, cout as fast as scanf and printf
    #ifndef ONLINE_JUDGE //if we are in spoj
    freopen("input.in","r",stdin);
    #endif
    ul T; cin>>T; //amount of cases
    while (T--){
        ul N,C; cin>>N>>C; //N=number of nodes,C=number of operations to the segtree of N nodes in the base
        Create(1,0,N-1); //create the segtree starting with node 1 as root, for an array that starts in 0 and ends in N-1 (will have N*2-1 nodes)
        //segtree image: http://4.bp.blogspot.com/-PMj9D5evM7M/UNUztCKI2SI/AAAAAAAAAiw/66Gnh2eHIW4/s1600/segtree.png
        while (C--){ //while there are commands left
            int T; cin>>T; //type of command
            if (T == 0){ //if we have write command
                ul p,q,v; cin>>p>>q>>v; p--; q--; //get start index, end index, and values to set within that range that includes both the start and end
                Update(1,0,N-1,p,q,v); //execute te function that add these values to the segtree
            }else if(T == 1){ //if we have read command
                ul p,q; cin>>p>>q; p--; q--; //get the start index and end index of the sumatory range we want to get
                cout<<Query(1,0,N-1,p,q)<<endl; //execute the query to get that value and show it
            }
        }
    }

}

void Create(ul id,ul A,ul B){
    //The most important rule of the segtree is that the value of each node is
    //*** If the node has A==B and the node has not any child the node reflects a real array position so its value is the position of the A=B position of the array
    //*** If not, the value of a node is, by definition, the sumatory of all their childs

    //id is the current node id
    //A is the start index that our node covers, and B is the end index that our node covers. Both of the included

    node[id] = 0; //set our node sumatory 0
    lazy[id] = 0; //set our node sumatory that we hadn't done and we must do in the future to 0
    if (A != B){ //if our start and end indexes are not equal it means the node is not a final child of the segtree, it points to more values
        //creating my 2 child, by general rule, the two childs of each node (if that node is not on the base), will have the id of the node duplicated and the id of the node duplicated *plus* 1
        Create(id*2,A,(A+B)/2);
        //create a new node that starts in my start index and ends in the half between start index and end index
        Create(id*2+1,(A+B)/2+1,B);
        //the same but starting in mthe half between my start index and my end index and ending at my end index
    }
}
void Whiten(ul id,ul A,ul B){ //means that we must update the node with that id that is in the range A,B
    if (lazy[id] == 0){ return; } //if we don't need to update
    node[id] += lazy[id]*(B-A+1); //we sum my lazy value that I left for the future multiplied by the amount of nodes that are in my range, because all of them will be added my lazy value
    if (A != B){ //if I am not in the base of the segtree
        lazy[id*2] += lazy[id]; //I pass my lazy value to both of my childs, because they probably will need to do the operation in the future
        lazy[id*2+1] += lazy[id];
    }
    lazy[id] = 0; //I have already updated my sumatory
}
void Update(ul id,ul A,ul B ,ul tA,ul tB,ull v){
    //id is the node reference that is in the range A,B while tA and tB are the target range we want to increase in the array. V is the value we want to add to every node in the tA,tB range

    if (tA > B or A > tB){ //out of range, it means that the range of the node does not matches with the target range
        return;
    }

    if (tA <= A and B <= tB){ //if the range of the node (A,B) is TOTALLY included in the target range tA,tB
        node[id] += v *(B-A+1); //easy, if all my nodes are included my sumatory must be incresed by the amount of nodes I have multiplied by the value each node will be increased
        if (A != B){ //if we are not in the base of the segtree and we have childs
            lazy[id*2]   += v; //as we want to increase performance we don't update our childs, we only tell them they must be updated in the future
            lazy[id*2+1] += v;
        }
        return;
    }
    //if A,B range is partially included in the target range tA,tB (not TOTALLY, not OUT of range)  this lines will run. As we can not do lazy propagation we update our two childs

    Update(id*2  ,A,(A+B)/2,tA,tB,v); //we update my child that has array range my start to the half
    Update(id*2+1,(A+B)/2+1,B,tA,tB,v); //we update my child that has array range the half to my end
    node[id] += v*((min(B,tB)-max(A,tA))+1); //my value will be increased in the amount of nodes that are in my range that are also in the target range multiplied to the value that will be added to each node
}
ull Query(ul id,ul A,ul B,ul tA,ul tB){
    //It is requested the value of the node id, that covers the array range A,B in the range tA,tB. If the range is wider than the node or covers partially the node we return the value of the range tA,tB THAT IS covered in the node of range A,B

    Whiten(id,A,B); //we call to update the node value id with A,B range
    if (tA > B or A > tB){ //out of range, it means that the range of the node does not matches with the target range
        return 0;
    }
    if (tA <= A and B <= tB){ //if the range of the node (A,B) is TOTALLY included in the target range tA,tB
        return node[id]; //we don't need to do anything more we have the value that is requested stored in the node
    }
    //we don't need to check if we are in the base of the segtree because if we are that, the totally included statement will be executed

    //so if the tA,tB is partially included in the range tA,tB, that also means we are not in the base of the segtree we query the two childs I have
    ull q1 = Query(id*2  ,A,(A+B)/2,tA,tB); //the child from my range start to my range half
    ull q2 = Query(id*2+1,(A+B)/2+1,B,tA,tB); //the child from my range half to my range end
    return q1 + q2; //return the sumatory of my two childs
}

