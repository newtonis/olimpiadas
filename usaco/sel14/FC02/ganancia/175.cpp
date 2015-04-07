#include <iostream>
#include <fstream>
using namespace std;

int main(){
    int autos=0;
    int perdida=0;
    int aut[50][3];
    for(int x=0; x<50; x++)
    for(int y=0; y<3; y++)aut[x][y]=0;


    ifstream in ("ganancia.in");
    ofstream out ("ganancia.out");

    in>>autos;

    for(int x=0; x<autos; x++)
    for(int y=0; y<3; y++)in>>aut[x][y];

    int ganancia=0;

    int maxperd[2];//0=Mayor perdida, 1=Auto que la genero

    for(int y=autos-1; y>=0; y--)
    {

        maxperd[0]=0;
        maxperd[1]=0;

        for(int x=0; x<autos; x++)
        {
            if(aut[x][0]*aut[x][1]>maxperd[0] && aut[x][0]!=50)maxperd[0]=aut[x][0]*aut[x][1], maxperd[1]=x;


        }
        perdida=perdida+maxperd[0];
        aut[maxperd[1]][0]=50;



    }

    ganancia=0;
    for(int x=0; x<autos; x++)ganancia=ganancia+aut[x][2];

    out<<ganancia-perdida;

}
