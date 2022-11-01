#include <bits/stdc++.h>
using namespace std;

vector<bool> seive(int n) {
    vector<bool> isPrime(n+1, true);
    isPrime[0] = isPrime[1] = false;
    for(int i = 2; i <= n; i++) {
        if (isPrime[i]) {
            int j = i * 2;
            while(j <= n) {
                isPrime[j] = false;
                j += i;
            }
        }
    }
    return isPrime;
}

bool check(int n, vector<bool>& isPrime) {
    int sum = 0;
    while(n!=0) {
        sum += n % 10;
        n = n / 10;
    } 
    
    return isPrime[sum];
}

int bruteforce(int L, int R, vector<bool>& isPrime) {
    int cnt = 0;
    for(int i = L; i<=R; i++) {
        if (check(i, isPrime)) cnt++;