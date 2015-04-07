#include <iostream>
#include <cstdio>

using namespace std;

#define forn(i,n) for(int i=0;i<(int)(n);i++)
#define forsn(i,s,n) for(int i=(s);i<(int)(n);i++)

struct Nodo
{
	char letter;
	Nodo *v[3];
	Nodo () : letter(0) {}
};

const int MAX = 1000000;

Nodo nodos[MAX];

int np = 0;
Nodo &newNodo() { return nodos[np++]; }

char input[MAX];

int pos;

Nodo *newOrigin;

void armar(Nodo ** childptr, Nodo *parent)
{
	Nodo &next = newNodo();
	next.v[0] = parent;
	*childptr = &next;
	if (input[pos] == '(')
	{
		pos++; // '('
		armar(&next.v[1], &next);
		armar(&next.v[2], &next);
		pos++; // ')'
	}
	else
	{
		next.letter = input[pos++];
		if (next.letter == 'Z')
			newOrigin = &next;
	}
}

void dibujar(Nodo * parent, Nodo *current)
{
	if (current->letter == 0)
	{
		int i = 0;
		while (current->v[i] != parent) i++;
		i = (i+1)%3; // Doblo a la izquierda...
		cout << "(";
		dibujar(current, current->v[i]);
		i = (i+1)%3; // y ahora recorro el que falta.
		dibujar(current, current->v[i]);
		cout << ")";
	}
	else
		cout << current->letter;
}

int main()
{
	freopen("topos.in","r",stdin);
	freopen("topos.out","w",stdout);
	gets(input);
	Nodo &origin = newNodo();
	origin.letter = input[0];
	pos = 2;
	armar(&origin.v[0], &origin);
	cout << "Z:";
	dibujar(newOrigin, newOrigin->v[0]);
	cout << endl;
	return 0;
}
