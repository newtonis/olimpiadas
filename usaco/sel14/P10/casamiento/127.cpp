#include <iostream>
#include <fstream>

using namespace std;

struct persona
    {
        int e1,e2;
        bool disp;
    };

int main()
{
    ifstream fin("casamiento.in");
    int n,m,invit=0;
    fin>>n>>m;
    persona enem[n];


    for(int i=0;i<n;i++)
        {
            enem[i].disp=1;
            enem[i].e1=enem[i].e2=-1;
        }


    for(int i=0;i<m;i++)
        {
            int auxa, auxb;
            fin>>auxa>>auxb;
            if(!enem[auxa].e1)
                enem[auxa].e1=auxb;
            else
                enem[auxa].e2=auxb;
            if(!enem[auxb].e1)
                enem[auxb].e1=auxa;
            else
                enem[auxb].e2=auxa;
        }



    for(int i=0;i<n;i++) //invito a los que no tienen enemigos
        if(enem[i].e1==-1)
            {
                enem[i].disp=0;
                invit++;
            }


    for(int i=0;i<n;i++) //invito a los que tienen un enemigo, echo a ese enemigo
        if(enem[i].disp&&enem[i].e2)
            {
                enem[i].disp=enem[enem[i].e2].disp=0;
                invit++;
            }

    ofstream fout("casamiento.out");
    fout<<invit<<endl;
    return 0;
}
