#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

#define forn(i,n) for(int i=0;i<(int)(n);i++)
#define forsn(i,s,n) for(int i=(s);i<(int)(n);i++)

#define forall(it,c) for(typeof((c).begin()) it = (c).begin(); it != (c).end(); it++)

const int MAXN = 100100;

vector<int> g[MAXN];
bool u[MAXN];

int main()
{
	freopen("casamiento.in","r",stdin);
	freopen("casamiento.out","w",stdout);
	int N,M; cin >> N >> M;	
	forn(i,M)
	{
		int x,y; 
		cin >> x >> y;
		x--; y--;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	int total = 0;
	forn(i,N) u[i] = false;
	forn(i,N)
	if (!u[i])
	{
		int cs = 1;
		u[i] = true;
		vector<int> pending(1, i);
		while (!pending.empty())
		{
			int x = pending.back(); pending.pop_back();
			forall(y, g[x])
			if (!u[*y])
			{
				u[*y] = true;
				cs++;
				pending.push_back(*y);
			}
		}
		total += (cs+1) / 2;
	}
	cout << total << endl;
	return 0;
}

