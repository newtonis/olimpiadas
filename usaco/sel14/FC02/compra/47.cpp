#include <iostream>
#include <fstream>

using namespace std;

int main(){

    ifstream in ("compra.in");
    ofstream out ("compra.out");

    int V, H, C;
    in>>V>>H>>C;

    int casas[C][2];
    double ideal[2]={0,0};


    for(int x=0; x<C; x++){

        in>>casas[x][0]>>casas[x][1];
        ideal[0]=ideal[0]+casas[x][0];
        ideal[1]=ideal[1]+casas[x][1];

    }

    ideal[0]=ideal[0]/C;
    ideal[1]=ideal[1]/C;


    int pos;

    bool entre=false;

    if(int(ideal[0]*10)%10<5){

        int pos=ideal[0];

        out<<pos<<' ';

    }
    else if(int(ideal[0]*10)%10>5){

        int pos=ideal[0]+1;

        out<<pos<<' ';

    }else
    {

        int pos=ideal[0];
        out<<pos<<' ';
        entre=true;

        if(int(ideal[1]*10)%10<5)
        {
            int pos2 = ideal[1];
            out<<pos2<<endl<<pos+1<<' '<<pos2;
        }
        else if(int(ideal[1]*10)%10>5)
        {
            int pos2 = ideal[1]+1;
            out<<pos2<<endl<<pos+1<<' '<<pos2;;
        }
        else
        {
            int pos2 = ideal[1];
            out<<pos2<<endl<<pos<<' '<<pos2+1<<endl<<pos+1<<' '<<pos2<<endl<<pos+1<<' '<<pos2+1;
        }


    }




        if(int(ideal[1]*10)%10<5 && !entre)
        {
            int pos2 = ideal[1];
            out<<pos2;
        }
        else if(int(ideal[1]*10)%10>5 && !entre)
        {
            int pos2 = ideal[1]+1;
            out<<pos2;
        }
        else if(!entre)
        {
            int pos2 = ideal[1];
            out<<pos2<<endl<<pos<<' '<<pos2+1;
        }





    out<<endl;

}
