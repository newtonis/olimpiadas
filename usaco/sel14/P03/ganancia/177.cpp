#include <fstream>

#include <iostream>
#include <vector>
#include <set>

#define forn(i,n) for(int i = 0 ;i<n;i++)

int max_ganancia[55][55];

using namespace std;

struct Auto {
	int demora, tarifa, precio;
	Auto(int d, int t,int p){
		this->demora = d;
		this->tarifa = t;
		this->precio = p;
		
	}
	Auto (){
		
	}
};

int main(){
	
	ifstream in ("ganancia.in");
	ofstream out("ganancia.out");

	int a;
	in>>a;
			
	vector <Auto>autos;
	
	set<int>all_autos;
	int totalPrec = 0, totalTar = 0;
	forn(i,a){
		int d,t,p;
		in>>d>>t>>p;
		totalPrec += p;
		totalTar += d * t;
		all_autos.insert(i);
		autos.push_back(Auto(d,t,p));
	}
	

	bool can_use[55][55][55];
	int can_tar[55][55];
	int can_prec[55][55];
	forn(i,a){
		forn(j,a+1){
			max_ganancia[j1][i] = 0;
		}
		forn(j,a){
			can_use[0][i][j] = true;
		}
		can_prec[0][i] = totalPrec;  
		can_tar[0][i] = totalTar ;
	}
	
	forn(k,a+1){
		forn(i,a){
			forn(j, a){
				if (can_use[k][i][j]){
					int newGanancia = max_ganancia[k][i] + autos[j].precio - (can_tar[k][i]  - autos[j].demora * autos[j].tarifa);
					cout<<newGanancia<<endl;
					if (max_ganancia[k][j] < newGanancia){
						max_ganancia[k][j] = newGanancia;
						can_tar[k][j]  = can_tar[k][i] - autos[j].demora * autos[j].tarifa;
						
					}
				}
			}
		}
	}
	
	int res = 0;
	forn(i,a){
		res = max(res, max_ganancia[a][i]);
	}
	
	cout<<res<<endl;
}
