#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;

int maxD[10000][10000];

const int INF=999999999;

	
void init(int v, int h){
	for(int i=0;i<v;i++){
		for(int j=0;j<h;j++){
			maxD[i][j]=-1;
		}
	}
}

int main(){
	freopen("compra.in", "r", stdin);
	freopen("compra.out", "w", stdout);
	int V, H, C;
	vector<pair<int, int> > solucion;
	vector<pair<int, int> > casas;	
	cin>>V>>H;
	cin>>C;
	init(V, H);
	pair<int, int> Nc;
	for(int i=0;i<C;i++){
		cin>>Nc.first>>Nc.second;
		casas.push_back(Nc);
	}
	int Nd;
	for(int i=0;i<V;i++){
		for(int j=0;j<H;j++){
			for(unsigned int z=0;z<casas.size();z++){
				Nd=abs(i-casas[z].first)+abs(j-casas[z].second);
				if(maxD[i][j]<Nd) maxD[i][j]=Nd;
			}
		}
	}
	int DF=INF;	
	for(int i=0;i<V;i++){
		for(int j=0;j<H;j++){
			if(maxD[i][j]<DF){
				while(!solucion.empty()){
					solucion.pop_back();
				}
				DF=maxD[i][j];
				Nc.first=i;
				Nc.second=j;
				solucion.push_back(Nc);
			} else {
				if(maxD[i][j]==DF){
					Nc.first=i;
					Nc.second=j;
					solucion.push_back(Nc);
				}
			}
		}
	}
	for(unsigned int i=0;i<solucion.size();i++){
		cout<<solucion[i].first<<" "<<solucion[i].second<<endl;
	}
	return 0;
}
