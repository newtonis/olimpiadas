#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    ifstream fin ("topos.in");
    ofstream fout ("topos.out");
    char inicio;
    fin>>inicio;
    fin>>basura;
    int izquierda[600000]={0};
    int derecha[600000]={0};
    int origen[600000];
    char puntaiz[600000];
    char puntade[600000];
    char puntaorigen[600000];
    int parentesis=0;
    int z;
    char n;
    fin>>n;
    origen[0]=-1;
    puntaorigen[0]=inicio;
    int maxpan=1;
    while (final==0)
    {
            fin>>n;
            if (n==40)
            {
                if (izquierda[parentesis]==0)
                {
                    izquierda[parentesis]=maxpan+1;
                    origen[maxpan+1]=parentesis;
                }
                    else
                    {
                        derecha[parentesis]=maxpan+1;
                        origen[maxpan+1]=parentesis;
                    }
                parentesis=maxpan+1;
                maxpan=parentesis;
            }
            if (n==41)
            {
                parentesis=origen[parentesis];
                if (origen[parentesis]==-1)
                {
                    final=1;
                }
            }
            if((n!=40)&&(n!=41))
            {
                if (izquierda[parentesis]==0)
                {
                    izquierda[parentesis]=-1;
                    puntaiz[parentesis]=n;
                }
                else
                {
                    derecha[parentesis]=-1;
                    puntade[parentesis]=n;
                }
                if (n==90)
                    z=parentesis;
            }
    }
    //esta armado solo falta recorrerlo
    fout<<"z:";
    int sentido;
    if (puntade[z]=90)
    {
        sentido=1;
    }
    if (puntaiz[z]=90)
    {
        sentido=0;
    }
    int visitadoiz[600000]={0};
    int visitadode[60000]={0};
    int ubicacion=z;
    while ()
    {
        if (sentido==0)
        {
            if (visitadode[izquierda])

        }
    }

}

