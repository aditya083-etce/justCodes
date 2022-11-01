#include<bits/stdc++.h>
using namespace std;

int nCr(int n, int r) {

    if(r == 0) {

        return 1;
    }

    int last = nCr(n - 1, r - 1);

    return n * last / r;
}

int way1(int n) {

    int i = 0, sum = 0;

    while(i <= n) {

        sum += nCr(n, i);

        i += 2;
    }

    return sum;
}

int way2(int n) {

    int fact[n + 1];

    fact[0] = 1;

    for(int i = 1; i <= n; i++) {

        fact[i] = fact[i - 1] * i;
    }

    int i = 0, sum = 0;

    while(i <= n) {

        sum += fact[n] / (fact[i] * fact[n - i]);

        i += 2;
    }

    return sum;
}

int power(int n) {

    if(n == 0) {

        return 1;
    }

    int ans = power(n / 2);

    ans *= ans;

    return n % 2 ? ans * 2 : ans;
}

int way3(int n) {

    return power(n - 1);
}

int main() {
    
    int n;
    cin >> n;

    return 0;
}