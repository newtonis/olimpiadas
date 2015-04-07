#include <iostream>
#include <fstream>
using namespace std;
int n;
int resultado;
int tabla[10][10];
void recursion(int lista[10],int posicion)
{
    int k=0;
    if (posicion==n)
    {
        for (int i=0;i<n;i++)
        {
            if (lista[i]==1)
            {
                k++;
            }
        }
        int res=0;
        for (int i=0;i<n;i++)
        {
            for (int j=0;j<n;j++)
            {
                if ((tabla[i][j]==1)&&(lista[i]==1)&&(lista[j]==1))
                {
                    res=1;
                }
            }
        }
        cout<<k;
        if ((res==0)&&(k>resultado))
        {
            resultado=k;
            cout<<resultado;
        }
    }
    else
    {
            lista[posicion]=0;
            recursion(lista,posicion+1);
            lista[posicion]=1;
            recursion(lista,posicion+1);
    }

}
int main()
{
    resultado=0;
    ifstream fin ("casamiento.in");
    ofstream fout ("casamiento.out");
    int m;
    fin>>n>>m;

    int q[10]={0};
    for (int i=0;i<10;i++)
    {
        for (int j=0;j<10;j++)
        {
            tabla[i][j]=0;
        }
    }
    int x,y;
    for (int i=0;i<m;i++)
    {
            fin>>x>>y;
            x--;
            y--;
            tabla[x][y]=1;
    }
    recursion(q,0);
    fout<<resultado;


}
