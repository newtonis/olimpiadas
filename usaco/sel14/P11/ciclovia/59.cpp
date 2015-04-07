 #include <iostream>
#include <fstream>

using namespace std;

main()
{
    ifstream in ("ciclovia.in",ifstream::in);
    ofstream out ("ciclovia.out",ofstream::out);

    int x,y;
    in >> x >> y;
    out << x*y << endl;
}


