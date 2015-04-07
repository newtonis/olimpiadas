#include <iostream>
#include <fstream>

using namespace std;

main()
{
    ifstream in ("compra.in",ifstream::in);
    ofstream out ("compra.out",ofstream::out);

    int x = -100, y = -100;
    int aux , aux2;
    in >> aux >> aux2;
    int c;
    in >> c;
    for(int c1=0; c1<c; c1++)
    {
        int a,b;
        in >> a >> b;
        if(a > x) x=a;
        if(b > y) y=b;
    }
    out << x/2 << " " << y/2 << endl;
    out << y/2 << " " << y/2 << endl;
}


