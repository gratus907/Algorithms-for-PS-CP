// Original Author : Ashishgup
struct Disjoint_Set_Union
{
    int connected;
    int parent[V], size[V];

    void init(int n)
    {
        for(int i=1;i<=n;i++)
        {
            parent[i]=i;
            size[i]=1;
        }
        connected=n;
    }
    int Find(int k)
    {
        while(k!=parent[k])
        {
            parent[k]=parent[parent[k]];
            k=parent[k];
        }
        return k;
    }
    int getSize(int k)
    {
        return size[Find(k)];
    }
    void unite(int x, int y)
    {
        int u=Find(x), v=Find(y);
        if(u==v)
            return;
        if(size[u]>size[v])
            swap(par1, par2);
        size[v]+=size[u];
        size[u] = 0;
        parent[u] = parent[v];
    }
} dsu;
