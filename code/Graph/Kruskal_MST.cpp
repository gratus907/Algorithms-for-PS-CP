
int Kruskal()
{
    int mstlen = 0;
    sort(edgelist.begin(),edgelist.end());
    for (auto it:edgelist)
    {
        if (Find(it.s)==Find(it.e)) // Cycle Detection
            continue;
        else
        {
            Union(it.s,it.e);
            mstlen += it.w;
        }
    }
    return mstlen;
}
