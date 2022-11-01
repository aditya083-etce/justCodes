#include <bits/stdc++.h>
using namespace std;

int main() {

    long long n;
    cin >> n;

    vector<long long> a(n), b(n);

    for(int i = 0; i < n; i++) {

        cin >> a[i];
    }

    long long mod = 998244353;

    for(int i = 0; i < n; i++) {

        a[i] *= (n - i) * (i + 1);
    }

    for(int i = 0; i < n; i++) {

        cin >> b[i];
    }

    sort(a.begin(), a.end());

    sort(b.begin(), b.end());

    long long res = 0;

    for(int i = 0; i < n; i++) {

        res = (res + (a[i] % mod * b[n - 1 - i] % mod) % mod) % mod;
    }

    cout << res;
    
    return 0;
}
