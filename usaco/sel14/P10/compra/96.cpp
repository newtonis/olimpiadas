#include <iostream>
#include <fstream>
#include <queue>

using namespace std;

int v,h;

int board[10000][10000];

int absoluto (int x)
{
    if (x<0)
        return -x;
    return x;
}

struct home
{
    int x,y;
};

void dist(int x, int y)
    {
        for (int i=0;i<h;i++)
            for (int j=0;j<v;j++)
                board[j][i]+=absoluto(i-x)+absoluto(j-y);
    }

int main()
{
    queue <home> result;
    queue <home> res;
    ifstream fin("compra.in");
    ofstream fout("compra.out");
    int c,mind=100000000;
    fin>>v>>h;
    fin>>c;
    home casa[c];
    for(int i=0;i<c;i++)
        fin>>casa[i].x>>casa[i].y;

    for(int i=0;i<c;i++)
        {
            dist(casa[i].x,casa[i].y);
        }


    for(int i=0;i<h;i++)
        for(int j=0;j<v;j++)
            {
                if(mind==board[j][i])
                    {
                        home aux;
                        aux.x=j;
                        aux.y=i;
                        result.push(aux);
                    }
                if(mind>board[j][i])
                    {
                        mind=board[j][i];
                        while(!result.empty())
                            result.pop();
                        home aux;
                        aux.x=j;
                        aux.y=i;
                        result.push(aux);
                    }
            }
    v=result.size();

    int maxd=0;

    for(int i=0;i<v;i++)
        {
            home aux;
            aux = result.front();
            if(!i)
                    for(int j=0;j<c;j++)
                        {
                            if(absoluto(casa[j].y-aux.y)+absoluto(casa[j].x-aux.x)>maxd)
                                maxd=absoluto(casa[j].y-aux.y)+absoluto(casa[j].x-aux.x);
                        }


            int iaux=0;
            for(int j=0;j<c;j++)
                    {
                        if(absoluto(casa[j].y-aux.y)+absoluto(casa[j].x-aux.x)>iaux)
                            iaux=absoluto(casa[j].x-aux.x)+absoluto(casa[j].y-aux.y);
                    }
            if(iaux==maxd)
                {
                    res.push(aux);
                }

            if (iaux<maxd)
                {
                    maxd=iaux;
                    while(! res.empty() )
                        res.pop();
                    res.push(aux);
                }
            result.pop();

        }
    v=res.size();

    for(int i=v-1;i>=0;i--)
        {
            home aux;
            aux = res.front();
            fout<<aux.x<<" "<<aux.y<<endl;
            res.pop();
        }

    return 0;
}
