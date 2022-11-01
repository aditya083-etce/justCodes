#include<bits/stdc++.h>
using namespace std;

vector<bool> getPrimes(int n) {
    vector<bool> sieve(n + 1, true);
    for (int i = 2; i * i <= n; i++) {
        if (sieve[i]) {
            for (int j = 2*i; j <= n; j += i) {
                sieve[j] = false;
            }
        }
    }
    return sieve;
}

void segmentedSieve(int l,int r) {
    int sz = r - l + 1;
    vector<bool> sieve(sz);
    vector<int> primes = getPrimes((int)sqrt(r) + 1);

    for (int prime : primes) {
        int idx = (int) (ceil((1.0*l) / prime) * prime) - l;

        for (int j = idx; j < sieve.size(); j += prime) {
            sieve[j] = true;
        }

        if (prime >= l && prime <= r) {
            sieve[prime - l] = false;
        }
    }

    for (int i = 0; i < sz; i++) {
        if (!sieve[i] and l + i > 1) {
            cout << l + i <<endl;
        }
    }
    cout<<endl;
}

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int l, r;
        cin>>l>>r;
        segmentedSieve(l,r);
    }
    return 0;
}