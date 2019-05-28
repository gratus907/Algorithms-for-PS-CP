const int INF = 987654321;
const int MX = V+something;
struct Edgeout
{
    int dest, w;
    bool operator<(const Edgeout &p) const
    {
        return w > p.w;
    }
};

vector <Edgeout> edgelist[MX];
int V, E, start;
int dist[MX];

bool relax(Edgeout edge, int u)
{
    bool flag = 0;
    int v = edge.dest, w = edge.w;
    if (dist[v] > dist[u] + w && (dist[u]!=INF))
    {
        flag = true;
        dist[v] = dist[u]+w;
    }
    return flag;
}

int dijkstra()
{
    fill(dist,dist+MX,INF);
    dist[start] = 0;
    priority_queue<Edgeout> pq;
    pq.push({start,0});
    while(!pq.empty())
    {
        Edgeout x = pq.top();
        int v = x.dest, w = x.w;
        pq.pop();
        if (w>dist[v])
            continue;
        for (auto ed : edgelist[v])
            if (relax(ed,v))
                pq.push({ed.dest,dist[ed.dest]});
    }
}
