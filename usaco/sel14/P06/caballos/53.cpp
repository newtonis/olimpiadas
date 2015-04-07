#include <iostream>
#include <cstdio>
#include <queue>

using namespace std;
char tab[1100][1100];
int cant[1100][1100];

struct est{
	int i, j, vL;
	bool vA;
};

void init(int f, int c){
	for(int i=1;i<=f;i++){
		for(int j=1;j<=c;j++) cant[i][j]=0;
	}
}

char nuevaL(int i, int j, bool vA, int vL){
	char Al=tab[i][j];
	if(Al=='C') return 'A';
	if(Al=='B') return 'A';
	if(Al=='A' && !vA) return 'B';
	if(Al=='A' && vA) return 'L';
	if(Al=='L' && vL!=3) return 'L';
	if(Al=='L' && vL==3) return 'O';
	return '*';
}

int main(){
	freopen("caballos.in", "r", stdin);
	freopen("caballos.out", "w", stdout);
	int F, C, M;
	cin>>F>>C>>M;
	init(F, C);
	queue<est> pasos;
	est Nest;
	for(int i=1;i<=F;i++){
		for(int j=1;j<=C;j++){
			cin>>tab[i][j];
			if(tab[i][j]=='C'){
				cant[i][j]+=1;
				Nest.i=i;
				Nest.j=j;
				Nest.vA=false;
				Nest.vL=0;
				pasos.push(Nest);
			}
		}
	}
	int Ni[8]={-2,-1,1,2,2,1,-1,-2};
	int Nj[8]={1,2,2,1,-1,-2,-2,-1};
	est Aest;
	int res=0;
	while(!pasos.empty()){
		Aest=pasos.front();
		pasos.pop();
		char Nl = nuevaL(Aest.i, Aest.j, Aest.vA, Aest.vL);
		if(Nl=='B') Nest.vA=true;
		if(Nl=='L'){
			Nest.vL++;
		}
		int sumC=cant[Aest.i][Aest.j];
		sumC%=M;
		cant[Aest.i][Aest.j]=0;
		for(int i=0;i<8;i++){
			Nest.i=Aest.i+Ni[i];
			Nest.j=Aest.j+Nj[i];
			if(Nest.i>0 && Nest.i<=F && Nest.j>0 && Nest.j<=C){
				if(tab[Nest.i][Nest.j]==Nl){
					if(cant[Nest.i][Nest.j]==0) pasos.push(Nest);
					cant[Nest.i][Nest.j]+=sumC;
				}
			}
		}
		if(tab[Aest.i][Aest.j]=='O') res+=sumC;
	}
	res%=M;
	cout<<res<<endl;
	return 0;
}
				
				
