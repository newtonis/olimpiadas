#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

#define forn(i,n) for(int i=0;i<(int)(n);i++)
#define dforn(i,n) for(int i=(n)-1;i>=0;i--)

const int dx[8] = {1,2,2,1,-1,-2,-2,-1};
const int dy[8] = {2,1,-1,-2,-2,-1,1,2};

const int MAX = 1024;

char t[MAX][MAX];

const char * target = "CABALLO";
const int len = strlen(target);

int dp[16][MAX][MAX];

int main()
{
    freopen("caballos.in", "r", stdin);
    freopen("caballos.out", "w", stdout);
    int f,c,m; cin >> f >> c >> m;
    forn(i,f)
        cin >> t[i];
    forn(i,f)
    forn(j,c)
        dp[len-1][i][j] = t[i][j] == target[len-1];
    dforn(k,len-1)
    forn(i,f)
    forn(j,c)
    {
        dp[k][i][j] = 0;
        if (t[i][j] == target[k])
        {
            forn(d, 8)
            {
                int nx = i + dx[d];
                int ny = j + dy[d];
                if (0 <= nx && nx < f && 0 <= ny && ny < c)
                {
                    dp[k][i][j] += dp[k+1][nx][ny];
                    dp[k][i][j] %= m;
                }
            }
        }
    }
    int res = 0;
    forn(i,f)
    forn(j,c)
    {
        res += dp[0][i][j];
        res %= m;
    }
    cout << res << endl;
    return 0;
}
