#include <iostream>
#include <cstdio>
#include <algorithm>


using namespace std;

#define forn(i,n) for(int i=0;i<(int)(n);i++)
#define forsn(i,s,n) for(int i=(s);i<(int)(n);i++)

const int MAX = 64;

int d[MAX], t[MAX];

bool f(int i, int j)
{
	return t[i] * d[j] > t[j] * d[i];
}

int a[MAX];

int main()
{
	freopen("ganancia.in","r",stdin);
	freopen("ganancia.out","w",stdout);
	// HAY QUE ORDENAR EN ORDEN CRECIENTE DE TIEMPO / COSTO_DIARIO
	int A; cin >> A;
	int tot = 0;
	forn(i,A)
	{
		int p;
		cin >> d[i] >> t[i] >> p;
		tot += p;
	}
	forn(i,A) a[i] = i;
	sort(a,a+A, f);
	int T = 0;
	forn(i,A)
	{
		tot -= t[a[i]] * T;
		T += d[a[i]];
	}
	cout << tot << endl;
	return 0;
}


