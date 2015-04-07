#include <iostream>
#include <fstream>

using namespace std;

int main(){

    ifstream in ("compra.out");
    ofstream out ("compra.in");

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

    out<<ideal[0]<<ideal[1]<<endl;

}
