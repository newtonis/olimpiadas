#include <fstream>
#include <iostream>
#include <vector>
#include <stack>

#define forn(i,n) for(int i = 0 ;i<n;i++)

using namespace std;

int min_sum_tar[55][55];

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
struct Nodo {
	bool poner;
	int car;
	int resta; 
	int turno;
};

int main(){


	ifstream in ("ganancia.in");
	ofstream out("ganancia.out");
	
	int a;
	in>>a;

	vector <Auto>autos;
	stack<Nodo>s;
	
	int totPre = 0;
	int totTar = 0; 
	forn(i,a){
		int d,t,p;
		in>>d>>t>>p;
		totPre += p;
		totTar += t;
		autos.push_back(Auto(d,t,p));
	}
	
	forn (i,55){
		forn(j,55){
			min_sum_tar[j][i] = 9999;

		}
	}
	
	forn(i,a){
		Nodo root;
		root.poner = false;
		root.car  = i;
		root.resta = (totTar - autos[i].tarifa);
		int tot =  (totTar - autos[i].tarifa) * autos[i].demora;
		root.turno = 0;
		s.push(root);
		root.poner = true;
		s.push(root);
		
		min_sum_tar[0][i] = tot;

		//cout<<i<<" "<<tot<<endl;
	}
	
	
	
	//cout<<"------------"<<endl;
	
	bool used[55];
	forn (i,a){
		used[i] = false;
	}
	
	while(!s.empty()){
		Nodo n = s.top();
		s.pop();
		
		if (n.poner && n.turno < a){
					//cout<<n.turno<<" "<<n.resta<< " "<<n.car<<endl;

			used[n.car] = true;
			//cout<<"-,...d.f"<<endl;
					
			forn(i,a){
				if (!used[i]){
					Nodo newNodo;
					newNodo.turno = n.turno + 1;
					newNodo.car = i;
					newNodo.resta = n.resta - autos[i].tarifa; 
					newNodo.poner = false;
					//cout<< (n.resta  - autos[i].tarifa) * autos[i].demora<<endl;
					
					if (min_sum_tar[n.turno + 1][i] > min_sum_tar[n.turno][n.car] + (n.resta  - autos[i].tarifa) * autos[i].demora ){
						//cout<<"SEEEEEE "<<newNodo.resta<<endl;
						min_sum_tar[n.turno + 1][i] =min_sum_tar[n.turno][n.car] +  (n.resta  - autos[i].tarifa) * autos[i].demora ;
						
						s.push(newNodo);
						newNodo.poner = true;
						s.push(newNodo);

					} 
				}
				
			}
			//cout<<"-,...d.f"<<endl;
					
		}
		else {
			used[n.car] = false;
		}
		
	}
	int res = 9999;
	forn(i,a){
		//cout<<min_sum_tar[a-1][i]<<endl;
		res = min(res, min_sum_tar[a-1][i]); 
	}
	//cout<<res<<endl;
	out<<totPre - res<<endl;
	
}
	

