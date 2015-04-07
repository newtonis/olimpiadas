#include <iostream>
#include <cstdlib>
#include <fstream>

using namespace std;

struct car
    {
        int d,t,p;
        float pot;
    };

void swapa (car *a, car *b)
    {
        car aux;
        aux=*a;
        *a=*b;
        *b=aux;
    }

int main()
{
    ifstream fin("ganancia.in");
    int a,ganancia=0,estac=0,noches;
    fin>>a;
    car autos[a];
    for(int i=0;i<a;i++)
        fin>>autos[i].d>>autos[i].t>>autos[i].p;
    for(int i=0;i<a;i++)
        {
            noches+=autos[i].d;
            autos[i].pot= (1.0*autos[i].t)/(1.0*autos[i].d);
        }
    for(int i=0;i<a-1;i++)
        if(autos[i].pot>autos[i+1].pot)
            {
                swapa(&autos[i],&autos[i+1]);
                i=-1;
            }
    for(int i=0;i<a;i++)
        {
            ganancia+=autos[i].p;
            noches-=autos[i].d;
            estac+=noches*autos[i].t;
        }
    ofstream fout("ganancia.out");
    fout<<ganancia-estac<<endl;
    return 0;
}
