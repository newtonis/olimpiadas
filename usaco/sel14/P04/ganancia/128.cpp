#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    ifstream fin ("ganancia.in");
    ofstream fout ("ganancia.out");

    int a;
    fin>>a;
    int t[50];
    int d[50];
    int cantidad[50]={0};
    int orden[50];
    int preciofinal=0;
    int p;
     for (int i=0;i<a;i++)
    {
        fin>>d[i]>>t[i]>>p;
        preciofinal=preciofinal+p;

    }

    for (int i=0;i<a;i++)
    {
        for (int j=i;j<a;j++)
        {
            if (d[i]*t[j]<d[j]*t[i])
            {
             cantidad[j]++;

            }
             if (d[i]*t[j]>d[j]*t[i])
            {
             cantidad[i]++;

            }
            if ((d[i]*t[j]==d[j]*t[i])&&((i>j)||(i<j)))
            {
                cantidad[j]++;
            }
        }
    }

    for (int i=0;i<a;i++)
    {
        for (int j=0;j<a;j++)
        {
            if (cantidad[j]==i)
            {
                orden[i]=j;
            }
        }
    }


     for (int i=0;i<a;i++)
    {
        for (int j=i+1;j<a;j++)
        {
            preciofinal=preciofinal-d[orden[i]]*t[orden[j]];


        }
    }
     fout<<preciofinal;

}
