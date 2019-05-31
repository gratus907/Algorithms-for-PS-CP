//Union Find with Pass compression
int parent[V]; //initialize with i
int level[V]; //initialize with 1
int Find(int x) // Finding root node of x
{
    if (x==parent[x])
        return x;
    else
        return parent[x] = Find(parent[x]);
}

void Union(int x, int y)
{
    int u = Find(x);
    int v = Find(y);
    if (u == v)
        return;
    if (level[u] > level[v])
    {
        Union(v,u);
        return;
    }
    parent[u] = v;
    if (level[u]==level[v])
        level[v]++;
}
