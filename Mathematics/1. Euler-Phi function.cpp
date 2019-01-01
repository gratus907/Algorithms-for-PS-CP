#define long long int lli
lli euler_phi(lli n)
{
    lli p=2;
    lli ephi = n;
    while(p*p<=n)
    {
        if (n%p == 0)
            ephi = ephi/p * (p-1);
        while(n%p==0)
            n/=p;
        p++;
    }
    if (n!=1)
    {
        ephi /= n;
        ephi *= (n-1);
    }
    return ephi;
}
