//modified from jason9319's original code.
int n, m;
bool visited[101010];
int par[101010][21];
int d[101010];
vector <int> graph[101010];
void dfs(int here,int depth) // run dfs(root,0)
{
    visited[here] = true;
    d[here] = depth;
    for (int there : graph[here])
    {
        if (visited[there])
            continue;
        par[there][0] = here;
        dfs(there, depth + 1);
    }
}

void precomputation()
{
    for (int i = 1; i<21; i++)
    {
        for (int j = 1; j<=n; j++)
        {
            par[j][i] = par[par[j][i-1]][i-1];
        }
    }
}

int lca(int x, int y)
{
    if (d[x]>d[y])
        swap(x,y);
    for (int i = 20; i>=0; i--)
    {
        if (d[y]-d[x] >= (1<<i))
        {
            y = par[y][i];
        }
    }
    if (x==y)
        return x;
    for (int i = 20; i>=0; i--)
    {
        if (par[x][i] != par[y][i])
        {
            x = par[x][i];
            y = par[y][i];
        }
    }
    return par[x][0];
}
