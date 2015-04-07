#include <iostream>
#include <cstdio>

using namespace std;

#define forn(i,n) for(int i=0;i<(int)(n);i++)
#define forsn(i,s,n) for(int i=(s);i<(int)(n);i++)

int main()
{
	freopen("compra.in", "r", stdin);
	freopen("compra.out", "w", stdout);
	int V,H,C;
	cin >> V >> H >> C;
	const int INF = 1000000000;
	int mu = INF, mv = INF, Mu = -INF, Mv = -INF;
	forn(i,C)
	{
		int x,y;
		cin >> x >> y;
		int u = x + y;
		int v = y - x;
		mu = min(u, mu);
		mv = min(v, mv);
		Mu = max(u, Mu);
		Mv = max(v, Mv);
	}
	int D = (max(Mu - mu, Mv - mv) + 1) / 2;
	// Calculo del rectangulo milagroso segun D
	int minU = Mu - D;
	int maxU = mu + D;
	int minV = Mv - D;
	int maxV = mv + D;
	if (minU == maxU && minV == maxV && (minU + minV) % 2 != 0)
	{
		// Caso especial: hay un unico punto ideal en un punto nuevo,
		// por lo tanto hay que aumentar la distancia porque no es
		// un punto alcanzable en nuestra grilla verdadera.
		minU--; maxU++;
		minV--; maxV++;
	}
	// u-v?
	for(int dosX = (minU - maxV) + (minU - maxV) % 2; dosX <= maxU - minV; dosX += 2)
	forsn(v, max(minV, minU - dosX), min(maxV, maxU - dosX) + 1)
	// minU <= dosX + v = u <= maxU
	// minV <= v = u - dosX <= maxV
	//forsn(v, minV, maxV+1)
	{
		int u = dosX + v;
		int x = (u-v)/2;
		int y = (u+v)/2;
		cout << x << " " << y << endl;
	}
	return 0;
}
