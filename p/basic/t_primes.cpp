#include<bits/stdc++.h>
using namespace std;

set<long long> findPrimes(long long n) {
    set<long long> primes;
    vector<bool> isPrime(n + 1, true);
    isPrime[0] = isPrime[1] = false;

    for(long long i = 2; i <= n; i++) {
        if(isPrime[i]) {
            long long j = 2 * i;
            while(j <= n) {

                isPrime[j] = false;

                j += i;
            }

            primes.insert(i*i);
        }
    }

    return primes;
}

int main() {

    int n;
    cin >> n;
    vector<long long>arr(n);
    long long mx = 0;

    for(long long i = 0; i<n; i++){
        cin >> arr[i];
        mx = max(mx, arr[i]);
    }

    set<long long> p = findPrimes(mx);

    for(long long i: arr)
    {
        if (p.find(i) != p.end()){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
    }
    return 0;
}
