#include <bits/stdc++.h>
#define ll long long
#define MAX(A,B) ((A)>(B)?(A):(B))
#define MIN(A,B) ((A)<(B)?(A):(B))
using namespace std;

/*
Stores minimum-length path on d[V][V]
Prints out all-path-shortest-length [V][V], by minimizing everything.
Time : O(V^3), Memory : O(V^2)
*/
int d[120][120];
int main()
{
    for (int i = 0; i<120; i++)
        for (int j = 0; j<120; j++)
            d[i][j] = (int)1e9;
    int n,m;
    scanf("%d%d",&n,&m);
    for (int i = 0; i<m; i++)
    {
        int a,b,v;
        scanf("%d %d %d",&a,&b,&v);
        d[a][b] = MIN(d[a][b],v);
    }
    for (int i = 1; i<=n; i++)
        for (int j = 1; j<=n; j++)
            for (int k = 1; k<=n; k++)
                d[j][k] = MIN(d[j][k],d[j][i]+d[i][k]);
    for (int i = 1; i<=n; i++)
    {
        for (int j = 1; j<=n; j++)
        {
            if (i==j)
                d[i][j] = 0;
            if (d[i][j] > 100000000)
                d[i][j] = 0;
            printf("%d ",d[i][j]);
        }
        printf("\n");
    }
}
