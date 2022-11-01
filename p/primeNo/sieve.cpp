#include<bits/stdc++.h>
using namespace std;

vector<int> findPrimes(int n) {
    vector<int> primes;
    vector<bool> isPrime(n + 1, true);
    isPrime[0] = isPrime[1] = false;

    for(int i = 2; i <= n; i++) {
        if(isPrime[i]) {
            int j = 2 * i;
            while(j <= n) {

                isPrime[j] = false;

                j += i;
            }

            primes.push_back(i);
        }
    }
    return primes;
}

int main() {

    int n;
    cin >> n;

    vector<int> primes = findPrimes(n);

    for(int i : primes) {

        cout << i << " ";
    }

    return 0;
}


// O(Nlog (log N))

// O(N)

// diff implementation starting fro highest runtime to lowest
    void sieve1(int n) {
        boolean[] sieve = new boolean[n+1];
        sieve[0] = sieve[1] = true;
        for (int i = 2; i <= n; i++) {
            if (!sieve[i]) {
                for (int j = 2*i; j <= n; j++) {
                    if (j%i == 0) {
                        sieve[j] = true;
                    }
                }
            }
        }
        for (int i = 2; i <= n; i++) {
            if (!sieve[i]) {
                System.out.println(i);
            }
        }
    }
    void sieve2(int n) {
        boolean[] sieve = new boolean[n+1];
        sieve[0] = sieve[1] = true;
        for (int i = 2; i <= n; i++) {
            if (!sieve[i]) {
                for (int j = 2*i; j <= n; j += i) {
                    sieve[j] = true;
                }
            }
        }
        for (int i = 2; i <= n; i++) {
            if (!sieve[i]) {
                System.out.println(i);
            }
        }
    }
    void sieve3(int n) {
        boolean[] sieve = new boolean[n+1];
        sieve[0] = sieve[1] = true;
        for (int i = 2; i * i <= n; i++) {
            if (!sieve[i]) {
                for (int j = 2*i; j <= n; j += i) {
                    sieve[j] = true;
                }
            }
        }
        for (int i = 2; i <= n; i++) {
            if (!sieve[i]) {
                System.out.println(i);
            }
        }
    }
    void sieve4(int n) {
        boolean[] sieve = new boolean[n+1];
        sieve[0] = sieve[1] = true;
        sieve[2] = false;
        for (int i = 4; i <= n; i += 2) sieve[i] = true;

        for (int i = 3; i * i <= n; i++) {
            if (!sieve[i]) {
                for (int j = 2*i; j <= n; j += i) {
                    sieve[j] = true;
                }
            }
        }
        for (int i = 2; i <= n; i++) {
            if (!sieve[i]) {
                System.out.println(i);
            }
        }
    }
