#include <iostream>
#include <fstream>
using namespace std;

int main(){
    int posinv, parej;

    ifstream in ("casamiento.in");
    ofstream out ("casamiento.out");

    in>>posinv>>parej;


    int maxinv=0;
    int regnum[posinv+1][3];//0=conectado, 1=largo, 2=otroextremo

    for(int x=0; x<posinv+1; x++)regnum[x][0]=0, regnum[x][1]=0, regnum[x][2]=0;


    for(int x=0; x<parej; x++){
        int uno, dos;
        in>>uno>>dos;

        cout<<uno<<' '<<dos<<endl;
        cout<<regnum[uno][0]<<' '<<regnum[uno][1]<<' '<<regnum[uno][2]<<' '<<endl;
        cout<<regnum[dos][0]<<' '<<regnum[dos][1]<<' '<<regnum[dos][2]<<' '<<endl;


        if(regnum[uno][0]==0 && regnum[dos][0]==0) regnum[uno][0]=1, regnum[uno][1]=2, regnum[dos][0]=1, regnum[dos][1]=2, maxinv++, regnum[uno][2]=dos, regnum[dos][2]=uno;
        else if(regnum[uno][0]==1 && regnum[dos][0]==0)
        {
            regnum[dos][0]=1;
            if(regnum[uno][1]%2==0)maxinv++;
            regnum[dos][1]=regnum[uno][1]+1;

            regnum[regnum[uno][2]][1]++;
            regnum[dos][2]=regnum[uno][2];
            regnum[regnum[uno][2]][2]=dos;

        }
        else if(regnum[dos][0]==1 && regnum[uno][0]==0)
        {
            regnum[uno][0]=1;
            if(regnum[dos][1]%2==0)maxinv++;
            regnum[uno][1]=regnum[dos][1]+1;

            regnum[regnum[dos][2]][1]++;
            regnum[uno][2]=regnum[dos][2];
            regnum[regnum[dos][2]][2]=uno;

        }
        else if(regnum[uno][0]==1 && regnum[dos][0]==1)
        {
            if(regnum[uno][1]%2==1)maxinv--;


        }
    }


    out<<maxinv;

}
