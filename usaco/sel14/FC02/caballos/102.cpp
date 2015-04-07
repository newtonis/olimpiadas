#include <iostream>
#include <fstream>
#include <queue>
#include <stack>

using namespace std;


int main(){

    ifstream in ("caballos.in");
    ofstream out ("caballos.out");



    int H, L, m;
    in>>H>>L>>m;



    char tblr[L+4][H+4];//tablero

    for (int y=0; y<H; y++)
    for (int x=0; x<L; x++){

        in>>tblr[x+2][y+2];

    }

    stack<int> S[3];

    for(int y=0; y<H+4; y++)
    for(int x=0; x<L+4; x++)
    {
        if(tblr[x][y] == 'C') S[0].push(x), S[1].push(y), S[2].push(1);
    }



        int x, y, lugar;

        int cantcab=0;

    while(S[2].empty()==false)
        {
            x=S[0].top();
            y=S[1].top();
            lugar=S[2].top();


            if(lugar==6){
                if(tblr[x-2][y+1]=='O')S[0].pop(), S[1].pop(), S[2].pop(), cantcab++;
                if(tblr[x-2][y-1]=='O')S[0].pop(), S[1].pop(), S[2].pop(), cantcab++;
                if(tblr[x-1][y+2]=='O')S[0].pop(), S[1].pop(), S[2].pop(), cantcab++;
                if(tblr[x-1][y-2]=='O')S[0].pop(), S[1].pop(), S[2].pop(), cantcab++;
                if(tblr[x+1][y+2]=='O')S[0].pop(), S[1].pop(), S[2].pop(), cantcab++;
                if(tblr[x+1][y-2]=='O')S[0].pop(), S[1].pop(), S[2].pop(), cantcab++;
                if(tblr[x+2][y+1]=='O')S[0].pop(), S[1].pop(), S[2].pop(), cantcab++;
                if(tblr[x+2][y-1]=='O')S[0].pop(), S[1].pop(), S[2].pop(), cantcab++;
            }



            if(lugar==5){
                if(tblr[x-2][y+1]=='L')S[0].pop(), S[1].pop(), S[2].pop(), S[0].push(x-2), S[1].push(y+1), S[2].push(6);
                if(tblr[x-2][y-1]=='L')S[0].pop(), S[1].pop(), S[2].pop(), S[0].push(x-2), S[1].push(y-1), S[2].push(6);
                if(tblr[x-1][y+2]=='L')S[0].pop(), S[1].pop(), S[2].pop(), S[0].push(x-1), S[1].push(y+2), S[2].push(6);
                if(tblr[x-1][y-2]=='L')S[0].pop(), S[1].pop(), S[2].pop(), S[0].push(x-1), S[1].push(y-2), S[2].push(6);
                if(tblr[x+1][y+2]=='L')S[0].pop(), S[1].pop(), S[2].pop(), S[0].push(x+1), S[1].push(y+2), S[2].push(6);
                if(tblr[x+1][y-2]=='L')S[0].pop(), S[1].pop(), S[2].pop(), S[0].push(x+1), S[1].push(y-2), S[2].push(6);
                if(tblr[x+2][y+1]=='L')S[0].pop(), S[1].pop(), S[2].pop(), S[0].push(x+2), S[1].push(y+1), S[2].push(6);
                if(tblr[x+2][y-1]=='L')S[0].pop(), S[1].pop(), S[2].pop(), S[0].push(x+2), S[1].push(y-1), S[2].push(6);
            }



            if(lugar==4){
                if(tblr[x-2][y+1]=='L')S[0].pop(), S[1].pop(), S[2].pop(), S[0].push(x-2), S[1].push(y+1), S[2].push(5);
                if(tblr[x-2][y-1]=='L')S[0].pop(), S[1].pop(), S[2].pop(), S[0].push(x-2), S[1].push(y-1), S[2].push(5);
                if(tblr[x-1][y+2]=='L')S[0].pop(), S[1].pop(), S[2].pop(), S[0].push(x-1), S[1].push(y+2), S[2].push(5);
                if(tblr[x-1][y-2]=='L')S[0].pop(), S[1].pop(), S[2].pop(), S[0].push(x-1), S[1].push(y-2), S[2].push(5);
                if(tblr[x+1][y+2]=='L')S[0].pop(), S[1].pop(), S[2].pop(), S[0].push(x+1), S[1].push(y+2), S[2].push(5);
                if(tblr[x+1][y-2]=='L')S[0].pop(), S[1].pop(), S[2].pop(), S[0].push(x+1), S[1].push(y-2), S[2].push(5);
                if(tblr[x+2][y+1]=='L')S[0].pop(), S[1].pop(), S[2].pop(), S[0].push(x+2), S[1].push(y+1), S[2].push(5);
                if(tblr[x+2][y-1]=='L')S[0].pop(), S[1].pop(), S[2].pop(), S[0].push(x+2), S[1].push(y-1), S[2].push(5);
            }



            if(lugar==3){
                if(tblr[x-2][y+1]=='A')S[0].pop(), S[1].pop(), S[2].pop(), S[0].push(x-2), S[1].push(y+1), S[2].push(4);
                if(tblr[x-2][y-1]=='A')S[0].pop(), S[1].pop(), S[2].pop(), S[0].push(x-2), S[1].push(y-1), S[2].push(4);
                if(tblr[x-1][y+2]=='A')S[0].pop(), S[1].pop(), S[2].pop(), S[0].push(x-1), S[1].push(y+2), S[2].push(4);
                if(tblr[x-1][y-2]=='A')S[0].pop(), S[1].pop(), S[2].pop(), S[0].push(x-1), S[1].push(y-2), S[2].push(4);
                if(tblr[x+1][y+2]=='A')S[0].pop(), S[1].pop(), S[2].pop(), S[0].push(x+1), S[1].push(y+2), S[2].push(4);
                if(tblr[x+1][y-2]=='A')S[0].pop(), S[1].pop(), S[2].pop(), S[0].push(x+1), S[1].push(y-2), S[2].push(4);
                if(tblr[x+2][y+1]=='A')S[0].pop(), S[1].pop(), S[2].pop(), S[0].push(x+2), S[1].push(y+1), S[2].push(4);
                if(tblr[x+2][y-1]=='A')S[0].pop(), S[1].pop(), S[2].pop(), S[0].push(x+2), S[1].push(y-1), S[2].push(4);
            }



            if(lugar==2){
                if(tblr[x-2][y+1]=='B')S[0].pop(), S[1].pop(), S[2].pop(), S[0].push(x-2), S[1].push(y+1), S[2].push(3);
                if(tblr[x-2][y-1]=='B')S[0].pop(), S[1].pop(), S[2].pop(), S[0].push(x-2), S[1].push(y-1), S[2].push(3);
                if(tblr[x-1][y+2]=='B')S[0].pop(), S[1].pop(), S[2].pop(), S[0].push(x-1), S[1].push(y+2), S[2].push(3);
                if(tblr[x-1][y-2]=='B')S[0].pop(), S[1].pop(), S[2].pop(), S[0].push(x-1), S[1].push(y-2), S[2].push(3);
                if(tblr[x+1][y+2]=='B')S[0].pop(), S[1].pop(), S[2].pop(), S[0].push(x+1), S[1].push(y+2), S[2].push(3);
                if(tblr[x+1][y-2]=='B')S[0].pop(), S[1].pop(), S[2].pop(), S[0].push(x+1), S[1].push(y-2), S[2].push(3);
                if(tblr[x+2][y+1]=='B')S[0].pop(), S[1].pop(), S[2].pop(), S[0].push(x+2), S[1].push(y+1), S[2].push(3);
                if(tblr[x+2][y-1]=='B')S[0].pop(), S[1].pop(), S[2].pop(), S[0].push(x+2), S[1].push(y-1), S[2].push(3);
            }


            if(lugar==1){
                if(tblr[x-2][y+1]=='A')S[0].pop(), S[1].pop(), S[2].pop(), S[0].push(x-2), S[1].push(y+1), S[2].push(2);
                if(tblr[x-2][y-1]=='A')S[0].pop(), S[1].pop(), S[2].pop(), S[0].push(x-2), S[1].push(y-1), S[2].push(2);
                if(tblr[x-1][y+2]=='A')S[0].pop(), S[1].pop(), S[2].pop(), S[0].push(x-1), S[1].push(y+2), S[2].push(2);
                if(tblr[x-1][y-2]=='A')S[0].pop(), S[1].pop(), S[2].pop(), S[0].push(x-1), S[1].push(y-2), S[2].push(2);
                if(tblr[x+1][y+2]=='A')S[0].pop(), S[1].pop(), S[2].pop(), S[0].push(x+1), S[1].push(y+2), S[2].push(2);
                if(tblr[x+1][y-2]=='A')S[0].pop(), S[1].pop(), S[2].pop(), S[0].push(x+1), S[1].push(y-2), S[2].push(2);
                if(tblr[x+2][y+1]=='A')S[0].pop(), S[1].pop(), S[2].pop(), S[0].push(x+2), S[1].push(y+1), S[2].push(2);
                if(tblr[x+2][y-1]=='A')S[0].pop(), S[1].pop(), S[2].pop(), S[0].push(x+2), S[1].push(y-1), S[2].push(2);
            }
        }
    out<<cantcab%3;

}
