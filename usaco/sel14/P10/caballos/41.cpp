#include <iostream>
#include <fstream>

using namespace std;

int f,c,result,m;
char board[1000][1000];

void findll(int x, int y);
void finda(int x, int y);
void findaa(int x, int y);
void findb(int x, int y);
void findc(int x, int y);

char uleft ( int x, int y)
    {
        if(x-1<0)
            return 'z';
        if(y-2<0)
            return 'z';
        return board[x-1][y-2];
    }

char uright ( int x, int y)
    {
        if(x+1>=c)
            return 'z';
        if(y-2<0)
            return 'z';
        return board[x+1][y-2];
    }
char dleft ( int x, int y)
    {
        if(x-1<0)
            return 'z';
        if(y+2>=f)
            return 'z';
        return board[x-1][y+2];
    }

char dright ( int x, int y)
    {
        if(x+1>=c)
            return 'z';
        if(y+2>=f)
            return 'z';
        return board[x+1][y+2];
    }

char lup ( int x, int y)
    {
        if(x-2<0)
            return 'z';
        if(y-1<0)
            return 'z';
        return board[x-2][y-1];
    }

char ldown ( int x, int y)
    {
        if(x-2<0)
            return 'z';
        if(y+1>=f)
            return 'z';
        return board[x-2][y+1];
    }

char rup ( int x, int y)
    {
        if(x+2>=c)
            return 'z';
        if(y-1<0)
            return 'z';
        return board[x+2][y-1];
    }

char rdown (int x, int y)
    {
        if(x+2>=c)
            return 'z';
        if(y+1>=f)
            return 'z';
        return board[x+2][y+1];
    }

void findl (int x, int y)
    {
        if(lup(x,y)=='L')
            findll(x-2,y-1);
        if(ldown(x,y)=='L')
            findll(x-2,y+1);
        if(rup(x,y)=='L')
            findll(x+2,y-1);
        if(rdown(x,y)=='L')
            findll(x+2,y+1);
        if(dleft(x,y)=='L')
            findll(x-1,y+2);
        if(dright(x,y)=='L')
            findll(x+1,y+2);
        if(uleft(x,y)=='L')
            findll(x-1,y-2);
        if(uright(x,y)=='L')
            findll(x+1,y-2);
        result=result%m;
    }

void findll (int x, int y)
    {
        if(lup(x,y)=='L')
            finda(x-2,y-1);
        if(ldown(x,y)=='L')
            finda(x-2,y+1);
        if(rup(x,y)=='L')
            finda(x+2,y-1);
        if(rdown(x,y)=='L')
            finda(x+2,y+1);
        if(dleft(x,y)=='L')
            finda(x-1,y+2);
        if(dright(x,y)=='L')
            finda(x+1,y+2);
        if(uleft(x,y)=='L')
            finda(x-1,y-2);
        if(uright(x,y)=='L')
            finda(x+1,y-2);
    }

void finda (int x, int y)
    {
        if(lup(x,y)=='A')
            findb(x-2,y-1);
        if(ldown(x,y)=='A')
            findb(x-2,y+1);
        if(rup(x,y)=='A')
            findb(x+2,y-1);
        if(rdown(x,y)=='A')
            findb(x+2,y+1);
        if(dleft(x,y)=='A')
            findb(x-1,y+2);
        if(dright(x,y)=='A')
            findb(x+1,y+2);
        if(uleft(x,y)=='A')
            findb(x-1,y-2);
        if(uright(x,y)=='A')
            findb(x+1,y-2);
    }

void findb (int x, int y)
    {
        if(lup(x,y)=='B')
            findaa(x-2,y-1);
        if(ldown(x,y)=='B')
            findaa(x-2,y+1);
        if(rup(x,y)=='B')
            findaa(x+2,y-1);
        if(rdown(x,y)=='B')
            findaa(x+2,y+1);
        if(dleft(x,y)=='B')
            findaa(x-1,y+2);
        if(dright(x,y)=='B')
            findaa(x+1,y+2);
        if(uleft(x,y)=='B')
            findaa(x-1,y-2);
        if(uright(x,y)=='B')
            findaa(x+1,y-2);
    }

void findaa (int x, int y)
    {
        if(lup(x,y)=='A')
            findc(x-2,y-1);
        if(ldown(x,y)=='A')
            findc(x-2,y+1);
        if(rup(x,y)=='A')
            findc(x+2,y-1);
        if(rdown(x,y)=='A')
            findc(x+2,y+1);
        if(dleft(x,y)=='A')
            findc(x-1,y+2);
        if(dright(x,y)=='A')
            findc(x+1,y+2);
        if(uleft(x,y)=='A')
            findc(x-1,y-2);
        if(uright(x,y)=='A')
            findc(x+1,y-2);
    }

void findc (int x, int y)
    {
        if(lup(x,y)=='C')
            result++;
        if(ldown(x,y)=='C')
            result++;
        if(rup(x,y)=='C')
            result++;
        if(rdown(x,y)=='C')
            result++;
        if(dleft(x,y)=='C')
            result++;
        if(dright(x,y)=='C')
            result++;
        if(uleft(x,y)=='C')
            result++;
        if(uright(x,y)=='C')
            result++;
    }

int main()
{
    ifstream fin("caballos.in");
    fin>>f>>c>>m;
    for(int i=0;i<f;i++)
        for(int j=0;j<c;j++)
            fin>>board[j][i];
    for(int i=0;i<f;i++)
        for(int j=0;j<c;j++)
            if(board[j][i]=='O')
                findl(j,i);
    ofstream fout("caballos.out");
    fout<<result<<endl;
    return 0;
}
