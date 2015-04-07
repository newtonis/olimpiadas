#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

pair<int, int> autos[51]; 

int costos[50][50];
bool visit[50];

int main(){
	freopen("ganancia.in", "r", stdin);
	freopen("ganancia.out", "w", stdout);
	for(int i=0;i<=50;i++) visit[i]=false;
	int A;
	cin>>A;
	int ganan=0, ng;
	pair<int, int> Naut;
	for(int i=0;i<A;i++){
		cin>>Naut.first;
		cin>>Naut.second;
		cin>>ng;
		ganan+=ng;
		autos[i]=Naut;
	}
	int perd=0;
	for(int i=0;i<A;i++){
		for(int j=0;j<A;j++){
			if(i==j){
				costos[i][j]=0;
			} else {
				costos[i][j]=autos[i].first*autos[j].second;
			}
		}
	}
	vector<int> c;
	vector<int> p;
	int Nc, Np;
	for(int i=0;i<A;i++){
		Np=0;
		for(int j=0;j<A;j++){
			Np+=costos[i][j];
		}
		p.push_back(Np);
	}
	for(int j=0;j<A;j++){
		Nc=0;
		for(int i=0;i<A;i++){
			Nc+=costos[i][j];
		}
		c.push_back(Nc);
	}
	for(int i=0;i<A;i++){
	int Nmax=0, borr;
		for(int j=0;j<A;j++){
			if(Nmax<c[j]){
				if(visit[j]) continue;
				Nmax=c[j];
				borr=j;
			}
		}
		visit[borr]=true;
		perd+=p[borr];
		p[borr]=0;
		c[borr]=0;
		for(int j=0;j<A;j++){
			if(borr==j) continue;
			p[j]-=costos[j][borr];
		}
		for(int j=0;j<A;j++){
			if(borr==j) continue;
			c[j]-=costos[borr][j];
		}
	}
	cout<<ganan-perd;
	return 0;
}
	
	
