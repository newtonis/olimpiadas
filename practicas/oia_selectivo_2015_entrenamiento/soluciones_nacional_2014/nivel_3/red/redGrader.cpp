#include "red.h"
#include "stdio.h"


int p,i, g, nl;
char pares[60000][2][12];
char lejanos[3000][12];

int main()
{
    freopen("input.in","r",stdin);
    scanf("%d", &p);
    for(i = 0; i < p; i++)
        scanf("%s%s",pares[i][0], pares[i][1]);
    g  = grado(p, pares, &nl, lejanos);
    printf("%d\n", g);
    for (i = 0; i < nl; i++)
        printf("%s\n", lejanos[i]);
    return 0;
}
