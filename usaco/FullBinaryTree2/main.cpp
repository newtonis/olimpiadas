#include <iostream>
#include <vector>
using namespace std;

#define MAX 1001

//void Dfs(int padre,int nodo,vector <int> *ma);

int main() {
    freopen("B-small-practice.in","r",stdin);
    freopen("output.out","w+",stdout);
    int T; cin>>T;
    for (int x = 1;x <= T;x++){
        cout<<"Case #"<<x<<": ";
        vector <int> ma[MAX];

        int N; cin>>N;
        for (int y = 0;y < N-1;y++){
            int a,b; cin>>a>>b;
            ma[a].push_back(b);
            ma[b].push_back(a);
        }
        //Dfs(-1,1,ma);
        int raiz = 0;
        int unio = 0;
        int bord = 0;

        for (int n = 1;n <= N;n++){
            if (ma[n].size() == 1){
                bord += 1;
            }else if(ma[n].size() == 2){
                raiz += 1;
            }else if(ma[n].size() > 2){
                unio += 1;
            }
        }
        //cout<<bord<<" "<<raiz<<" "<<unio<<endl;
        int amount = 0;

        amount += raiz - 1;
        amount += abs( bord - unio  - 2);
        if (amount < 0) {
            cout<<"1"<<endl;
        }else {
            cout << amount << endl;
        }
        //cout<<raiz<<" "<<bord<<" "<<unio<<endl;
    }
};

/*void Dfs(int padre,int nodo,vector <int> *ma){
    cout<<"Ejecutando DFS con el nodo "<<nodo<<" de padre "<<padre<<endl;
    if (ma[nodo].size() == 1){
        cout<<"Borde"<<endl;
    }else if(ma[nodo].size() == 2){
        cout<<"Raiz"<<endl;
    }else if(ma[nodo].size() >= 3){
        cout<<"Union"<<endl;
    }
    for (int h = 0;h < ma[nodo].size();h++){
        if (ma[nodo][h] != padre){
            Dfs(nodo,ma[nodo][h],ma);
        }
    }
}*/