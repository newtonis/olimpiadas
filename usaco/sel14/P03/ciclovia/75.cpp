#include <fstream>
#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <set>


#define forn(i,n) for(int i=0;i<n;i++)
#define INF 9999999999


using namespace std;

enum SentidoCirc {NS, SN, OE, EO};

struct Posicion {
	int x,y;
	Posicion(int x, int y){
		this->x = x;
		this->y = y;
	}
	bool isValid(int limiteV, int limiteH){
		return (this->x >= 0 && this->x < limiteV && this->y >=0 && this->y < limiteH);
	}
	Posicion(){
	
	}
	
	bool operator < (const Posicion p) const {
		return (this->x < p.x && (this-> x == p.x && this-> y < p.y));
	}
	
	
};

struct Calle {
	SentidoCirc sentido;
	int riesgoCalle;
	Calle(SentidoCirc sen, int res){
		this->sentido = sen;
		this->riesgoCalle = res;
	}
};

struct Arista {
	Posicion pos;
	SentidoCirc sen;
	int riesgo;
	bool dobla;
	Arista(Posicion p, SentidoCirc s, int r, bool d){
		this->pos = p;
		this->sen = s;
		this->riesgo = r;
		this->dobla = d;
	}
};

struct Node {
	SentidoCirc prevSen;
	SentidoCirc newSen;
	Posicion pos;
	int riesgo;
	Node(Posicion pos, SentidoCirc prevS, SentidoCirc newS, int r){
		this->pos = pos;
		this->prevSen = prevS;
		this->newSen = newS;
		this->riesgo = r;
		
	}
	
	bool operator < (const Node n) const {
		if (this->riesgo > n.riesgo)
			return false;
		
		if (this->riesgo == n.riesgo){		
			if (this->prevSen > n.prevSen )
				return false;
		
			if (this->prevSen == n.prevSen ){
				if (this->newSen > n.newSen )
					return false;
			
				if (this->newSen == n.newSen ){
					if (this->pos < n.pos ) // menor
						return true;
				}
		
			}
			
		}
			
		
		return true;
	}
};

int min_riesgo[1010][1010];

int main(){
	
	forn(i, 1010){
		forn(j, 1010){
			min_riesgo[i][j] = INF;
		}
	}
	
	ifstream in ("ciclovia.in");
	ofstream out ("ciclovia.out");

	int v,h;
	in>>v>>h;
	int a,b;
		
	vector <Calle> callesNS;
	callesNS.push_back(Calle(NS,0));
	forn(i,v){
		in>>a>>b;
		if (a == 0){  
			callesNS.push_back(Calle(NS,b));
		}
		else {
			callesNS.push_back(Calle(SN,b));	
		}	
	}
	
	
	vector <Calle> callesOE;
	callesOE.push_back(Calle(NS,0));

	forn(i,h){
		int a,b;
		in>>a>>b;
		if (a == 0){  
			callesOE.push_back(Calle(OE,b));
		}
		else {
			callesOE.push_back(Calle(EO,b));	
		}
	}

	in>>a>>b;
	Posicion posA = Posicion (a,b);

	in>>a>>b;
	Posicion posB = Posicion (a,b);
	
	map<pair<int,int>, vector<Arista> > aristas;
	
	forn(posx,v+1){
		forn(posy,h+1){
			// calcular aristas
			
			int dx[] ={-1,1,0,0};
			int dy[] ={0,0,-1,1};
			
			Posicion pos = Posicion(posx, posy);
			forn(k,4){
				Posicion nuevaPos = Posicion(posx + dx[k], posy + dy[k]);
				if(nuevaPos.isValid(v,h)){
					if (nuevaPos.x > posx){ // hacia este
						bool dobla = false;

						int nuevoRiesgo  = callesOE[posy].riesgoCalle;
						if(callesOE[posy].sentido == EO){
							nuevoRiesgo += 1;
							dobla = true;
						}
						Arista ar = Arista(nuevaPos, OE, nuevoRiesgo, dobla);
						
						aristas[make_pair(pos.x, pos.y)].push_back(ar);

					}
					if (nuevaPos.x < posx){ // hacia oeste
						int nuevoRiesgo  = callesOE[posy].riesgoCalle;
						bool dobla  =false;
						if(callesOE[posy].sentido == OE){
							nuevoRiesgo += 1;
							dobla = true;

						}
						Arista ar = Arista(nuevaPos, EO, nuevoRiesgo, dobla);
						aristas[make_pair(pos.x, pos.y)].push_back(ar);

					}

					if (nuevaPos.y > posy){ // hacia sur
						int nuevoRiesgo  = callesNS[posx].riesgoCalle;
						bool dobla = false;
						if(callesOE[posx].sentido == SN){
							nuevoRiesgo += 1;
							dobla = true;

						}
						Arista ar = Arista(nuevaPos, NS , nuevoRiesgo, dobla );
						aristas[make_pair(pos.x, pos.y)].push_back(ar);

					}
					
					if (nuevaPos.y < posy){ // hacia norte
						int nuevoRiesgo  = callesOE[posy].riesgoCalle;
						bool dobla = false;
						if(callesOE[posy].sentido == NS){
							nuevoRiesgo += 1;
							dobla = true;
						}
						Arista ar = Arista(nuevaPos, SN, nuevoRiesgo, dobla);
						aristas[make_pair(pos.x, pos.y)].push_back(ar);
					}

				}
			}
		
		}
	}
	
	set <Node> s;
	
	s.insert(Node(posA, NS, NS, 0));
	s.insert(Node(posA, NS, SN, 0));
	s.insert(Node(posA, NS, OE, 0));
	s.insert(Node(posA, NS, EO, 0));

	min_riesgo[posA.y][posA.x] = 0;
	
	//cout<<"NS, SN, OE, EO"<<endl;
	
	while (!s.empty()){
		Node node = *s.begin();
		s.erase(s.begin());
		Posicion pos = node.pos;
		//cout<<node.pos.x<<" "<<node.pos.y<<" "<<node.riesgo<<" "<<node.newSen<<":"<<endl;
		
		forn(i,(int) aristas[make_pair(pos.x, pos.y)].size()){
		
			
			Arista toArista = aristas[make_pair(pos.x, pos.y)][i];
			int newRiesgo = node.riesgo + toArista.riesgo;
			
			
			if (node.newSen != toArista.sen){
				//cout<<"CUIDADO QUE DOBLO WACHO!"<<endl;
				if (toArista.dobla){
					newRiesgo += 3;
					
				}
			}
			
			if (min_riesgo[toArista.pos.y][toArista.pos.x] > newRiesgo){
				min_riesgo[toArista.pos.y][toArista.pos.x] = newRiesgo;
				
				//cout<<toArista.pos.x<<" "<<toArista.pos.y<<" "<<newRiesgo<<" "<<toArista.sen<<endl;

				s.insert(Node(toArista.pos, node.newSen, toArista.sen, newRiesgo ));
			}
		}
		
		//cout<<"----------------"<<endl;
	}

	out<<min_riesgo[posB.y][posB.x]<<endl;
}
