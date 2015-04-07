#include <iostream>
#include <fstream>
#include <stack>
using namespace std;
int main()
{
    ifstream fin("ciclovia.in");
    ofstream fout("ciclovia.out");
    int v,h;
    int mapa[1000][1000];
    int temporal[1000][1000]={0};
    int senv[1000];
    int senh[1000];
    int costoh[1000];
    int costov[1000];
    stack<int> nextx[21];
    stack<int> nexty[21];
    stack<int> tipocalle[21];//0v y 1h
    fin>>v>>h;
    for (int i=0;i<v;i++)
    {
        fin>>senv[i]>>costov[i];
    }
     for (int i=0;i<h;i++)
    {
        fin>>senh[i]>>costoh[i];
    }
    for (int i=0;i<1000;i++)
    for (int j=0;j<1000;j++)
        mapa[i][j]=100000;

    int xfinal,yfinal;
    fin>>yfinal>>xfinal;
    nextx[1].push(xfinal-1);
    nexty[1].push(yfinal-1);
    mapa[xfinal-1][yfinal-1]=0;
    fin>>yfinal>>xfinal;//posicionfinal

    tipocalle[1].push(2);
    xfinal--;
    yfinal--;
    int final=0;
    int sig=0;
    while (final==0)
    {
        sig=(sig+1)%21;
        while (nextx[sig].size()>0)
        {
            int x=nextx[sig].top();
            nextx[sig].pop();
            int y=nexty[sig].top();
            nexty[sig].pop();
            int calle=tipocalle[sig].top();//0v y 1h y v=x h=y
            tipocalle[sig].pop();
            temporal[x][y]=1;

            if ((x==xfinal)&&(y==yfinal)) final=1;


            if ((temporal[x+1][y]==0) &&(x<(h-1)))
            {
                int costo=mapa[x][y]+costov[y];
                if (senv[y]==1)
                {
                    costo=costo+1;
                    if (calle==1) costo=costo+3;
                }
                if (costo<mapa[x+1][y])
                {

                    mapa[x+1][y]=costo;
                }
                int proximo=(sig+costo)%21;
                nextx[proximo].push(x+1);
                nexty[proximo].push(y);
                tipocalle[proximo].push(0);
            }

            //y en +1
            if ((temporal[x][y+1]==0)&&(y<(v-1)))
            {
                int costo=mapa[x][y]+costoh[x];
                if (senh[x]==1)
                {
                    costo=costo+1;
                    if (calle==0) costo=costo+3;
                }
                 if (costo<mapa[x][y+1])
                {

                    mapa[x][y+1]=costo;
                }
                int proximo=(sig+costo)%21;
                nextx[proximo].push(x);
                nexty[proximo].push(y+1);
                tipocalle[proximo].push(1);
            }

            //y en -1
            if ((temporal[x][y-1]==0)&&(y>0))
            {
                int costo=mapa[x][y]+costoh[x];
                if (senh[x]==0)
                {
                    costo=costo+1;
                    if (calle==0) costo=costo+3;
                }
                 if (costo<mapa[x][y-1])
                {

                    mapa[x][y-1]=costo;
                }
                int proximo=(sig+costo)%21;
                nextx[proximo].push(x);
                nexty[proximo].push(y-1);
                tipocalle[proximo].push(1);
            }
            //x en -1
             if ((temporal[x-1][y]==0) &&(x>0))
            {
                int costo=mapa[x][y]+costov[y];
                if (senv[y]==0)
                {
                    costo=costo+1;
                    if (calle==1) costo=costo+3;
                }
                 if (costo>mapa[x-1][y])
                {

                    mapa[x-1][y]=costo;
                }
                int proximo=(sig+costo)%21;
                nextx[proximo].push(x-1);
                nexty[proximo].push(y);
                tipocalle[proximo].push(0);

            }






        }

    }
    fout<<mapa[xfinal][yfinal]<<endl;


    return(0);
}
