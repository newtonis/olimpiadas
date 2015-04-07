#include <iostream>
#include <cstdio>
#include <stack>

using namespace std;

#define forn(i,n) for(int i=0;i<(int)(n);i++)
#define forsn(i,s,n) for(int i=(s);i<(int)(n);i++)

const int MAX = 1024;

const int INF = 1000000000;

int vr[MAX], hr[MAX];
bool vs[MAX], hs[MAX];

const int dv[4] = {1,0,-1,0};
const int dh[4] = {0,1,0,-1};

int V,H;

int dis[MAX][MAX][4];
const int MOD = 32;

struct Pos
{
	int v,h,dir;
	Pos(int vv, int hh, int dd) : v(vv), h(hh), dir(dd) {}
	
	int dist() const { return dis[v][h][dir]; }
	void setDist(int nd) const { dis[v][h][dir] = nd; }
	pair<Pos, int> advance() const
	{
		int cost;
		if (dir == 0 || dir == 2)
			cost = hr[h] + (hs[h] == (dir == 0));
		else
			cost = vr[v] + (vs[v] == (dir == 1));
		return make_pair(Pos(v + dv[dir], h + dh[dir], dir), cost); 
	}
	pair<Pos, int> turn(int delta) const {
		int newdir = (dir + delta + 16) % 4;
		int cost;
		if (newdir == 0 || newdir == 2)
			cost = 3 * (hs[h] == (newdir == 0));
		else
			cost = 3 * (vs[v] == (newdir == 1));
		return make_pair(Pos(v, h, newdir) , cost); 
	}
	bool valid() const { return 0 <= v && v < V && 0 <= h && h < H; }
};

int dijkstra(int v1,int h1,int v2,int h2)
{
	stack<Pos> _bag[MOD];
	#define bag(i) _bag[(i)%MOD]
	forn(d,4)
	{
		Pos npos(v1,h1,d);
		npos.setDist(0);
		bag(0).push(npos);
	}
	int D = 0;
	while (true)
	{
		if (bag(D).empty()) D++;
		else
		{
			Pos p = bag(D).top(); bag(D).pop();
			if (p.dist() == D)
			{
				// Tenemos una ocurrencia posta, chequiemos si llegamos...
				if (p.v == v2 && p.h == h2)
					return D;
				pair<Pos, int> candidates[3] = {p.advance(), p.turn(-1), p.turn(1)};
				forn(k,3)
				{
					const Pos &npos = candidates[k].first;
					int cost = candidates[k].second;
					if (npos.valid())
					{
						int newDist = D + cost;
						if (newDist < npos.dist())
						{
							npos.setDist(newDist);
							bag(newDist).push(npos);
						}
					}
				}
			}
		}
	}
}

int main()
{
	freopen("ciclovia.in", "r", stdin);
	freopen("ciclovia.out", "w", stdout);
	cin >> V >> H;
	// 0 la calle "sube", 1 la calle "baja"
	forn(i,V)
	forn(j,H)
	forn(d,4)
		dis[i][j][d] = INF;
	forn(i,V) cin >> vs[i] >> vr[i];
	forn(i,H) cin >> hs[i] >> hr[i];
	int v1,h1; cin >> v1 >> h1; v1--; h1--;
	int v2,h2; cin >> v2 >> h2; v2--; h2--;
	cout << dijkstra(v1,h1,v2,h2) << endl;
	return 0;
}
