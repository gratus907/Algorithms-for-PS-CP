/*
Uses Dynamic Approach and extended Euclidean Algorithm
Find modular inverse of n in O(n) time.
*/
int modularInverse(int n, int p)
{
    int dp[n + 1];
    dp[0] = dp[1] = 1;
    for (int i = 2; i <= n; i++)
        dp[i] = dp[p % i] *
               (p - p / i) % p;

    return dp[n];
}
