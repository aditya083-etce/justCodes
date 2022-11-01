// EXTENDED ECUID
int[] extendedEuclid(int a, int b)
{
    if (b == 0)
    {
        return new int[]{1, 0};
    }
    int[] pair = extendedEuclid(b, a % b);
    int x = pair[1];
    int y = pair[0] - (a / b) * pair[1];
    return new int[]{x, y};
}

// FORMAT LITTLE THEOREM
long fastExpo(long b, long m, long mod)
{
    if (m == 0) return 1;
    long x = fastExpo(b, m/2, mod);
    if ((n&1) == 1){
        return ((b * x)%mod * x)%mod;
    }
    return (x * x)%mod;
}

long modinverse(long a, long mod){
    return fastExpo(b, mod-2, mod)%mod;
}

void solve()
{
    int b = 10;
    int mod = 29;

    long ans = modinverse(b, mod);

    cout<<ans;
}