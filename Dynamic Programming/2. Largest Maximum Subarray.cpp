#include <bits/stdc++.h>
using namespace std;

int INF = (int)1e9;
int dp[1000200];
int number[1000200];

int MAX(int a, int b)
{
    return a>b? a: b;
}

void consum(int n)
{
    dp[0] = number[0];
    for (int i = 1; i<n; i++)
        dp[i] = MAX(dp[i-1]+number[i],number[i]);
}

int maxsum(int n)
{
    consum(n);
    int max_sum=-INF;
    for (int i = 0; i<n; i++)
        dp[i] > max_sum ? max_sum = dp[i] : 0;
    return max_sum;
}

int main()
{
    int n;
    scanf("%d",&n);
    for (int i = 0; i<n; i++)
        scanf("%d",number+i);
    int ax = maxsum(n);
    printf("%d",ax);
}
