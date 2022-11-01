//( a ^ b ) % mod

//  using fast modular expo
// https://www.youtube.com/watch?v=K8mJ27S72v0&t=537s


#include<bits/stdc++.h>
using namespace std;
#define mod 1e9+7

long long int powerRecursive(long long int a, long long int b, long long int mod)
{
    if (b == 0) return 1;
    long long int val = powerRecursive(a, b/2, mod);

    if(b & 1) { // power is odd
        return (a * ((val * val) % mod) ) % mod;
    } else { // power is even
        return (val * val) % mod;
    }
}

long long int powerIterative(long long int a, long long int b, long long int mod)
{
    if (b == 0) return 1;
    long long int res = 1;

    while(b > 0){
        if(b & 1){ // 0th bit set 
            res = (res * a) % mod;
        }
        a = (a * a) % mod;
        b = b >> 1;
    }
    return res;
}

long long int power(long long int a, long long int b, long long int mod)
{
    if (b == 0) return 1;
    long long int res = 1;

    while(b > 0) {
        if (b % 2 == 1) {
            res = (res * a) % mod;
            b = b - 1;
        } else {
            a = (a * a) % mod;
            b = b / 2;
        }
    }
    return res;
}

int main()
{
    long long int a, b; cin >> a >> b;
    cout << power(a,b) << endl;
    return 0;
}