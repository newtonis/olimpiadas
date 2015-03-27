#include "television.h"
#include "stdio.h"

int acierto[3000], error[3000], cupon[3000], fin[3000];
int C,S,M,i;
int ng,maxp,nmaxp;

int main()
{
    freopen("input.in","r",stdin);
    scanf("%d%d%d", &C, &S, &M);
    for (i = 0; i < C; i++)
        scanf("%d%d%d", acierto + i, error + i, cupon + i);
    for (i = 0; i < S; i++)
        scanf("%d", fin + i);
    TV(C,S,M,acierto,error,cupon,fin, &ng, &maxp, &nmaxp);
    printf("%d %d %d\n", ng, maxp, nmaxp);
    return 0;
}
