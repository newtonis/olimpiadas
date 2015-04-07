#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
int invi, canti,lol[100001][3],v1,v2;
vector <int> pos;
ifstream entrada;
ofstream salida;
int main(){
	entrada.open("casamiento.in");
	salida.open("casamiento.out");
	entrada >> invi >> canti;
	vector<int>::iterator iter;
	for(int rep=0;rep<canti;rep++){
		entrada >> v1 >> v2;
		lol[v1][2]++;
		lol[v2][2]++;
		if(lol[v1][0]==0) lol[v1][0]=v2;
		else lol[v1][1]=v2;
		if(lol[v2][0]==0) lol[v2][0]=v1;
		else lol[v2][1]=v1;
		pos.push_back(v1);
	}
  for( iter = pos.begin(); iter != pos.end(); iter++ ) {
    if (lol[*iter][2]==2){
		invi--;
		if (lol[lol[*iter][0]][0]==*iter) lol[lol[*iter][0]][0]=0;
		else lol[lol[*iter][0]][1]=0;
		if (lol[lol[*iter][1]][0]==*iter) lol[lol[*iter][0]][0]=0;
		else lol[lol[*iter][1]][1]=0;
		lol[lol[*iter][0]][2]--;
		lol[lol[*iter][1]][2]--;
		}
  }
    for (iter=pos.begin();iter!=pos.end();iter++) {
    if (lol[*iter][2]==1){
		invi--;
		if (lol[lol[*iter][0]][0]==*iter) {
			lol[lol[*iter][0]][0]=0; 
		}
		else lol[lol[*iter][0]][1]=0;
		if (lol[lol[*iter][1]][0]==*iter) {
			lol[lol[*iter][1]][0]=0;
			}
		else lol[lol[*iter][1]][1]=0;
		lol[lol[*iter][0]][2]--;
		lol[lol[*iter][1]][2]--;
		}
  }
  salida << invi << endl;
}
			
			
