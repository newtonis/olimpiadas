#include <iostream>
#include <fstream>
#include <queue>

using namespace std;

queue <int> back;

int invit=0,n;

struct persona
    {
        int e1,e2;
        bool disp;
    };

persona enem[100001];

void unenem (int i)
    {
        if(enem[i].disp&&enem[i].e2==-1)
            {
                enem[i].disp=enem[(enem[i].e1)].disp=0;
                if (enem[(enem[i].e1)].e2!=-1)//elimino a la persona echada de las demas listas de enemigos en caso de que aparezca
                    {
                        if(enem[(enem[(enem[i].e1)].e2)].e1==enem[i].e1)
                            {
                                enem[(enem[(enem[i].e1)].e2)].e1=-1;
                                if(enem[(enem[(enem[i].e1)].e2)].e2>0)//si la persona echada tiene dos enemigos, el otro pasa a tener un enemigo, por lo que entra en una queue a la cual luego le aplico unenem
                                back.push(enem[(enem[(enem[i].e1)].e2)].e2);
                            }
                        else
                            {
                                enem[(enem[(enem[i].e1)].e2)].e2=-1;
                                if(enem[(enem[(enem[i].e1)].e2)].e1>0)//idem comentario anterior
                                back.push(enem[(enem[(enem[i].e1)].e2)].e1);
                            }
                    }
                invit++;
            }
    }


int main()
{
    ifstream fin("casamiento.in");
    int m;
    fin>>n>>m;


    for(int i=0;i<n+1;i++)
        {
            enem[i].disp=1;
            enem[i].e1=enem[i].e2=-1;
        }


    for(int i=1;i<m+1;i++)
        {
            int auxa, auxb;
            fin>>auxa>>auxb;
            if(enem[auxa].e1==-1)
                enem[auxa].e1=auxb;
            else
                enem[auxa].e2=auxb;
            if(enem[auxb].e1==-1)
                enem[auxb].e1=auxa;
            else
                enem[auxb].e2=auxa;
        }



    for(int i=1;i<n+1;i++) //invito a los que no tienen enemigos
        if(enem[i].e1==-1)
            {
                enem[i].disp=0;
                invit++;
            }

    for(int i=1;i<n+1;i++) //invito a los que tienen un enemigo, echo a ese enemigo
        unenem(i);



    while(!back.empty())//aplico unenem a la queue
        {
            unenem(back.front());
            back.pop();
        }

    //ahora solo quedan ciclos porque solo quedan personas con dos enemigos. los ciclos son pares porque no hay miembros de una misma familia que sean enemigos. de cada ciclo puedo invitar a lo sumo la mitad por lo que puedo invitar a lo sumo a la mitad de los familiares con dos enemigos
    m=0; //m va a valer la cantidad de familiares con dos enemigos

    for(int i=1;i<n+1;i++)
        if(enem[i].disp)
            m++;

    invit+=m/2;

    ofstream fout("casamiento.out");
    fout<<invit<<endl;
    return 0;
}
