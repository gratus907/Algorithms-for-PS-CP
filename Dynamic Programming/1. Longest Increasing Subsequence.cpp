#include <bits/stdc++.h>
using namespace std;

vector <int> seq;
vector <int> L;
int lis_len;
int position[1000003];
int lis[1000003];
int lis_pushed[1000003];
int main()
{
    int n;
    scanf("%d",&n);
    for (int i = 0; i<n; i++)
    {
        int x;
        scanf("%d",&x);
        seq.push_back(x);
    }
    L.push_back(seq[0]);
    position[0] = 0;
    for (int i = 1; i<n; i++)
    {
        if (seq[i] > L[L.size()-1])
        {
            position[i] = L.size();
            L.push_back(seq[i]);
        }
        else
        {
            int pos = lower_bound(L.begin(),L.end(),seq[i])-L.begin();
            L[pos] = seq[i];
            position[i] = pos;
        }
    }
    lis_len=L.size();
    int lookingfor = lis_len-1;
    for (int i = n-1; i>=0; i--)
    {
        if (lis_pushed[position[i]]==0 && lookingfor == position[i])
        {
            lis[position[i]] = seq[i];
            lis_pushed[position[i]]=1;
            lookingfor--;
        }
    }
    printf("%d\n",lis_len);
    for (int i = 0; i<lis_len; i++)
        printf("%d ",lis[i]);
}
