struct Trie_Node
{
    Trie_Node * child[26];
    Trie_Node()
    {
        fill(child,child+26,nullptr);
        this->end = 0;
    }
    bool end;
    void insert(const char* key)
    {
        if (*key == 0)
            end = true;
        else
        {
            int cur = *key-'a';
            if (child[cur]==NULL)
                child[cur] = new Trie_Node();
            child[cur]->insert(key+1);
        }
    }
    bool find(char *key)
    {
        if (*key == 0)
            return false;
        if (end)
            return true;
        int cur = *key - 'a';
        return child[cur]->find(key+1);
    }
};
