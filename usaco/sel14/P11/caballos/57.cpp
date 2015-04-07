#include <iostream>
#include <fstream>
#include <queue>

using namespace std;

char matriz[1000][1000];

main()
{
    ifstream in ("caballos.in",ifstream::in);
    ofstream out ("caballos.out",ofstream::out);
    int xlargo , ylargo , VariableLaCualNoSeParaQueSeUsaYElProblemaNoLoExplicaBien;
    int c=0;
    in >> xlargo;
    in >> ylargo;
    in >> VariableLaCualNoSeParaQueSeUsaYElProblemaNoLoExplicaBien;
    for(int c1=0; c1 < xlargo; c1++)
    {
        for(int c2=0; c2 < ylargo; c2++)
        {
            char aux;
            in >> aux;
            if('C'== aux ||'A'==aux || 'B'==aux ||'L'==aux ||'O'==aux)
            {
                matriz[c1][c2] = aux;
                if(aux == 'A')
                {
                    c++;
                }
            }
            else
            {
                matriz[c1][c2] = '#';
            }
        }
    }
    if(VariableLaCualNoSeParaQueSeUsaYElProblemaNoLoExplicaBien > c) VariableLaCualNoSeParaQueSeUsaYElProblemaNoLoExplicaBien -= c;
    out << c-VariableLaCualNoSeParaQueSeUsaYElProblemaNoLoExplicaBien << endl ;

}





































