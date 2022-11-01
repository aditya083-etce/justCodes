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



int main()
{
    int n;
    cin>>n;
    if (n%2 == 1)
    {
        if (isPrime(n - 2)){
            cout<<2<<" "<<n-2<<endl;
        }else{
            cout<<-1;
        }
    }else{
        vector<int> primes = findPrimes(n);

        for(int x: primes){
            if (x > n/2)
            {
                
            }
        }
    }
}