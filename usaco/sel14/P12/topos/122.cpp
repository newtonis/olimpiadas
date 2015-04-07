#include<iostream>
#include<fstream>
#include<vector>
#define forn(a,b) for((a)=0; (a)<(b); ++(a))
using namespace std;
const int maxn = 600010;

ifstream fin("topos.in");
ofstream fout("topos.out");

int N;
char S[maxn];

struct nodo{

    char rotulo;
    vector<nodo *> hijos;
    nodo *pa;

    void descargar(nodo *padre){
        int i;
        forn(i,hijos.size())
                if(hijos[i] != padre){
                    hijos[i]->descargar(this);
                    delete hijos[i];
                }
    }

    int leer(char *s){
        int cant, offa, offb;   //leer primer parentesis
        nodo *p, *q;

        if( s[0] == '(' ){
            cant = 1; //lei (
            p = new nodo;

            p->pa = this;
            p->hijos.push_back(this);
            offa = p->leer(s+1);

            hijos.push_back(p);

            q = new nodo;

            q->pa = this;
            q->hijos.push_back(this);
            offb = q->leer(s+1+offa);

            hijos.push_back(q);

            return 1 + offa + offb + 1;
        }else{
            rotulo = s[0];
            return 1;
        }
    }

    void mostrar(nodo *padre){
        int i;
        if( hijos.size() <= 1) fout<<rotulo;
        else{
            fout<<'(';
            forn(i,hijos.size())
                if(hijos[i] != padre)
                    hijos[i]->mostrar(this);
            fout<<')';
        }
    }


    nodo *encontrar(nodo *padre){
        nodo *p = NULL;
        int i;

        if( rotulo == 'Z' ) return this;
        else forn(i,hijos.size()){
            if(hijos[i] != padre){
                p = hijos[i]->encontrar(this);
                if( p != NULL ) return p;
            }

        } return NULL;
    }
};

nodo R;

int main(){
    int i, e;
    nodo *zeta;

    fin.getline(S,maxn);
    //R.rotulo = S[0];

    zeta = new nodo;
    zeta->rotulo = S[0];
    zeta->hijos.push_back(&R);

    R.hijos.push_back(zeta);

    R.leer(S+2);

    zeta = R.encontrar(NULL);
    fout<<"Z:";
    zeta -> hijos[0]-> mostrar(zeta);
    fout<<endl;

    R.descargar(NULL);

    return 0;
}
